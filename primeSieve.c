/*Create a list of natural numbers 2,3,4,...,n,none of which is marked.*/
/*Set k to 2, the first unmarked number on the list.*/
/*Repeat*/
    /* a) Mark all multiples of k between k^2 and n*/
    /* b) Find the smallest number greater than k that is unmarked, Set k to the new value.*/
    /* c) Until k^2 > n*/
/*The unmarked numbers are primes*/
#include <stdio.h>
#define unmarked 0
#define marked 1
int main(int argc, char* argv[]) {
    int N = strtol(argv[1], NULL, 10);
    
    /*Create a list of natural numbers 2,3,4,...,n,none of which is marked.*/
    int *list = (int *) malloc((N+1)*sizeof(int));
    for(int i = 0;i <= N;i++)
        *(list + i) = unmarked;
    
    /*Set k to 2, the first unmarked number on the list.*/
    int k = 2;
    
    /*Repeat*/
    /* a) Mark all multiples of k between k^2 and n*/
    /* b) Find the smallest number greater than k that is unmarked, Set k to the new value.*/
    /* c) Until k^2 > n */
    while(1) {
        if(k*k < N) {
           for(int i = k;i <= n;i++) { // a)
                if(i % k == 0)   
                    *(list + i) = marked;
           }
           for(int i = k;i <= n;i++) { // b)
               if(*(list + i) == unmarked) {
                   k = i;
                   break;
               }
           }
        }
        else break; // c)
    }

    /*The unmarked numbers are primes*/
    int count = 0;
    for(int i = 2;i <= n;i++) {
        if(*(list + i) == unmarked) {
//            printf("%d ", i);
            count++;
        }
    }
    printf("total prime: %d", count);
    return 0;
}