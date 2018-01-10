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
#include <mpi.h>
#define reduceFrequency 1
#define whichCPUprint 0
int test(int);

int main(int argc, char* argv[]) {
	clock_t startTime, endTime;
    float totalTime = 0.0;
    
    int i;
    int processID;//rank
    int processQuantity;//size
    
    
    int input;
    scanf("%d", &input);
    
    startTime = clock();
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &processID);
    MPI_Comm_size(MPI_COMM_WORLD, &processQuantity);
    
    int count = 0;//reduce
    int globalCount;//reduce
    if(input <= 2) {
		printf("2 ");
		count++;
	}
    for( i = processID ; i <= input ; i+=processQuantity ) {
    	if(i == 0 | i == 1 | i == 2) continue;
        int isPrim = test(i);
        if(isPrim) {
            count++;
            printf("%d ", i);
        }        
    }
    MPI_Reduce(&count, &globalCount, reduceFrequency, MPI_INT, MPI_SUM, whichCPUprint, MPI_COMM_WORLD);
    printf("Process %d finish.\n", processID);
    MPI_Finalize();
    endTime = clock();
    totalTime = (float) (endTime-startTime) / CLOCKS_PER_SEC;
    if(processID == 0)
    	printf("from 0 ~ %d, there are %d prime number, take %.2f sec\n", input, globalCount, totalTime);
    return 0;
}

int test(int num) {
    int i;
    int isPrim = 1;
    for(i = 2 ; i < num ; i++ ) {
        if(num%i == 0) {
            isPrim = 0;
            break;
        }
        else if (num == (i + 1))
        	isPrim = 1;
        	break;
    }

    return isPrim;
}
