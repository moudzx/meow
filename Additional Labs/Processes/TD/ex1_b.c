#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
void main(){
	pid_t p,p1;
p=fork();
		switch(p){
		case -1: perror("Fork");
				exit(1);
	case 0: 	printf("I am the child 1\n");	break;
	default:
	       
		   p1=fork();
		   if(p1<0){
		   perror("Fork of child 2");
				exit(1);
		   }
		   else
		   if(p1==0){
		   printf("I am the child 2\n");
		   }
		   else
		    printf("I am the parent\n");
	}
}