#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char command[1024];

    void read(char *command){
        scanf(" %[^\t\n]s", command);
    }
    while(1){
        read(command);
        system(command);
    }
}
