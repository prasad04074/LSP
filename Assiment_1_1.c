#include<stdio.h>
#include<fcntl.h>

int main(int argc,char *argv[])
{
  int fd = 0;
  
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
  else
  {
    printf("File is Successfully open\n");
  }

  close(fd);
   return 0;
}