#include<stdio.h>
int left(int i) {
	return 2 * i;
}
int right(int i) {
	return 2 * i + 1;
}
int parent(int i) {
	return i / 2;
}
int is_max_heap(int heap[], int heap_size) {

	int i, p;

	for (i = heap_size; i > 1; i--) {
		p = parent(i);

		if (heap[p] < heap[i])
			return 0;
	}
	return 1;
}
void heapy(int heap[],int heap_size,int i) {

	int l, r, largest, t;
	l = left(i);
	r = right(i);
	if (l <= heap_size && heap[l] > heap[i]) {
		largest = l;
	}
	else
	{
		largest = i;
	}
	if (r <= heap_size && heap[r] > heap[largest]) {
		largest = r;
	}
	if (largest != i) {
		t = heap[i];
		heap[i] = heap[largest];
		heap[largest] = t;

		heapy(heap, heap_size, largest);
	}
}
void print_heap(int heap[],int heap_size) {
	for (int i = 1; i <= heap_size; i++) {
		printf("%d ", heap[i]);
	}
	printf("\n");
}

int extract_max(int heap[], int heap_size) {
	int max_item = heap[1];
	heap[1] = heap[heap_size];
	heap_size -= 1;
	heapy(heap, heap_size, 1);
	return max_item;
}
int insert_node(int heap[], int heap_size, int node) {
	int i, p, t;
	heap_size += 1;
	heap[heap_size] = node;
	i = heap_size;
	while (i > 1 && heap[i] > heap[parent(i)]) {
		p = parent(i);
		t = heap[p];
		heap[p] = heap[i];
		heap[i] = t;
		i = p;
	}
	return heap_size;
}
int main() {
	int heap[100] = {0,4,1,10,19,7,17,3,5,12};
	int heap_size = 9;
	for (int i = heap_size / 2 ; i >= 1; i--) {
		heapy(heap,heap_size,i);
	}
	printf("%d\n", is_max_heap(heap,heap_size));
	print_heap(heap,heap_size);
	heap_size = insert_node(heap, heap_size, 100);
	print_heap(heap, heap_size);

}
