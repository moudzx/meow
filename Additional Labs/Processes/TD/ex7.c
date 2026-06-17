#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
void main(int argc, char**argv){
	if(argc>1)
	execvp(argv[1],argv+1);
else
	printf("No command to execute\n");

}