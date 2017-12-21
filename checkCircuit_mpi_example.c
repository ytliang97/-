#include <stdio.h>
#include <mpi.h>
#define EXTRACT_BIT(n, i) ((n & (1 << i)) ? 1 : 0)
int main(int argc, char* argv[]) {
    int i;
    int id;
    int p;
    int global_solutions;
    int solutions;
    int check_circuit(int, int);

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &id);
    MPI_Comm_size(MPI_COMM_WORLD, &p);

    solutions = 0;
    for(i = id;i < 65535;i += p) {
        solutions += check_circuit(id, i);
    }

    MPI_Reduce(&solutions, &global_solutions, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    printf("Process %d finish!\n", id);
    fflush(stdout);
    MPI_Finalize();
    if(id == 0)
        printf("There are %d different solutions\n", global_solutions);
    return 0;
}

int check_circuit(int id, int z) {
    int AtoP[16];
    int i;

    for(i = 0;i < 16;i++)
        AtoP[i] = EXTRACT_BIT(z, i);
        if((AtoP[0] | AtoP[1]) & (!AtoP[1] | !AtoP[3]) & (AtoP[2] | AtoP[3]) & (!AtoP[3] | !AtoP[4]) & (AtoP[4] | !AtoP[5]) & (AtoP[5] | AtoP[6]) & (AtoP[5] | !AtoP[6]) & (AtoP[7] | !AtoP[8]) & (AtoP[8] | AtoP[9]) & (AtoP[8] | !AtoP[9]) & (!AtoP[9] | !AtoP[10]) & (AtoP[10] | AtoP[11]) & (AtoP[11] | AtoP[9]) & (AtoP[12] | AtoP[13]) & (!AtoP[7] | !AtoP[13]) & (AtoP[13] | !AtoP[14]) & (AtoP[14] | AtoP[15]) & (!AtoP[15] | AtoP[6])) {
            printf("%d) %d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d\n", id,AtoP[0],AtoP[1],AtoP[2],AtoP[3],AtoP[4],AtoP[5],AtoP[6],AtoP[7],AtoP[8],AtoP[9],AtoP[10],AtoP[11],AtoP[12],AtoP[13],AtoP[14],AtoP[15]);
            fflush(stdout);
            return 1;
        }
        fflush(stdout);
        return 0;
    }
    