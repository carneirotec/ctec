/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#SenãoDefinido _INC_PROCESS
#Defina _INC_PROCESS

#Inclua <_mingw.h>

/* Includes a definition of _pid_t and pid_t */
#Inclua <sys/types.h>

#SenãoDefinido _POSIX_
#SeDefinido __cplusplus
Externo "C" {
#FimSe

#Defina _P_WAIT 0
#Defina _P_NOWAIT 1
#Defina _OLD_P_OVERLAY 2
#Defina _P_NOWAITO 3
#Defina _P_DETACH 4
#Defina _P_OVERLAY 2

#Defina _WAIT_CHILD 0
#Defina _WAIT_GRANDCHILD 1

  _CRTIMP uintptr_t __cdecl _beginthread(Vazio (__cdecl *_StartAddress) (Vazio *),SemSinal _StackSize,Vazio *_ArgList);
  _CRTIMP Vazio __cdecl _endthread(Vazio);
  _CRTIMP uintptr_t __cdecl _beginthreadex(Vazio *_Security,SemSinal _StackSize,SemSinal (__stdcall *_StartAddress) (Vazio *),Vazio *_ArgList,SemSinal _InitFlag,SemSinal *_ThrdAddr);
  _CRTIMP Vazio __cdecl _endthreadex(SemSinal _Retval);

#SenãoDefinido _CRT_TERMINATE_DEFINED
#Defina _CRT_TERMINATE_DEFINED
  Vazio __cdecl __MINGW_NOTHROW exit(Inteiro _Code) __MINGW_ATTRIB_NORETURN;
  _CRTIMP Vazio __cdecl __MINGW_NOTHROW _exit(Inteiro _Code) __MINGW_ATTRIB_NORETURN;

#Diretiva push_macro("abort")
#Indefinido abort
  Vazio __cdecl __declspec(noreturn) abort(Vazio);
#Diretiva pop_macro("abort")

#FimSe

  _CRTIMP Vazio __cdecl __MINGW_NOTHROW _cexit(Vazio);
  _CRTIMP Vazio __cdecl __MINGW_NOTHROW _c_exit(Vazio);
  _CRTIMP Inteiro __cdecl _getpid(Vazio);
  _CRTIMP intptr_t __cdecl _cwait(Inteiro *_TermStat,intptr_t _ProcHandle,Inteiro _Action);
  _CRTIMP intptr_t __cdecl _execl(Constante Caractere *_Filename,Constante Caractere *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execle(Constante Caractere *_Filename,Constante Caractere *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execlp(Constante Caractere *_Filename,Constante Caractere *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execlpe(Constante Caractere *_Filename,Constante Caractere *_ArgList,...);
  _CRTIMP intptr_t __cdecl _execv(Constante Caractere *_Filename,Constante Caractere *Constante *_ArgList);
  _CRTIMP intptr_t __cdecl _execve(Constante Caractere *_Filename,Constante Caractere *Constante *_ArgList,Constante Caractere *Constante *_Env);
  _CRTIMP intptr_t __cdecl _execvp(Constante Caractere *_Filename,Constante Caractere *Constante *_ArgList);
  _CRTIMP intptr_t __cdecl _execvpe(Constante Caractere *_Filename,Constante Caractere *Constante *_ArgList,Constante Caractere *Constante *_Env);
  _CRTIMP intptr_t __cdecl _spawnl(Inteiro _Mode,Constante Caractere *_Filename,Constante Caractere *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnle(Inteiro _Mode,Constante Caractere *_Filename,Constante Caractere *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnlp(Inteiro _Mode,Constante Caractere *_Filename,Constante Caractere *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnlpe(Inteiro _Mode,Constante Caractere *_Filename,Constante Caractere *_ArgList,...);
  _CRTIMP intptr_t __cdecl _spawnv(Inteiro _Mode,Constante Caractere *_Filename,Constante Caractere *Constante *_ArgList);
  _CRTIMP intptr_t __cdecl _spawnve(Inteiro _Mode,Constante Caractere *_Filename,Constante Caractere *Constante *_ArgList,Constante Caractere *Constante *_Env);
  _CRTIMP intptr_t __cdecl _spawnvp(Inteiro _Mode,Constante Caractere *_Filename,Constante Caractere *Constante *_ArgList);
  _CRTIMP intptr_t __cdecl _spawnvpe(Inteiro _Mode,Constante Caractere *_Filename,Constante Caractere *Constante *_ArgList,Constante Caractere *Constante *_Env);

#SenãoDefinido _CRT_SYSTEM_DEFINED
#Defina _CRT_SYSTEM_DEFINED
  Inteiro __cdecl system(Constante Caractere *_Command);
#FimSe

#SenãoDefinido _WPROCESS_DEFINED
#Defina _WPROCESS_DEFINED
  _CRTIMP intptr_t __cdecl _wexecl(Constante wchar_t *_Filename,Constante wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecle(Constante wchar_t *_Filename,Constante wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclp(Constante wchar_t *_Filename,Constante wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexeclpe(Constante wchar_t *_Filename,Constante wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wexecv(Constante wchar_t *_Filename,Constante wchar_t *Constante *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecve(Constante wchar_t *_Filename,Constante wchar_t *Constante *_ArgList,Constante wchar_t *Constante *_Env);
  _CRTIMP intptr_t __cdecl _wexecvp(Constante wchar_t *_Filename,Constante wchar_t *Constante *_ArgList);
  _CRTIMP intptr_t __cdecl _wexecvpe(Constante wchar_t *_Filename,Constante wchar_t *Constante *_ArgList,Constante wchar_t *Constante *_Env);
  _CRTIMP intptr_t __cdecl _wspawnl(Inteiro _Mode,Constante wchar_t *_Filename,Constante wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnle(Inteiro _Mode,Constante wchar_t *_Filename,Constante wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlp(Inteiro _Mode,Constante wchar_t *_Filename,Constante wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnlpe(Inteiro _Mode,Constante wchar_t *_Filename,Constante wchar_t *_ArgList,...);
  _CRTIMP intptr_t __cdecl _wspawnv(Inteiro _Mode,Constante wchar_t *_Filename,Constante wchar_t *Constante *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnve(Inteiro _Mode,Constante wchar_t *_Filename,Constante wchar_t *Constante *_ArgList,Constante wchar_t *Constante *_Env);
  _CRTIMP intptr_t __cdecl _wspawnvp(Inteiro _Mode,Constante wchar_t *_Filename,Constante wchar_t *Constante *_ArgList);
  _CRTIMP intptr_t __cdecl _wspawnvpe(Inteiro _Mode,Constante wchar_t *_Filename,Constante wchar_t *Constante *_ArgList,Constante wchar_t *Constante *_Env);
#SenãoDefinido _CRT_WSYSTEM_DEFINED
#Defina _CRT_WSYSTEM_DEFINED
  _CRTIMP Inteiro __cdecl _wsystem(Constante wchar_t *_Command);
#FimSe
#FimSe

  Vazio __cdecl __security_init_cookie(Vazio);
#Se (Definido(_X86_) && !Definido(__x86_64))
  Vazio __fastcall __security_check_cookie(uintptr_t _StackCookie);
  __declspec(noreturn) Vazio __cdecl __report_gsfailure(Vazio);
#Senão
  Vazio __cdecl __security_check_cookie(uintptr_t _StackCookie);
  __declspec(noreturn) Vazio __cdecl __report_gsfailure(uintptr_t _StackCookie);
#FimSe
  Externo uintptr_t __security_cookie;

  intptr_t __cdecl _loaddll(Caractere *_Filename);
  Inteiro __cdecl _unloaddll(intptr_t _Handle);
  Inteiro (__cdecl *__cdecl _getdllprocaddr(intptr_t _Handle,Caractere *_ProcedureName,intptr_t _Ordinal))(Vazio);

#SeDefinido _DECL_DLLMAIN
#SeDefinido _WINDOWS_
  WINBOOL WINAPI DllMain(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  WINBOOL WINAPI _CRT_INIT(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  WINBOOL WINAPI _wCRT_INIT(HANDLE _HDllHandle,DWORD _Reason,LPVOID _Reserved);
  Externo WINBOOL (WINAPI *Constante _pRawDllMain)(HANDLE,DWORD,LPVOID);
#Senão
  Inteiro __stdcall DllMain(Vazio *_HDllHandle,SemSinal _Reason,Vazio *_Reserved);
  Inteiro __stdcall _CRT_INIT(Vazio *_HDllHandle,SemSinal _Reason,Vazio *_Reserved);
  Inteiro __stdcall _wCRT_INIT(Vazio *_HDllHandle,SemSinal _Reason,Vazio *_Reserved);
  Externo Inteiro (__stdcall *Constante _pRawDllMain)(Vazio *,SemSinal,Vazio *);
#FimSe
#FimSe

#SenãoDefinido	NO_OLDNAMES
#Defina P_WAIT _P_WAIT
#Defina P_NOWAIT _P_NOWAIT
#Defina P_OVERLAY _P_OVERLAY
#Defina OLD_P_OVERLAY _OLD_P_OVERLAY
#Defina P_NOWAITO _P_NOWAITO
#Defina P_DETACH _P_DETACH
#Defina WAIT_CHILD _WAIT_CHILD
#Defina WAIT_GRANDCHILD _WAIT_GRANDCHILD

  intptr_t __cdecl cwait(Inteiro *_TermStat,intptr_t _ProcHandle,Inteiro _Action);
#SeDefinido __GNUC__
  Inteiro __cdecl execl(Constante Caractere *_Filename,Constante Caractere *_ArgList,...);
  Inteiro __cdecl execle(Constante Caractere *_Filename,Constante Caractere *_ArgList,...);
  Inteiro __cdecl execlp(Constante Caractere *_Filename,Constante Caractere *_ArgList,...);
  Inteiro __cdecl execlpe(Constante Caractere *_Filename,Constante Caractere *_ArgList,...);
#Senão
    intptr_t __cdecl execl(Constante Caractere *_Filename,Constante Caractere *_ArgList,...);
  intptr_t __cdecl execle(Constante Caractere *_Filename,Constante Caractere *_ArgList,...);
  intptr_t __cdecl execlp(Constante Caractere *_Filename,Constante Caractere *_ArgList,...);
  intptr_t __cdecl execlpe(Constante Caractere *_Filename,Constante Caractere *_ArgList,...);
#FimSe
  intptr_t __cdecl spawnl(Inteiro,Constante Caractere *_Filename,Constante Caractere *_ArgList,...);
  intptr_t __cdecl spawnle(Inteiro,Constante Caractere *_Filename,Constante Caractere *_ArgList,...);
  intptr_t __cdecl spawnlp(Inteiro,Constante Caractere *_Filename,Constante Caractere *_ArgList,...);
  intptr_t __cdecl spawnlpe(Inteiro,Constante Caractere *_Filename,Constante Caractere *_ArgList,...);
  Inteiro __cdecl getpid(Vazio);
#SeDefinido __GNUC__
  /* Those methods are predefined by gcc builtins to Retorno Inteiro. So to prevent
     stupid warnings, Defina them in POSIX way.  This is save, because those
     methods Faça not Retorno in success Caso, so that the Retorno value is not
     really dependent to its scalar width.  */
  Inteiro __cdecl execv(Constante Caractere *_Filename,Constante Caractere *Constante _ArgList[]);
  Inteiro __cdecl execve(Constante Caractere *_Filename,Constante Caractere *Constante _ArgList[],Constante Caractere *Constante _Env[]);
  Inteiro __cdecl execvp(Constante Caractere *_Filename,Constante Caractere *Constante _ArgList[]);
  Inteiro __cdecl execvpe(Constante Caractere *_Filename,Constante Caractere *Constante _ArgList[],Constante Caractere *Constante _Env[]);
#Senão
  intptr_t __cdecl execv(Constante Caractere *_Filename,Constante Caractere *Constante _ArgList[]);
  intptr_t __cdecl execve(Constante Caractere *_Filename,Constante Caractere *Constante _ArgList[],Constante Caractere *Constante _Env[]);
  intptr_t __cdecl execvp(Constante Caractere *_Filename,Constante Caractere *Constante _ArgList[]);
  intptr_t __cdecl execvpe(Constante Caractere *_Filename,Constante Caractere *Constante _ArgList[],Constante Caractere *Constante _Env[]);
#FimSe
  intptr_t __cdecl spawnv(Inteiro,Constante Caractere *_Filename,Constante Caractere *Constante _ArgList[]);
  intptr_t __cdecl spawnve(Inteiro,Constante Caractere *_Filename,Constante Caractere *Constante _ArgList[],Constante Caractere *Constante _Env[]);
  intptr_t __cdecl spawnvp(Inteiro,Constante Caractere *_Filename,Constante Caractere *Constante _ArgList[]);
  intptr_t __cdecl spawnvpe(Inteiro,Constante Caractere *_Filename,Constante Caractere *Constante _ArgList[],Caractere *Constante _Env[]);
#FimSe

#SeDefinido __cplusplus
}
#FimSe
#FimSe
#FimSe
