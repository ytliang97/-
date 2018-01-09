/*Create a list of natural numbers 2,3,4,...,n,none of which is marked.*/
/*Set k to 2, the first unmarked number on the list.*/
/*Repeat*/
    /* a) Mark all multiples of k between k^2 and n*/
    /* b) Find the smallest number greater than k that is unmarked, Set k to the new value.*/
    /* c) Until k^2 > n
/*The unmarked numbers are primes*/
#include <stdio.h>
#define unmarked 0
#define marked 1
int main(int argc, int* argv[]) {
    int N = argv[1];
    
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
        if(k*k < n) {
           for(i = k;i <= n;i*=i) { // a)
               *(list + i) = marked;
           }
           for(i = k;i <= n;i++) { // b)
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
    for(i = k;i <= n;i++) {
        if(*(list + i) == unmarked) {
            printf("%d", *(list + i));
            count++;
        }
    }
    printf("total prime: %d", count);
    return 0;
}