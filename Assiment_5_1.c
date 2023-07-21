#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

#pragma pack(1)
struct Student
{
    int Rollno;
    char Sname[20];
    float Marks;
    int Age;
};

int main(int argc, char *argv[])
{
    struct Student sobj;
    int fd = 0;

    sobj.Rollno = 11;
    sobj.Marks = 89.99f;
    sobj.Age = 25;
    strcpy(sobj.Sname,"Rahul");

    if(argc != 2)
    {
      printf("Insuficent Argument \n");
      return -1;
    }

    fd = creat(argv[1],0777);

    write(fd,&sobj,sizeof(sobj));

    return 0;
}
