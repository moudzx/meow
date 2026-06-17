#include "lib.h"


void main(int argc,char**argv){
Message m;
int fd;
if((fd=open(argv[1],O_WRONLY))<0){
perror("Open");
exit(EXIT_FAILURE);}

do{
puts("Donner votre message");
gets(m.message);
m.pidClient=getpid();
write(fd,&m,sizeof(Message));
//getchar();
}while(strcmp(m.message,"Fin")!=0);
close(fd);
}
