#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<unistd.h>
#include<time.h>

void printPermission(mode_t mode){

printf("%c",(mode&S_IRUSR?'r':'-'));
printf("%c",(mode&S_IWUSR?'w':'-'));
printf("%c",(mode&S_IXUSR?'x':'-'));


printf("%c",(mode&S_IRGRP?'r':'-'));
printf("%c",(mode&S_IWGRP?'w':'-'));
printf("%c",(mode&S_IXGRP?'x':'-'));	


printf("%c",(mode&S_IROTH?'r':'-'));
printf("%c",(mode&S_IWOTH?'w':'-'));
printf("%c",(mode&S_IXOTH?'x':'-'));	
}


void printType(mode_t mode){
if(S_ISREG(mode))
printf("-");
else
	if(S_ISLNK(mode))
printf("l");
else
	if(S_ISDIR(mode))
printf("d");
else
	if(S_ISCHR(mode))
printf("c");
else
	if(S_ISBLK(mode))
printf("b");
else
	if(S_ISFIFO(mode))
printf("f");
else
	if(S_ISSOCK(mode))
printf("s");

	
	
}
void printInfos(struct stat *stFile){
	
printf(" %d ",(int)stFile->st_ino);
printType(stFile->st_mode);
printPermission(stFile->st_mode);
printf(" %d ",(int)stFile->st_nlink);

printf(" %d ",(int)stFile->st_uid);
printf(" %d ",(int)stFile->st_gid);
printf(" %d ",(int)stFile->st_size);
printf(" %d ",(int)stFile->st_blksize);
printf(" %d ",(int)stFile->st_blocks);

struct tm* at;
at=localtime(&(stFile->st_atime));
printf("%d/%d/%d\n",at->tm_mday,(at->tm_mon+1),(at->tm_year+1900));
	
}

void main(int argc, char**argv){
	
if(argc<2){
	fprintf(stderr,"Use : %s fileName\n",argv[0]);
	/*char buf[64];
	int n=sprintf(buf,"Use : %s fileName\n",argv[0]);
	write(2,buf,n);
	//write(STDERR_FILENO,buf,n);
	*/
	exit(1);
}
struct stat st;
	for(int i=1;i<argc;i++){
	if(lstat(argv[i],&st)<0){
	perror("LSTAT");
	exit(2);
}
	printf("%s:\n",argv[i]);
	printInfos(&st);
}
}
