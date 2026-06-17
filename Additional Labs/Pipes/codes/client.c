/* Client: envoie expressions
   * Les fifos sont supposes crees
   * par le serveur et sont cli2serv
   * et serv2cli
 */

#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#define QUESTION "cli2serv"
#define REPONSE "serv2cli"
void trait();                   /* traitement client */
main()
{
    int fdq, fdr;
    fdq = open(QUESTION, O_WRONLY);
    if (fdq == -1) {
        fprintf(stderr, "Impossible ouvrire fifo %s\n", QUESTION);
        fprintf(stderr, "Lancer serveur d\'abord?\n");
        exit(2);
    }
    fdr = open(REPONSE, O_RDONLY);
    if (fdr == -1) {
        fprintf(stderr, "Impossible ouvrire fifo %s\n", REPONSE);
        fprintf(stderr, "Lancer serveur d\'abord?\n");
        exit(2);
    }
    trait(fdr, fdq);
    close(fdq);
    close(fdr);
    exit(0);
}

void trait(fdr, fdq)
int fdr, fdq;
/* fdr et fdq descripteurs reponse/question */
{
    char rep[11];
    char quest[10];
/* traitement client
   * lecture expression a op b
   * dans stdin et ecriture reponse
   * dans stdout. Arret rep = "Bye"
 */
    while (1) {
        if (gets(quest) == NULL)
            exit(2);
        write(fdq, quest, 10);
        printf("Client -> %s \n", quest);
        read(fdr, rep, 10);
        printf("Serveur -> %s \n", rep);
        if (strcmp(rep, "Bye") == 0)
            break;
    }
}