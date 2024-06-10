#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>


void print_heap(int* heap, int n) {
	for (int y = 0; y < n; ++y) {
		printf("%d ", heap[y]);
	}
}

int max(int* heap, int n) {
	int j = 0;
	int l, p;
	do {
		l = 2 * j + 1;
		p = 2 * j + 2;
		if ((l < n) && (p < n) && ((heap[j] < heap[l]) || (heap[j] < heap[p]))) {
			if (heap[l] >= heap[p]) {
				int temp = heap[j];
				heap[j] = heap[l];
				heap[l] = temp;
				j = l;
			}
			else {
					if (heap[p] >= heap[l]) {
						int temp = heap[j];
						heap[j] = heap[p];
						heap[p] = temp;
						j = p;
					}
			}
		}
		else {
			if ((l < n) && (heap[l] > heap[j])) {
				int temp = heap[j];
				heap[j] = heap[l];
				heap[l] = temp;
				j = l;
			}
			else {
				if ((p < n) && (heap[p] > heap[j])) {
					int temp = heap[j];
					heap[j] = heap[p];
					heap[p] = temp;
					j = p;
				}
				else {
					j = n;
				}
			}
		}
		l = 2 * j + 1;
		p = 2 * j + 2;
	} while ((j < n) && ((heap[j] < heap[l]) || (heap[j] < heap[p])) && ((l < n) || (p < n)));
	return heap[n];
}

int main() {
	setlocale(LC_ALL, "Rus");
	int n = 9;
	int val;
	FILE* fp;
	fp = fopen("Heap.txt", "r");
	int heap[9];
	for (int i = 0; i < n; ++i) {
		fscanf(fp, "%d", &val);
		heap[i] = val;
		if(i != 0) {
			int j = i;
			int m = (int)((j - 1) / 2);
			while ((j > 0) && (heap[m] < heap[j])) {
				int temp;
				temp = heap[m];
				heap[m] = heap[j];
				heap[j] = temp;
				j = m;
				m = (int)((j - 1) / 2);
			}
		}
		print_heap(heap, i+1);
		printf("n=%d\n", i + 1);
	}
	printf("_________________________________________________\n");
	printf("Heap\n");
	print_heap(heap, n);
	printf("n=%d\n", n);
	int cpn = n;
	printf("Sort\n");
	for (int i = 0; i < n; ++i) {
		int temp = heap[0];
		heap[0] = heap[cpn - 1];
		heap[cpn - 1] = temp;
		cpn--;
		max(heap, cpn);
		int j = 0;
		print_heap(heap, n);
		printf("HeapSize = %d\n", cpn);
	}
	fclose(fp);
	return 0;
}