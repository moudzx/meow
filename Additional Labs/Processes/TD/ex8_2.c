#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>

void main() {
if(!fork()) {
  execlp("who", "who", NULL);
  wait(NULL);
  }
if(!fork()) {
  execlp("ps", "ps", NULL);
  wait(NULL);
  }
 execlp("ps", "ps", "-l",NULL);
}
