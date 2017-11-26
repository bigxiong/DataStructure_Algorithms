#include "doublyLinkedList.h"

DoublyLinkedList* DoublyLinkedList_Init() {
	DoublyLinkedList *list = (DoublyLinkedList *)malloc(sizeof(DoublyLinkedList));
	if (list == NULL) {
		fprintf(stderr,"malloc DoublyLinkedList error.\n");
		return NULL;
	}
	list->length = 0;
	list->root.next = &list->root;
	list->root.prev = &list->root;
	return list;
}

//��������
void DoublyLinkedList_Destory(DoublyLinkedList* list) {
	if (list != NULL) {
		free(list);
		list = NULL;
	}
}

int DoublyLinkedList_Len(DoublyLinkedList* list) {
	if (list == NULL) {
		return 0;
	}
	return list->length;
}

//��ͷ�ڵ�
DoublyLinkedListNode* DoublyLinkedList_Front(DoublyLinkedList* list) {
	if (list == NULL || list->length == 0) {
		return 0;
	}
	return list->root.next;
}

//��β�ڵ�
DoublyLinkedListNode* DoublyLinkedList_Back(DoublyLinkedList* list) {
	if (list == NULL || list->length == 0) {
		return 0;
	}
	return list->root.prev;
}

//��at�������e���ɹ�����e
DoublyLinkedListNode* DoublyLinkedList_InsertAfter(DoublyLinkedList* list, DoublyLinkedListNode* at, DoublyLinkedListNode* e) {
	if (list == NULL || at == NULL) {
		fprintf(stderr,"wrong argument\n");
		return NULL;
	}
	DoublyLinkedListNode* next = at->next;
	at->next = e;
	e->prev = at;
	e->next = next;
	next->prev = e;
	list->length++;
	return e;
}

//��atǰ�����e���ɹ�����e
DoublyLinkedListNode* DoublyLinkedList_InsertBefore(DoublyLinkedList* list, DoublyLinkedListNode* at, DoublyLinkedListNode* e) {
	if (list == NULL || at == NULL) {
		fprintf(stderr, "wrong argument\n");
		return NULL;
	}
	return DoublyLinkedList_InsertAfter(list, at->prev, e);
}

//��ͷ������e������e
DoublyLinkedListNode* DoublyLinkedList_PushFront(DoublyLinkedList* list, DoublyLinkedListNode* e) {
	return DoublyLinkedList_InsertAfter(list,&list->root,e);
}

//��β������e,����e
DoublyLinkedListNode* DoublyLinkedList_PushBack(DoublyLinkedList* list, DoublyLinkedListNode* e) {
	return DoublyLinkedList_InsertBefore(list, &list->root, e);
}

//ɾ���ڵ�e,�����ر�ɾ����e
DoublyLinkedListNode* DoublyLinkedList_Remove(DoublyLinkedList* list, DoublyLinkedListNode* e) {
	if (list == NULL || e == NULL) {
		return NULL;
	}

	e->prev->next = e->next;
	e->next->prev = e->prev;
	e->next = NULL;
	e->prev = NULL;
	list->length--;
	return e;
}

//��e�ƶ���ͷ��
void DoublyLinkedList_MoveFront(DoublyLinkedList* list, DoublyLinkedListNode* e) {
	if(list == NULL || e == NULL){
		return;
	}
	
	DoublyLinkedList_InsertAfter(list, &list->root, DoublyLinkedList_Remove(list,e));
}

//��e�ƶ���β��
void DoublyLinkedList_MoveBack(DoublyLinkedList* list, DoublyLinkedListNode* e) {
	if (list == NULL || e == NULL) {
		return;
	}

	DoublyLinkedList_InsertBefore(list, &list->root, DoublyLinkedList_Remove(list, e));
}


