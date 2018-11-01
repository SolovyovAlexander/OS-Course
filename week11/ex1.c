#include <sys/fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <zconf.h>
#include <sys/mman.h>


int main() {
    int fd;
    char *map;
    char *p = "This is a nice day";
    fd = open("D:\\untitled\\ex1.txt", O_RDWR);
    struct stat st;
    stat("./ex1.txt", &st);
    map = mmap(NULL, st.st_size, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
    for (int j = 0; j < 18; ++j) {
        map[j] = p[j];
    }
    close(fd);
    return 0;

};