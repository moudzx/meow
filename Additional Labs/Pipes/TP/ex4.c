#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int pf[2],fp[2];
char mp[50],mf[50];
pid_t fils;
void main(){
if(pipe(pf)<0 || pipe(fp)<0){
perror("Pipe"); 
exit(EXIT_FAILURE);
}

switch(fork()){
case -1: perror("Fork");exit(EXIT_FAILURE);break;
case 0: {close(pf[1]); close(fp[0]);
	int n=read(pf[0],mp,50);
		mp[n]='\0';
	printf("J'ai recu le message %s de mon pere\n",mp);
	write(fp[1],"Au Revoir",15);
	exit(0);} break;
default :{
close(fp[1]); close(pf[0]);
write(pf[1],"Bonjour",15);
int n=read(fp[0],mf,50);
mf[n]='\0';
printf("J'ai recu le message %s de mon fils\n",mf);
wait(NULL);
exit(EXIT_SUCCESS);}
}
}