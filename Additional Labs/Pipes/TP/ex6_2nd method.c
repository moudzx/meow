#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
void main(){
int tube[2],n;
char buf[128];
if(pipe(tube)<0){
perror("Creaion tube");
exit(1); }
switch(fork()){
case -1 :  break;
case 0:    
	close(tube[0]);
	sleep(2);
	dup2(tube[1],1);
	close(tube[1]);
	execl("/bin/date","date",NULL);
	exit(0);
	break;
default :close(tube[1]);
	//wait(NULL);
	n=read(tube[0],buf,128);
	buf[n]='\0';
	printf("Date : %s \n",buf);
}}