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
switch(fork()) {
case -1: perror("fork"); exit(1);
case 0: {
	int ppid=getppid();
	printf("My father has pid %d\n",ppid);
	while (ppid==getppid());
	printf("My father has now pid %d\n",getppid());
	exit(0);
}
default: {
	/* Father waits and then commits suicide; orphan is fathered by init */
	sleep(1);
	exit(0);
}
}
return 0;
}
