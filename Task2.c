

void swap(int A[], int i, int j){
	int t = A[i];
	A[i] = A[j];
	A[j] = t;
}

int partitionHoare(int A[], int low, int high){
	int x = A[high];
	int i = low-1;
	int j = high+1;
	while (1) {
        do  j--; while (A[j] > x && j>=low);
        do  i++; while (A[i] < x && i<=high);

        if  (i < j){
            swap(A,i,j);
        }
        else{
            return j;
        }
    }
}

void quicksort(int A[], int low, int high){
	if (low < high){
		int m = partitionHoare(A,low,high);
		quicksort(A,low,m-1);
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
	printArray(A,n);
	quicksort(A,0,n-1);
	printArray(A,n);
}

