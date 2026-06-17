#include <stdio.h>
#include <stdio.h>
#include <signal.h>
int compteur; int captation=0;
void traiter_signal (int sig) {
printf ("\nGestionnaire\tCompteur:\t\t\t%d\n", compteur);
captation=1; return;
}
main(){ signal(SIGUSR1, traiter_signal); signal(SIGUSR2, traiter_signal);
for (;;) {compteur++;
if (captation) {printf("Main\t\tCompteur après captation\t%d\n", compteur); captation=0;}
}
}