#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <errno.h>
#include <signal.h>
#include <string.h>
#include <time.h>


void SIGXCPU_handler(int n) {
printf("Kernel sent SIGXCPU signal but I want to sleep 3 seconds\n");
sleep(3);
printf("Now I exit the SIGXCPU signal handler\n");
}


void SIGINT_handler(int n) {
printf("User sent SIGINT signal. Let's kill the program with exit\n");
exit(1);
}


int main(int argc,char* argv[]) {
struct rlimit l;
/* We use this trick to ask for a SGIXCPU signal every second */
l.rlim_cur=1;
l.rlim_max=-1;
if (-1==setrlimit(RLIMIT_CPU,&l)) {
	perror("setrlimit");
}
/* We install a signal handler */
struct sigaction sig;
memset(&sig,0,sizeof(struct sigaction));
sig.sa_handler=SIGINT_handler;
sigaction(SIGINT,&sig,NULL);

/* Now, we want to block SIGINT while SIGXCPU is dealt with, so that
 * SIGINT_handler will be called only at the end of SIGXCPU_handler */
sigset_t set;
sigemptyset(&set);
sigaddset(&set,SIGINT);
sig.sa_mask=set;
sig.sa_handler=SIGXCPU_handler;
sigaction(SIGXCPU,&sig,NULL);

int i=0;
while (1) {
	/* We have to do busy waiting since sleep would
	 * not consume CPU time */
	int t=time(0);
	while (t==time(0));
	i++;
}
return 0;
}
