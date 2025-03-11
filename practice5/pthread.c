#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

volatile int val = 15;


void bar() {
    static int ret_v = 0;
    printf("BAR EXECUTION\n");
    pthread_exit(&ret_v);
}

void* foo(void* args) {
    printf("FOO EXECUTION\n");
    ++val;
    sleep(2);
    bar();
    sleep(100);
    return NULL;
}



int main() {
    pthread_t id;
    int res = pthread_create(&id, NULL, foo, NULL);
    puts("MAIN THREAD SAYS HELLO");
    sleep(1);
    puts("MAIN THREAD SAYS HELLO");
    void* thread_ret;
    if (!pthread_equal(pthread_self(), id))
        pthread_join(id, &thread_ret);
    printf("RET: %d\n", *(int*)thread_ret);
    printf("Val: %d\n", val);
    pthread_cancel(id);
    printf("Canceled val: %p\n", PTHREAD_CANCELED);
    // while (1);
}