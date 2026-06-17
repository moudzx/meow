#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
int n;
char buffer[100];

int main (int argc, char ** argv){

int fd_write;

if(mkfifo(argv[1],S_IRUSR|S_IWUSR)==-1){//creer un tube nommé
perror("mkfifo");
exit(1);}

if ((fd_write=open(argv[1],O_WRONLY))==-1){
perror("open");
exit(2);
}
if((n=write(fd_write,"BONJOOUR",8))==-1){
perror("write");
exit(3);
}
close(fd_write);
}