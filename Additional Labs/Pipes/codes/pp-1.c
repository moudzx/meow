int  main  (int  argc,  char  *argv[])  { int  fds[2];
pipe(fds);
switch  (fork())  {
case  -1:  perror("fork");  exit(EXIT_FAILURE); 
case  0:
close(fds[1]);
dup2(fds[0],  STDIN_FILENO);
close(fds[0]);
execlp("grep",  "grep",  "a",  NULL); perror("exec");  
exit(EXIT_FAILURE);
default: 
 close(fds[0]);
dup2(fds[1],  STDOUT_FILENO);
close(fds[1]); 
execlp("cat",  "cat",  NULL);
perror("exec");  
exit(EXIT_FAILURE);
}
}
