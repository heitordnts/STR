#include <cstdio>
#include <cstring>
#include <cstdlib>

void barra(int n,char *buff){
	printf("[");
	fwrite(buff+100,1,n,stdout);
	fwrite(buff,1,100-n,stdout);
	/*
	for(int i=0;i<n;i++){
		putchar('#');
	}
	for(int i=0;i<100-n;i++){
		putchar('-');
	}
	*/
	puts("]");
}
int carga(){
	int a=0,i=1;
	for(i=1;i<1000000;i++){
		a+=0.23*(a+i)/i;
		//printf("%f\n",(float)i/10000000);
	}
	system("clear");
	return a;
}


int main(){
	char buff[200];
	memset(buff,'-',100);
	memset(buff+100,'#',100);
	//while(i < 100){
	int a=0,i=1;
	for(i=1;i<10000;i++){
		a+=0.23*(a+i)/i;
		//printf("%d\n",(int)(100*(float)i/1000000.0));
		barra((int)(100*(float)i/10000.0),buff);
		system("clear");
	}
	//}
	return 0;
}
