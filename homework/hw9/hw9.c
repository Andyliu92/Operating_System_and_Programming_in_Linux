#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

void print_file_type(const char *filePath, mode_t fileMode)
{
    if (S_ISREG(fileMode) == 1)
    {
        printf("%s is a regular file\n", filePath);
    }
    else if (S_ISDIR(fileMode) == 1)
    {
        printf("%s is a directory\n", filePath);
    }
    else if (S_ISCHR(fileMode) == 1)
    {
        printf("%s is char device\n", filePath);
    }
    else if (S_ISBLK(fileMode) == 1)
    {
        printf("%s is a block file\n", filePath);
    }
    else if (S_ISFIFO(fileMode) == 1)
    {
        printf("%s is a pipe\n", filePath);
    }
    else if (S_ISLNK(fileMode) == 1)
    {
        printf("%s is a symbolic link\n", filePath);
    }
    else if (S_ISSOCK(fileMode) == 1)
    {
        printf("%s is a socket file\n", filePath);
    }
    else
    {
        printf("File type ERROR!\n");
    }
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <file path>\n", argv[0]);
    }

    const char *filePath = argv[1];
    struct stat fileStat;

    int fd = open(filePath, O_RDONLY);
    if (fd == -1)
    {
        printf("File open ERROR!\n");
        return -1;
    }

    fstat(fd, &fileStat);

    print_file_type(filePath, fileStat.st_mode);

    printf("inode: %ld\n", fileStat.st_ino);
    printf("uid: %d\n", fileStat.st_uid);
    printf("nlink: %ld\n", fileStat.st_nlink);
    printf("gid: %d\n", fileStat.st_gid);
    printf("size: %ld\n", fileStat.st_size);

    if (access(filePath, R_OK) != -1)
    {
        printf("The file CAN be read\n");
    }
    else
    {
        printf("The file CANNOT be read\n");
    }

    if (fchmod(fd, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP) != -1)
    {
        printf("Chmod success!\n");
    }
    else
    {
        printf("Chmod failed!\n");
    }
}