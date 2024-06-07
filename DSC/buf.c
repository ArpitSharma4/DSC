#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>

int main(int argc, char* argv[]) {
    int fd1, n;
    char buf1[2];
    
    if (argc < 2) {
        perror("Too few arguments...");
        return 0;
    }
    
    fd1 = open(argv[1], O_RDONLY);
    if (fd1 == -1) {
        perror(" ");
        return 0;
    }
    
    while ((n = read(fd1, buf1, 1)) > 0) {
        write(1, buf1, 1);
        printf("%c", buf1[0]);  // Print each character as it is read
    }
    
    close(fd1);  // Close the file descriptor
    return 0;
}
