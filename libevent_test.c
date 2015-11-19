#include <stdio.h>
#include <stdlib.h>
#include <event.h>

void time_handle(int sock, short event, void *arg)
{
    printf("hello word!\n");
    struct timeval tv;       
    tv.tv_sec = 1;       
    tv.tv_usec = 0;      
    // 重新添加定时事件（定时事件触发后默认自动删除）
    event_add((struct event*)arg, &tv);   
}

void time_handle2(int sock, short event, void *arg)
{
    printf("hello word2!\n");
    struct timeval tv;       
    tv.tv_sec = 2;       
    tv.tv_usec = 0;      
    // 重新添加定时事件（定时事件触发后默认自动删除）
    event_add((struct event*)arg, &tv);   
}
int main(void)
{
    event_init();
    struct event evTime1,evTime2;
    evtimer_set(&evTime1,time_handle,&evTime1);
    evtimer_set(&evTime2,time_handle2,&evTime2);
    struct timeval tv;
    tv.tv_sec = 1;
    tv.tv_usec = 0;

    event_add(&evTime1,&tv);
    event_add(&evTime2,&tv);
    event_dispatch();
    return 0;
}
