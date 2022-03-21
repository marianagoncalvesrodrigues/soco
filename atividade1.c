#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <signal.h>

int cont = 0;
char resposta;

void handler(int sigmum){
 printf("SAINDO...");
 exit(0);
}

void handler_saida(int sigmum){
 printf("Demorou muito para responder. Saindo......");
}
void handler_sigint(int sigmum){
  cont++;
  if(cont == 3){
    printf("\nRealmente deseja sair? [Y/n]: ");
    scanf("%c", &resposta);
    alarm(20);
    
    if(resposta == 'Y'){
        cont = 0;
    	exit(0);
    }
       printf("Continuando...");
       cont =0;
  }
}

void handler_sigtstp(int sigmum){
 printf("\n Você apertou Ctl-C %d vezes\n", cont);
}

int main(){

  signal(SIGALRM, handler);
  signal(SIGINT, handler_sigint);
  signal(SIGTSTP, handler_sigtstp);
  signal(SIGALRM, handler_saida);
  
  while(1);
 
  return 0;
  
}
