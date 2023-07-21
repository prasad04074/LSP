#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

int main(int argc, char *argv[])
{
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char name[30];
    struct stat sobj;
    char namecopy[30] = {'\0'};
    char Buffer[1024] = {'\0'};
    int iMax = 0;
    int fd = 0;

    if(argc != 2)
    {
      printf("Insuficent argument \n");
      return -1;
    }

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
        if(S_ISREG(sobj.st_mode))
        {
             fd = open(name,O_RDONLY);

              read(fd,Buffer,sizeof(Buffer));
              
              printf("Data of File is : %s\n\n",Buffer);
        }
    }

    closedir(dp);
    
    return 0;
}
