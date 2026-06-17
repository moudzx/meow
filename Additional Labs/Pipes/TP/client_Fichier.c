#include "data.h"

void main(int argc,char**argv){
int fd,fd1,n;
Donnees mes;

if(argc<3){
fprintf(stderr,"Using %s pipe_name message\n",argv[0]);
exit(1);
}

	if((fd=open(PIPE,O_WRONLY))<0){
	perror("Open");
	exit(1);
	}

	mes.pid_client=getpid();
	strcpy( mes.message,argv[2]);
	write(fd,&mes,sizeof(Donnees));
	close(fd);


}