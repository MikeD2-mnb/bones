#include <stdio.h>
#include <time.h>

int main() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    printf("CLOCK_REALTIME: %ld seconds, %ld nanoseconds\n", ts.tv_sec, ts.tv_nsec);
    float tx = (float)ts.tv_sec + (float)((ts.tv_nsec)/1000000000.0);
    printf("%f \n",tx);
    int a = 0;
    while (a<65534){
        a +=1;
    }
    clock_gettime(CLOCK_MONOTONIC, &ts);
    float ty = (float)ts.tv_sec + (float)((ts.tv_nsec)/1000000000.0);
    printf("%f \n",ty);
    printf("%f \n",(ty-tx));
    return 0;
}