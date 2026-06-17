#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
pid_t filsa,filsc;

void hand_sigusr1(int signum){
printf("---");
kill(filsa,SIGUSR2);
printf("[%d] je suis le fils cadet j'ai envoye SIGUSR2 a mon frere aine[%d]\n",filsc,filsa);
exit(0);
}

void main(){
if((filsa=fork())==0){
while(1) pause();
}
if((filsc=fork())==0){

signal(SIGUSR1,hand_sigusr1);
while(1)
 pause();}


sleep(1);
kill(filsc,SIGUSR1);
printf("[%d] je suis le pere j'ai envoye SIGUSR1 a mon fils cadet[%d]\n",getpid(),filsc);

wait(NULL); wait(NULL);

}