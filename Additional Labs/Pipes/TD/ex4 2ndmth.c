#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/wait.h>

#define PTIME 2
pid_t *enfants;
int nbJoueurs,possedeBombe=0;
int* tubes;
char bombe='M';

void annoncerFinJeu(int s){
	int i;
	for(i=0;i<nbJoueurs;i++)
	kill(enfants[i],SIGUSR1);
}

void declarerPerdant(int i){
	if(possedeBombe)
	printf("%d est le joueur perdant \n",getpid());
	exit(0);
}

void jouer(int i){
int r,l;
l=2*i;
r=(i==0? 2*nbJoueurs -1:2*i-1);

while(1){
	read(tubes[l],&bombe,1);
	printf("%d a abtenu la bombe \n",getpid());
	possedeBombe=1;
	sleep(PTIME);
	write(tubes[r],&bombe,1);
	possedeBombe=0;
	printf("%d a relache la bombe \n",getpid());
     }
}
void main(int argc,char**argv){
int i, total;

if(argc<2){
fprintf(stderr,"Using %s nombre de joueurs\n",argv[0]);
exit(0);
}
nbJoueurs=atoi(argv[1]);
if(argc==3)
total=atoi(argv[2]);
else 
total=10;




enfants=(pid_t *) malloc(nbJoueurs*sizeof(pid_t));
tubes=(int *) malloc(2*nbJoueurs*sizeof(int));


/*creation des tubes */
for(i=0;i<nbJoueurs;i++)
pipe(tubes+2*i);

/* creation des enfants */
for(i=0;i<nbJoueurs;i++){
	if((enfants[i]=fork())==0){
	signal(SIGUSR1,declarerPerdant);
	jouer(i);
	} else
	printf("%6d",enfants[i]);
	fflush(stdout);
}
printf("\n");
signal(SIGALRM,annoncerFinJeu);

sleep(1);
alarm(total);
write(tubes[1],&bombe,1);
pause();
for(i=1;i<=nbJoueurs;i++)
wait(NULL);
}
