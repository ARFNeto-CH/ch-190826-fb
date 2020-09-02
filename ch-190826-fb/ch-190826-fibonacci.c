#include "stdio.h"
#include "stdlib.h"

long proximo_fibonacci(int n)
{
	static long ultimo;
	static long penultimo;
	long		proximo;
	if (n==0)
	{
		ultimo = 1;
		penultimo = 0;
		return 1;
	}
	proximo = ultimo + penultimo;
	penultimo = ultimo;
	ultimo = proximo;
	return proximo;
}	// end proximo_fibonacci()


int main(int argc, char** argv)
{
	unsigned int	limite;
	unsigned int	soma = 0;
	unsigned int	v;
	unsigned int	sequencia = 0;

	if (argc > 1)
	{
		limite = atol(argv[1]);
	}
	else
	{
		limite = 4000000L;
	}	// end if
	printf("Usando limite de %d\n", limite);
	proximo_fibonacci(0);	// inicia a sequencia
	do
	{
		v = proximo_fibonacci(1);
		if(v>limite)
		{
			printf("Soma dos valores pares (limite=%d): %d\n", limite, soma);
			break;
		}
		if ((v%2)==0) soma += v;
	} while (1);
	// de novo com mais detalhes
	soma = 0;
	sequencia = 1;
	proximo_fibonacci(0);	// inicia a sequencia
	do
	{
		v = proximo_fibonacci(1);
		sequencia += 1;
		if (v > limite)
		{
			printf("\nSoma dos valores pares (limite=%d): %d\n", limite, soma);
			return 0;
		}
		if ((v%2)==0)
		{
			printf("[%d] %ld\n", sequencia, v);
			soma += v;
		}
	} while (1);

}	// end main()