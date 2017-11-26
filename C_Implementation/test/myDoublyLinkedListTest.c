#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"doublylinkedList.h"

typedef struct Student{
	DoublyLinkedListNode node;
	int  id;
	char name[30];
}Stu;

void printStuDoublyLinkedList(DoublyLinkedList *list) {
	DoublyLinkedListNode* p = DoublyLinkedList_Front(list);
	while (p != &list->root) {
		Stu* s = (Stu*)p;
		p = p->next;
		printf("stu->id: %d, stu->name: %s\n", s->id, s->name);
	}
}

int main() {

	DoublyLinkedList* list = DoublyLinkedList_Init();

	Stu* stus = (Stu*)malloc(sizeof(Stu*) * 5);
	for (int i = 0; i < 5; i++) {
		stus[i].id   = i;
		sprintf(stus[i].name, "stu_%d", i);
		DoublyLinkedList_PushBack(list, (DoublyLinkedListNode*)&stus[i]);
	}
	printf("---------after insert------------\n");
	printf("Length:%d\n", DoublyLinkedList_Len(list));
	printStuDoublyLinkedList(list);
	
	printf("---------move back to front------------\n");
	printf("Length:%d\n", DoublyLinkedList_Len(list));
	DoublyLinkedListNode* back = DoublyLinkedList_Back(list);
	DoublyLinkedList_MoveFront(list,back);
	printStuDoublyLinkedList(list);

	printf("---------after delete the penult element------------\n");
	printf("Length:%d\n", DoublyLinkedList_Len(list));
	DoublyLinkedListNode* e = DoublyLinkedList_Back(list);
	DoublyLinkedList_Remove(list, e->prev);
	printStuDoublyLinkedList(list);

	system("pause");
	return 0;
}