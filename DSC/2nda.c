#define _POSIX_SOURCE
#define POSIX_C_SOURCE 199309L
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>
int main(int argc, char* argv[])
{
struct stat statv; char c[100];
if(stat(argv[1],&statv)==0)
printf("File exists\n");
else
{
printf("No file"); return 0;
}
if(S_ISDIR(statv.st_mode))
 printf("Directory file\n");
if(S_ISCHR(statv.st_mode))
 printf("Character file\n");
if(S_ISBLK(statv.st_mode))
 printf("Block file\n");
if(S_ISLNK(statv.st_mode))
 printf("Symbolic link file\n");
if(S_ISFIFO(statv.st_mode))
 printf("FIFO or pipe\n");
if(S_ISREG(statv.st_mode))
 printf("Regular file\n");
printf("Number of links: %d \n",statv.st_nlink);
printf("User id: %d\n",statv.st_uid);
 printf("Group id: %d\n",statv.st_gid);
printf("size of the file is %d\n",statv.st_size);
printf("Inode numberof the file is %d",statv.st_ino);
return 0;
}