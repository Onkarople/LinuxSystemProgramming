#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{
    int fd=0;
    char *Buffer=NULL;
    int ret=0;
    //int size=0;

    if(argc!=3)
    {
        printf("Insufficient arguments");
        return -1;
    }

    fd=open(argv[1],O_RDONLY);
    if(fd==-1)
    {
        printf("Unable to open file\n");
        return -1;
    }


    //size=atoi(argv[2]);
    Buffer=(char *)malloc(atoi(argv[2])*sizeof(char));

    ret=read(fd,Buffer,atoi(argv[2]));
    if(ret==0)
    {
        printf("Unable to read data from file\n");
        return -1;
    }

    write(1,Buffer,ret);

    return 0;
}