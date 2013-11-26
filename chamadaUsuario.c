/* 
 * Teste da nova chamada de sistema
 */ 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char* argv[]) {

	if(atoi(argv[2])>5000)
	{
		printf("o maximo de tempo de espera permitido eh 5000 ms, portanto sera usado 5000 ms\n");
		strcpy(argv[2], "5000");
	}

	int r = syscall(351, atoi(argv[1]), atoi(argv[2]));

	if(r==0)
		printf("Processo %d inexistente\n", atoi(argv[1]));
	else if(r==1)
		printf("Processo %d foi morto por SIGKILL ja que nao morreu por SIGTERM apos %d milissegundos\n", atoi(argv[1]), atoi(argv[2]));
	else if(r==2)
		printf("Processo %d foi morto por SIGTERM\n", atoi(argv[1]));
	
	/*printf("Retorno da chamada de sistema: %d.\n", r);*/
	return r;
}
