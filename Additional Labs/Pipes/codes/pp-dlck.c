#define BSIZE 1024

int main () {
int fdts[2], /* to son */ 
fdfs[2]; /* from son */
char bufr[BSIZE], bufw[BSIZE];
pipe(fdts); 
pipe(fdfs);
 switch (fork()) {
case -1: exit(EXIT_FAILURE);
case 0:
read(fdts[0], bufr, 1);
write(fdfs[1], bufw, 1); break;
default:
read(fdfs[0], bufr, 1);
write(fdts[1], bufw, 1);
}
prinf("bye\n");
 exit(EXIT_SUCCESS);
}
