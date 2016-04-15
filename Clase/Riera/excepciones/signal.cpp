#include <iostream>
#include <csignal>
#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;

void signalHandler( int signum )
{
    time_t timer;
    struct tm * timeinfo;
    
    time(&timer);
    
    timeinfo = localtime ( &timer );
	 
    cout << asctime(timeinfo);  
    cout << "Para seguir introduzca 1, y para parar introduzca 0" << endl;

    int entrada;
    cin >> entrada;

    if (!entrada)
	exit(signum);  

}

int main ()
{  
    signal(SIGINT, signalHandler);  

    while(1){
    }

    return 0;
}
