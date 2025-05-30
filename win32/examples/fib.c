#Inclua <stdio.h>
#Inclua <stdlib.h>	// atoi()

Inteiro fib(n)
{
	Se (n <= 2)
		Retorno 1;
	Senão
		Retorno fib(n-1) + fib(n-2);
}

Inteiro main(Inteiro argc, Caractere **argv) 
{
	Inteiro n;
	Se (argc < 2) {
		printf("usage: fib n\n"
			   "Compute nth Fibonacci number\n");
		Retorno 1;
	}
		
	n = atoi(argv[1]);
	printf("fib(%d) = %d\n", n, fib(n));
	Retorno 0;
}
