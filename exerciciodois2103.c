
/*Mariana Goncalves Rodrigues*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <signal.h>
#include <stdio.h>
#include <sys/wait.h>

int main(void) {

  int pid=5;// processo id
  bool status;
  int result;
  //pid = fork();//retorna um inteiro,novo pid do processo criado(filho)
  if(pid<0){
    perror("ERROR: erro no fork\n");
    WIFEXITED(status);
  }else if (pid == 0){//pid filho
    printf("1");
    WIFEXITED(status);
  }else{//pid pai
    //printf("Eu sou o processo %i filho de %i\n", getpid(), getppid());
    while(pid>0){
      result = result + pid * (pid-1);
      pid--;
    }
    printf("result = %i", result);
    WIFEXITED(status);
    //wait(&status);//espera o processo do filho acabar
  }
  return 0;
}
