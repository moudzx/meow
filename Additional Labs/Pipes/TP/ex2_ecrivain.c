#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
void main(int argc,char**argv){
int fd;
if(argc<3){
fprintf(stderr,"Using %s pipe_name message\n",argv[0]);
exit(1);
}
unlink(argv[1]);

if(mkfifo(argv[1],0777)<0){
perror("mkfifo");
exit(1);
}

if((fd=open(argv[1],O_WRONLY))<0){
perror("Open");
exit(1);
}
write(fd,argv[2],strlen(argv[2]));

close(fd);
}