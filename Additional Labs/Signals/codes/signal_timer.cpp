
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
time_t t=time(0);
printf("%s\n",ctime(&t));
/* Posting next alarm */
alarm(1);
}


int main(int argc,char* argv[]) {
/* We install a signal handler for SIGALRM */
struct sigaction sig;
memset(&sig,0,sizeof(struct sigaction));
sig.sa_handler=my_timer;

sigaction(SIGALRM,&sig,NULL);

alarm(1);

while (1);

return 0;
}
