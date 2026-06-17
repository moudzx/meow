#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>

int row, col;

void main(int argc, char ** argv) {
if(argc < 3) {
  fprintf(stderr,"use %s nb-rows nb-cols\n",argv[0]);
  exit(0);
  }
int row = atoi(argv[1]);
int col = atoi(argv[2]);
int ** arr;
arr = (int **)malloc(row*sizeof(int));
for(int i = 0; i < row; i++)
{ arr[i] = (int *)malloc(col*sizeof(int));
  for(int j = 0; j < col; j++) {
  printf("arr[%d][%d]: ",i, j);
  scanf("%d",&arr[i][j]); 
}}
for(int i = 0; i < row; i++) {
  if(fork()==0) {
   int s = 0;
   for(int j = 0; j < col; j++)
      s += arr[i][j];
    exit(s);
    }
  }
int sum = 0;
int status;
for(int i = 0; i < row; i++) {
  wait(&status);
  if(WIFEXITED(status)){
    sum += WEXITSTATUS(status);
    }
  }
printf("sum = %d\n",sum);
}
