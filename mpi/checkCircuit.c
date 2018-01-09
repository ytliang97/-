#include <stdio.h>
#include <time.h>

int checkCircuit(int []);
int main(int argc, char* argv[]){
	
	int circuit[16];//circuit
	for(int i = 0;i < 16;i++) {
		circuit[i]=0;	
	}
	/*	a)save 16 bit 0/1 in the circuit array. save integer from 0 to 65535
    	b)store bit from highest to lowest in binary to circuit array
        c)final: compute circuit to get output, and print the output
	*/
	
	int count=0;
	// a)
	clock_t t1, t2;
	t1 = clock();
	for(int i = 0;i < 65536;i++) {
		int j=0;

		// b)
	  	for(int k = 15; k >= 0; k--) {
	   		int binary = (i >> k) & 1;
	   		circuit[j] = binary;
	   		j++;		
	  	}
		
		// c)
		int output = checkCircuit(circuit);
		if (output == 1) {
			printf("pid)");
            for(int k=0;k<16;k++){
                printf("%d", circuit[k]);
            }
            printf("\n");
            count++;
        }
	}
	t2 = clock();
	float global_time = (float)(t2 - t1) / CLOCKS_PER_SEC;
    printf("Process 0 is done\n");
	printf("total: %d\n",count);
	printf("total take %f sec\n", global_time);

	return 0;
}
int checkCircuit(int circuit[]) {
    int output = (circuit[0] | circuit[1]) & (!circuit[1] | !circuit[3]) & (circuit[2] | circuit[3]) & (!circuit[3] | !circuit[4]) & (circuit[4] | !circuit[5]) & (circuit[5] | circuit[6]) & (circuit[5] | !circuit[6]) & (circuit[7] | !circuit[8]) & (circuit[8] | circuit[9]) & (circuit[8] | !circuit[9]) & (!circuit[9] | !circuit[10]) & (circuit[10] | circuit[11]) & (circuit[11] | circuit[9]) & (circuit[12] | circuit[13]) & (!circuit[7] | !circuit[13]) & (circuit[13] | !circuit[14]) & (circuit[14] | circuit[15]) & (!circuit[15] | circuit[6]);
    return output;
}
