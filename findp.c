// find prim
//
// 1. input
// 2. start from 1 to input
// 2. find sqrt of input
// 3. test if 1 ~ sqrt of input is divisible
// 4. branch:if divisible ignore else print

#include <stdio.h>
#include <math.h>
#include <time.h>
int test(int);

int main(int argc, char* argv[]) {
    clock_t startTime, endTime;
    float totalTime = 0.0;
    
    int input;
    scanf("%d", &input);
    
    startTime = clock();
    
    for( int i = 2 ; i <= input ; i++ ) {
        int isPrim = test(i);
        int count = 0;
        if(isPrim) {
            count++;
            printf("%d\n", i);
        }        
    }
    endTime = clock();
    totalTime = (float) (endTime-startTime) / CLOCKS_PER_SEC;
    printf("take %.2f sec\n", totalTime);
    return 0;
}

int test(int num) {

    return 0;
}