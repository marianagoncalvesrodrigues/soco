/*Mariana Goncalves Rodrigues*/

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <signal.h>

int cont = 0; // contador de quantidade de control C

void handler_saida(int sigmum){//o alarme de 20 segundo é ouvido e esta funçao é requisitada
 write(1, "Demorou muito para responder. Saindo......", 42);
  exit(0);
}
void handler_sigint(int sigmum){//ouve o control C
  cont++;//conta a quantidade de control C
  if(cont == 3){
    alarm(20);//dispara alarme para caso há demora de resposta
    char resposta;
    write(1, "\nRealmente deseja sair?[Y/n]\n", 30);
    read(0, &resposta, 1 );

    if(resposta == 'n'){//caso nao deseje sair do programa
      cont = 0;//a quantidade de control C é zerada
      write(1, "Continuando...", 14);
      alarm(0);//força o alarme zerar
    }
    
    if(resposta == 'Y'){//caso deseja sair
      cont = 0;//zera a quantidade de control C
    	exit(0); //sai do programa
    } 
  }
}

void handler_sigtstp(int sigmum){//Control Z é ouvido e entao é requisitada esta funçao
  if(cont != 3){//só mostrará a quantidade de Control C se for diferente de 3, se for igual a tres o programa vai ser ouvido por outro alarme e perguntará se deseja sair
    char msg[30]="\n Você apertou Ctl-C % vezes\n";
    msg[22]=cont+'0';
    write(1, msg, 30);
  }
}

int main(){
  //dispara ouvintes de alarme
  signal(SIGALRM, handler_saida);
  signal(SIGINT, handler_sigint);
  signal(SIGTSTP, handler_sigtstp);
  
  while(1);
 
  return 0;
  
}
