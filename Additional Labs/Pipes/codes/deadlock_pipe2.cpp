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

int main(int argc,char* argv[]) {
int father2child[2];
int child2father[2];
if (-1==pipe(father2child) || -1==pipe(child2father)) {
	perror("pipe");
	exit(1);
}
switch(fork()) {
case -1: perror("fork"); exit(1);
case 0: {
	/* I've read my lessons and I know I must close
	 * the pipe sides I don't use */
	close(father2child[1]);
	close(child2father[0]);
	char c;
	/* Trying in vain to read from my father that did not write */
	read(father2child[0],&c,1);
	break;
}
default: {
	close(father2child[0]);
	close(child2father[1]);
	char c;
	/* Trying in vain to read from my child that did not write */
	read(child2father[0],&c,1);
	break;
}
}
return 0;
}
