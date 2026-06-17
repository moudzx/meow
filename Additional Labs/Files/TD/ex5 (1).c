#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
int main(int argc,char**argv){
int fds,fdd,x;
char buf[256];//any power of 2

if(argc<2){
fprintf(stdout,"Using : %s fileName\n",argv[0]);
exit(EXIT_FAILURE);
}
if(arc==2)
{
	if((fds=open(argv[1],O_RDONLY))<0){
	perror("Open");
	exit(EXIT_FAILURE);
	}
}
	
if(argc==3){
				if(strcmp("+",argv[2])==0){
				  if((fdd=open(argv[3],O_WRONLY|O_CREAT|O_TRUNC,0666))<0){
					perror("Open");
					exit(EXIT_FAILURE);
					} 
				//while((x=read(fds,buf,256))>0)
				//write(fdd,buf,x);//le meilleur
				//close(1);
				//dup(fdd);
				dup2(fdd,1);
				close(fdd);

			}
		else
			if(strcmp("++",argv[2])==0){
				if((fdd=open(argv[3],O_WRONLY|O_CREAT|O_APPEND,0666))<0){
					perror("Open");
					exit(EXIT_FAILURE);
					} 
				//while((x=read(fds,buf,256))>0)
				//write(fdd,buf,x);//le meilleur
				dup2(fdd,1);
				close(fdd);
			}
			else {
				fprintf(stderr,"using %s fileName +[++] filename\n",argv[0]);
				exit(EXIT_FAILURE);
			}
	fds=STDIN_FILENO;
}
	
	while((x=read(fds,buf,256))>0)
	write(STDOUT_FILENO,buf,x);//le meilleur
close(fds);
//close(fdd);
}