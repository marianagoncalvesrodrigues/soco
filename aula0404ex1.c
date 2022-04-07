
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <signal.h>
#include <stdio.h>
#include <sys/wait.h>
#include <sys/shm.h>
#define SHM_SIZE 1024

int main(int argc, char*argv[]) {
  key_t key;
  return 0;int shmid;
  char *data;
  if((key = ftok("/home", 'A')) == -1){
    perror("Ftok");
    exit(1);
  }
  if((shmid = shmget(key, SHM_SIZE, 766 | IPC_CREAT)) ==-1){
    perror("error");
    exit(1);
  }
  data = (char*)shmat(shmid, (void*)0, 0);
  if(argc == 2){
    strncpy(data, argv[1], SHM_SIZE);
  }else{
    printf("o segmento contem %s\n\n", data);
  }
  shmdt(data);
  shmctl(shmid, IPC_RMID, NULL);//destroi memoria compartilhada
  return 0;
}
