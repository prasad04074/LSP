#include<stdio.h>
#include<fcntl.h>
#include<string.h>

int main(int argc,char *argv[])
{
  int fd = 0;
  int Mode = 0;
  if(argc != 3)
  {
     printf("Envalid Argument Pass !\n");
     return -1;
  }
  
  if(strcmp(argv[2],"help") == 0)
  {
    printf("Enter 2 argument is 'Read' to open file read mode and pass the 'Write' the open write mode\n");
  }
  else if(strcmp(argv[2],"Read") == 0)
  {
    Mode = O_RDONLY; 
  }
  else if(strcmp(argv[2],"Write") == 0)
  {
    Mode = O_WRONLY;
  }
  else
  { 
    Mode = O_RDONLY;
  }
  fd = open(argv[1],Mode);
   
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
