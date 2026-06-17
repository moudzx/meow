#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc,char**argv){
int fd,x;
char buf[256];//any power of 2

if(argc<2){
fprintf(stdout,"Using : %s fileName\n",argv[0]);
exit(EXIT_FAILURE);
}

if((fd=open(argv[1],O_RDONLY))<0){
perror("Open");
exit(EXIT_FAILURE);
}

while((x=read(fd,buf,256))>0){
//write(1,buf,x);
//write(STDOUT_FILENO,buf,x);//le meilleur
buf[x]='\0';
printf("%s",buf);
}

close(fd);
}