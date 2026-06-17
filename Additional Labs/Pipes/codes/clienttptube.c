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
Message m;
int fd;
if((fd=open(argv[1],O_WRONLY))<0){
perror("Open");
exit(EXIT_FAILURE);}

do{
puts("Donner votre message");
gets(m.text);
m.pid=getpid();
write(fd,&m,sizeof(Message));
//getchar();
}while(strcmp(m.text,"Fin")!=0);
close(fd);
}
