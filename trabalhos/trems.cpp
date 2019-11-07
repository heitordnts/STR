#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h> 
#include <semaphore.h>
#include <string.h>

void *thread_function(void *arg);
void *tfunc(void *arg);
void *tfunc2(void *arg);
void *tfunc3(void *arg);
pthread_mutex_t work_mutex; /* proteção para: work_area e time_to_exit */
sem_t s;
int n=0;

#define WORK_SIZE 1024
char work_area[WORK_SIZE];
int time_to_exit = 0;

int main() {
    int res;
    pthread_t thread1,thread2,thread3;
    int trem1=1,trem2=2,trem3=3;
	/*
    res = pthread_mutex_init(&work_mutex, NULL);
    if (res != 0) {
        perror("Iniciação do Mutex falhou");
        exit(EXIT_FAILURE);
    }
	*/
    res = sem_init(&s, 0, 2);
    if (res != 0) {
        perror("Semaphore initialization failed");
        exit(EXIT_FAILURE);
    }
    printf("\nMAIN() -->Criando threads\n");
    res = pthread_create(&thread1, NULL, tfunc, (void*)trem1);
    if (res != 0) {
        perror("Criação da Thread falhou");
        exit(EXIT_FAILURE);
    }
    res = pthread_create(&thread2, NULL, tfunc2,(void*) trem2);
    if (res != 0) {
        perror("Criação da Thread falhou");
        exit(EXIT_FAILURE);
    }
    res = pthread_create(&thread3, NULL, tfunc3,(void*) trem3);
    if (res != 0) {
        perror("Criação da Thread falhou");
        exit(EXIT_FAILURE);
    }

	while(1){
		printf("trems no trilho : %d\n",n);

	}
    res = pthread_join(thread1,NULL);// &thread_result);
    if (res != 0) {
        perror("Jun��o da Thread falhou");
        exit(EXIT_FAILURE);
    }
    printf("MAIN() --> Thread foi juntada com sucesso\n");
    sem_destroy(&s);
    exit(EXIT_SUCCESS);
}

void L1(int a ,int b){
		printf("trem %d no %d\n",a,b);	
		fflush(stdout);
}

void* tfunc3(void *arg){
	while(1){
		//L1((int)(arg),9);
		sleep(1);
		//L1((int)(arg),10);
		sleep(1);
    //pthread_mutex_lock(&work_mutex);
		sem_wait(&s);
	//	printf("3 - MUTEX LOCK\n");
	//	L1((int)(arg),11);
		n++;
		sleep(1);
		//printf("3 - MUTEX UNLOCK\n");
    //pthread_mutex_unlock(&work_mutex);
		n--;
		sem_post(&s);
		//L1((int)(arg),12);
		sleep(1);
	}
    pthread_exit(0);
}
void* tfunc2(void *arg){
	while(1){
		//L1((int)(arg),5);
		sleep(1);
		//L1((int)(arg),6);
		sleep(1);
    //pthread_mutex_lock(&work_mutex);
		sem_wait(&s);
		//printf("2 - MUTEX LOCK\n");
		//L1((int)(arg),7);
		n++;
		sleep(1);
		n--;
		//printf("2 - MUTEX UNLOCK\n");
    //pthread_mutex_unlock(&work_mutex);
		sem_post(&s);
		//L1((int)(arg),8);
		sleep(1);
	}
    pthread_exit(0);
}
void* tfunc(void *arg){
	while(1){
		//L1((int)(arg),1);
		sleep(1);
		//L1((int)(arg),2);
		sleep(1);
    //pthread_mutex_lock(&work_mutex);
		sem_wait(&s);
		//printf("1 - MUTEX LOCK\n");
		//L1((int)(arg),3);
		n++;
		sleep(1);
		n--;
		//printf("1 - MUTEX UNLOCK\n");
    //pthread_mutex_unlock(&work_mutex);
		sem_post(&s);
		//L1((int)(arg),4);
		sleep(1);
	}
    pthread_exit(0);
}
void *thread_function(void *arg) {
    sleep(1);
    pthread_mutex_lock(&work_mutex);
    while(strncmp("fim", work_area, 3) != 0) {
        printf("THREAD() --> Seu texto tem %lu caracteres\n", strlen(work_area) -1);
        work_area[0] = '\0';
        pthread_mutex_unlock(&work_mutex);
        sleep(1);
        pthread_mutex_lock(&work_mutex);
        while (work_area[0] == '\0' ) {
            pthread_mutex_unlock(&work_mutex);
            sleep(1);
            pthread_mutex_lock(&work_mutex);
        }
    }
    time_to_exit = 1;
    work_area[0] = '\0';
    pthread_mutex_unlock(&work_mutex);
    pthread_exit(0);
}
