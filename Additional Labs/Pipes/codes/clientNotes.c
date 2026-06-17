#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define QUESTION "accesspoint"

void trait();                   /* traitement client */
void main()
{   char repName[30];
    int fdq, fdr;
    char rep[11],nom[50];
    char tamponreq[50];

	printf("Nom?");
	scanf("%s",nom);
	sprintf(tamponreq,"PID-%d+%s",getpid(),nom);

    	fdq = open(QUESTION, O_WRONLY);
	    if (fdq == -1) {
	        fprintf(stderr, "Impossible ouvrire fifo %s\n", QUESTION);
	        fprintf(stderr, "Lancer serveur d\'abord?\n");
	        exit(2);
	    }

	write(fdq, tamponreq, strlen(tamponreq));
	printf("Client -> %s \n", tamponreq);
	sleep(1);
        	sprintf(repName,"PID-%d",getpid());
	fdr = open(repName, O_RDONLY);
	if (fdr == -1) {perror("open fifo");
		fprintf(stderr, "Impossible ouvrir fifo %s\n", repName);
		fprintf(stderr, "Lancer serveur d\'abord?\n");
		exit(2);
	}
	
	read(fdr, rep, 10);
    printf("Serveur -> %s %s \n",nom, rep);
       
    close(fdq);
    close(fdr);
    exit(0);
}
