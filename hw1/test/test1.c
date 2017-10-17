//#include <stdio.h>

int main(void){
	int i;
	int A[20];
	int C[20];
	int D[20];

	for(i = 4; i < 20; i++){
		A[i] = C[i];
		D[i] = A[i-4];
	}
	
	return 0;
}
