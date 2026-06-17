#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc, char**argv){// int main()
int cpt=0,desc;

while ((desc= dup(1))>0)
{
printf("%d\n",desc);
cpt++;
}
printf("The maximum number of files that a process can open in the same time is %d\n",cpt);


}