#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<dirent.h>

int main(int argc,char *argv[])
{
    DIR *dp =NULL;
    struct dirent *entry=NULL;
    struct stat sobj; 
    char name[256];
    int iMax=0;
    char fname[50]={"\0"};

    
    if(argc!=2)
    {
        printf("Insufficient parameters");
        return -1;

    }

    dp=opendir(argv[1]);
    if(dp==NULL)
    {
        printf("Unable to open directory");
        return -1;
    }
   

    while((entry=readdir(dp))!=NULL)
    {
        
         sprintf(name,"%s/%s",argv[1],entry->d_name);
          stat(name,&sobj);
          if(S_ISREG(sobj.st_mode))
          {
           
            if(iMax<sobj.st_size)
            {
                iMax=sobj.st_size;
                strcpy(fname,name);
            }

          }
   }

   printf("Name of largest file is : %s with size %d bytes\n",fname,iMax);
          
    closedir(dp);


    return 0;
}
