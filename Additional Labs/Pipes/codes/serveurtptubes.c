#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<fcntl.h>
typedef struct {
pid_t pid;
char text[128];
} Message;

void main(int argc,char**argv){
int fd;
Message m;

if(mkfifo(argv[1],0666)<0){
perror("mkfifo");
exit(EXIT_FAILURE);
}

if((fd=open(argv[1],O_RDONLY))<0){
perror("Open");
exit(EXIT_FAILURE);}
int n;
do{
n=read(fd,&m,sizeof(Message));
if(n!=0)
printf("%s + %d \n",m.text,m.pid);
}while(1);
}