#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>
int pf[2],fp[2],pid,fd,size,rep;
char*text,mot[50],*token;

void chercher(){
int n=read(fp[0],mot,50);

fd=open("data.txt",O_RDONLY);
if(fd<0){
	perror("open data");
 exit(0);
 }
size=lseek(fd,0,SEEK_END);
lseek(fd,0,SEEK_SET);

text=(char*)malloc(size*sizeof(char));
read(fd,text,size);

token=strtok(text," \n");

while(token!=NULL){

printf("%s = %s\n",token,mot);
if(strcmp(token,mot)==0){
rep=1; 
break;
}
token=strtok(NULL," \n");
}
if(token==NULL) rep=0;

write(pf[1],&rep,sizeof(int));
wait(NULL);
close(pf[1]); 
close(fp[0]);
exit(EXIT_SUCCESS);
}
void fils(){ 
puts("Donner le mot a chercher");
scanf("%s",mot);
write(fp[1],mot,strlen(mot));
read(pf[0],&rep,sizeof(int));
if(rep)
puts("Le mot existe dans le fichier");
else
puts("Le mot n'existe pas dans le fichier");
}

void main(){
if(pipe(pf)<0 || pipe(fp)<0){
	perror("pipe"); 
exit(EXIT_FAILURE);}
pid=fork();
if(pid==-1){
	perror("fork"); exit(EXIT_FAILURE);}
if(pid==0){
close(pf[1]); 
close(fp[0]);
fils();
}
else {
	close(pf[0]); 
close(fp[1]);
chercher();
}
}