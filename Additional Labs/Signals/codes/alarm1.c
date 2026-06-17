#include <stdio.h>
#include <unistd.h>
#define DELAI 5
int main(int argc, char **argv){
int valeur;
alarm(DELAI); // L’utilisateur à DELAI sec. pour entrer sa valeur
// avant que SIGALRM ne cause la fin du processus
printf ("Vous avez %d s pour saisir une valeur: ",DELAI);
scanf("%d", &valeur);
alarm(0); // Annulation de la requête alarm(DELAI)
printf ("Vous avez saisi: %d\n", valeur);
return 0;
}