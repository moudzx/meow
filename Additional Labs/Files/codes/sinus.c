#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/wait.h>
#include <math.h>
int main(void)
{
pid_t pid_fils;
int tube[2];
double x, valeurW, valeurR;
puts("Création d'un tube");
if (pipe(tube) != 0) /* pipe */
{
fprintf(stderr, "Erreur dans pipe\n");
exit(1);
}
switch(pid_fils = fork()) /* fork */
{
case -1 :
perror("Erreur dans fork\n");
exit(errno);
case 0 : /* processus fils */
close(tube[1]);
read(tube[0], &valeurR, sizeof(double));
printf("Le fils (%d) a lu : %.2f\n", getpid(), valeurR);
break;

default : /* processus père */
printf("Fermeture sortie dans le père (pid = %d)\n", getpid());
close(tube[0]);
puts("Entrez x :");
scanf("%lf", &x);
valeurW = sin(x);
write(tube[1], &valeurW, sizeof(double));
wait(NULL);
break;
}
return 0;
}
