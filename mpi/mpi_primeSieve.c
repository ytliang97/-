/*1)Create a list of natural numbers 2,3,4,...,n,none of which is marked.*/
/*2)Set k to 2, the first unmarked number on the list.*/
/*3)Repeat*/
    /* 3.a) Mark all multiples of k between k^2 and n*/
    /* 3.b) Find the smallest number greater than k that is unmarked, Set k to the new value.*/
    /* 3.c) Until k^2 > n*/
/*4)The unmarked numbers are primes*/
#include "mpi.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define unmarked 0
#define marked 1
#define root 0
#define notprime 2
int main(int argc, char* argv[]) {
    int N = strtol(argv[1], NULL, 10);

    // 1)
    int *list = (int *) malloc((N+1)*sizeof(int));
    for(int i = 0;i <= N;i++)
        *(list + i) = unmarked;
    *(list) = notprime;
    *(list + 1) = notprime;
    // 2)
    int k = 2;

    int pid;
    int pnum;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &pid);
    MPI_Comm_size(MPI_COMM_WORLD, &pnum);

    double t2,t1;
    t1 = MPI_Wtime();
    // 3)
    while(1) {
        if(k*k < N) {
            for(int i = (N/pnum) * pid + 1;i <= (pid == (pnum - 1)?N:(N / pnum) * (pid + 1));i++) { // 3.a)
                /*if(i == 1) continue; not need this anymore(use notprime)*/
                if(i % k == 0 && i != k && *(list + i) == unmarked) {
                    *(list + i) = marked;
                }
            }
///            if(pid == root) { //--why?
                for(int i = k+1;i <= N;i++) { // 3.b)
                    if(*(list + i) == unmarked) {
///                     printf("origin k: %d\n", k);
                        k = i;
                        MPI_Bcast(&k, 1, MPI_INT, root, MPI_COMM_WORLD);
///                     printf("-------------%d\n", k);
                        break;
                    }
                }
///            }
///     printf("k*k = %d\n",k*k);
        }
        else break; // 3.c)
    }
    MPI_Barrier(MPI_COMM_WORLD);
    // 4)
    int count = 0;
    int global_count = 0;
    for(int i = (N/pnum) * pid + 1;i <= (pid == (pnum - 1)?N:(N / pnum) * (pid + 1));i++) {
        if(*(list + i) == unmarked) {
///            printf("%d ", i);
            count++;
        }
    }
    t2 = MPI_Wtime();
    double ptime = t2 - t1;
    double global_time;
    MPI_Barrier(MPI_COMM_WORLD);
    MPI_Reduce(&count, &global_count, 1, MPI_INT, MPI_SUM, root, MPI_COMM_WORLD);
    MPI_Reduce(&ptime, &global_time, 1, MPI_DOUBLE, MPI_SUM, root, MPI_COMM_WORLD);
    if(pid == root) {
        printf("total prime: %d\n", global_count);
        printf("total take %.3f sec\n", global_time/pnum);
    }
    MPI_Finalize();
    free(list);
    return 0;
}
