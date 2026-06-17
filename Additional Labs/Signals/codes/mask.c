#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

/* ================================================= */
void affich_mask (char *message, sigset_t *mask){
/* ================================================= */
sigset_t set_signaux;
int i;
if (mask == NULL){// Affichage du masque courant
if (sigprocmask(0, NULL, &set_signaux)<0) {
perror("pb sigprocmask"); exit (EXIT_FAILURE);
}
}
else set_signaux= *mask; // Affichage du masque passé en paramètre
printf("%s{", message);
for (i=1; i< NSIG; i++){
if (sigismember(&set_signaux, i)) printf("%d ", i);
}
printf("}\n");
}// affich_mask