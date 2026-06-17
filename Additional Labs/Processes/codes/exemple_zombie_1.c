#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (void){
pid_t pid;
char commande[128];

if ((pid = fork()) < 0) {
fprintf(stderr, "échec fork()\n");
exit(EXIT_FAILURE);
}

if (pid == 0) {/* processus fils */
sleep(4);
fprintf(stdout, "Le processus fils %ld se termine \n",(long) getpid());
exit(EXIT_SUCCESS);
} else {
/* processus père */
snprintf (commande, 128, "ps %ld", (long) pid);
system(commande);
sleep(1);
system(commande);
sleep(1);
system(commande);
sleep(1);
system(commande);
sleep(1);
system(commande);
sleep(1);
system(commande);
}