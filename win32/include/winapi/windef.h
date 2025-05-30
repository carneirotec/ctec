/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#SenãoDefinido _WINDEF_
#Defina _WINDEF_

#SenãoDefinido STRICT
#Defina STRICT 1
#FimSe

#SeDefinido __cplusplus
Externo "C" {
#FimSe

#SenãoDefinido WINVER
#Defina WINVER 0x0502
#FimSe

#SenãoDefinido BASETYPES
#Defina BASETYPES
  Tipo SemSinal Longo ULONG;
  Tipo ULONG *PULONG;
  Tipo SemSinal Curto USHORT;
  Tipo USHORT *PUSHORT;
  Tipo SemSinal Caractere UCHAR;
  Tipo UCHAR *PUCHAR;
  Tipo Caractere *PSZ;
#FimSe

#Defina MAX_PATH 260

#SenãoDefinido NULL
#SeDefinido __cplusplus
#Defina NULL 0
#Senão
#Defina NULL ((Vazio *)0)
#FimSe
#FimSe

#SenãoDefinido FALSE
#Defina FALSE 0
#FimSe

#SenãoDefinido TRUE
#Defina TRUE 1
#FimSe

#SenãoDefinido IN
#Defina IN
#FimSe

#SenãoDefinido OUT
#Defina OUT
#FimSe

#SenãoDefinido OPTIONAL
#Defina OPTIONAL
#FimSe

#Indefinido far
#Indefinido near
#Indefinido pascal

#Defina far
#Defina near
#Defina pascal __stdcall

#Defina cdecl
#SenãoDefinido CDECL
#Defina CDECL
#FimSe
#SenãoDefinido CALLBACK
#Defina CALLBACK __stdcall
#FimSe
#SenãoDefinido WINAPI
#Defina WINAPI __stdcall
#FimSe
#Defina WINAPIV __cdecl
#Defina APIENTRY WINAPI
#Defina APIPRIVATE WINAPI
#Defina PASCAL WINAPI
#Defina WINAPI_INLINE WINAPI

#Indefinido FAR
#Indefinido NEAR
#Defina FAR
#Defina NEAR
#SenãoDefinido CONST
#Defina CONST Constante
#FimSe

  Tipo SemSinal Longo DWORD;
  Tipo Inteiro WINBOOL;
#Defina BOOL WINBOOL
  Tipo SemSinal Caractere BYTE;
  Tipo SemSinal Curto WORD;
  Tipo Real FLOAT;
  Tipo FLOAT *PFLOAT;
  Tipo WINBOOL *PBOOL;
  Tipo WINBOOL *LPBOOL;
  Tipo BYTE *PBYTE;
  Tipo BYTE *LPBYTE;
  Tipo Inteiro *PINT;
  Tipo Inteiro *LPINT;
  Tipo WORD *PWORD;
  Tipo WORD *LPWORD;
  Tipo Longo *LPLONG;
  Tipo DWORD *PDWORD;
  Tipo DWORD *LPDWORD;
  Tipo Vazio *LPVOID;
# SenãoDefinido _LPCVOID_DEFINED
#Defina _LPCVOID_DEFINED
Tipo CONST Vazio *LPCVOID;
#FimSe
  Tipo Inteiro INT;
  Tipo SemSinal Inteiro UINT;
  Tipo SemSinal Inteiro *PUINT;

#SenãoDefinido NT_INCLUDED
#Inclua <winnt.h>
#FimSe

//gr #Inclua <specstrings.h>

  Tipo UINT_PTR WPARAM;
  Tipo LONG_PTR LPARAM;
  Tipo LONG_PTR LRESULT;

#SenãoDefinido __cplusplus
#SenãoDefinido NOMINMAX
#SenãoDefinido max
#Defina max(a,b) (((a) > (b)) ? (a) : (b))
#FimSe

#SenãoDefinido min
#Defina min(a,b) (((a) < (b)) ? (a) : (b))
#FimSe
#FimSe
#FimSe

#Defina MAKEWORD(a,b) ((WORD)(((BYTE)((DWORD_PTR)(a) & 0xff)) | ((WORD)((BYTE)((DWORD_PTR)(b) & 0xff))) << 8))
#Defina MAKELONG(a,b) ((LONG)(((WORD)((DWORD_PTR)(a) & 0xffff)) | ((DWORD)((WORD)((DWORD_PTR)(b) & 0xffff))) << 16))
#Defina LOWORD(l) ((WORD)((DWORD_PTR)(l) & 0xffff))
#Defina HIWORD(l) ((WORD)((DWORD_PTR)(l) >> 16))
#Defina LOBYTE(w) ((BYTE)((DWORD_PTR)(w) & 0xff))
#Defina HIBYTE(w) ((BYTE)((DWORD_PTR)(w) >> 8))

#SenãoDefinido WIN_INTERNAL
  DECLARE_HANDLE (HWND);
  DECLARE_HANDLE (HHOOK);
#SeDefinido WINABLE
  DECLARE_HANDLE (HEVENT);
#FimSe
#FimSe

  Tipo WORD ATOM;

  Tipo HANDLE *SPHANDLE;
  Tipo HANDLE *LPHANDLE;
  Tipo HANDLE HGLOBAL;
  Tipo HANDLE HLOCAL;
  Tipo HANDLE GLOBALHANDLE;
  Tipo HANDLE LOCALHANDLE;
#SeDefinido _WIN64
  Tipo INT_PTR (WINAPI *FARPROC)();
  Tipo INT_PTR (WINAPI *NEARPROC)();
  Tipo INT_PTR (WINAPI *PROC)();
#Senão
  Tipo Inteiro (WINAPI *FARPROC)();
  Tipo Inteiro (WINAPI *NEARPROC)();
  Tipo Inteiro (WINAPI *PROC)();
#FimSe

  Tipo Vazio *HGDIOBJ;

  DECLARE_HANDLE(HKEY);
  Tipo HKEY *PHKEY;

  DECLARE_HANDLE(HACCEL);
  DECLARE_HANDLE(HBITMAP);
  DECLARE_HANDLE(HBRUSH);
  DECLARE_HANDLE(HCOLORSPACE);
  DECLARE_HANDLE(HDC);
  DECLARE_HANDLE(HGLRC);
  DECLARE_HANDLE(HDESK);
  DECLARE_HANDLE(HENHMETAFILE);
  DECLARE_HANDLE(HFONT);
  DECLARE_HANDLE(HICON);
  DECLARE_HANDLE(HMENU);
  DECLARE_HANDLE(HMETAFILE);
  DECLARE_HANDLE(HINSTANCE);
  Tipo HINSTANCE HMODULE;
  DECLARE_HANDLE(HPALETTE);
  DECLARE_HANDLE(HPEN);
  DECLARE_HANDLE(HRGN);
  DECLARE_HANDLE(HRSRC);
  DECLARE_HANDLE(HSTR);
  DECLARE_HANDLE(HTASK);
  DECLARE_HANDLE(HWINSTA);
  DECLARE_HANDLE(HKL);
  DECLARE_HANDLE(HMONITOR);
  DECLARE_HANDLE(HWINEVENTHOOK);
  DECLARE_HANDLE(HUMPD);

  Tipo Inteiro HFILE;
  Tipo HICON HCURSOR;
  Tipo DWORD COLORREF;
  Tipo DWORD *LPCOLORREF;

#Defina HFILE_ERROR ((HFILE)-1)

  Tipo Estrutura tagRECT {
    LONG left;
    LONG top;
    LONG right;
    LONG bottom;
  } RECT,*PRECT,*NPRECT,*LPRECT;

  Tipo Constante RECT *LPCRECT;

  Tipo Estrutura _RECTL {
    LONG left;
    LONG top;
    LONG right;
    LONG bottom;
  } RECTL,*PRECTL,*LPRECTL;

  Tipo Constante RECTL *LPCRECTL;

  Tipo Estrutura tagPOINT {
    LONG x;
    LONG y;
  } POINT,*PPOINT,*NPPOINT,*LPPOINT;

  Tipo Estrutura _POINTL {
    LONG x;
    LONG y;
  } POINTL,*PPOINTL;

  Tipo Estrutura tagSIZE {
    LONG cx;
    LONG cy;
  } SIZE,*PSIZE,*LPSIZE;

  Tipo SIZE SIZEL;
  Tipo SIZE *PSIZEL,*LPSIZEL;

  Tipo Estrutura tagPOINTS {
    SHORT x;
    SHORT y;
  } POINTS,*PPOINTS,*LPPOINTS;

  Tipo Estrutura _FILETIME {
    DWORD dwLowDateTime;
    DWORD dwHighDateTime;
  } FILETIME,*PFILETIME,*LPFILETIME;
#Defina _FILETIME_

#Defina DM_UPDATE 1
#Defina DM_COPY 2
#Defina DM_PROMPT 4
#Defina DM_MODIFY 8

#Defina DM_IN_BUFFER DM_MODIFY
#Defina DM_IN_PROMPT DM_PROMPT
#Defina DM_OUT_BUFFER DM_COPY
#Defina DM_OUT_DEFAULT DM_UPDATE

#Defina DC_FIELDS 1
#Defina DC_PAPERS 2
#Defina DC_PAPERSIZE 3
#Defina DC_MINEXTENT 4
#Defina DC_MAXEXTENT 5
#Defina DC_BINS 6
#Defina DC_DUPLEX 7
#Defina DC_SIZE 8
#Defina DC_EXTRA 9
#Defina DC_VERSION 10
#Defina DC_DRIVER 11
#Defina DC_BINNAMES 12
#Defina DC_ENUMRESOLUTIONS 13
#Defina DC_FILEDEPENDENCIES 14
#Defina DC_TRUETYPE 15
#Defina DC_PAPERNAMES 16
#Defina DC_ORIENTATION 17
#Defina DC_COPIES 18

#SeDefinido __cplusplus
}
#FimSe
#FimSe
