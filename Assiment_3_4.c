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
    
    printf("Enter name of directory : \n");
    scanf("%s",DirName);
    
    dp = opendir(DirName);
    
    if(dp == NULL)
    {
       printf("Unable to open directory\n");
       return -1;
    }
    
    while((entry = readdir(dp)) != NULL)
    {
      sprintf(name,"%s/%s",DirName,entry->d_name);
      stat(name,&sobj);
       if(S_ISREG(sobj.st_mode))
       {
        if(sobj.st_size == 0)
        {
           printf("Empty file name : %s\n",name);
           remove(name);
        }
       }
    }
    closedir(dp);
   return 0;
}
