#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAX 1000
int partition(int A[], int low, int high) {
	int i, j;
	int pivot = A[high];
	for (j = low, i = low - 1; j < high; j++) {
		if (A[j] < pivot) {
			i++;
			int tem = A[i];
			A[i] = A[j];
			A[j] = tem;

		}
	}
	int tem = A[high];
	A[high] = A[i + 1];
	A[i + 1] = tem;
	return i + 1;
}
void Quic_sort(int A[], int low, int high) {
	if (low > high)
		return;

	int p = partition(A, low, high);


	Quic_sort(A, low, p-1);
	Quic_sort(A, p + 1, high);
}
int main() {
	int n;
	int arr[MAX] = {1,5,6,3,8,4,7,2};
	n = 8;
	printf("\n");

	Quic_sort(arr, 0, n - 1);

	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
