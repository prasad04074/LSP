#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
#include<sys/stat.h>

int main(int argc,char *argv[])
{
   struct stat sobj;

  if(argc != 2)
  {
     printf("Envalid Argument Pass !\n");
     return -1;
  }
  
  stat(argv[1],&sobj);
  
    printf("File name : %s\n",argv[1]);
    printf("File size of : %d\n",sobj.st_size);
    printf("Number of link : %d\n",sobj.st_nlink);
    printf("Inode number : %d\n",sobj.st_ino);
    printf("File system number : %d\n",sobj.st_dev);
    printf("Number of block : %d\n",sobj.st_blocks);
    printf("Mode of file : %d\n",sobj.st_mode);

   return 0;
}
