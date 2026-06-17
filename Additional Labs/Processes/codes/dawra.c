#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
void play(int n) {
  printf("I am player %d\n", n);

  exit(n); }

void main(){
  int max = 4;
  for(int i =0; i <max; i++) 
    if(fork()==0) {
      sleep(1);
      play(i);}
while(1) {
int status;
wait(&status);
if(WIFEXITED(status)) {
if(fork()==0) {
  sleep(1);
  play(WEXITSTATUS(status)); }
} 
}
}
