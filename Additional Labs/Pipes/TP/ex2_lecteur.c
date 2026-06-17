#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>
#include<fcntl.h>
#include<sys/stat.h>
void main(int argc,char**argv){
int fd,n;
char message[100];
if(argc<2){
fprintf(stderr,"Using %s pipe_name \n",argv[0]);
exit(1);
}

if((fd=open(argv[1],O_RDONLY))<0){
perror("Open");
exit(1);
}
n=read(fd,message,100);
message[n]='\0';
printf("J'ai recu le message: %s\n ",message);
close(fd);
}