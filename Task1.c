#include <math.h>


void heapify(int A[], int i, int n){
	int m = i;
	int l = 2*i+1;
	int r = 2*i+2;
	if (l<n && A[l]>A[m]){
		m=l;
	}
	if (r<n && A[r]>A[m]){
		m=r;
	}
	if (i!=m){
		int t = A[i];
		A[i] = A[m];
		A[m] = t;
		heapify(A,m,n);
	}
}

void buildMaxHeap(int A[], int n){
	int i = floor(n/2)-1;

	for (i; i>=0; i--){
		heapify(A,i,n);
	}
}

void printHeap(int A[], int n){
	int i = 0;
	for (i; i<=n/2; i++){
		int l = 2*i+1;
		int r = 2*i+2;
		if (l<n){
			printf("%d -- %d\n", A[i], A[l]);
		}
		if (r<n){
			printf("%d -- %d\n", A[i], A[r]);			
		}
	}
}

void heapSort(int A[], int n){
	int s = n;
	buildMaxHeap(A,n);
	int i = n-1;
	for (i; i>=1; i--){
		int t = A[i];
		A[i] = A[0];
		A[0] = t;
		s = s-1;
		buildMaxHeap(A,s);
	}
}

void printArray(int A[], int n){
	int i=0;
	printf("A = [");
	for (i; i<n; i++){
		printf("%d", A[i]);
		if (i<n-1){
			printf(",");
		}
	}
	printf("]\n");
}

int main(){
	int A[10]={4,3,2,5,6,7,8,9,12,1};
	int n = 10;
	buildMaxHeap(A,n);
	printHeap(A,n);
	heapSort(A,n);
	printArray(A,n);
	}
