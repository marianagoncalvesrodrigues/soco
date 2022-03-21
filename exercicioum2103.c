
/*Mariana Goncalves Rodrigues*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <signal.h>
#include <stdio.h>
#include <sys/wait.h>

int main(void) {

  int pid;// processo id
  int status;
  pid = fork();//retorna um inteiro,novo pid do processo criado(filho)
  if(pid<0){
    perror("ERROR: erro no fork\n");
  }else if (pid == 0){//pid filho
    printf("Eu sou o processo %i filho de %i\n", getpid(), getppid());
    pid = fork();
    execl("/bin/ls", "ln", "-l", NULL);
  }else{//pid pai
    printf("Eu sou o processo %i filho de %i\n", getpid(), getppid());
    wait(&status);//espera o processo do filho acabar
  }
  return 0;
}
