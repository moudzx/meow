#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>

int nbdiv(int num) {
  if(num == 1 || num == 2) return 1;
  int d = 2;
  int div = 1;
  while(d <= num/2) {
    if(num%d==0) div++;
    d++;
    }
  return div; }

void main(int argc, char ** argv){
if(argc < 3) {
  fprintf(stderr, "use %s nb1 nb2 ...\n",argv[0]);
  exit(0);
}
int tube[2];
int nb1 = atoi(argv[1]);
int big = nbdiv(nb1);
int fnb;
if(pipe(tube)==-1) {
  perror("pipe");
  exit(0);
}
for(int i = 2; i < argc; i++) {
  if(fork()==0) {
    close(tube[0]);
    int num = atoi(argv[i]);
    int divs = nbdiv(num);
    write(tube[1],&divs,sizeof(int));
    exit(0);
  }
}
close(tube[1]);
for(int i = 2; i < argc; i++) {
  read(tube[0],&fnb,sizeof(int));
  if(fnb > big){ big = fnb; nb1 = atoi(argv[i]);}
}
printf("biggest divisors is %d\n",nb1);
}
