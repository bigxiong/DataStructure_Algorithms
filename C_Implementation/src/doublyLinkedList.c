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

//销毁链表
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

//求头节点
DoublyLinkedListNode* DoublyLinkedList_Front(DoublyLinkedList* list) {
	if (list == NULL || list->length == 0) {
		return 0;
	}
	return list->root.next;
}

//求尾节点
DoublyLinkedListNode* DoublyLinkedList_Back(DoublyLinkedList* list) {
	if (list == NULL || list->length == 0) {
		return 0;
	}
	return list->root.prev;
}

//在at后面插入e，成功返回e
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

//在at前面插入e，成功返回e
DoublyLinkedListNode* DoublyLinkedList_InsertBefore(DoublyLinkedList* list, DoublyLinkedListNode* at, DoublyLinkedListNode* e) {
	if (list == NULL || at == NULL) {
		fprintf(stderr, "wrong argument\n");
		return NULL;
	}
	return DoublyLinkedList_InsertAfter(list, at->prev, e);
}

//在头部插入e，返回e
DoublyLinkedListNode* DoublyLinkedList_PushFront(DoublyLinkedList* list, DoublyLinkedListNode* e) {
	return DoublyLinkedList_InsertAfter(list,&list->root,e);
}

//在尾部插入e,返回e
DoublyLinkedListNode* DoublyLinkedList_PushBack(DoublyLinkedList* list, DoublyLinkedListNode* e) {
	return DoublyLinkedList_InsertBefore(list, &list->root, e);
}

//删除节点e,并返回被删除的e
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

//将e移动到头部
void DoublyLinkedList_MoveFront(DoublyLinkedList* list, DoublyLinkedListNode* e) {
	if(list == NULL || e == NULL){
		return;
	}
	
	DoublyLinkedList_InsertAfter(list, &list->root, DoublyLinkedList_Remove(list,e));
}

//将e移动到尾部
void DoublyLinkedList_MoveBack(DoublyLinkedList* list, DoublyLinkedListNode* e) {
	if (list == NULL || e == NULL) {
		return;
	}

	DoublyLinkedList_InsertBefore(list, &list->root, DoublyLinkedList_Remove(list, e));
}


