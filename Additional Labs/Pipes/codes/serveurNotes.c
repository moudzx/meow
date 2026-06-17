#include <sys/types.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#define QUESTION "accesspoint"

	int chercherNote(char nom[]){
	int fd,note,size;
	char*text,nomE[20],*token;	
	
	if((fd=open("notes.txt",O_RDONLY))<0){
		perror("open notes");
		exit(2);
	}

	size=lseek(fd,0,SEEK_END);
	text=(char*)malloc(size*sizeof(char));
	lseek(fd,0,SEEK_SET);	

	 read(fd,text,size);

	token=strtok(text,"\n");
	while(token!=NULL){
	sscanf(token,"%s %d",nomE,&note);
	if(strcmp(nom,nomE)==0){
			close(fd);
			return note;
		}
	token=strtok(NULL,"\n");
	}
	close(fd);
	return -1;
}

void main()
{
    int fdq, fdr,pid,res;
	char nom[20];
	char quest[31];
	char repName[11],rep[15];
	
    unlink(QUESTION);
    
/* Creation fifos */
    if (mkfifo(QUESTION, 0777) == -1 ) {
        perror("Impossible creer fifos");
        exit(2);
    }
/* Attente des ouvertures Clients */
	int n;
    while (1) {
	 fdq = open(QUESTION, O_RDONLY);
      	n=read(fdq, quest, 50);
	   quest[n]='\0';
	sscanf(quest, "PID-%d+%s", &pid, nom);
        	sprintf(repName,"PID-%d",pid);
      
	if (mkfifo(repName, 0777) <0 ) {
           perror("Impossible creer fifos");
        	exit(2);
    	}

	fdr = open(repName, O_WRONLY);
	//chercher note a partir de fichier
	res=chercherNote(nom);
        	sprintf(rep, "%d", res);
        	write(fdr, rep, 10);sleep(1);
	close(fdr);
	close(fdq);        
	}
	
    unlink(QUESTION);
    //unlink(REPONSE);
    exit(0);
}


