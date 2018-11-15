#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

#define MAXCHAR 1000

int *readline_and_createArray(char *str, FILE *fp) {
    int *A = malloc(sizeof(int));
    if (fgets(str, MAXCHAR, fp) != NULL) {

        char *pch = strtok(str, " ");
        int size = 0;
        while (pch != NULL) {

            A = (int *) realloc(A, (1 + size) * sizeof(int));
            A[size] = atoi(pch);
            size++;

            pch = strtok(NULL, " ");
        }

//        printf("Line read and created Array. Size: %d\n", size);
//        for (int i = 0; i < size; ++i) {
//            printf("Arr[%d] = %d\n", i, A[i]);
//        }
//        printf("\n");

        return A;
    } else return NULL;
}

int *createArrayfromString(char *str) {
    int *A = malloc(sizeof(int));

    char *pch = strtok(str, " ");
    int size = 0;
    while (pch != NULL) {

        A = (int *) realloc(A, (1 + size) * sizeof(int));
        A[size] = atoi(pch);
        size++;

        pch = strtok(NULL, " ");
    }

//    printf("Line read and created Array. Size: %d\n", size);
//    for (int i = 0; i < size; ++i) {
//        printf("Arr[%d] = %d\n", i, A[i]);
//    }
//    printf("\n");

    return A;

}

int checker(int arr[],int size){
    for (int i = 0; i <size ; ++i) {
        if(arr[i]==-1){ return 1;}
    }
    return 0;
}


int main(){

    char *filename = "../week13/input.txt";
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Could not open file %s", filename);
        return 1;
    }

    char str[MAXCHAR];
    int *E;
    int *A;

    int size = 3;

    E = readline_and_createArray(str, fp);
    A = readline_and_createArray(str, fp);

    //empty line
    fgets(str, MAXCHAR, fp);

    int **C = malloc(sizeof(int *));
    int processes = 0;

    printf("================ Double Array ======================\n");
    while (fgets(str, MAXCHAR, fp) != NULL) {
        if (strcmp(str, "\n") == 0 || strcmp(str,"\r\n") == 0) break;
        processes++;
        int *array = createArrayfromString(str);
        C = (int **) realloc(C, processes * sizeof(int));
        C[processes - 1] = array;
    }

    for (int i = 0; i < processes; ++i) {
        for (int j = 0; j < size; ++j) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    int **R = malloc(sizeof(int *));
    processes = 0;

    printf("================ Double Array ======================\n");
    while (fgets(str, MAXCHAR, fp) != NULL & strcmp(str, "\n") != 0) {
        if (strcmp(str, "\n") == 0 || strcmp(str,"\r\n") == 0) break;
        processes++;
        int *array = createArrayfromString(str);
        R = (int **) realloc(R, processes * sizeof(int));
        R[processes - 1] = array;
    }

    for (int i = 0; i < processes; ++i) {
        for (int j = 0; j < size; ++j) {
            printf("%d ", R[i][j]);
        }
        printf("\n");
    }



    int arr[processes];
    int check1 =0;
    int done[5];
    done[0]=-1;
    done[1]=-1;
    done[2]=-1;

    int deadlock=0;


    while(checker(done,5)==1){
        for (int i = 0; i <5 ; ++i) {
            if (done[i]!=1){
                for (int j = 0; j <3 ; ++j) {
                    arr[j]= A[j]-R[i][j];
                }
                for (int k = 0; k <3 ; ++k) {
                    if(arr[k]<0){
                        check1=1;
                    }
                }
                if (check1==0){
                    done[i]=1;
                    for (int j = 0; j <3 ; ++j) {
                        A[j]=A[j]+C[i][j];
                    }
                    check1=0;

                    break;
                }
            }



        }
        if (check1==1){
            printf("DEADLOCK\n");
            printf("Processes are deadlocked:\n");
            for (int i = 0; i <5 ; ++i) {
                if(done[i]==-1){
                    printf("%d ",i+1);
                }
            }
            break;
        }
        else{
            printf("NO DEADLOCK");
        }
    }

    fclose(fp);


}






