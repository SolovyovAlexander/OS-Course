#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <zconf.h>

int counter = 0;
void *produce()
{

    while(1)
    {
        if(counter < 10)
        {
            counter++;
            printf("counter = %d\n", counter);
            sleep(1);
        }
        else
        {
            printf("Going for a long sleep as counter is 10!\n");
            sleep(50);
        }
    }
}
void *consume()
{

    sleep(15);
    while(1)
    {
        if(counter > 0)
        {
            counter--;
            printf("counter = %d\n", counter);
            sleep(1);
        }
        else
        {
            printf("Going for a long sleep as counter is zero!\n");
            sleep(50);
        }
    }
}


int main()
{


    pthread_t tid[2];
    {
        pthread_create(&tid[0],NULL,produce,NULL);
        pthread_create(&tid[1],NULL,consume,NULL);
    }
    {
        pthread_join(tid[0],NULL);
        pthread_join(tid[1],NULL);
    }
    return 0;
}

