#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
void main(){
int tube[2];
char buf[50];
int n;
if(pipe(tube)<0){
perror("Creation de tube");
exit(1);
}

switch(fork()){
case -1 :   break;
case 0: //sleep(2);
	dup2(tube[1],1);
	close(tube[0]);   
	close(tube[1]);
	system("date");
	//execlp("date","date",NULL);
	exit(0);
default :close(tube[1]);
	//wait(NULL);
	int n=read(tube[0],buf,50);
	buf[n]='\0';	
	printf("%s\n",buf);
}


}