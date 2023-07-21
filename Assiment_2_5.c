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
    
    dp = opendir(argv[1]);
    
    if(dp == NULL)
    {
       printf("Unable to open directory\n");
       return -1;
    }
    
    while((entry = readdir(dp)) != NULL)
    {
      sprintf(name,"%s/%s",argv[1],entry->d_name);
      stat(name,&sobj);
      
         if(iMax < sobj.st_size)
         {
           iMax = sobj.st_size;
           strcmp(namecopy,name);
           
         }
    }
    printf("File name : %s  : File Size : %d \n",namecopy,iMax);
    closedir(dp);
   return 0;
}
