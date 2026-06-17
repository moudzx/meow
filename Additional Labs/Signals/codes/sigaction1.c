#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int donnees[5];

void gestionnaire(int numero) {
int fd;
int i;
if (numero == SIGINT) {
printf("\nSignal d'interruption, sauvegarde...\n");
fd = open("/tmp/sauve.txt", O_WRONLY| O_TRUNC |O_CREAT, S_IRUSR|S_IWUSR);
for (i=0 ; i<5 ; i++) {
write(fd,&donnees[i],sizeof(int));
}
close(fd);
printf("Sauvegarde terminée, terminaison du processus\n");
exit(0);
 }
}

int main(void) {
int i;
char continuer='o';
struct sigaction action;
action.sa_handler = gestionnaire; /* pointeur de fonction */
sigemptyset(&action.sa_mask); /* ensemble de signaux vide */
action.sa_flags = 0; /* options par défaut */

if (sigaction(SIGINT, &action, NULL) != 0){
fprintf(stderr, "Erreur sigaction\n");
exit(1);
}

for (i=0 ; i<5 ; i++)
{
printf("donnees[%d] = ", i);
scanf("%d", &donnees[i]); getchar();
}

while (continuer == 'o'){
puts("zzz...");
sleep(3);
for (i=0 ; i<5 ; i++)
printf("donnees[%d] = %d ", i, donnees[i]);
printf(“\nVoules-vous continuer ? (o/n) ");
continuer = getchar();  getchar();
} }

