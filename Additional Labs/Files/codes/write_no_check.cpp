/*
 * Exemples du cours de programmation système de Sébastien Paumier
 *
 * Copyright (C) 2010 Université Paris-Est Marne-la-Vallée <paumier@univ-mlv.fr>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/* A tester avec un chmod 0 qui ne bloque pas l'exécution, pas plus qu'un unlink */
int main(int argc,char* argv[]) {
if (argc!=2) return 1;
int fd=open(argv[1],O_WRONLY|O_CREAT|O_TRUNC,0777);
if (fd==-1) {
	perror("open");
	return 1;
}
char c='$';
while (1) {
	if (1!=write(fd,&c,1)) break;
	sleep(1);
}
close(fd);
return 0;
}
