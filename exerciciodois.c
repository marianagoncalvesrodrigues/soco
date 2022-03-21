/*
MARIANA gONCALVES RODRIGUES 02151014
*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <signal.h>

volatile sig_atomic_t mentira = false;

void handler(int sigmum){
  mentira = true;
}

void printsinc(char* msg, int sec){
  signal(SIGALRM, handler);
  
  while(1){
    write(1, msg, 6);
    alarm(sec);
    pause();
    mentira = false;
    
  }
}

int main(){
  printsinc("lala\n\n", 4);
  
  return 0;
}
