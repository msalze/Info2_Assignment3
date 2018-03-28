#include <math.h>


void buildMaxHeap(int A[], int n){
	
}

void printHeap(int A[], int n){
	int k = 0;
	while (n>0){
		n=floor(n/2);
		k++;
	}
	int i = 1;
	for (i; i<=n/2; i++){
		int m = floor(i/2);
		print("%d -- %d", A[i], A[m]);
	}
}

void heapSort(int A[], int n){
	
}

void printArray(int A[], int n){
	
}

int main(){
	int A[10]={3,8,9,1,7};
	printHeap(A,5);
}
