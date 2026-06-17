#include "data.h"

void main(int argc,char**argv){
int fd,fd1,n;
Donnees mes;
unlink(PIPE);

	if(mkfifo(PIPE,0777)<0){
	perror("mkfifo");
	exit(1);
	}

	if((fd1=open("data.txt",O_WRONLY|O_CREAT|O_TRUNC,0777))<0){
	perror("Open");
	exit(1);
	}


do{
	if((fd=open(PIPE,O_RDONLY))<0){
	perror("Open");
	exit(1);
	}
	read(fd,&mes,sizeof(Donnees));
	printf("%s-%d\n",mes.message,mes.pid_client);
	if(strcmp("FIN",mes.message)!=0)
	{strcat(mes.message,"\n");	
	write(fd1,mes.message,strlen(mes.message));
	}	
	
	close(fd);
}while(strcmp("FIN",mes.message)!=0);
close(fd1);
}