#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main (void) {
pid_t pid;
if ((pid = fork()) < 0) {
fprintf (stderr, "échec fork()\n");
exit(EXIT_FAILURE);
}
if (pid != 0) {
/* processus père */
fprintf(stdout, "Père : mon PID est %ld\n", (long)getpid());
sleep(2);
fprintf(stdout, "Père : je me termine \n");
exit(EXIT_SUCCESS);
} else {
/* processus fils */
fprintf(stdout, "Fils : mon père est %ld\n", (long)getppid ());
sleep(1);
fprintf(stdout, "Fils : mon père est %ld\n",(long)getppid ());
sleep(1);
fprintf(stdout, "Fils : mon père est %ld\n",(long)getppid ());
sleep(1);
fprintf(stdout, "Fils : mon père est %ld\n",(long)getppid ());
sleep(1);
fprintf(stdout, "Fils : mon père est %ld\n",(long)getppid ());
}
return EXIT_SUCCESS;
}