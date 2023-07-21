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
  
  
  fd = open(argv[1],O_RDONLY);
   
  if(fd == -1)
  {
    printf("Unable to open file! \n");
    return -1;
  }
  
  read(fd,Buffer,sizeof(Buffer));
     printf("%s\n",Buffer);
  
  close(fd);
   return 0;
}
