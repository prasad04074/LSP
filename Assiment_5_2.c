#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>

#pragma pack(1)
struct Student
{
    int EMPID;
    char EMPname[20];
    float EMPSalary;
    int EMPAge;
};

int main(int argc, char *argv[])
{
    struct Student sobj;
    int fd = 0;

  if(argc != 2)
  {
    printf("Insuficent argument \n");
    return -1;
  }

    fd = open(argv[1],O_RDONLY);

    read(fd,&sobj,sizeof(sobj));

    printf("Employee ID : %d : \n",sobj.Rollno);
    printf("Employee Name : %s : \n",sobj.Sname);
    printf("Salary : %f : \n",sobj.Marks);
    printf("Employee Age : %d : \n",sobj.Age);

    close(fd);

    return 0;
} 
