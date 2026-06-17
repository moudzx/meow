#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<signal.h>
void main(){
char c[26] = "abcdefghijklmnopqrstuvwxyz";
int pid;
switch(pid = fork()) {
case -1: perror("fork");
exit(EXIT_FAILURE); break;
case 0:
for(int i = 0; i <26;i+=2) {
  printf("child: %c\n", c[i]);
  kill(getppid(),SIGCONT);
  raise(SIGSTOP);
}
break;
default: 
for(int i = 1; i <26;i+=2) {
  raise(SIGSTOP);
  printf("parent: %c\n", c[i]);
  kill(pid,SIGCONT);
}
}
}
