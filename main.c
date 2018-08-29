


#include <stdio.h>
#include <float.h>
#include <earley.h>
#include <string.h>

int main( int argc, char *argv[] )  {
    ex3(5);

}

void ex1(){
    int a;
    float b;
    double c;
    a = INT_MAX;
    b = FLT_MAX;
    c = DBL_MAX;
    printf("size of a = %d\n",(int)sizeof(a));
    printf("value of a = %d\n",a);
    printf("size of b = %d\n",(int)sizeof(b));
    printf("value of b = %f\n",b);
    printf("size of c = %d\n",(int)sizeof(c));
    printf("value of c = %f\n",c);

}

void ex2(){
    char a[256];
    scanf("%s",a);
    for (int i = ((int) strlen(a))-1; i >=0 ; --i) {
        printf("%c",a[i]);
    }

}

void ex3(int n){
    for (int i = 0; i <n ; ++i) {
        for (int j = 0; j <((2*n)-1-i-1) ; ++j) {
            printf(" ");
        }
        int c = i;
        for (int k = 0; k <c+i; ++k) {
            printf("*");
        }
        printf("*\n");
    }
}

void swap(int *a, int *b){
    int c=*a;
    int d=*b;
    *a=d;
    *b=c;
}

void ex4(){
    int a;
    int b;
    scanf("%d",&a);
    scanf("%d",&b);
    swap(&a,&b);
    printf("%d\n",a);
    printf("%d\n",b);
}

