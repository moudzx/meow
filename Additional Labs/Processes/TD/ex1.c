#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
void main(){
	
pid_t p;

p=fork();
	/*if(p<0){
		perror("Fork");
		exit(1);
		}
	else
	if(p>0) {  //if(p) code for parent
	printf("I am the parent\n");
	}
	else
	{
	printf("I am the child\n");	
	}	*/
	
	switch(p){
		case -1: perror("Fork");
				exit(1);
	case 0: 	printf("I am the child\n");	break;
	default:printf("I am the parent\n");
	}
	
}