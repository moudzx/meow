#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
void main(){
switch(fork()){
case -1: perror("Fork"); 
	exit(0);
case 0: printf("Hello,"); 
	break;
default :
	printf("World!\n");
}
}