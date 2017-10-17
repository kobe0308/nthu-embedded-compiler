//#include <stdio.h>

int main(void){
	int i;
	int A[60];
	int C[60];
	int D[60];

	for(i = 2; i < 20; i++){
		A[i] = C[i];
		D[i] = A[3*i-4];
	}
	
	return 0;
}
