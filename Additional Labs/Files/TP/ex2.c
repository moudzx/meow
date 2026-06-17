#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
void main(int argc, char**argv){
	
if(argc<2){
	fprintf(stderr,"Use : %s fileName\n",argv[0]);
exit(1);
}

int fd=open(argv[1],O_CREAT|O_EXCL,0777);
if(fd<0){
perror("open:");
printf("%d\n",errno);
exit(1);	
}

}
