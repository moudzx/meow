#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h> 
#include <signal.h>

int main(int argc, char **argv) {

pid_t pidToSend;
char rep;

if (argc != 2) {
fprintf(stderr, "Usage %s pid\n", argv[0]);
exit(1); }

pidToSend = atoi(argv[1]);

printf("Etes-vous sûr de vouloir tuer le processus %d ? (o/n)", pidToSend);
rep = getchar();
if (rep == 'o')
kill(pidToSend, SIGTERM);
return 0; }
