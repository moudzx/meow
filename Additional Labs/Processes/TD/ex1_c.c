#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
void main(){

	for(int i=1;i<=5;i++){
			
			if(fork()==0){
			printf("I am the child number %d\n",i);
			//sleep(10);
			exit(0);
			}
	}
	printf("I am the Parent \n");

//sleep(100);
}