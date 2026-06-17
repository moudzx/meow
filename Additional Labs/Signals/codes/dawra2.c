#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

void main(){
char c[26] = "abcdefghijklmnopqrstuvwxyz";
int pf[2], fp[2];
char x = '.';
if(pipe(pf)==-1 || pipe(fp)==-1) {
perror("pipe");
exit(EXIT_FAILURE);
}
switch(fork()) {
case -1: perror("fork");
exit(EXIT_FAILURE); break;
case 0:
close(pf[1]); close(fp[0]);
for(int i = 0; i <26;i+=2) {
  printf("child: %c\n", c[i]);
  write(fp[1],&x,1);
  read(pf[0],&x,1);
}
break;
default: close(fp[1]); close(pf[0]);
for(int i = 1; i <26;i+=2) {
  read(fp[0],&x,1);
  printf("parent: %c\n", c[i]);
  write(pf[1],&x,1);
}
}
}
