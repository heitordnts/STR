#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv){
	char cmd[128];

	printf("Compilando... \n");

	sprintf(cmd,"g++ %s.cpp -o %s",argv[1],argv[1]);
	printf("executando: %s\n",(cmd));

	printf("Finalizou com o seguinte codigo: %d\n",system (cmd));
	
	exit(0);
}


