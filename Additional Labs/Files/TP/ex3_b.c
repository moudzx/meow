#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

void main(int argc, char**argv){
	
if(argc<3){
	fprintf(stderr,"Use : %s fileNameSrc fileNameDest\n",argv[0]);
exit(1);
}
int fds= open(argv[1],O_RDONLY);

if(fds<0){
	perror("Open source file");
	exit(1);
}

int fdd= open(argv[2],O_WRONLY|O_CREAT,0777);

if(fdd<0){
	perror("Open destination file");
	exit(2);
}

char c;
	while(read(fds,&c,1)>0)
		write(fdd,&c,1);
close(fds);
close(fdd);
}