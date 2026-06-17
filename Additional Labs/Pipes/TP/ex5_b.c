#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int p2fs[2],f1f2[2],f2f1[2];
char mp[53]="aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ";
void main(){
pid_t pid1,pid2;
char c;
if(pipe(p2fs)<0 ||  pipe(f1f2)<0|| pipe(f2f1)<0){
perror("Pipe"); 
exit(EXIT_FAILURE);
}
switch(pid1=fork()){
case -1: perror("Fork 1");exit(EXIT_FAILURE);break;
case 0:{
	close(p2fs[1]);
	close(f2f1[1]);
	close(f1f2[0]);
	int i;
	for(i=1;i<=26;i++){
	read(f2f1[0],&c,1);
	read(p2fs[0],&c,1);
	//printf("%d:%c\n",getpid(),c);	
	printf("%c",c);fflush(stdout);
	write(f1f2[1],&c,1);	
	}
	exit(EXIT_SUCCESS);	
	}
default: 
switch(pid2=fork()){
case -1: perror("Fork 2");exit(EXIT_FAILURE);break;
case 0:{close(p2fs[1]); close(f2f1[0]);close(f1f2[1]);
	int i;
	for(i=1;i<=26;i++)
	{
	read(f1f2[0],&c,1);
	read(p2fs[0],&c,1);
	//printf("%d:%c\n",getpid(),c);	
	printf("%c",c);fflush(stdout);
	write(f2f1[1],&c,1);	
	}
	exit(EXIT_SUCCESS);	
	}
default: close(p2fs[0]); 
	close(f2f1[0]);
	close(f1f2[1]); 
	close(f1f2[0]);
	write(p2fs[1],mp,52);
	write(f2f1[1],&c,1);	
	wait(NULL);wait(NULL);
	printf("\n");
}}
}