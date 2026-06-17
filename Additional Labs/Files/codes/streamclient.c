/* Usage : streamclient /usr/local/mysock "Hello World !" */
#include <sys/types.h>
#include <sys/socket.h>
#include<string.h>
main(int argc, char *argv[]) {
int sd; int len;
struct sockaddr_un serveraddr;
sd=socket(AF_INET, SOCK_STREAM,0);
serveraddr.sun_family=AF_UNIX;
strcpy(argv[1], serveraddr.sun_path, sizeof(argv[1]));
if(connect(sd, (sockaddr *)&serveraddr, sizeof(serveraddr)) <0) exit();
len=strlen(argv[2]); write(sd, &len, sizeof(len));
write(sd, argv[2], len);
close(sd);
}