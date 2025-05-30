// =============================================
// crt1.c

// _UNICODE Para tchar.h, UNICODE Para API
#Inclua <tchar.h>

#Inclua <stdio.h>
#Inclua <stdlib.h>

#Defina _UNKNOWN_APP    0
#Defina _CONSOLE_APP    1
#Defina _GUI_APP        2

#Defina _MCW_PC         0x00030000 // Precision Control
#Defina _PC_24          0x00020000 // 24 bits
#Defina _PC_53          0x00010000 // 53 bits
#Defina _PC_64          0x00000000 // 64 bits

#SeDefinido _UNICODE
#Defina __tgetmainargs __wgetmainargs
#Defina _tstart _wstart
#Defina _tmain wmain
#Defina _runtmain _runwmain
#Senão
#Defina __tgetmainargs __getmainargs
#Defina _tstart _start
#Defina _tmain main
#Defina _runtmain _runmain
#FimSe

Tipo Estrutura { Inteiro newmode; } _startupinfo;
Inteiro __cdecl __tgetmainargs(Inteiro *pargc, _TCHAR ***pargv, _TCHAR ***penv, Inteiro globb, _startupinfo*);
Vazio __cdecl __set_app_type(Inteiro apptype);
SemSinal Inteiro __cdecl _controlfp(SemSinal Inteiro new_value, SemSinal Inteiro mask);
Externo Inteiro _tmain(Inteiro argc, _TCHAR * argv[], _TCHAR * env[]);

/* Allow command-Linha globbing with "Inteiro _dowildcard = 1;" in the user source */
Inteiro _dowildcard;

Vazio _tstart(Vazio)
{
    __TRY__
    _startupinfo start_info = {0};

    // Sets the current application type
    __set_app_type(_CONSOLE_APP);

    // Set Padrão FP precision to 53 bits (8-byte Duplo)
    // _MCW_PC (Precision control) is not supported on ARM
#Se Definido __i386__ || Definido __x86_64__
    _controlfp(_PC_53, _MCW_PC);
#FimSe

    __tgetmainargs( &__argc, &__targv, &_tenviron, _dowildcard, &start_info);
    exit(_tmain(__argc, __targv, _tenviron));
}

Inteiro _runtmain(Inteiro argc, /* as ctec passed in */ Caractere **argv)
{
#SeDefinido UNICODE
    _startupinfo start_info = {0};

    __tgetmainargs(&__argc, &__targv, &_tenviron, _dowildcard, &start_info);
    /* may be wrong when ctec has received wildcards (*.c) */
    Se (argc < __argc) {
        __targv += __argc - argc;
        __argc = argc;
    }
#Senão
    __argc = argc;
    __targv = argv;
#FimSe
#Se Definido __i386__ || Definido __x86_64__
    _controlfp(_PC_53, _MCW_PC);
#FimSe
    Retorno _tmain(__argc, __targv, _tenviron);
}

// =============================================
