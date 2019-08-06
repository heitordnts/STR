
/////\// UFRN-CT-DCA
// Disciplina: Sistemas Operacionais
// Programa: sleep.c


#include <iostream> // para: cout
#include <stdio.h>
#include <unistd.h> // para: sleep()


using std::cout;

//using namespace std;


int main ( )
{

  double x = 1;
    
  //usleep(1000);
  sleep(2);
  cout << "passei. levou 2 segundos" << '\n';
  clock_t t = time(0);
  for(int i=0; i<5; i++) {
    sleep(1);
    cout << "teste "  << i <<'\n';
  }
  cout << " tempo gasto : " << (time(0) - t) << " segundos\n" ;
  cout << "teste" <<'\n';
  return(0);
}

