#include "greeter.h"
#include <stdio.h>
#include <pthread.h>

int globalVar = 0;
pthread_mutex_t count_mutex;

int greet(struct Greetee *g, char *out) {
    int n = 0;
    n += sprintf(out + strlen(out), "ThreadID=%d, waiting\n", pthread_self());
    pthread_mutex_lock(&count_mutex);
    sleep(5);
    globalVar++;
    n += sprintf(out + strlen(out), "goroutine=%d, ThreadId=%d, GlobalVar=%d", g->year, pthread_self(), globalVar);
    pthread_mutex_unlock(&count_mutex);
    return n;
}