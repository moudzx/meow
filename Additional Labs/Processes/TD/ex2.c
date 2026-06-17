#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/wait.h>

void copiell(char * src, char * dest) {
int fdsrc, fddest;
char buf[32];
int n;
if ((fdsrc = open(src, O_RDONLY)) < 0) {
  perror("open src");
  exit(1);
  }
if ((fddest = open(dest, O_WRONLY | O_CREAT, 0777)) < 0) {
  perror("open dest");
  exit(1);
  }
while ((n = read(fdsrc, buf, sizeof(buf))) > 0)
  write(fddest, buf, n);
close(fddest);
close(fdsrc);
}

void copiesystem(char * src, char * dest) {
char buf[64];
sprintf(buf, "cp %s %s", src, dest);
system(buf);
}

void copiexec(char * src, char * dest) {
execlp("cp", "cp", src, dest, NULL);
}

void main(int argc, char ** argv) {
if(argc < 3) {
  fprintf(stderr, "use %s src-file dest-file\n", argv[0]);
  exit(1);
  }
int i;
for(i = 2; i < argc; i++) {
  if(fork() == 0) {
    copiell(argv[1], argv[i]);
    // copiesystem(argv[1], argv[i]);
    // copiexec(argv[1], argv[i]);
    exit(i);
    }
  }
int status;
pid_t pid;
for(i = 2; i < argc; i++) {
  pid = wait(&status);
  if(WIFEXITED(status))
    printf("The child No %d of pid %d is finish the copie of file %s\n",
      WEXITSTATUS(status), pid, argv[WEXITSTATUS(status)]);
  }
printf("Mission Done!\n");
}
