/*Melanie Salzer, 16-922-593*/

#include <stdio.h>

void bubblesort(int a[], int n){
	int i,j,t;
	for (i=n-1; i>0; i--){
		for (j=0; j<i;j++){
			if (a[j]> a[j+1]){
				t= a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}
	}
}

void printArray(int A[], int size){
	int i=0;
	printf("A = [");
	for (i; i<size; i++){
		printf("%d", A[i]);
		if (i<size-1){
			printf(",");
		}
	}
	printf("]\n");
}


int main(){
	int a[10] ={1,2,6,5,4,3,7};
	int n = 7;
	bubblesort(a,n);
	printArray(a,n);
    return 0;
}


