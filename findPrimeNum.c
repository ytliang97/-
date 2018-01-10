// find < input's prim
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
    int count = 0;
    if(input <= 2) {
        printf("2 ");
        count++;
    }
    else if(input > 2) {
        printf("2 ");
        count++;
        for( int i = 3 ; i <= input ; i++ ) {
            int isPrim = test(i);
            if(isPrim) {
                count++;
                printf("%d ", i);
            }
        }
    }
    endTime = clock();
    totalTime = (float) (endTime-startTime) / CLOCKS_PER_SEC;
    printf("\nfrom 0 ~ %d, there are %d prime number, take %.2f sec\n", input, count, totalTime);
    return 0;
}

int test(int num) {
//    int sqrt_num = (int) sqrt(num);
    int isPrim = 1;
    for(int i = 2 ; i < num ; i++ ) {
        if(num%i == 0) {
            isPrim = 0;
            break;
        }
        else if (num == (i + 1))
            break;
    }

    return isPrim;
}
