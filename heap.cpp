
#include<stdio.h>
#define MAX 11
int N;
int left(int i) {
		return 2 * i;
}
int right(int i) {
		return 2 * i + 1;
}
int parent(int i) {
	return i / 2;
}
int is_max_heap(int H[], int heap_size) {
	int i, p;

	for (i = heap_size; i > 1; i--) {
		p = parent(i);
		if (H[p] < H[i])
			return 0;
	}
	return 1;
}
void max_heapify(int heap[], int heap_size, int i) {
	int l, r, largest, t;
	l = left(i);
	r = right(i);

	if (r <= heap_size && heap[l] > heap[i]) {
		largest = l;
	}
	else {
		largest = i;
	}
	if (r <= heap_size && heap[r] > heap[i]) {
		largest = r;
	}
	else
	{
		largest = i;
	}
	if (largest != i) {
		t = heap[i];
		heap[i] = heap[largest];
		heap[largest] = t;

		max_heapify(heap, heap_size, largest);
	}
}
void print_heap(int heap[], int heap_size) {
	int i;

	for (i=1; i <= heap_size; i++) {
		printf("%d", heap[i]);
	}
	printf("\n\n");
}
int main() {
	int heap_size = 9;

	int H[] = {0,19,7,17,3,5,12,10,1,4};

	print_heap(H, heap_size);
	max_heapify(H, heap_size, parent(9));
	print_heap(H, heap_size);
	printf("\n%d\n",is_max_heap(H, heap_size));

}
