#include<stdio.h>
#include<stdlib.h>
struct item {
	int key;
	void* data;
};

int binary_search(item* a[], int n, int num) {
	int l, r, m, step;
	step = 0;
	l = 0;
	r = n - 1;

	while (l <= r) {
		m = (l + r) / 2;
		printf("Step = %d\n", step);
		printf("L = %d\n",l);
		printf("R = %d\n", r);
		printf("M = %d\n", m);
		printf("a[%d] = %d\n", m, a[m]->key);
		
		if (a[m]->key == num) {
			return m;
		}
		if (num > a[m]->key) {
			l = m + 1;
		}
		else {
			r = m - 1;
		}
		step++;
	}
	return -1; 
}

int main() {
	item** p;
	int n;
	printf("n=");
	scanf_s("%d", &n);

	p = (item**)malloc(n*sizeof(struct item*));

	for (int i = 0; i < n; i++) {
		p[i] = (item*)malloc(sizeof(struct item));
		printf("p[%d]->key = ", i);
		scanf_s("%d", &p[i]->key);
	}

	int number;
	printf("searched number = ");
	scanf_s("%d", &number);
	int m = binary_search(p,n,number);
	if (m != -1)
		printf("\nvalue found at index %d\n", m);
	else
		printf("\nvalue not found\n");
}