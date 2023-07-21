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
    char DirName[20];
    char name[30];
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    struct stat sobj;
    char namecopy[30] = {'\0'};
    int iMax = 0;
    
    if(argc != 2)
    {
      printf("Insuficent argument \n");
      return -1;
    }
    
    dp = mkdir(argv[1],0777);
    
    if(dp == 0)
    {
       printf("create directory successfully\n");
    }
    else
    {
      printf("Unable to create directory");
    }
    
    closedir(dp);
   return 0;
}
