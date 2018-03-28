

void swap(int A[], int i, int j){
	int t = A[i];
	A[i] = A[j];
	A[j] = t;
}

int partitionHoare(int A[], int low, int high){
	if (low == high){
		return low;
	}
	int x = A[high];
	int i = low;
	int j = high-1;
	while (1){
		while (A[j]>x && j>=i){
			j=j-1;
		}
		while (A[i]<x && i<j){
			i=i+1;
		}
		if (i<j){
			swap(A,i,j);
		}
		else {
			return i;
		}
	}
}

void quicksort(int A[], int low, int high){
	if (low < high){
		int m = partitionHoare(A,low,high);
		/*quicksort(A,low,m);*/
		quicksort(A,m+1,high);
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
	int A[10]={4,3,2,5,6,7,8,9,12,1};
	int n=10;
	partitionHoare(A, 0,n-1);
	printArray(A,n);
	quicksort(A,0,n-1);
	printArray(A,n);
}

