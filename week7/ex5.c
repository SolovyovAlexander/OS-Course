#include <stdio.h>
#include <stdlib.h>

int main() {
    char **s;
    s=malloc(sizeof(char**));
    *s=malloc(sizeof(char*));
    char foo[] = "Hello World";
    *s = foo;
    printf("s is %s\n",*s);
    return(0);
}