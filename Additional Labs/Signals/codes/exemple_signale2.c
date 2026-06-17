#include <stdio.h>
#include <signal.h>
#include <string.h>
unsigned int s;
void traiter_signal (int sig) {printf("Reception de: %s\n", strsignal(sig)); return;
}
main(){ signal(SIGUSR1, traiter_signal);
signal(SIGUSR2, traiter_signal);
s=sleep (50);
printf ("REVEIL %d SECONDES AVANT LA FIN DE MA SIESTE\n", s);
}