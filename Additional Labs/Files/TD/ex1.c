#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char ** argv) {//./ex1 data.txt  7
int * tab, fd, N;

if(argc<3){
  fprintf(stderr,"Using :%s fileName elementsNumber\n",argv[0]);
  exit(EXIT_FAILURE);
}

N=atoi(argv[2]);

tab=(int*)malloc(N*sizeof(int));

puts("Entrer les elements du tableau:\n");
for(int i=0;i<N;i++){
  printf("tab[%d]?",i);
  scanf("%d",&tab[i]);
}

fd=open(argv[1],O_WRONLY|O_CREAT,0724);
if(fd<0){
  perror("Open");
  exit(EXIT_FAILURE);
}

for(int i=0;i<N;i++)
  write(fd,&tab[i],sizeof(int));

close(fd);

return EXIT_SUCCESS;
}
