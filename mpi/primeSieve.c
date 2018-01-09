/*1)Create a list of natural numbers 2,3,4,...,n,none of which is marked.*/
/*2)Set k to 2, the first unmarked number on the list.*/
/*3)Repeat*/
    /* 3.a) Mark all multiples of k between k^2 and n*/
    /* 3.b) Find the smallest number greater than k that is unmarked, Set k to the new value.*/
    /* 3.c) Until k^2 > n*/
/*4)The unmarked numbers are primes*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define unmarked 0
#define marked 1
int main(int argc, char* argv[]) {
    int N = strtol(argv[1], NULL, 10);
    
    // 1)
    int *list = (int *) malloc((N+1)*sizeof(int));
    for(int i = 0;i <= N;i++)
        *(list + i) = unmarked;
    
    // 2)
    int k = 2;
    
    clock_t t2,t1;
    t1 = clock();
    // 3)
    while(1) {
        if(k*k < N) {
           for(int i = k+1;i <= N;i++) { // 3.a)
                if(i % k == 0)   
                    *(list + i) = marked;
           }
           for(int i = k+1;i <= N;i++) { // 3.b)
               if(*(list + i) == unmarked) {
                   k = i;
                   break;
               }
           }
        }
        else break; // 3.c)
    }

    // 4)
    int count = 0;
    for(int i = 2;i <= N;i++) {
        if(*(list + i) == unmarked) {
//            printf("%d ", i);
            count++;
        }
    }
    t2 = clock();
    float global_time = (float)(t2 - t1) / CLOCKS_PER_SEC;
    printf("total prime: %d\n", count);
    printf("total take %.3f sec\n", global_time);
    free(list);
    return 0;
}