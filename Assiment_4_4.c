#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<dirent.h>
#include<sys/stat.h>

#pragma pack(1)
struct FileInfo
{
    char FileName[20];
    int FileSize;
};

int main(int argc, char *argv[])
{
    char DirName[20];
    DIR *dp = NULL;
    struct dirent *entry = NULL;
    char name[30];
    struct stat sobj;
    char namecopy[30] = {'\0'};
    int iMax = 0;
    struct FileInfo fobj;
    char Buffer[1024];
    int fd = 0;
    int fd1 = 0,ret = 0;

    /*printf("Enter name of directory : \n");
    scanf("%s",DirName);*/

    dp = opendir(argv[1]);
    if(dp == NULL)
    {
        printf("Unable to open directory\n");
        return -1;
    }

    fd = creat("FIleExtract.txt",0777);

    while((entry = readdir(dp)) != NULL)
    {
        sprintf(name,"%s/%s",argv[1],entry->d_name);
        stat(name,&sobj);
        if(S_ISREG(sobj.st_mode))
        {
            fd1 = open(fobj.FileName,O_RDONLY);
             ret = read(fd1,Buffer,10);
            write(fd,&fobj,10);
        }
    }

    closedir(dp);
    
    return 0;
}
