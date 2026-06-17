#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<string.h>

int N,dureeT=10,dureeP=1,possede_bombe=0,pro;
int*pids;
int *tubes;

void Annoncer(int i){
if(possede_bombe==1)
printf("Le processus %d est perdant son PID est %d\n",pro,getpid());
exit(0);
}

void diffuserAlarme(int sig){
int i;
printf("Explosion a eu lieu\n");
for(i=0;i<N;i++)
kill(pids[i],SIGUSR1);

for(i=0;i<N;i++)
wait(NULL);

printf("Fin du jeu\n");
}

void jouer(int p){
char bombe='*';
int lecture,ecriture;

printf("Processus %d a commencer de jouer\n",p);

ecriture = 2*p + 1;
lecture = (p==0 ? 2*(N-1) : 2*(p-1)  );

while(1){
read(tubes[lecture],&bombe,1);
possede_bombe=1;
printf("le processus %d a recu la bombe\n",p);
sleep(dureeP);
write(tubes[ecriture],&bombe,1);
possede_bombe=0;
}
}

void main(int argc,char**argv){
int i;
if(argc==4){
	N=atoi(argv[1]);
	dureeT=atoi(argv[2]);
	dureeP=atoi(argv[3]);
}else if(argc==3){
	N=atoi(argv[1]);
	dureeT=atoi(argv[2]);
}else if(argc==2){
	N=atoi(argv[1]);
}else{
printf("Vous devez au moins donner le nombre de joueurs\n");
exit(EXIT_FAILURE);
}
if(N==0){
printf("Vous devez au moins donner un joueurs\n");
exit(EXIT_FAILURE);
}

tubes=( int *)malloc(2*N*sizeof(int));
pids=( int *)malloc(N*sizeof(int));
struct sigaction sa;

for(i=0;i<N;i++)
if( pipe(&tubes[2*i])==-1){
printf("erreur de creation de tubes\n");
exit(EXIT_FAILURE);}

int j;
for(pro=0;pro<N;pro++)
if((pids[pro]=fork())==0) 
{

memset(&sa,0,sizeof(struct sigaction));
sa.sa_handler=Annoncer;
sigaction(SIGUSR1,&sa,NULL);
jouer(pro);
}
sleep(1);
printf("Le pere lance le jeu \n");

memset(&sa,0,sizeof(struct sigaction));
sa.sa_handler=diffuserAlarme;
sigaction(SIGALRM,&sa,NULL);


alarm(dureeT);
if(write(tubes[2*N-1],&i,1)!=1){
perror("write");
exit(0);
}

pause();
}




