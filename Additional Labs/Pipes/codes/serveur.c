/* Serveur: retourne resultat (requete a+b)
 * Cree les fifos cli2serv et serv2cli
 * LANCER LE SERVEUR D'ABORD (car il ecrase fifos)
 */

#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#define QUESTION "cli2serv"
#define REPONSE "serv2cli"

void trait();             /* traitement du serveur */

main()
{
    int fdq, fdr;
    unlink(QUESTION);
    unlink(REPONSE);
/* Creation fifos */
    if (mkfifo(QUESTION, 0644) == -1 ||
        mkfifo(REPONSE, 0644) == -1) {
        perror("Impossible creer fifos");
        exit(2);
    }
/* Attente des ouvertures Clients */

    fdq = open(QUESTION, O_RDONLY);
    fdr = open(REPONSE, O_WRONLY);
    trait(fdr, fdq);
    close(fdq);
    close(fdr);
    unlink(QUESTION);
    unlink(REPONSE);
    exit(0);
}


void trait(fdr, fdq)
int fdr, fdq;
/* fdr et fdq descripteurs reponse/question */
{
    int opd1, opd2, res;
    char opr;
    char quest[11];
    char rep[11];

/* traitement serveur
   * envoi reponse a question
   * a + b venant de client.
   * arret question = "Ciao"
 */

    while (1) {
        read(fdq, quest, 10);
        sscanf(quest, "%d%1s%d", &opd1, &opr, &opd2);
        if (strcmp(quest, "Ciao") == 0) {
            strcpy(rep, "Bye");
            write(fdr, rep, 10);
            break;
        }
        res = opd1 + opd2;
        sprintf(rep, "%d", res);
        write(fdr, rep, 10);
    }
}