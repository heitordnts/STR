#include <iostream>
#include <cstdio>
#include <ctime>

using namespace std;

int main(){
	struct tm nasc;
	char date[80];

	cout << "Digite sua data e hora de nascimento:(dd/mm/yyyy hh:mm:ss)\n> ";

	scanf("%d/%d/%d %d:%d:%d",&nasc.tm_mday,&nasc.tm_mon,&nasc.tm_year,&nasc.tm_hour,&nasc.tm_min,&nasc.tm_sec);

	//consertando o mes e ano
	nasc.tm_mon -= 1;
	nasc.tm_year -= 1900;

	time_t nasc_secs = mktime(&nasc);
	strftime(date,80,"%d de %B de %Y as %X\n",&nasc);	

	//cout << "Ja se passaram " << (time(0) - nasc_secs) << " segundos desde " << asctime(&nasc);	
	cout << "Ja se passaram " << (time(0) - nasc_secs) << " segundos desde " << date;	
	return 0;
}
