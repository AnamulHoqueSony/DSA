
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAX 1000

void marge(int A[], int left, int mid, int right) {
	int s_l = left;
	int s_r = mid + 1;
	int Arr[right - left+ 1];
	int k = 0;
	for (int i = left; i <=right; i++) {

		if (s_l > mid)
			Arr[k++] = A[s_r++];
		else if (s_r > right)
			Arr[k++] = A[s_l++];
		else if (A[s_l] < A[s_r]) {
			Arr[k++] = A[s_l++];
		 }
		else {
			Arr[k++] = A[s_r++];
		}
	}

	for (int i = 0; i < k; i++) {
		A[left++] = Arr[i];
	}

}
void marge_sort(int A[], int start,int en) {
	if(start < en){
        int mid = (start + en) / 2;
        marge_sort(A, start, mid);
        marge_sort(A, mid + 1, en);
        marge(A, start, mid, en);
	}
}

int main() {
	int arra[MAX];

	int n;
	scanf("%d",&n);

	for (int i = 0; i < n; i++) {
		int r = rand() % n;
		arra[i] = r;
		printf("%d ", arra[i]);
	}
	printf("\n");
	marge_sort(arra,0,n-1);

	for (int i = 0; i < n; i++) {
		printf("%d ", arra[i]);
	}
	printf("\n");
}
