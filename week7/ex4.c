#include <stdlib.h>
#include <stdio.h>


int my_realloc(void *a,int n){
    free(a);
    a = malloc(n);

}

int main(){
}

