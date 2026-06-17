#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
int p2fs[2];
char mp[53]="aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ";
void main(){
pid_t pid1,pid2;
char c;
if(pipe(p2fs)<0 ){
perror("Pipe"); 
exit(EXIT_FAILURE);
}
switch(pid1=fork()){
case -1: perror("Fork 1");exit(EXIT_FAILURE);break;
case 0:{close(p2fs[1]);
	int i;
	for(i=1;i<=26;i++)
	{
	read(p2fs[0],&c,1);
	printf("%c",c);	
	}
//printf("\n");
	exit(EXIT_SUCCESS);	
	}
default: 
switch(pid2=fork()){
case -1: perror("Fork 2");exit(EXIT_FAILURE);break;
case 0:{close(p2fs[1]);
	int i;
	for(i=1;i<=26;i++)
	{
	read(p2fs[0],&c,1);
	printf("%c",c);	
	}
//printf("\n");
	exit(EXIT_SUCCESS);	
	}
default: close(p2fs[0]);
	write(p2fs[1],mp,52);
	wait(NULL);wait(NULL);
	printf("\n");
}}
}