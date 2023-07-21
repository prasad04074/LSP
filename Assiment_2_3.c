#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<dirent.h>

int main(int argc,char *argv[])
{
  DIR *dp = NULL;
  struct dirent *status =NULL;
  
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
    printf("%10s\n",status->d_name);
  }
  
   closedir(dp);
   return 0;
}
