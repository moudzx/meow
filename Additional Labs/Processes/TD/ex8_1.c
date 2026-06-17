#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>

void main() {
if(!fork()) {
  execlp("who", "who", NULL);
  }
if(!fork()) {
  execlp("ps", "ps", NULL);
  }
execlp("ls", "ls", "-l", NULL);
}
