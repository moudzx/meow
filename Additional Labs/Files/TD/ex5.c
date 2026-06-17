#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
int main(int argc,char**argv){
int fds,fdd,x;
char buf[256];//any power of 2


if( argc<2 || argc >3){
	fprintf(stdout,"Using : %s  +[++] filename\n",argv[0]);
	exit(EXIT_FAILURE);
}
if(argc==2)
{
	if((fds=open(argv[1],O_RDONLY))<0){
	perror("Open");
	exit(EXIT_FAILURE);
	}
}
	
if(argc==3){
		if(strcmp("+",argv[1])==0){
				  if((fdd=open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,0666))<0){
					perror("Open");
					exit(EXIT_FAILURE);
					} 
				// 1rst method
				//while((x=read(fds,buf,256))>0)
				//write(fdd,buf,x);//le meilleur
				
				//2nd method
				//close(1);
				//dup(fdd);
				
				//3rd method
				dup2(fdd,1);
				close(fdd);

			}
		else
			if(strcmp("++",argv[1])==0){
				if((fdd=open(argv[2],O_WRONLY|O_CREAT|O_APPEND,0666))<0){
					perror("Open");
					exit(EXIT_FAILURE);
					} 
					// 1rst method
				//while((x=read(fds,buf,256))>0)
				//write(fdd,buf,x);//le meilleur
			
			//2nd method
				//close(1);
				//dup(fdd);
				
				//3rd method
				dup2(fdd,1);
				close(fdd);
			}
			else {
				fprintf(stderr,"using %s fileName +[++] filename\n",argv[0]);
				exit(EXIT_FAILURE);
			}
//	fds=STDIN_FILENO;  not necessary because by dfault fds is 0
}
	
	while((x=read(fds,buf,256))>0)
	write(STDOUT_FILENO,buf,x);//le meilleur

close(fds);
close(fdd);
}
