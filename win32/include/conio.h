/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#SenãoDefinido _INC_CONIO
#Defina _INC_CONIO

#Inclua <_mingw.h>

#SeDefinido __cplusplus
Externo "C" {
#FimSe

  _CRTIMP Caractere *_cgets(Caractere *_Buffer);
  _CRTIMP Inteiro __cdecl _cprintf(Constante Caractere *_Format,...);
  _CRTIMP Inteiro __cdecl _cputs(Constante Caractere *_Str);
  _CRTIMP Inteiro __cdecl _cscanf(Constante Caractere *_Format,...);
  _CRTIMP Inteiro __cdecl _cscanf_l(Constante Caractere *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro __cdecl _getch(Vazio);
  _CRTIMP Inteiro __cdecl _getche(Vazio);
  _CRTIMP Inteiro __cdecl _vcprintf(Constante Caractere *_Format,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _cprintf_p(Constante Caractere *_Format,...);
  _CRTIMP Inteiro __cdecl _vcprintf_p(Constante Caractere *_Format,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _cprintf_l(Constante Caractere *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro __cdecl _vcprintf_l(Constante Caractere *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _cprintf_p_l(Constante Caractere *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro __cdecl _vcprintf_p_l(Constante Caractere *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _kbhit(Vazio);

#Se Definido(_X86_) && !Definido(__x86_64)
  Inteiro __cdecl _inp(SemSinal Curto);
  SemSinal Curto __cdecl _inpw(SemSinal Curto);
  SemSinal Longo __cdecl _inpd(SemSinal Curto);
  Inteiro __cdecl _outp(SemSinal Curto,Inteiro);
  SemSinal Curto __cdecl _outpw(SemSinal Curto,SemSinal Curto);
  SemSinal Longo __cdecl _outpd(SemSinal Curto,SemSinal Longo);
#FimSe

  _CRTIMP Inteiro __cdecl _putch(Inteiro _Ch);
  _CRTIMP Inteiro __cdecl _ungetch(Inteiro _Ch);
  _CRTIMP Inteiro __cdecl _getch_nolock(Vazio);
  _CRTIMP Inteiro __cdecl _getche_nolock(Vazio);
  _CRTIMP Inteiro __cdecl _putch_nolock(Inteiro _Ch);
  _CRTIMP Inteiro __cdecl _ungetch_nolock(Inteiro _Ch);

#SenãoDefinido _WCONIO_DEFINED
#Defina _WCONIO_DEFINED

#SenãoDefinido WEOF
#Defina WEOF (wint_t)(0xFFFF)
#FimSe

  _CRTIMP wchar_t *_cgetws(wchar_t *_Buffer);
  _CRTIMP wint_t __cdecl _getwch(Vazio);
  _CRTIMP wint_t __cdecl _getwche(Vazio);
  _CRTIMP wint_t __cdecl _putwch(wchar_t _WCh);
  _CRTIMP wint_t __cdecl _ungetwch(wint_t _WCh);
  _CRTIMP Inteiro __cdecl _cputws(Constante wchar_t *_String);
  _CRTIMP Inteiro __cdecl _cwprintf(Constante wchar_t *_Format,...);
  _CRTIMP Inteiro __cdecl _cwscanf(Constante wchar_t *_Format,...);
  _CRTIMP Inteiro __cdecl _cwscanf_l(Constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro __cdecl _vcwprintf(Constante wchar_t *_Format,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _cwprintf_p(Constante wchar_t *_Format,...);
  _CRTIMP Inteiro __cdecl _vcwprintf_p(Constante wchar_t *_Format,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _cwprintf_l(Constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro __cdecl _vcwprintf_l(Constante wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _cwprintf_p_l(Constante wchar_t *_Format,_locale_t _Locale,...);
  _CRTIMP Inteiro __cdecl _vcwprintf_p_l(Constante wchar_t *_Format,_locale_t _Locale,va_list _ArgList);
  _CRTIMP wint_t __cdecl _putwch_nolock(wchar_t _WCh);
  _CRTIMP wint_t __cdecl _getwch_nolock(Vazio);
  _CRTIMP wint_t __cdecl _getwche_nolock(Vazio);
  _CRTIMP wint_t __cdecl _ungetwch_nolock(wint_t _WCh);
#FimSe

#SenãoDefinido	NO_OLDNAMES
  Caractere *__cdecl cgets(Caractere *_Buffer);
  Inteiro __cdecl cprintf(Constante Caractere *_Format,...);
  Inteiro __cdecl cputs(Constante Caractere *_Str);
  Inteiro __cdecl cscanf(Constante Caractere *_Format,...);
  Inteiro __cdecl getch(Vazio);
  Inteiro __cdecl getche(Vazio);
  Inteiro __cdecl kbhit(Vazio);
  Inteiro __cdecl putch(Inteiro _Ch);
  Inteiro __cdecl ungetch(Inteiro _Ch);

#Se (Definido(_X86_) && !Definido(__x86_64))
  Inteiro __cdecl inp(SemSinal Curto);
  SemSinal Curto __cdecl inpw(SemSinal Curto);
  Inteiro __cdecl outp(SemSinal Curto,Inteiro);
  SemSinal Curto __cdecl outpw(SemSinal Curto,SemSinal Curto);
#FimSe

  /* I/O intrin functions.  */
  __CRT_INLINE SemSinal Caractere __inbyte(SemSinal Curto Port)
  {
      SemSinal Caractere value;
      Montador Volátil ("inb %w1,%b0"
          : "=a" (value)
          : "Nd" (Port));
      Retorno value;
  }
  __CRT_INLINE SemSinal Curto __inword(SemSinal Curto Port)
  {
      SemSinal Curto value;
      Montador Volátil ("inw %w1,%w0"
          : "=a" (value)
          : "Nd" (Port));
      Retorno value;
  }
  __CRT_INLINE SemSinal Longo __indword(SemSinal Curto Port)
  {
      SemSinal Longo value;
      Montador Volátil ("inl %w1,%0"
          : "=a" (value)
          : "Nd" (Port));
      Retorno value;
  }
  __CRT_INLINE Vazio __outbyte(SemSinal Curto Port,SemSinal Caractere Data)
  {
      Montador Volátil ("outb %b0,%w1"
          :
          : "a" (Data), "Nd" (Port));
  }
  __CRT_INLINE Vazio __outword(SemSinal Curto Port,SemSinal Curto Data)
  {
      Montador Volátil ("outw %w0,%w1"
          :
          : "a" (Data), "Nd" (Port));
  }
  __CRT_INLINE Vazio __outdword(SemSinal Curto Port,SemSinal Longo Data)
  {
      Montador Volátil ("outl %0,%w1"
          :
          : "a" (Data), "Nd" (Port));
  }
  __CRT_INLINE Vazio __inbytestring(SemSinal Curto Port,SemSinal Caractere *Buffer,SemSinal Longo Count)
  {
	Montador Volátil (
		"cld ; rep ; insb " 
		: "=D" (Buffer), "=c" (Count)
		: "d"(Port), "0"(Buffer), "1" (Count)
		);
  }
  __CRT_INLINE Vazio __inwordstring(SemSinal Curto Port,SemSinal Curto *Buffer,SemSinal Longo Count)
  {
	Montador Volátil (
		"cld ; rep ; insw " 
		: "=D" (Buffer), "=c" (Count)
		: "d"(Port), "0"(Buffer), "1" (Count)
		);
  }
  __CRT_INLINE Vazio __indwordstring(SemSinal Curto Port,SemSinal Longo *Buffer,SemSinal Longo Count)
  {
	Montador Volátil (
		"cld ; rep ; insl " 
		: "=D" (Buffer), "=c" (Count)
		: "d"(Port), "0"(Buffer), "1" (Count)
		);
  }

  __CRT_INLINE Vazio __outbytestring(SemSinal Curto Port,SemSinal Caractere *Buffer,SemSinal Longo Count)
  {
      Montador Volátil (
          "cld ; rep ; outsb " 
          : "=S" (Buffer), "=c" (Count)
          : "d"(Port), "0"(Buffer), "1" (Count)
          );
  }
  __CRT_INLINE Vazio __outwordstring(SemSinal Curto Port,SemSinal Curto *Buffer,SemSinal Longo Count)
  {
      Montador Volátil (
          "cld ; rep ; outsw " 
          : "=S" (Buffer), "=c" (Count)
          : "d"(Port), "0"(Buffer), "1" (Count)
          );
  }
  __CRT_INLINE Vazio __outdwordstring(SemSinal Curto Port,SemSinal Longo *Buffer,SemSinal Longo Count)
  {
      Montador Volátil (
          "cld ; rep ; outsl " 
          : "=S" (Buffer), "=c" (Count)
          : "d"(Port), "0"(Buffer), "1" (Count)
          );
  }

  __CRT_INLINE SemSinal __int64 __readcr0(Vazio)
  {
      SemSinal __int64 value;
      Montador Volátil (
          "mov %%cr0, %[value]" 
          : [value] "=q" (value));
      Retorno value;
  }
 
  /* Register sizes are different between 32/64 bit mode. So we have to Faça this Para _WIN64 and _WIN32
     separately.  */
 
#SeDefinido _WIN64
  __CRT_INLINE Vazio __writecr0(SemSinal __int64 Data)
  {
   Montador Volátil (
       "mov %[Data], %%cr0"
       :
       : [Data] "q" (Data)
       : "memory");
  }
 
  __CRT_INLINE SemSinal __int64 __readcr2(Vazio)
  {
      SemSinal __int64 value;
      Montador Volátil (
          "mov %%cr2, %[value]" 
          : [value] "=q" (value));
      Retorno value;
  }

 __CRT_INLINE Vazio __writecr2(SemSinal __int64 Data)
 {
   Montador Volátil (
       "mov %[Data], %%cr2"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
  __CRT_INLINE SemSinal __int64 __readcr3(Vazio)
  {
      SemSinal __int64 value;
      Montador Volátil (
          "mov %%cr3, %[value]" 
          : [value] "=q" (value));
      Retorno value;
  }

 __CRT_INLINE Vazio __writecr3(SemSinal __int64 Data)
 {
   Montador Volátil (
       "mov %[Data], %%cr3"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
  __CRT_INLINE SemSinal __int64 __readcr4(Vazio)
  {
      SemSinal __int64 value;
      Montador Volátil (
          "mov %%cr4, %[value]" 
          : [value] "=q" (value));
      Retorno value;
  }

 __CRT_INLINE Vazio __writecr4(SemSinal __int64 Data)
 {
     Montador Volátil (
         "mov %[Data], %%cr4"
         :
         : [Data] "q" (Data)
         : "memory");
 }
 
  __CRT_INLINE SemSinal __int64 __readcr8(Vazio)
  {
      SemSinal __int64 value;
      Montador Volátil (
          "mov %%cr8, %[value]" 
          : [value] "=q" (value));
      Retorno value;
  }

 __CRT_INLINE Vazio __writecr8(SemSinal __int64 Data)
 {
   Montador Volátil (
       "mov %[Data], %%cr8"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
#SenãoSe Definido(_WIN32)

  __CRT_INLINE Vazio __writecr0(SemSinal Data)
  {
    Montador Volátil (
       "mov %[Data], %%cr0"
       :
       : [Data] "q" (Data)
       : "memory");
  }
 
  __CRT_INLINE SemSinal Longo __readcr2(Vazio)
  {
      SemSinal Longo value;
      Montador Volátil (
          "mov %%cr2, %[value]" 
          : [value] "=q" (value));
      Retorno value;
  }

 __CRT_INLINE Vazio __writecr2(SemSinal Data)
 {
   Montador Volátil (
       "mov %[Data], %%cr2"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
  __CRT_INLINE SemSinal Longo __readcr3(Vazio)
  {
      SemSinal Longo value;
      Montador Volátil (
          "mov %%cr3, %[value]" 
          : [value] "=q" (value));
      Retorno value;
  }

 __CRT_INLINE Vazio __writecr3(SemSinal Data)
 {
   Montador Volátil (
       "mov %[Data], %%cr3"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
  __CRT_INLINE SemSinal Longo __readcr4(Vazio)
  {
      SemSinal Longo value;
      Montador Volátil (
          "mov %%cr4, %[value]" 
          : [value] "=q" (value));
      Retorno value;
  }

 __CRT_INLINE Vazio __writecr4(SemSinal Data)
 {
     Montador Volátil (
         "mov %[Data], %%cr4"
         :
         : [Data] "q" (Data)
         : "memory");
 }
 
 __CRT_INLINE SemSinal Longo __readcr8(Vazio)
 {
   SemSinal Longo value;      Montador Volátil (
          "mov %%cr8, %[value]" 
          : [value] "=q" (value));
     Retorno value;
 }

 __CRT_INLINE Vazio __writecr8(SemSinal Data)
 {
   Montador Volátil (
       "mov %[Data], %%cr8"
       :
       : [Data] "q" (Data)
       : "memory");
 }
 
#FimSe

  __CRT_INLINE SemSinal __int64 __readmsr(SemSinal Longo msr)
  {
      SemSinal __int64 val1, val2;
       Montador Volátil(
           "rdmsr"
           : "=a" (val1), "=d" (val2)
           : "c" (msr));
      Retorno val1 | (val2 << 32);
  }

 __CRT_INLINE Vazio __writemsr (SemSinal Longo msr, SemSinal __int64 Value)
 {
    SemSinal Longo val1 = Value, val2 = Value >> 32;
   Montador Volátil (
       "wrmsr"
       :
       : "c" (msr), "a" (val1), "d" (val2));
 }
 
  __CRT_INLINE SemSinal __int64 __rdtsc(Vazio)
  {
      SemSinal __int64 val1, val2;
      Montador Volátil (
          "rdtsc" 
          : "=a" (val1), "=d" (val2));
      Retorno val1 | (val2 << 32);
  }

  __CRT_INLINE Vazio __cpuid(Inteiro CPUInfo[4], Inteiro InfoType)
  {
      Montador Volátil (
          "cpuid"
          : "=a" (CPUInfo [0]), "=b" (CPUInfo [1]), "=c" (CPUInfo [2]), "=d" (CPUInfo [3])
          : "a" (InfoType));
  }

#FimSe

#SeDefinido __cplusplus
}
#FimSe

#Inclua <sec_api/conio_s.h>

#FimSe
