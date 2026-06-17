#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main (void)
{
FILE * fp;

char chaine[27];

fprintf(stdout, "Création fichier\n");

fp = fopen("essai.unlink", "w+");

if (fp == NULL) {
perror("fopen");
exit(EXIT_FAILURE);
}

fprintf(fp, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");

fflush(fp);

system("ls -l essai.unlink");

fprintf(stdout, "Effacement fichier\n");

if (unlink("essai.unlink") < 0) {
perror("unlink");
exit(EXIT_FAILURE);
}

system("ls -l essai.unlink");

fprintf(stdout, "Relecture du contenu du fichier\n");

if (fseek(fp, 0, SEEK_SET) < 0) {
perror("fseek");
exit(EXIT_FAILURE);
}

if (fgets(chaine, 27, fp) == NULL) {
perror("fgets");
exit(EXIT_FAILURE);
}

fprintf(stdout, "Lu : %s\n", chaine);

fprintf(stdout, "Fermeture fichier\n");

fclose(fp);

return EXIT_SUCCESS;
}