#include <stdio.h>

int main(){
	
	int AtoP[16];
	for(int i = 0;i < 16;i++) {
		AtoP[i]=0;	
	}
	/*將16位數0.1存進陣列
		將整數0-65535存進去，再以二進位拿出來從最高位依續存至最低位到AtoP
		然後再將AtoP經過運算得到output，將其印出 
	*/
    int id;
    
	int count=0;
	for(int i = 0;i < 65536;i++) {
		int j=0;
	  	for(int k = 15; k >= 0; k--) {
	   		int binary = (i >> k) & 1;
	   		AtoP[j] = binary;
	   		j++;		
	  	}
			
		int output = (AtoP[0] | AtoP[1]) & (!AtoP[1] | !AtoP[3]) & (AtoP[2] | AtoP[3]) & (!AtoP[3] | !AtoP[4]) & (AtoP[4] | !AtoP[5]) & (AtoP[5] | AtoP[6]) & (AtoP[5] | !AtoP[6]) & (AtoP[7] | !AtoP[8]) & (AtoP[8] | AtoP[9]) & (AtoP[8] | !AtoP[9]) & (!AtoP[9] | !AtoP[10]) & (AtoP[10] | AtoP[11]) & (AtoP[11] | AtoP[9]) & (AtoP[12] | AtoP[13]) & (!AtoP[7] | !AtoP[13]) & (AtoP[13] | !AtoP[14]) & (AtoP[14] | AtoP[15]) & (!AtoP[15] | AtoP[6]);
		
		if (output == 1) {
			for(int k=0;k<16;k++){	
				std::cout << AtoP[k] << " ";
			}
			std::cout << i << " : " << output << std::endl;
			count++;
		}	
	}
	std::cout << "共 : " << count << std::endl;

	return 0;
}