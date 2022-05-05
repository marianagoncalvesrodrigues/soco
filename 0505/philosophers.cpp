#include <iostream>
#include "thread.h"
#include "semaphore.h"
#include "mutex.h"
#include <unistd.h>
 
using namespace std;
 
const int DELAY = 10000000;
const int ITERATIONS = 5;
Mutex table; 


Semaphore chopstick[5];
 
int philosopher(int n)
{
    
    int first = (n < 4)? n : 0;      // se n < 4 first = n, senão 0; left for phil 0 .. 3, right for phil 4
    int second = (n < 4)? n + 1 : 4; // se n < 4 second = n+1, senão 4; right for phil 0 .. 3, left for phil 4
	
    // Foram removidos do laço abaixo:
    //  - uma chamada para chopstick[first].p()
    //  - uma chamada para chopstick[second].p()
    //  - uma chamada para chopstick[first].v()
    //  - uma chamada para chopstick[second].v()

    for(int i = 0; i < ITERATIONS; i++) {

	 table.lock();
	 cout << "Philosopher " << n << " thinking ...\n";
	 table.unlock();
	 	
	 for(int i = 0; i < DELAY * 10; i++);
	 sleep(1);
	 
	 chopstick[first].p();
	 chopstick[second].p();
	 
	 table.lock();
	 cout << "Philosopher " << n << " eating ...\n";
	 table.unlock();
	 
	 for(int i = 0; i < DELAY; i++);
	 sleep(1);
	 
	 chopstick[first].v();
	 chopstick[second].v();
	 
	 table.lock();
	 cout << "Philosopher " << n << " release forks!\n";
	 table.unlock();
	
    }
 
    return n;
}
 
int main()
{
    cout << "The Dining-Philosophers Problem\n";
 
    Thread * phil[5];
    for(int i = 0; i < 5; i++)
	phil[i] = new Thread(&philosopher, i);
 
    int status;
    for(int i = 0; i < 5; i++) {
	phil[i]->join(&status);
	if(status == i)
	    cout << "Philosopher " << i << " went to heaven!\n";
	else
	    cout << "Philosopher " << i << " went to hell!\n";
    }
 
    return 0;
}
