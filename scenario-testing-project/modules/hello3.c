#include <stdio.h>
#define WORK_NUMBER 3

void onLoad() {
    printf("hello world %d\n", WORK_NUMBER);
}

void onUnload() {
    printf("bye world %d\n", WORK_NUMBER);
}

void doWork() {
    printf("doWork %d\n", WORK_NUMBER);
}

