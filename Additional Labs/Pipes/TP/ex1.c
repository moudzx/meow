#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<signal.h>

void main(){
int tube[2];

if(pipe(tube)<0){
perror("Pipe");
exit(0);
}
char c='-';
int nblus;
close(tube[1]);
nblus=read(tube[0],&c,1);
printf("Jai lue %d caracteres qui sont %c \n",nblus,c);
}