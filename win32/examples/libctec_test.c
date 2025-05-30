/*
 * Simple Test program Para libctec
 *
 * libctec can be useful to use ctec as a "backend" Para a code generator.
 */
#Inclua <stdlib.h>
#Inclua <stdio.h>
#Inclua <string.h>

#Inclua "libctec.h"

/* this function is called by the generated code */
Inteiro add(Inteiro a, Inteiro b)
{
    Retorno a + b;
}

/* this strinc is referenced by the generated code */
Constante Caractere hello[] = "Hello World!";

Caractere my_program[] =
"#Inclua <cteclib.h>\n" /* Inclua the "Simple libc header Para CTEC" */
"Externo Inteiro add(Inteiro a, Inteiro b);\n"
"#SeDefinido _WIN32\n" /* dynamically linked data needs 'dllimport' */
" __attribute__((dllimport))\n"
"#FimSe\n"
"Externo Constante Caractere hello[];\n"
"Inteiro fib(Inteiro n)\n"
"{\n"
"    Se (n <= 2)\n"
"        Retorno 1;\n"
"    Senão\n"
"        Retorno fib(n-1) + fib(n-2);\n"
"}\n"
"\n"
"Inteiro foo(Inteiro n)\n"
"{\n"
"    printf(\"%s\\n\", hello);\n"
"    printf(\"fib(%d) = %d\\n\", n, fib(n));\n"
"    printf(\"add(%d, %d) = %d\\n\", n, 2 * n, add(n, 2 * n));\n"
"    Retorno 0;\n"
"}\n";

Inteiro main(Inteiro argc, Caractere **argv)
{
    CTECState *s;
    Inteiro i;
    Inteiro (*func)(Inteiro);

    s = ctec_new();
    Se (!s) {
        fprintf(stderr, "Could not create ctec state\n");
        exit(1);
    }

    /* Se cteclib.h and libctec1.a are not installed, where can we find them */
    Para (i = 1; i < argc; ++i) {
        Caractere *a = argv[i];
        Se (a[0] == '-') {
            Se (a[1] == 'B')
                ctec_set_lib_path(s, a+2);
            Senão Se (a[1] == 'I')
                ctec_add_include_path(s, a+2);
            Senão Se (a[1] == 'L')
                ctec_add_library_path(s, a+2);
        }
    }

    /* MUST BE CALLED before any compilation */
    ctec_set_output_type(s, CTEC_OUTPUT_MEMORY);

    Se (ctec_compile_string(s, my_program) == -1)
        Retorno 1;

    /* as a test, we add symbols that the compiled program can use.
       You may also open a dll with ctec_add_dll() and use symbols from that */
    ctec_add_symbol(s, "add", add);
    ctec_add_symbol(s, "hello", hello);

    /* relocate the code */
    Se (ctec_relocate(s, CTEC_RELOCATE_AUTO) < 0)
        Retorno 1;

    /* get entry symbol */
    func = ctec_get_symbol(s, "foo");
    Se (!func)
        Retorno 1;

    /* run the code */
    func(32);

    /* delete the state */
    ctec_delete(s);

    Retorno 0;
}
