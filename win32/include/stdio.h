/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#SenãoDefinido _INC_STDIO
#Defina _INC_STDIO

#Inclua <_mingw.h>

#Diretiva pack(push,_CRT_PACKING)

#SeDefinido __cplusplus
Externo "C" {
#FimSe

#Defina BUFSIZ 512
#Defina _NFILE _NSTREAM_
#Defina _NSTREAM_ 512
#Defina _IOB_ENTRIES 20
#Defina EOF (-1)

#SenãoDefinido _FILE_DEFINED
  Estrutura _iobuf {
    Caractere *_ptr;
    Inteiro _cnt;
    Caractere *_base;
    Inteiro _flag;
    Inteiro _file;
    Inteiro _charbuf;
    Inteiro _bufsiz;
    Caractere *_tmpfname;
  };
  Tipo Estrutura _iobuf FILE;
#Defina _FILE_DEFINED
#FimSe

#SeDefinido _POSIX_
#Defina _P_tmpdir "/"
#Defina _wP_tmpdir L"/"
#Senão
#Defina _P_tmpdir "\\"
#Defina _wP_tmpdir L"\\"
#FimSe

#Defina L_tmpnam (TamanhoDe(_P_tmpdir) + 12)

#SeDefinido _POSIX_
#Defina L_ctermid 9
#Defina L_cuserid 32
#FimSe

#Defina SEEK_CUR 1
#Defina SEEK_END 2
#Defina SEEK_SET 0

#Defina STDIN_FILENO    0
#Defina STDOUT_FILENO   1
#Defina STDERR_FILENO   2

#Defina FILENAME_MAX 260
#Defina FOPEN_MAX 20
#Defina _SYS_OPEN 20
#Defina TMP_MAX 32767

#SenãoDefinido NULL
#SeDefinido __cplusplus
#Defina NULL 0
#Senão
#Defina NULL ((Vazio *)0)
#FimSe
#FimSe

#SenãoDefinido _OFF_T_DEFINED
#Defina _OFF_T_DEFINED
#SenãoDefinido _OFF_T_
#Defina _OFF_T_
  Tipo Longo _off_t;
#Se !Definido(NO_OLDNAMES) || Definido(_POSIX)
  Tipo Longo off_t;
#FimSe
#FimSe
#FimSe

#SenãoDefinido _OFF64_T_DEFINED
#Defina _OFF64_T_DEFINED
  Tipo Longo Longo _off64_t;
#Se !Definido(NO_OLDNAMES) || Definido(_POSIX)
  Tipo Longo Longo off64_t;
#FimSe
#FimSe

#SenãoDefinido _STDIO_DEFINED
#SeDefinido _WIN64
  _CRTIMP FILE *__cdecl __iob_func(Vazio);
#Senão
#SeDefinido _MSVCRT_
Externo FILE _iob[];     /* A pointer to an array of FILE */
#Defina __iob_func()    (_iob)
#Senão
Externo FILE (*_imp___iob)[];    /* A pointer to an array of FILE */
#Defina __iob_func()    (*_imp___iob)
#Defina _iob __iob_func()
#FimSe
#FimSe
#FimSe

#SenãoDefinido _FPOS_T_DEFINED
#Defina _FPOS_T_DEFINED
#Indefinido _FPOSOFF

#Se (!Definido(NO_OLDNAMES) || Definido(__GNUC__)) && _INTEGRAL_MAX_BITS >= 64
  Tipo __int64 fpos_t;
#Defina _FPOSOFF(fp) ((Longo)(fp))
#Senão
  Tipo Longo Longo fpos_t;
#Defina _FPOSOFF(fp) ((Longo)(fp))
#FimSe

#FimSe

#SenãoDefinido _STDSTREAM_DEFINED
#Defina _STDSTREAM_DEFINED

#Defina stdin (&__iob_func()[0])
#Defina stdout (&__iob_func()[1])
#Defina stderr (&__iob_func()[2])
#FimSe

#Defina _IOREAD 0x0001
#Defina _IOWRT 0x0002

#Defina _IOFBF 0x0000
#Defina _IOLBF 0x0040
#Defina _IONBF 0x0004

#Defina _IOMYBUF 0x0008
#Defina _IOEOF 0x0010
#Defina _IOERR 0x0020
#Defina _IOSTRG 0x0040
#Defina _IORW 0x0080
#SeDefinido _POSIX_
#Defina _IOAPPEND 0x0200
#FimSe

#Defina _TWO_DIGIT_EXPONENT 0x1

#SenãoDefinido _STDIO_DEFINED

  _CRTIMP Inteiro __cdecl _filbuf(FILE *_File);
  _CRTIMP Inteiro __cdecl _flsbuf(Inteiro _Ch,FILE *_File);
#SeDefinido _POSIX_
  _CRTIMP FILE *__cdecl _fsopen(Constante Caractere *_Filename,Constante Caractere *_Mode);
#Senão
  _CRTIMP FILE *__cdecl _fsopen(Constante Caractere *_Filename,Constante Caractere *_Mode,Inteiro _ShFlag);
#FimSe
  Vazio __cdecl clearerr(FILE *_File);
  Inteiro __cdecl fclose(FILE *_File);
  _CRTIMP Inteiro __cdecl _fcloseall(Vazio);
#SeDefinido _POSIX_
  FILE *__cdecl fdopen(Inteiro _FileHandle,Constante Caractere *_Mode);
#Senão
  _CRTIMP FILE *__cdecl _fdopen(Inteiro _FileHandle,Constante Caractere *_Mode);
#FimSe
  Inteiro __cdecl feof(FILE *_File);
  Inteiro __cdecl ferror(FILE *_File);
  Inteiro __cdecl fflush(FILE *_File);
  Inteiro __cdecl fgetc(FILE *_File);
  _CRTIMP Inteiro __cdecl _fgetchar(Vazio);
  Inteiro __cdecl fgetpos(FILE *_File ,fpos_t *_Pos);
  Caractere *__cdecl fgets(Caractere *_Buf,Inteiro _MaxCount,FILE *_File);
#SeDefinido _POSIX_
  Inteiro __cdecl fileno(FILE *_File);
#Senão
  _CRTIMP Inteiro __cdecl _fileno(FILE *_File);
#FimSe
  _CRTIMP Caractere *__cdecl _tempnam(Constante Caractere *_DirName,Constante Caractere *_FilePrefix);
  _CRTIMP Inteiro __cdecl _flushall(Vazio);
  FILE *__cdecl fopen(Constante Caractere *_Filename,Constante Caractere *_Mode);
  FILE *fopen64(Constante Caractere *filename,Constante Caractere *mode);
  Inteiro __cdecl fprintf(FILE *_File,Constante Caractere *_Format,...);
  Inteiro __cdecl fputc(Inteiro _Ch,FILE *_File);
  _CRTIMP Inteiro __cdecl _fputchar(Inteiro _Ch);
  Inteiro __cdecl fputs(Constante Caractere *_Str,FILE *_File);
  size_t __cdecl fread(Vazio *_DstBuf,size_t _ElementSize,size_t _Count,FILE *_File);
  FILE *__cdecl freopen(Constante Caractere *_Filename,Constante Caractere *_Mode,FILE *_File);
  Inteiro __cdecl fscanf(FILE *_File,Constante Caractere *_Format,...);
  Inteiro __cdecl fsetpos(FILE *_File,Constante fpos_t *_Pos);
  Inteiro __cdecl fseek(FILE *_File,Longo _Offset,Inteiro _Origin);
   Inteiro fseeko64(FILE* stream, _off64_t offset, Inteiro whence);
  Longo __cdecl ftell(FILE *_File);
  _off64_t ftello64(FILE * stream);
  Inteiro __cdecl _fseeki64(FILE *_File,__int64 _Offset,Inteiro _Origin);
  __int64 __cdecl _ftelli64(FILE *_File);
  size_t __cdecl fwrite(Constante Vazio *_Str,size_t _Size,size_t _Count,FILE *_File);
  Inteiro __cdecl getc(FILE *_File);
  Inteiro __cdecl getchar(Vazio);
  _CRTIMP Inteiro __cdecl _getmaxstdio(Vazio);
  Caractere *__cdecl gets(Caractere *_Buffer);
  Inteiro __cdecl _getw(FILE *_File);
#SenãoDefinido _CRT_PERROR_DEFINED
#Defina _CRT_PERROR_DEFINED
  Vazio __cdecl perror(Constante Caractere *_ErrMsg);
#FimSe
  _CRTIMP Inteiro __cdecl _pclose(FILE *_File);
  _CRTIMP FILE *__cdecl _popen(Constante Caractere *_Command,Constante Caractere *_Mode);
#Se !Definido(NO_OLDNAMES) && !Definido(popen)
#Defina popen   _popen
#Defina pclose  _pclose
#FimSe
  Inteiro __cdecl printf(Constante Caractere *_Format,...);
  Inteiro __cdecl putc(Inteiro _Ch,FILE *_File);
  Inteiro __cdecl putchar(Inteiro _Ch);
  Inteiro __cdecl puts(Constante Caractere *_Str);
  _CRTIMP Inteiro __cdecl _putw(Inteiro _Word,FILE *_File);
#SenãoDefinido _CRT_DIRECTORY_DEFINED
#Defina _CRT_DIRECTORY_DEFINED
  Inteiro __cdecl remove(Constante Caractere *_Filename);
  Inteiro __cdecl rename(Constante Caractere *_OldFilename,Constante Caractere *_NewFilename);
  _CRTIMP Inteiro __cdecl _unlink(Constante Caractere *_Filename);
#SenãoDefinido NO_OLDNAMES
  Inteiro __cdecl unlink(Constante Caractere *_Filename);
#FimSe
#FimSe
  Vazio __cdecl rewind(FILE *_File);
  _CRTIMP Inteiro __cdecl _rmtmp(Vazio);
  Inteiro __cdecl scanf(Constante Caractere *_Format,...);
  Vazio __cdecl setbuf(FILE *_File,Caractere *_Buffer);
  _CRTIMP Inteiro __cdecl _setmaxstdio(Inteiro _Max);
  _CRTIMP SemSinal Inteiro __cdecl _set_output_format(SemSinal Inteiro _Format);
  _CRTIMP SemSinal Inteiro __cdecl _get_output_format(Vazio);
  Inteiro __cdecl setvbuf(FILE *_File,Caractere *_Buf,Inteiro _Mode,size_t _Size);
  _CRTIMP Inteiro __cdecl _scprintf(Constante Caractere *_Format,...);
  Inteiro __cdecl sscanf(Constante Caractere *_Src,Constante Caractere *_Format,...);
  _CRTIMP Inteiro __cdecl _snscanf(Constante Caractere *_Src,size_t _MaxCount,Constante Caractere *_Format,...);
  FILE *__cdecl tmpfile(Vazio);
  Caractere *__cdecl tmpnam(Caractere *_Buffer);
  Inteiro __cdecl ungetc(Inteiro _Ch,FILE *_File);
  Inteiro __cdecl vfprintf(FILE *_File,Constante Caractere *_Format,va_list _ArgList);
  Inteiro __cdecl vprintf(Constante Caractere *_Format,va_list _ArgList);
  /* Make sure macros are not Definido.  */
#Diretiva push_macro("vsnprintf")
#Diretiva push_macro("snprintf")
# Indefinido vsnprintf
# Indefinido snprintf
  Externo
  __attribute__((format(gnu_printf, 3, 0))) __attribute__((nonnull (3)))
  Inteiro __mingw_vsnprintf(Caractere *_DstBuf,size_t _MaxCount,Constante Caractere *_Format,va_list _ArgList);
  Externo
  __attribute__((format(gnu_printf, 3, 4))) __attribute__((nonnull (3)))
  Inteiro __mingw_snprintf(Caractere* s, size_t n, Constante Caractere*  format, ...);
  Inteiro __cdecl vsnprintf(Caractere *_DstBuf,size_t _MaxCount,Constante Caractere *_Format,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _snprintf(Caractere *_Dest,size_t _Count,Constante Caractere *_Format,...);
  _CRTIMP Inteiro __cdecl _vsnprintf(Caractere *_Dest,size_t _Count,Constante Caractere *_Format,va_list _Args);
  Inteiro __cdecl sprintf(Caractere *_Dest,Constante Caractere *_Format,...);
  Inteiro __cdecl vsprintf(Caractere *_Dest,Constante Caractere *_Format,va_list _Args);
#SenãoDefinido __NO_ISOCEXT  /* externs in libmingwex.a */
  Inteiro __cdecl snprintf(Caractere* s, size_t n, Constante Caractere*  format, ...);
  __CRT_INLINE Inteiro __cdecl vsnprintf (Caractere* s, size_t n, Constante Caractere* format,va_list arg) {
    Retorno _vsnprintf ( s, n, format, arg);
  }
  Inteiro __cdecl vscanf(Constante Caractere * Format, va_list argp);
  Inteiro __cdecl vfscanf (FILE * fp, Constante Caractere * Format,va_list argp);
  Inteiro __cdecl vsscanf (Constante Caractere * _Str,Constante Caractere * Format,va_list argp);
#FimSe
/* Restore may prior Definido macros snprintf/vsnprintf.  */
#Diretiva pop_macro("snprintf")
#Diretiva pop_macro("vsnprintf")
/* Check Se vsnprintf and snprintf are defaulting to gnu-style.  */
# Se Definido(USE_MINGW_GNU_SNPRINTF) && USE_MINGW_GNU_SNPRINTF
# SenãoDefinido vsnprint
# Defina vsnprintf __mingw_vsnprintf
# FimSe
# SenãoDefinido snprintf
# Defina snprintf __mingw_snprintf
# FimSe
# FimSe
  _CRTIMP Inteiro __cdecl _vscprintf(Constante Caractere *_Format,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _set_printf_count_output(Inteiro _Value);
  _CRTIMP Inteiro __cdecl _get_printf_count_output(Vazio);

#SenãoDefinido _WSTDIO_DEFINED

#SenãoDefinido WEOF
#Defina WEOF (wint_t)(0xFFFF)
#FimSe

#SeDefinido _POSIX_
  _CRTIMP FILE *__cdecl _wfsopen(Constante wchar_t *_Filename,Constante wchar_t *_Mode);
#Senão
  _CRTIMP FILE *__cdecl _wfsopen(Constante wchar_t *_Filename,Constante wchar_t *_Mode,Inteiro _ShFlag);
#FimSe
  wint_t __cdecl fgetwc(FILE *_File);
  _CRTIMP wint_t __cdecl _fgetwchar(Vazio);
  wint_t __cdecl fputwc(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _fputwchar(wchar_t _Ch);
  wint_t __cdecl getwc(FILE *_File);
  wint_t __cdecl getwchar(Vazio);
  wint_t __cdecl putwc(wchar_t _Ch,FILE *_File);
  wint_t __cdecl putwchar(wchar_t _Ch);
  wint_t __cdecl ungetwc(wint_t _Ch,FILE *_File);
  wchar_t *__cdecl fgetws(wchar_t *_Dst,Inteiro _SizeInWords,FILE *_File);
  Inteiro __cdecl fputws(Constante wchar_t *_Str,FILE *_File);
  _CRTIMP wchar_t *__cdecl _getws(wchar_t *_String);
  _CRTIMP Inteiro __cdecl _putws(Constante wchar_t *_Str);
  Inteiro __cdecl fwprintf(FILE *_File,Constante wchar_t *_Format,...);
  Inteiro __cdecl wprintf(Constante wchar_t *_Format,...);
  _CRTIMP Inteiro __cdecl _scwprintf(Constante wchar_t *_Format,...);
  Inteiro __cdecl vfwprintf(FILE *_File,Constante wchar_t *_Format,va_list _ArgList);
  Inteiro __cdecl vwprintf(Constante wchar_t *_Format,va_list _ArgList);
  _CRTIMP Inteiro __cdecl swprintf(wchar_t*, Constante wchar_t*, ...);
  _CRTIMP Inteiro __cdecl vswprintf(wchar_t*, Constante wchar_t*,va_list);
  _CRTIMP Inteiro __cdecl _swprintf_c(wchar_t *_DstBuf,size_t _SizeInWords,Constante wchar_t *_Format,...);
  _CRTIMP Inteiro __cdecl _vswprintf_c(wchar_t *_DstBuf,size_t _SizeInWords,Constante wchar_t *_Format,va_list _ArgList);
  _CRTIMP Inteiro __cdecl _snwprintf(wchar_t *_Dest,size_t _Count,Constante wchar_t *_Format,...);
  _CRTIMP Inteiro __cdecl _vsnwprintf(wchar_t *_Dest,size_t _Count,Constante wchar_t *_Format,va_list _Args);
#SenãoDefinido __NO_ISOCEXT  /* externs in libmingwex.a */
  Inteiro __cdecl snwprintf (wchar_t* s, size_t n, Constante wchar_t*  format, ...);
  __CRT_INLINE Inteiro __cdecl vsnwprintf (wchar_t* s, size_t n, Constante wchar_t* format, va_list arg) { Retorno _vsnwprintf(s,n,format,arg); }
  Inteiro __cdecl vwscanf (Constante wchar_t *, va_list);
  Inteiro __cdecl vfwscanf (FILE *,Constante wchar_t *,va_list);
  Inteiro __cdecl vswscanf (Constante wchar_t *,Constante wchar_t *,va_list);
#FimSe
  _CRTIMP Inteiro __cdecl _swprintf(wchar_t *_Dest,Constante wchar_t *_Format,...);
  _CRTIMP Inteiro __cdecl _vswprintf(wchar_t *_Dest,Constante wchar_t *_Format,va_list _Args);

#SenãoDefinido RC_INVOKED
#Inclua <vadefs.h>
#FimSe

#SeDefinido _CRT_NON_CONFORMING_SWPRINTFS
#SenãoDefinido __cplusplus
#Defina swprintf _swprintf
#Defina vswprintf _vswprintf
#Defina _swprintf_l __swprintf_l
#Defina _vswprintf_l __vswprintf_l
#FimSe
#FimSe

  _CRTIMP wchar_t *__cdecl _wtempnam(Constante wchar_t *_Directory,Constante wchar_t *_FilePrefix);
  _CRTIMP Inteiro __cdecl _vscwprintf(Constante wchar_t *_Format,va_list _ArgList);
  Inteiro __cdecl fwscanf(FILE *_File,Constante wchar_t *_Format,...);
  Inteiro __cdecl swscanf(Constante wchar_t *_Src,Constante wchar_t *_Format,...);
  _CRTIMP Inteiro __cdecl _snwscanf(Constante wchar_t *_Src,size_t _MaxCount,Constante wchar_t *_Format,...);
  Inteiro __cdecl wscanf(Constante wchar_t *_Format,...);
  _CRTIMP FILE *__cdecl _wfdopen(Inteiro _FileHandle ,Constante wchar_t *_Mode);
  _CRTIMP FILE *__cdecl _wfopen(Constante wchar_t *_Filename,Constante wchar_t *_Mode);
  _CRTIMP FILE *__cdecl _wfreopen(Constante wchar_t *_Filename,Constante wchar_t *_Mode,FILE *_OldFile);
#SenãoDefinido _CRT_WPERROR_DEFINED
#Defina _CRT_WPERROR_DEFINED
  _CRTIMP Vazio __cdecl _wperror(Constante wchar_t *_ErrMsg);
#FimSe
  _CRTIMP FILE *__cdecl _wpopen(Constante wchar_t *_Command,Constante wchar_t *_Mode);
#Se !Definido(NO_OLDNAMES) && !Definido(wpopen)
#Defina wpopen  _wpopen
#FimSe
  _CRTIMP Inteiro __cdecl _wremove(Constante wchar_t *_Filename);
  _CRTIMP wchar_t *__cdecl _wtmpnam(wchar_t *_Buffer);
  _CRTIMP wint_t __cdecl _fgetwc_nolock(FILE *_File);
  _CRTIMP wint_t __cdecl _fputwc_nolock(wchar_t _Ch,FILE *_File);
  _CRTIMP wint_t __cdecl _ungetwc_nolock(wint_t _Ch,FILE *_File);

#Indefinido _CRT_GETPUTWCHAR_NOINLINE

#Se !Definido(__cplusplus) || Definido(_CRT_GETPUTWCHAR_NOINLINE)
#Defina getwchar() fgetwc(stdin)
#Defina putwchar(_c) fputwc((_c),stdout)
#Senão
  __CRT_INLINE wint_t __cdecl getwchar() { Retorno (fgetwc(stdin)); }
  __CRT_INLINE wint_t __cdecl putwchar(wchar_t _C) { Retorno (fputwc(_C,stdout)); }
#FimSe

#Defina getwc(_stm) fgetwc(_stm)
#Defina putwc(_c,_stm) fputwc(_c,_stm)
#Defina _putwc_nolock(_c,_stm) _fputwc_nolock(_c,_stm)
#Defina _getwc_nolock(_stm) _fgetwc_nolock(_stm)

#Defina _WSTDIO_DEFINED
#FimSe

#Defina _STDIO_DEFINED
#FimSe

#Defina _fgetc_nolock(_stream) (--(_stream)->_cnt >= 0 ? 0xff & *(_stream)->_ptr++ : _filbuf(_stream))
#Defina _fputc_nolock(_c,_stream) (--(_stream)->_cnt >= 0 ? 0xff & (*(_stream)->_ptr++ = (Caractere)(_c)) : _flsbuf((_c),(_stream)))
#Defina _getc_nolock(_stream) _fgetc_nolock(_stream)
#Defina _putc_nolock(_c,_stream) _fputc_nolock(_c,_stream)
#Defina _getchar_nolock() _getc_nolock(stdin)
#Defina _putchar_nolock(_c) _putc_nolock((_c),stdout)
#Defina _getwchar_nolock() _getwc_nolock(stdin)
#Defina _putwchar_nolock(_c) _putwc_nolock((_c),stdout)

  _CRTIMP Vazio __cdecl _lock_file(FILE *_File);
  _CRTIMP Vazio __cdecl _unlock_file(FILE *_File);
  _CRTIMP Inteiro __cdecl _fclose_nolock(FILE *_File);
  _CRTIMP Inteiro __cdecl _fflush_nolock(FILE *_File);
  _CRTIMP size_t __cdecl _fread_nolock(Vazio *_DstBuf,size_t _ElementSize,size_t _Count,FILE *_File);
  _CRTIMP Inteiro __cdecl _fseek_nolock(FILE *_File,Longo _Offset,Inteiro _Origin);
  _CRTIMP Longo __cdecl _ftell_nolock(FILE *_File);
  _CRTIMP Inteiro __cdecl _fseeki64_nolock(FILE *_File,__int64 _Offset,Inteiro _Origin);
  _CRTIMP __int64 __cdecl _ftelli64_nolock(FILE *_File);
  _CRTIMP size_t __cdecl _fwrite_nolock(Constante Vazio *_DstBuf,size_t _Size,size_t _Count,FILE *_File);
  _CRTIMP Inteiro __cdecl _ungetc_nolock(Inteiro _Ch,FILE *_File);

#Se !Definido(NO_OLDNAMES) || !Definido(_POSIX)
#Defina P_tmpdir _P_tmpdir
#Defina SYS_OPEN _SYS_OPEN

  Caractere *__cdecl tempnam(Constante Caractere *_Directory,Constante Caractere *_FilePrefix);
  Inteiro __cdecl fcloseall(Vazio);
  FILE *__cdecl fdopen(Inteiro _FileHandle,Constante Caractere *_Format);
  Inteiro __cdecl fgetchar(Vazio);
  Inteiro __cdecl fileno(FILE *_File);
  Inteiro __cdecl flushall(Vazio);
  Inteiro __cdecl fputchar(Inteiro _Ch);
  Inteiro __cdecl getw(FILE *_File);
  Inteiro __cdecl putw(Inteiro _Ch,FILE *_File);
  Inteiro __cdecl rmtmp(Vazio);
#FimSe

#SeDefinido __cplusplus
}
#FimSe

#Diretiva pack(pop)

#Inclua <sec_api/stdio_s.h>

#FimSe
