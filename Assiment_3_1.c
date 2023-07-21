#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

#define BLOCKSIZE 1024

int main(int argc,char *argv[])
{

  int fdSourse = 0;
  int fdDest = 0;
  int Ret = 0;
  
  char Buffer[BLOCKSIZE] = {'\0'};
  
  if(argc != 3)
  {
     printf("Insufficient argument\n");
     return -1;
  }
  
  fdSourse = open(argv[1],O_RDONLY);
  
  if(fdSourse == -1)
  {
     printf("Unable to open source file\n");
     return -1;
  }
  
  fdDest = open(argv[2],O_WRONLY);
  
  if(fdDest == -1)
  {
     printf("Unable to create desrination file\n");
     close(fdSourse);
     return -1;
  }

  while((Ret = read(fdSourse,Buffer,sizeof(Buffer))) != 0)
  {
     write(fdDest,Buffer,Ret);
     memset(Buffer,0,sizeof(Buffer));
  }
  
  close(fdSourse);
  close(fdDest);
  
  return 0;
}
