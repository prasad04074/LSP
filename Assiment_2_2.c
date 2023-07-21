#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

#define BLOCKSIZE 1024

int main(int argc,char *argv[])
{
  int fd = 0;
  int Ret = 0;
  char Buffer[BLOCKSIZE];
  
  if(argc != 2)
  {
     printf("Envalid Argument Pass !\n");
     return -1;
  }
  
  
  fd = open(argv[1],O_WRONLY);
   
  if(fd == -1)
  {
    printf("Unable to open file! \n");
    return -1;
  }
  
   
  write(1,"Hello word !",Ret);
  
  close(fd);
   return 0;
}
