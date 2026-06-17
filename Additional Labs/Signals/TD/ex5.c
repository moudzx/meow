#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>
#define N 5

void handler(int s){
	if(s==SIGUSR1)
		pause();
	
}
void main(){
	signal(SIGUSR1,handler);
	signal(SIGUSR2,handler);
	pid_t fils[N];
	
	for(int i=0;i<N;i++)
		if((fils[i]=fork())==0)
		while(1);

	
		char answer;
		int child;
		do
		{		
		printf("Enter the number of child");
		scanf("%d",&child); getchar();
		printf("Enter:\n");
		printf("s - pour endormir mon fils\n");
		printf("r - pour reveiller mon fils\n");
		printf("q - pour tuer mon fils\n");
		printf("e - pour exit\n");
		scanf("%c",&answer); getchar();
		switch(answer){
			case 's': kill(fils[child],SIGUSR1);   break;
			case 'r': kill(fils[child],SIGUSR2);   break;
			case 'q':  
printf("I am the child [%d], I finished my work\n",getpid());
			kill(fils[child],9);   break;
			case 'e': 
			printf("I am the parent [%d], I finished my work\n",getpid());
			exit(0);
			default:
			printf("Invalid choice\n");
			}
		}
		while(1);

	
	}
