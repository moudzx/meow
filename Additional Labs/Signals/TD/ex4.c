#include<stdio.h>
#include<signal.h>
#include<stdlib.h>
#include<unistd.h>

void main(){
	pid_t fils;
	if((fils=fork())==0)
		while(1){printf("M\n"); sleep(1);}
	else
	{
		char answer;
		do
		{		printf("Enter:\n");
		printf("s - pour endormir mon fils\n");
		printf("r - pour reveiller mon fils\n");
		printf("q - pour tuer mon fils\n");
		scanf("%c",&answer); getchar();
		switch(answer){
			case 's': kill(fils,SIGSTOP);   break;
			case 'r': kill(fils,SIGCONT);   break;
			
			
			case 'q':  kill(fils,9);   //kill(fils,SIGKILL);
			case 'e': exit(0);
			default:
			printf("Invalid choice\n");
			}
		}
		while(1);

	}
	}
