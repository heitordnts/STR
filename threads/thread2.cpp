// programa thread2.cpp
// Programa que cria uma thread e espera seu término para também poder terminar 
// Para compilá-lo utilise: g++ -o thread2 thread2.cpp -lpthread

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>   // biblioteca pthread

void *thread_function(void *arg);

char message[] = "Alô, Mundo cruel!";

int main() {
    int res;

    pthread_t a_thread;
    void *thread_result;
    // criação de thread: (endereco_da_thread, atributos_da_thread, endereco_da_função, argumentos_da_função)
    res = pthread_create(&a_thread, NULL, thread_function, (void *)message); // char* to void*
    if (res != 0) {
        perror("A Craição da Thread falhou");
        exit(EXIT_FAILURE);
    }
    printf("MAIN()--> Esperando pelo término da thread...\n");
  
    res = pthread_join(a_thread, &thread_result);
    if (res != 0) {
        perror("O thread_join falhou");
        exit(EXIT_FAILURE);
    }
  
	int t=5;
	while(printf("%d\n",t), t--)
    sleep(1);

    printf("MAIN()--> O thread_join retornou:   %s\n", (char *)thread_result);
    printf("MAIN()--> Message agora é: %s\n\n", message);
    exit(EXIT_SUCCESS);
}

void *thread_function(void *arg) {
    printf("THREAD--> thread_function está rodando. O argumento foi %s\n", (char *)arg);
    printf("THREAD--> Agora vou dormir por 3 segundos\n");
	int t=3;
	while(printf("%d\n",t), t--)
    sleep(1);
    printf("THREAD--> Acordei e agora vou terminar\n");
    strcpy((char*)message, "Estou indo embora! (escrito pela thread)");
    pthread_exit((void *) "Obrigado pelo seu tempo de CPU");
}
