#include<stdio.h>
#include<stdlib.h>
#define N 8
#define HTSIZE 100

struct hash_slot2 {
	int key;
	void* data;
};
struct hash_slot {
	hash_slot2 slot[N];
};

int hf(int k) {
	return k % HTSIZE;
} 

hash_slot hashtable[HTSIZE];

hash_slot2* hash_search(int k, int *hash_slot, int*slot) {
	int i, slot_index;
	slot_index = hf(k);
	for (i = 0; i < N; i++) {
		if (hashtable[slot_index].slot[i].key==k) {
			*hash_slot = slot_index;
			*slot = i;
			return hashtable[slot_index].slot+i;
		}
		return NULL;
	}
}

int main() {
	
	int input_key;

	for (int i = 0; i < N; i++) {
		printf("key=");
		scanf_s("%d\n", &input_key);
		int hash_slot=hf(input_key);
		for (int j = 0; j < N; j++) {
			if (hashtable[hash_slot].slot[i].key == 0) {
				hashtable[hash_slot].slot[i].key = input_key;
			}
			else {
				printf("The hash slot %d is full",hash_slot);
			}
		}
		printf("\nThe key %d is stored in hash_slot %d in slot %d", input_key, hash_slot, i);
		//print slot and subslot of stored key
	}

	int searched_key;
	printf("\nsearched key=");
	scanf_s("\n%d", &searched_key);
	hash_slot2* found;
	int* ihs=NULL;
	int* is=NULL;
	found = hash_search(searched_key, ihs, is);
	
	if (found != NULL) {
		printf("\nIndex of slot = %d, index of subslot = %d of the searched key.", ihs, is);
	}
	
}