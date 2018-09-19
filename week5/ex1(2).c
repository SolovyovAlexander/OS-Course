#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>



void *PrintRickAstley(void *threadid)
{
    long tid;
    tid = (long)threadid;

    if (tid==0){
        printf("Never gonna give you up #%ld!\n", tid);
    }
    if (tid==1){
        printf("never gonna let you down #%ld!\n", tid);
    }
    if (tid==2){
        printf("Never gonna run around #%ld!\n", tid);
    }
    if (tid==3){
        printf("and desert you #%ld!\n", tid);
    }
    if (tid==4){
        printf("Never gonna make you cry #%ld!\n", tid);
    }
    if (tid==5){
        printf("never gonna say goodbye #%ld!\n", tid);
    }
    if (tid==6){
        printf("Never gonna tell a lie and hurt you #%ld!\n", tid);
    }
    if (tid>6){
        printf("Ooh give you up #%ld!\n", tid);
    }


    pthread_exit(NULL);
}

int main ()
{
    int N;
    scanf("%d",&N);
    pthread_t threads[N];

    int i;
    for(i=0; i<N; i++){
        printf("In main: creating thread %ld\n", i);
        pthread_create(&threads[i], NULL, PrintRickAstley, (void *)i);
        pthread_join(threads[i],NULL);

    }


    pthread_exit(NULL);
}