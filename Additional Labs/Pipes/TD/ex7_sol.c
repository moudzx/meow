#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include<stdio.h>
static int n = 0;

void erreur(const char *errmess)
{
  perror(errmess); 
  exit(EXIT_FAILURE);
}

void interruption(int signum)
{
  switch(signum)
    {
    case SIGINT :
      printf("[%d] No choisi : %d\n",getpid(),n);
      break;
    case SIGPIPE :
      fprintf(stderr,"[%d] ecriture dans un tube sans lecteurs.\n",  getpid());
	//erreur("SIGPIPE");      
	break ;
    }
  exit(EXIT_SUCCESS);
}
  
void init_iteration(int d_ecriture)
{
  write(d_ecriture,&n,sizeof(int));
}

void iteration(int d_lecture, int d_ecriture)
{
  while(1){ 
    read(d_lecture,&n,sizeof(int));
    n++;
    write(d_ecriture,&n,sizeof(int));
  }
}

int main(void)
{
  int pf[2],fp[2]; /* Communication bidirectionnelle */
  struct sigaction action;
  action.sa_flags=0;
  sigemptyset(&action.sa_mask);
      
  if(pipe(pf) == -1 || pipe(fp) == -1 )
    erreur("pipe");
  
  switch(fork())
    {
    case -1:
      erreur("fork");
    case 0 : /* Fils */
      action.sa_handler=SIG_IGN; 
      sigaction(SIGINT,&action,NULL);    
      action.sa_handler=interruption;
      sigaction(SIGPIPE,&action,NULL);
      close(fp[0]);close(pf[1]); 
      iteration(pf[0],fp[1]);
    default : /* Père */
      action.sa_handler=interruption;
      sigaction(SIGINT,&action,NULL);
      close(pf[0]); close(fp[1]);
      init_iteration(pf[1]);
      iteration(fp[0],pf[1]);
    }
  exit(EXIT_SUCCESS);
}


