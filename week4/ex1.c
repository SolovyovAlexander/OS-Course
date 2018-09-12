#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int n = 42;
    int PID= fork();
    if (PID>0){
        printf("Hello from parent [%d - %d]",PID,n);
    }
    else if(PID==0){
        printf("Hello from child [%d - %d]",PID,n);
    }
    else{ printf("Error");}
}
