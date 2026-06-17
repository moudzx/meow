#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>

#include<sys/stat.h>

int main(int argc, char*argv[]){//./ex1_b fileName
int fd,i,*tab,N;

if(argc<2){
fprintf(stderr,"Using :%s fileName \n",argv[0]);
exit(EXIT_FAILURE);
}


fd=open(argv[1],O_RDONLY);
if(fd<0){
perror("Open");
exit(EXIT_FAILURE);
}

//first method
N=(lseek(fd,0,SEEK_END))/4;
printf("file size with lseek is %d\n",N);
lseek(fd,0,SEEK_SET);
/*
//second method
N=0;
int v;
while(read(fd,&v,sizeof(int))>0)
N++;
printf("file size with read %d\n",N);

//third method
struct stat st;
if(fstat(fd,&st)<0){
perror("stat");
exit(EXIT_FAILURE);
}
N=st.st_size/4;
printf("file size with stat %d\n",N);
*/

tab=(int *)malloc(N*sizeof(int));

i=0;
while(read(fd,&tab[i],sizeof(int))>0)
i++;
/*
//2nd method
for(i=0;i<N;i++)
read(fd,&tab[i],sizeof(int))
*/
close(fd);
printf("les elements sont :\n");

for(i=0;i<N;i++)
printf("%4d",tab[i]);
printf("\n");
return 0;
}

