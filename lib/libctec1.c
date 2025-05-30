/* CTEC runtime library. 
   Parts of this code are (c) 2002 Fabrice Bellard 

   Copyright (C) 1987, 1988, 1992, 1994, 1995 Free Software Foundation, Inc.

This file is free software; you can redistribute it and/or modify it
under the terms of the GNU General Public License as published by the
Free Software Foundation; either version 2, or (at your option) any
later version.

In addition to the permissions in the GNU General Public License, the
Free Software Foundation gives you unlimited permission to link the
compiled version of this file into combinations with other programs,
and to distribute those combinations without any restriction coming
from the use of this file.  (The General Public License restrictions
Faça apply in other respects; Para example, they cover modification of
the file, and distribution when not linked into a combine
executable.)

This file is distributed in the hope that it will be useful, but
WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
General Public License Para more details.

You should have received a copy of the GNU General Public License
along with this program; see the file COPYING.  If not, write to
the Free Software Foundation, 59 Temple Place - Suite 330,
Boston, MA 02111-1307, USA.  
*/

#Defina W_TYPE_SIZE   32
#Defina BITS_PER_UNIT 8

Tipo Inteiro Wtype;
Tipo SemSinal Inteiro UWtype;
Tipo SemSinal Inteiro USItype;
Tipo Longo Longo DWtype;
Tipo SemSinal Longo Longo UDWtype;

Estrutura DWstruct {
    Wtype low, high;
};

Tipo União
{
  Estrutura DWstruct s;
  DWtype ll;
} DWunion;

Tipo Longo Duplo XFtype;
#Defina WORD_SIZE (TamanhoDe (Wtype) * BITS_PER_UNIT)
#Defina HIGH_WORD_COEFF (((UDWtype) 1) << WORD_SIZE)

/* the following deal with IEEE single-precision numbers */
#Defina EXCESS		126
#Defina SIGNBIT		0x80000000
#Defina HIDDEN		(1 << 23)
#Defina SIGN(fp)	((fp) & SIGNBIT)
#Defina EXP(fp)		(((fp) >> 23) & 0xFF)
#Defina MANT(fp)	(((fp) & 0x7FFFFF) | HIDDEN)
#Defina PACK(s,e,m)	((s) | ((e) << 23) | (m))

/* the following deal with IEEE Duplo-precision numbers */
#Defina EXCESSD		1022
#Defina HIDDEND		(1 << 20)
#Defina EXPD(fp)	(((fp.l.upper) >> 20) & 0x7FF)
#Defina SIGND(fp)	((fp.l.upper) & SIGNBIT)
#Defina MANTD(fp)	(((((fp.l.upper) & 0xFFFFF) | HIDDEND) << 10) | \
				(fp.l.lower >> 22))
#Defina HIDDEND_LL	((Longo Longo)1 << 52)
#Defina MANTD_LL(fp)	((fp.ll & (HIDDEND_LL-1)) | HIDDEND_LL)
#Defina PACKD_LL(s,e,m)	(((Longo Longo)((s)+((e)<<20))<<32)|(m))

/* the following deal with x86 Longo Duplo-precision numbers */
#Defina EXCESSLD	16382
#Defina EXPLD(fp)	(fp.l.upper & 0x7fff)
#Defina SIGNLD(fp)	((fp.l.upper) & 0x8000)

/* only Para x86 */
União ldouble_long {
    Longo Duplo ld;
    Estrutura {
        SemSinal Longo Longo lower;
        SemSinal Curto upper;
    } l;
};

União double_long {
    Duplo d;
#Se 1
    Estrutura {
        SemSinal Inteiro lower;
        Inteiro upper;
    } l;
#Senão
    Estrutura {
        Inteiro upper;
        SemSinal Inteiro lower;
    } l;
#FimSe
    Longo Longo ll;
};

União float_long {
    Real f;
    SemSinal Inteiro l;
};

/* XXX: we don't support several builtin supports Para now */
#Se !Definido __x86_64__ && !Definido __arm__

/* XXX: use gcc/ctec intrinsic ? */
#Se Definido __i386__
#Defina sub_ddmmss(sh, sl, ah, al, bh, bl) \
  Montador ("subl %5,%1\n\tsbbl %3,%0"					\
	   : "=r" ((USItype) (sh)),					\
	     "=&r" ((USItype) (sl))					\
	   : "0" ((USItype) (ah)),					\
	     "g" ((USItype) (bh)),					\
	     "1" ((USItype) (al)),					\
	     "g" ((USItype) (bl)))
#Defina umul_ppmm(w1, w0, u, v) \
  Montador ("mull %3"							\
	   : "=a" ((USItype) (w0)),					\
	     "=d" ((USItype) (w1))					\
	   : "%0" ((USItype) (u)),					\
	     "rm" ((USItype) (v)))
#Defina udiv_qrnnd(q, r, n1, n0, dv) \
  Montador ("divl %4"							\
	   : "=a" ((USItype) (q)),					\
	     "=d" ((USItype) (r))					\
	   : "0" ((USItype) (n0)),					\
	     "1" ((USItype) (n1)),					\
	     "rm" ((USItype) (dv)))
#Defina count_leading_zeros(count, x) \
  Faça {									\
    USItype __cbtmp;							\
    Montador ("bsrl %1,%0"						\
	     : "=r" (__cbtmp) : "rm" ((USItype) (x)));			\
    (count) = __cbtmp ^ 31;						\
  } Enquanto (0)
#Senão
#Erro unsupported CPU type
#FimSe

/* most of this code is taken from libgcc2.c from gcc */

Estático UDWtype __udivmoddi4 (UDWtype n, UDWtype d, UDWtype *rp)
{
  DWunion ww;
  DWunion nn, dd;
  DWunion rr;
  UWtype d0, d1, n0, n1, n2;
  UWtype q0, q1;
  UWtype b, bm;

  nn.ll = n;
  dd.ll = d;

  d0 = dd.s.low;
  d1 = dd.s.high;
  n0 = nn.s.low;
  n1 = nn.s.high;

#Se !Definido(UDIV_NEEDS_NORMALIZATION)
  Se (d1 == 0)
    {
      Se (d0 > n1)
	{
	  /* 0q = nn / 0D */

	  udiv_qrnnd (q0, n0, n1, n0, d0);
	  q1 = 0;

	  /* Remainder in n0.  */
	}
      Senão
	{
	  /* qq = NN / 0d */

	  Se (d0 == 0)
	    d0 = 1 / d0;	/* Divide intentionally by zero.  */

	  udiv_qrnnd (q1, n1, 0, n1, d0);
	  udiv_qrnnd (q0, n0, n1, n0, d0);

	  /* Remainder in n0.  */
	}

      Se (rp != 0)
	{
	  rr.s.low = n0;
	  rr.s.high = 0;
	  *rp = rr.ll;
	}
    }

#Senão /* UDIV_NEEDS_NORMALIZATION */

  Se (d1 == 0)
    {
      Se (d0 > n1)
	{
	  /* 0q = nn / 0D */

	  count_leading_zeros (bm, d0);

	  Se (bm != 0)
	    {
	      /* Normalize, i.e. make the most significant bit of the
		 denominator set.  */

	      d0 = d0 << bm;
	      n1 = (n1 << bm) | (n0 >> (W_TYPE_SIZE - bm));
	      n0 = n0 << bm;
	    }

	  udiv_qrnnd (q0, n0, n1, n0, d0);
	  q1 = 0;

	  /* Remainder in n0 >> bm.  */
	}
      Senão
	{
	  /* qq = NN / 0d */

	  Se (d0 == 0)
	    d0 = 1 / d0;	/* Divide intentionally by zero.  */

	  count_leading_zeros (bm, d0);

	  Se (bm == 0)
	    {
	      /* From (n1 >= d0) /\ (the most significant bit of d0 is set),
		 conclude (the most significant bit of n1 is set) /\ (the
		 leading quotient digit q1 = 1).

		 This special Caso is necessary, not an optimization.
		 (Shifts counts of W_TYPE_SIZE are undefined.)  */

	      n1 -= d0;
	      q1 = 1;
	    }
	  Senão
	    {
	      /* Normalize.  */

	      b = W_TYPE_SIZE - bm;

	      d0 = d0 << bm;
	      n2 = n1 >> b;
	      n1 = (n1 << bm) | (n0 >> b);
	      n0 = n0 << bm;

	      udiv_qrnnd (q1, n1, n2, n1, d0);
	    }

	  /* n1 != d0...  */

	  udiv_qrnnd (q0, n0, n1, n0, d0);

	  /* Remainder in n0 >> bm.  */
	}

      Se (rp != 0)
	{
	  rr.s.low = n0 >> bm;
	  rr.s.high = 0;
	  *rp = rr.ll;
	}
    }
#FimSe /* UDIV_NEEDS_NORMALIZATION */

  Senão
    {
      Se (d1 > n1)
	{
	  /* 00 = nn / DD */

	  q0 = 0;
	  q1 = 0;

	  /* Remainder in n1n0.  */
	  Se (rp != 0)
	    {
	      rr.s.low = n0;
	      rr.s.high = n1;
	      *rp = rr.ll;
	    }
	}
      Senão
	{
	  /* 0q = NN / dd */

	  count_leading_zeros (bm, d1);
	  Se (bm == 0)
	    {
	      /* From (n1 >= d1) /\ (the most significant bit of d1 is set),
		 conclude (the most significant bit of n1 is set) /\ (the
		 quotient digit q0 = 0 or 1).

		 This special Caso is necessary, not an optimization.  */

	      /* The condition on the next Linha takes advantage of that
		 n1 >= d1 (true due to program flow).  */
	      Se (n1 > d1 || n0 >= d0)
		{
		  q0 = 1;
		  sub_ddmmss (n1, n0, n1, n0, d1, d0);
		}
	      Senão
		q0 = 0;

	      q1 = 0;

	      Se (rp != 0)
		{
		  rr.s.low = n0;
		  rr.s.high = n1;
		  *rp = rr.ll;
		}
	    }
	  Senão
	    {
	      UWtype m1, m0;
	      /* Normalize.  */

	      b = W_TYPE_SIZE - bm;

	      d1 = (d1 << bm) | (d0 >> b);
	      d0 = d0 << bm;
	      n2 = n1 >> b;
	      n1 = (n1 << bm) | (n0 >> b);
	      n0 = n0 << bm;

	      udiv_qrnnd (q0, n1, n2, n1, d1);
	      umul_ppmm (m1, m0, q0, d0);

	      Se (m1 > n1 || (m1 == n1 && m0 > n0))
		{
		  q0--;
		  sub_ddmmss (m1, m0, m1, m0, d1, d0);
		}

	      q1 = 0;

	      /* Remainder in (n1n0 - m1m0) >> bm.  */
	      Se (rp != 0)
		{
		  sub_ddmmss (n1, n0, n1, n0, m1, m0);
		  rr.s.low = (n1 << b) | (n0 >> bm);
		  rr.s.high = n1 >> bm;
		  *rp = rr.ll;
		}
	    }
	}
    }

  ww.s.low = q0;
  ww.s.high = q1;
  Retorno ww.ll;
}

#Defina __negdi2(a) (-(a))

Longo Longo __divdi3(Longo Longo u, Longo Longo v)
{
    Inteiro c = 0;
    DWunion uu, vv;
    DWtype w;
    
    uu.ll = u;
    vv.ll = v;
    
    Se (uu.s.high < 0) {
        c = ~c;
        uu.ll = __negdi2 (uu.ll);
    }
    Se (vv.s.high < 0) {
        c = ~c;
        vv.ll = __negdi2 (vv.ll);
    }
    w = __udivmoddi4 (uu.ll, vv.ll, (UDWtype *) 0);
    Se (c)
        w = __negdi2 (w);
    Retorno w;
}

Longo Longo __moddi3(Longo Longo u, Longo Longo v)
{
    Inteiro c = 0;
    DWunion uu, vv;
    DWtype w;
    
    uu.ll = u;
    vv.ll = v;
    
    Se (uu.s.high < 0) {
        c = ~c;
        uu.ll = __negdi2 (uu.ll);
    }
    Se (vv.s.high < 0)
        vv.ll = __negdi2 (vv.ll);
    
    __udivmoddi4 (uu.ll, vv.ll, (UDWtype *) &w);
    Se (c)
        w = __negdi2 (w);
    Retorno w;
}

SemSinal Longo Longo __udivdi3(SemSinal Longo Longo u, SemSinal Longo Longo v)
{
    Retorno __udivmoddi4 (u, v, (UDWtype *) 0);
}

SemSinal Longo Longo __umoddi3(SemSinal Longo Longo u, SemSinal Longo Longo v)
{
    UDWtype w;
    
    __udivmoddi4 (u, v, &w);
    Retorno w;
}

/* XXX: fix ctec's code generator to Faça this instead */
Longo Longo __ashrdi3(Longo Longo a, Inteiro b)
{
#SeDefinido __TINYC__
    DWunion u;
    u.ll = a;
    Se (b >= 32) {
        u.s.low = u.s.high >> (b - 32);
        u.s.high = u.s.high >> 31;
    } Senão Se (b != 0) {
        u.s.low = ((SemSinal)u.s.low >> b) | (u.s.high << (32 - b));
        u.s.high = u.s.high >> b;
    }
    Retorno u.ll;
#Senão
    Retorno a >> b;
#FimSe
}

/* XXX: fix ctec's code generator to Faça this instead */
SemSinal Longo Longo __lshrdi3(SemSinal Longo Longo a, Inteiro b)
{
#SeDefinido __TINYC__
    DWunion u;
    u.ll = a;
    Se (b >= 32) {
        u.s.low = (SemSinal)u.s.high >> (b - 32);
        u.s.high = 0;
    } Senão Se (b != 0) {
        u.s.low = ((SemSinal)u.s.low >> b) | (u.s.high << (32 - b));
        u.s.high = (SemSinal)u.s.high >> b;
    }
    Retorno u.ll;
#Senão
    Retorno a >> b;
#FimSe
}

/* XXX: fix ctec's code generator to Faça this instead */
Longo Longo __ashldi3(Longo Longo a, Inteiro b)
{
#SeDefinido __TINYC__
    DWunion u;
    u.ll = a;
    Se (b >= 32) {
        u.s.high = (SemSinal)u.s.low << (b - 32);
        u.s.low = 0;
    } Senão Se (b != 0) {
        u.s.high = ((SemSinal)u.s.high << b) | ((SemSinal)u.s.low >> (32 - b));
        u.s.low = (SemSinal)u.s.low << b;
    }
    Retorno u.ll;
#Senão
    Retorno a << b;
#FimSe
}

#FimSe /* !__x86_64__ */

/* XXX: fix ctec's code generator to Faça this instead */
Real __floatundisf(SemSinal Longo Longo a)
{
    DWunion uu; 
    XFtype r;

    uu.ll = a;
    Se (uu.s.high >= 0) {
        Retorno (Real)uu.ll;
    } Senão {
        r = (XFtype)uu.ll;
        r += 18446744073709551616.0;
        Retorno (Real)r;
    }
}

Duplo __floatundidf(SemSinal Longo Longo a)
{
    DWunion uu; 
    XFtype r;

    uu.ll = a;
    Se (uu.s.high >= 0) {
        Retorno (Duplo)uu.ll;
    } Senão {
        r = (XFtype)uu.ll;
        r += 18446744073709551616.0;
        Retorno (Duplo)r;
    }
}

Longo Duplo __floatundixf(SemSinal Longo Longo a)
{
    DWunion uu; 
    XFtype r;

    uu.ll = a;
    Se (uu.s.high >= 0) {
        Retorno (Longo Duplo)uu.ll;
    } Senão {
        r = (XFtype)uu.ll;
        r += 18446744073709551616.0;
        Retorno (Longo Duplo)r;
    }
}

SemSinal Longo Longo __fixunssfdi (Real a1)
{
    Registrador União float_long fl1;
    Registrador Inteiro exp;
    Registrador SemSinal Longo l;

    fl1.f = a1;

    Se (fl1.l == 0)
	Retorno (0);

    exp = EXP (fl1.l) - EXCESS - 24;

    l = MANT(fl1.l);
    Se (exp >= 41)
	Retorno (SemSinal Longo Longo)-1;
    Senão Se (exp >= 0)
        Retorno (SemSinal Longo Longo)l << exp;
    Senão Se (exp >= -23)
        Retorno l >> -exp;
    Senão
        Retorno 0;
}

Longo Longo __fixsfdi (Real a1)
{
    Longo Longo ret; Inteiro s;
    ret = __fixunssfdi((s = a1 >= 0) ? a1 : -a1);
    Retorno s ? ret : -ret;
}

SemSinal Longo Longo __fixunsdfdi (Duplo a1)
{
    Registrador União double_long dl1;
    Registrador Inteiro exp;
    Registrador SemSinal Longo Longo l;

    dl1.d = a1;

    Se (dl1.ll == 0)
	Retorno (0);

    exp = EXPD (dl1) - EXCESSD - 53;

    l = MANTD_LL(dl1);

    Se (exp >= 12)
	Retorno (SemSinal Longo Longo)-1;
    Senão Se (exp >= 0)
        Retorno l << exp;
    Senão Se (exp >= -52)
        Retorno l >> -exp;
    Senão
        Retorno 0;
}

Longo Longo __fixdfdi (Duplo a1)
{
    Longo Longo ret; Inteiro s;
    ret = __fixunsdfdi((s = a1 >= 0) ? a1 : -a1);
    Retorno s ? ret : -ret;
}

#SenãoDefinido __arm__
SemSinal Longo Longo __fixunsxfdi (Longo Duplo a1)
{
    Registrador União ldouble_long dl1;
    Registrador Inteiro exp;
    Registrador SemSinal Longo Longo l;

    dl1.ld = a1;

    Se (dl1.l.lower == 0 && dl1.l.upper == 0)
	Retorno (0);

    exp = EXPLD (dl1) - EXCESSLD - 64;

    l = dl1.l.lower;

    Se (exp > 0)
	Retorno (SemSinal Longo Longo)-1;
    Senão Se (exp >= -63) 
        Retorno l >> -exp;
    Senão
        Retorno 0;
}

Longo Longo __fixxfdi (Longo Duplo a1)
{
    Longo Longo ret; Inteiro s;
    ret = __fixunsxfdi((s = a1 >= 0) ? a1 : -a1);
    Retorno s ? ret : -ret;
}
#FimSe /* !ARM */
