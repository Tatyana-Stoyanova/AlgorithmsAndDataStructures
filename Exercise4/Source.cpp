#include<stdio.h>
#include<stdlib.h>

struct item
{
	int key;
	void* data;
	item* next;
};

item *tos;
item *tail;
item *head;


int push(item* v)
{
	v->next = tos;
	tos = v;
	return 0;
}

int pop(item* v)
{
	if (tos == NULL) return -1;
	*v = *tos;
	tos = tos->next;
	return 0;
}

void enqueue(item* v)
{
	if (tail == NULL)
		head = tail = v;
	else
	{
		tail->next = v;
		tail = v;
	}
}

int dequeue(item* v)
{
	if (head == NULL) return -1;
	*v = *head;
	head = head->next;
	if (head == NULL) tail = NULL;
	return 0;
}

void printq() {
	while (head!=NULL) {
		printf("key=%d", head->key);
		dequeue(head);
	}
}

void printstack() {
	while(tos!=NULL){
		printf("key=%d",tos->key);
		pop(tos);
	}
}

int main() {
	int newKey;
	char user;
	char task;
	item *v = (item*)malloc(sizeof(item));
	tos = NULL;
	head = NULL;
	tail = NULL;

	do {
		printf("Stack(s) or queue(q)?\n");
		scanf_s("%c", &user);
	} while (user != 's' && user != 'q');

	if (user == 'q') {
		printf("enqueue (e) or dequeue (d) or print all queue (p)?\n");
		scanf_s(" %c", &task);
		if (task == 'e') {
			printf("Key=");
			scanf_s(" %d", &newKey);//user input for key
			v->key = newKey;
			enqueue(v);
		}
		else if (task == 'd') {
			dequeue(head);
			printq();
		}
		else if (task == 'p') {
			printq();
		}
	}
	else if (user == 's') {
		printf("push(u) or pop(o) or print all stack(p) ?\n");
		scanf_s(" %c", &task);
		if (task == 'u') {
			printf("Key=");
			scanf_s(" %d", &newKey);//user input for key

			v->key = newKey;
			push(v);

		}
		else if (task == 'o') {
			pop(tos);
			printstack();
		}
		else if (task == 'p') {
			printstack();
		}
	}
	else {
		printf("\nNot good choice! Try again!");
	}
}

	
