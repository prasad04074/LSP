#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>

#pragma pack(1)

#define BLOCKSIZE 1024

int main(int argc,char *argv[])
{
  int fd = 0;
  int Ret = 0;
  char Buffer[BLOCKSIZE] = {'\0'};
  
  if(argc != 3)
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
  
  Ret = read(fd,Buffer,atoi(argv[2]));
  
  if(Ret == 0)
  {
    printf("Unable to Read data from file\n");
    return -1;
  }
  
  printf("data from file is %s\n",Buffer);  

  close(fd);
   return 0;
}
