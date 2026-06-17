#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <errno.h>
#include <signal.h>
#include <string.h>
#include <time.h>


void my_timer(int n) {
printf("Time expired\n");
}

void do_nothing(int n) {
printf("SIGINT: do nothing\n");
}

int main(int argc,char* argv[]) {
/* We install a signal handler for SIGALRM */
struct sigaction sig;
memset(&sig,0,sizeof(struct sigaction));
sig.sa_handler=my_timer;
sigaction(SIGALRM,&sig,NULL);
/* And a one that does nothing for SIGINT */
sig.sa_handler=do_nothing;
sigaction(SIGINT,&sig,NULL);

sig.sa_handler=my_timer;
sigaction(SIGALRM,&sig,NULL);
printf("Alarm in 5 seconds. Would you Ctrl+C ?\n");
alarm(5);
sigset_t sigset;
sigemptyset(&sigset);
sigaddset(&sigset,SIGALRM);
int signum;
/* We only want to take SIGALRM into account there */
sigwait(&sigset,&signum);
printf("Program terminates normally\n");
return 0;
}
