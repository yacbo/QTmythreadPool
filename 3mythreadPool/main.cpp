#include "condition.h"
#include "threadpool.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <time.h>

#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

void* mytask(void *arg)
{
    printf("thread %d is working on task %d\n", (int)pthread_self(), *(int*)arg);
    for(int i = 65;i<91;i++)
    {
        printf(".....%c....\n",(char)i);
    }
    sleep(1);
    free(arg);
    return NULL;
}

void* mytask1(void *arg)
{
    printf("thread %d is working on task %d\n", (int)pthread_self(), *(int*)arg);
    for(int i = 97;i<*(int*)arg;i++)
    {
        printf(".....%c....\n",(char)i);
    }
    sleep(1);
    free(arg);
    return NULL;
}
threadpool_t pool;  //定义线程池结构体变量

int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;

    threadpool_init(&pool, 3);//初始化线程池，最多三个线程
    int i;
    //创建十个任务
    for(i=0; i < 10; i++)
    {
        int *arg = (int*)malloc(sizeof(int));
        *arg = i;
        threadpool_add_task(&pool, mytask, arg);
    }

    int *arg1 = (int*)malloc(sizeof(int));
    *arg1 = 170;
    threadpool_add_task(&pool, mytask1, arg1);

    threadpool_destroy(&pool);
    return 0;
}
