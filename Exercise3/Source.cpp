#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct item
{
	int key;
	void* data;
	item* next;
};

int main() {
	int n;
	printf("Size of array:");
	scanf_s("%d",&n);
	n *= 1000;

	int m;
	printf("Repetitions:");
	scanf_s("%d", &m);

	item* head = NULL;
	item* temp = NULL;
	item* p = NULL;

	time_t starttime=time(NULL);
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			temp = (item*)malloc(sizeof(item));
			temp->key = 0;
			temp->next = NULL;
			if (head == NULL) {
				head = temp;
			}
			else {
				p = head;
				while (p->next != NULL) {
					p = p->next;
				}
				p->next = temp;
			}
		}
	}
	time_t endtime;
	time(&endtime);
	printf("\nThe execution time for list = %d",int(endtime-starttime));


	item* arr;
	arr = (item*)malloc(n * sizeof(item));
	time_t starttimearr = time(NULL);
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {

			arr[i].key = 0;
		}
	}
	time_t endtimearr;
	time(&endtimearr);
	printf("\nThe execution time for array of items = %d", int(endtimearr - starttimearr));
	

	item** arrpoint;
	arrpoint = (item**)malloc(n * sizeof(item*));
	time_t starttimearr_item = time(NULL);
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			arrpoint[i] = (item*)malloc(sizeof(struct item));
			arrpoint[i]->key = 0;
		}
	}
	time_t endtimearr_item;
	time(&endtimearr_item);
	printf("\nThe execution time for array of poiners to items = %d", int(endtimearr_item - starttimearr_item));
	
}