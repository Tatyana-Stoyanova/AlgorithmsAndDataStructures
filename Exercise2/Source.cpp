#include <stdio.h>
#include <stdlib.h>
#define NUM 1331

struct item {
	int key;
	void* data;
};

int selection_sort(item *a[], int n) {
	int i, index_min, j;
	int steps = 0; 
	for (i = 0; i < n-1; i++) {
		index_min = i;
		steps++;

		for (j = i + 1; j < n; j++) {
			steps++;
			if (a[index_min]->key > a[j]->key) {
				index_min = j;	
			}
		}
		if (index_min != i) {
			item* temp = a[index_min];
			a[index_min] = a[i];
			a[i] = temp;
		}

	}
	for (int i = 0; i < n; i++) {
		printf("\nItem a[%d] has key %d \n", i, a[i]->key);
	}
	return steps;
}

int insertion_sort(item* a[], int n) {
	int i, j;
	int steps = 0;
	item* v; 
	for (i = 1; i < n; i++){
		steps++;
		v = a[i];
		for (j = i-1; j >= 0 && v->key < a[j]->key; j--){ // Move elements greater than v->key one position ahead
			steps++;
			a[j+1] = a[j]; 
		}
		a[j+1] = v;
	}
	for (int i = 0; i < n; i++) {
		printf("\nItem a[%d] has key %d \n", i, a[i]->key);
	}
	return steps;
}

int bubble_sort(item* a[], int n) {
	int i, j, flag;
	int steps = 0;
	flag = 1;
	for (i = n - 1; flag == 1 && i > 0; i--) {
		flag = 0;
		steps++;
		for (j = 0; j < i; j++) {
			steps++;
			if (a[j]->key > a[j + 1]->key){
				item* temp = a[j];
				a[j]= a[j+1];
				a[j+1] = temp;
				flag = 1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		printf("\nItem a[%d] has key %d \n", i, a[i]->key);
	}
	return steps;
}

int main() {
	int n;
	printf("Enter number of elements: ");
	scanf_s("%d", &n);

	//fully unsorted array
	printf("\nFully unsorted array\n");

	item** unsorted;
	unsorted = (item**)malloc(n * sizeof(struct item*));

	for (int i = 0; i < n; i++) {
		unsorted[i] = (item*)malloc(sizeof(struct item));	
	}
	for (int i = 0; i < n; i++) {
		unsorted[i]->key = NUM - i;
	}
	int unsorted_selectionsteps = selection_sort(unsorted, n);
	printf("\nSteps by fully unsorted array: selectionsteps=%d\n", unsorted_selectionsteps);

	//random generated array
	printf("\nrandom generated array\n");
	item** randarr;
	randarr = (item**)malloc(n * sizeof(struct item*));
	
	for (int i = 0; i < n; i++) {
		randarr[i] = (item*)malloc(sizeof(struct item));
	}
	srand(1);
	for (int i = 0; i < n; i++) {
		randarr[i]->key = rand();
	}
	int random_insertionsteps = insertion_sort(randarr, n);
	printf("\nSteps by random generated array: insertionsteps=%d\n", random_insertionsteps);

	//partially random generated array
	printf("\npartially random generated array\n");
	item** partrandarr;
	partrandarr = (item**)malloc(n * sizeof(struct item*));

	for (int i = 0; i < n; i++) {
		partrandarr[i] = (item*)malloc(sizeof(struct item));
	}
	srand(1);
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			partrandarr[i]->key = rand();
		}
		else {
			partrandarr[i]->key = NUM - i;
		}
	}
	int partrandom_bubblesteps = bubble_sort(partrandarr, n);
	printf("\nSteps by random generated array: bubblesteps=%d\n", partrandom_bubblesteps);
}
