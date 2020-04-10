#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<sys/wait.h>
int main()
{
   char read_msg[10];
   int fd[2];
   pid_t p;
   if(pipe(fd)==-1)
   {
      fprintf(stderr,"pipe failed");
      return 1;
   }
   p=fork();
   if(p<0)
   {
      fprintf(stderr,"fork failed!");
      return 1;
   }
   if(p>0)//parent process
   {
    wait(NULL);
    read(fd[0],read_msg,8);
    close(fd[1]);
    printf("%s",read_msg);
    close(fd[0]);
   }
   else//child process
   {
      close(fd[0]);
      write(fd[1],"Hey there!Whatsapp is using me",8);
      close(fd[1]);
   }
}
