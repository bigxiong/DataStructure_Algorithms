#include"arrayList.h"

MyArrayList* ArrayList_Create(int capacity) {
	MyArrayList *list = NULL;
	list = (MyArrayList *)malloc(sizeof(MyArrayList));
	if (list == NULL) {
		fprintf(stderr,"create ArrayList failed.\n");
		return NULL;
	}
	memset(list, 0, sizeof(list));
	list->data = (unsigned int**)malloc(sizeof(unsigned int*) * capacity);
	if (list->data == NULL) {
		fprintf(stderr, "malloc data space failed.\n");
		return NULL;
	}
	list->capacity = capacity;
	list->length = 0;
	return  list;
}

void ArrayList_Destroy(MyArrayList* list) {
	if (list == NULL) {
		return;
	}
	if (list->data) {
		free(list->data);
	}
	free(list);
}

void ArrayList_Clear(MyArrayList* list) {
	if (list == NULL) {
		return;
	}
	list->length = 0;
}

int ArrayList_Length(MyArrayList* list) {
	MyArrayList* arrayList = (MyArrayList* )list;
	return arrayList->length;
}

int ArrayList_Insert(MyArrayList* list, MyArrayListNode* node, int pos) {
	
	if (list == NULL) {
		return -1;
		fprintf(stderr,"the ArrayList is Null\n");
	}
	if (pos < 0) {
		return -2;
		fprintf(stderr, "the ArrayList is Null\n");
	}
	if (list->length == list->capacity) {
		fprintf(stdout, "the ArrayList is Full,Grow Capacity\n");
		int ret = grow(list,list->capacity * 2);
		if (ret == -1) {
			return -3;
		}
	}

	for (int i = list->length; i > pos; i--) {
		list->data[i] = list->data[i - 1];
	}
	list->data[pos] = (unsigned int*)node;
	list->length += 1;
	return 0;
}

MyArrayListNode* ArrayList_Get(MyArrayList* list, int pos) {
	if (list == NULL || pos < 0 || pos > list->length) {
		fprintf(stderr,"wrong arguments\n");
		return NULL;
	}
	return (MyArrayListNode*)list->data[pos];
}

MyArrayListNode* ArrayList_Delete(MyArrayList* list, int pos){
	if (list == NULL || pos < 0 || pos > list->length) {
		fprintf(stderr, "wrong arguments\n");
		return NULL;
	}
	MyArrayListNode* node = (MyArrayListNode*)list->data[pos];
	for (int i = pos + 1; i < list->length; i++) {
		list->data[i-1] = list->data[i];
	}
	list->length--;
	return node;
}

int grow(MyArrayList* list, int size) {
	if (list == NULL || size < list->capacity) {
		fprintf(stderr, "wrong argument.\n");
		return -1;
	}
	int newSize = size;
	if (size > 2 * list->capacity) {
		newSize = 2 * list->capacity;
	}
	unsigned int **oldData = list->data;
	unsigned int **newData = (unsigned int**)malloc(newSize * sizeof(unsigned int*));
	if (newData == NULL) {
		fprintf(stderr,"grow capacity failed.\n");
		return -1;
	}

	list->data = newData;
	memset(list->data,0, newSize * sizeof(unsigned int *));
	memcpy(list->data, oldData, list->length * sizeof(unsigned int *));
	list->capacity = newSize;
	free(oldData);
	return newSize;
}
