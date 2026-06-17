#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>
#include<time.h>

void main() {
for(int i = 1; i < 5; i++) {
  int face = random() % 6 + 1;
  printf("%d\t", face);
  }
printf("\n");
srand(getpid());
if(fork()) {
  if(fork()) {
    int t1 = time(NULL);
    wait(NULL);
    wait(NULL);
    int t2 = time(NULL);
    printf("Total time : %d\n", (t2 - t1));
    } else {
    sleep(random() % 10 + 1);
    }
  } else {
  sleep(random() % 10 + 1);
  }
}
