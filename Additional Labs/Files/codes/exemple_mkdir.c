
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
int main (void)
{
fprintf(stderr, "Création repertoire mode rwxrwxrwx : ");
if (mkdir("repertoire", 0777) != 0) {
perror("");
exit(EXIT_FAILURE);
} else {
fprintf(stderr, "Ok\n");
}
system("ls -ld repertoire");
fprintf(stderr, "Suppression repertoire : ");
if (rmdir("repertoire") != 0) {
perror("");
exit(EXIT_FAILURE);
} else {
fprintf(stderr, "Ok\n");
}
fprintf(stderr, "Modification umask\n");
umask(0);
fprintf(stderr, "Création repertoire mode rwxrwxrwx : ");
if (mkdir("repertoire", 0777) != 0) {
perror("");
exit(EXIT_FAILURE);
} else {
fprintf(stderr, "Ok\n");
}
system("ls -ld repertoire");
fprintf(stderr, "Suppression repertoire : ");
if (rmdir("repertoire") != 0) {
perror("");
exit(EXIT_FAILURE);
} else {
fprintf(stderr, "Ok\n");
}
return EXIT_SUCCESS;
}