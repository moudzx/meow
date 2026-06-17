#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>
void dormir(int s){}
void main(int argc, char**argv){
	int nbs=0;
	if(argc==2)
		nbs=atoi(argv[1]);
	
	signal(SIGALRM,dormir);
	alarm(nbs);
	if(nbs>0)
	pause();
}