//+---------------------------------------------------------------------------

// _UNICODE Para tchar.h, UNICODE Para API
#Inclua <tchar.h>

#Inclua <windows.h>
#Inclua <stdlib.h>

#Defina __UNKNOWN_APP    0
#Defina __CONSOLE_APP    1
#Defina __GUI_APP        2
Vazio __set_app_type(Inteiro);
Vazio _controlfp(SemSinal a, SemSinal b);

#SeDefinido _UNICODE
#Defina __tgetmainargs __wgetmainargs
#Defina _twinstart _wwinstart
#Defina _runtwinmain _runwwinmain
Inteiro APIENTRY wWinMain(HINSTANCE, HINSTANCE, LPWSTR, Inteiro);
#Senão
#Defina __tgetmainargs __getmainargs
#Defina _twinstart _winstart
#Defina _runtwinmain _runwinmain
#FimSe

Tipo Estrutura { Inteiro newmode; } _startupinfo;
Inteiro __cdecl __tgetmainargs(Inteiro *pargc, _TCHAR ***pargv, _TCHAR ***penv, Inteiro globb, _startupinfo*);

Estático Inteiro go_winmain(TCHAR *arg1)
{
    STARTUPINFO si;
    _TCHAR *szCmd, *p;
    Inteiro fShow;

    GetStartupInfo(&si);
    Se (si.dwFlags & STARTF_USESHOWWINDOW)
        fShow = si.wShowWindow;
    Senão
        fShow = SW_SHOWDEFAULT;

    szCmd = NULL, p = GetCommandLine();
    Se (arg1)
        szCmd = _tcsstr(p, arg1);
    Se (NULL == szCmd)
        szCmd = _tcsdup(__T(""));
    Senão Se (szCmd > p && szCmd[-1] == __T('"'))
        --szCmd;
#Se Definido __i386__ || Definido __x86_64__
    _controlfp(0x10000, 0x30000);
#FimSe
    Retorno _tWinMain(GetModuleHandle(NULL), NULL, szCmd, fShow);
}

Inteiro _twinstart(Vazio)
{
    __TRY__
    _startupinfo start_info_con = {0};
    __set_app_type(__GUI_APP);
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info_con);
    exit(go_winmain(__argc > 1 ? __targv[1] : NULL));
}

Inteiro _runtwinmain(Inteiro argc, /* as ctec passed in */ Caractere **argv)
{
#SeDefinido UNICODE
    _startupinfo start_info = {0};
    __tgetmainargs(&__argc, &__targv, &_tenviron, 0, &start_info);
    /* may be wrong when ctec has received wildcards (*.c) */
    Se (argc < __argc)
        __targv += __argc - argc, __argc = argc;
#Senão
    __argc = argc, __targv = argv;
#FimSe
    Retorno go_winmain(__argc > 1 ? __targv[1] : NULL);
}
