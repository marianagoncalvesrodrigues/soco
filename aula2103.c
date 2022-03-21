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
  int aux=0;
  pid = fork();//retorna um inteiro,novo pid do processo criado(filho)
  if(pid<0){
    perror("ERROR: erro no fork\n");
  }else if (pid == 0){//pid filho
    aux+=100;
    printf("Pid = filho -> pid = %i -> aux = %i\n", getpid(), aux);
    execl("/bin/ls", "ln", "-l", NULL);
  }else{//pid pai
    aux+=10;
    printf("Pid = pai -> pid = %i -> aux = %i\n", getpid(), aux);
    wait(&status);//espera o processo do filho acabar
  }
  return 0;
}
