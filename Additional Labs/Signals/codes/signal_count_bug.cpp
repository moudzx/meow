#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <errno.h>
#include <signal.h>
#include <string.h>
#include <time.h>


void counter(int n) {
static int count;
count++;
fprintf(stderr,"Child SIGUSR1 counter = %d\n",count);
}


int main(int argc,char* argv[]) {
int pid;
switch(pid=fork()) {
case -1: perror("fork"); exit(1);
case 0: {
	/* First, we install the signal handler */
	struct sigaction sig;
	memset(&sig,0,sizeof(struct sigaction));
	sig.sa_handler=counter;
	sigaction(SIGUSR1,&sig,NULL);
	/* The child has nothing to do but waiting for signals */
	while (1);
	break;
}
default: {
	/* Then father has nothing to do but sending signals to its child */
	int n=0;
	while (1) {
		kill(pid,SIGUSR1);
		n++;
		if (n%100000==0) fprintf(stderr,"Father sent %d SIGUSR1\n",n);
	}
}
}
return 0;
}
