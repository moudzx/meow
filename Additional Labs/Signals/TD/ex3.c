#include<stdio.h>
#include<unistd.h>
#include<signal.h>
#include<stdlib.h>

 int nb_children;
 pid_t* children;
 
 void allouer(){pause();}
 void donothing(int s){}
 void  ustiliserresource(){
	 printf("[%d] je vais utiliser la ressource\n",getpid());
	 sleep(2);
	 printf("[%d] vient de terminer l'utilisation\n",getpid());
 }
 
 void liberer(int proc){
	 int p;
	p= (proc==0?nb_children:proc-1);
	 kill(children[p],SIGUSR1);
	}
 void work( int proc){
	 
	 while(1){
		 allouer();
		 ustiliserresource();
		 liberer(proc);
	 }
	 
 }
 
 void main(){
	 signal(SIGUSR1,donothing);
	 printf("Enter le nombre de fils");
	 scanf("%d",&nb_children);
	 children=(pid_t*) malloc(nb_children*sizeof(pid_t));
	 children[0]=getpid();
	 
	 for(int i=1;i<=nb_children;i++)
		if((children[i]=fork())==0)
			work(i);
		
		for(int i=0;i<=nb_children;i++)
			printf("%d\t",children[i]);
		
		printf("\n");
		
	sleep(1);	
		kill(children[nb_children],SIGUSR1);
		work(0);
 }