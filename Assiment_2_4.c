#include<stdio.h>
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>
#include<string.h>
#pragma pack(1)

int main(int argc,char *argv[])
{
  char name[255];
  DIR *dp = NULL;
  struct dirent *status =NULL;
  struct stat sobj;
  
  if(argc != 2)
  {
     printf("Envalid Argument Pass !\n");
     return -1;
  }
  
  dp = opendir(argv[1]);
  
  if(dp == NULL)
  {
    printf("Unable to open directory\n");
    return -1;
  }
  
  while((status = readdir(dp)) != NULL)
  {
    sprintf(name,"%s/%s",argv[1],status->d_name);
      stat(name,&sobj);
       printf("file name : %s and type of Directory : %d \n",status->d_name,sobj.st_mode);
  }
  
   closedir(dp);
   return 0;
}
