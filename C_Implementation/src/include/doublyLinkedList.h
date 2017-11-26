#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

/*����ڵ�*/
typedef struct DoublyLinkedListNodeS{
	struct DoublyLinkedListNodeS *prev,*next;
}DoublyLinkedListNode;

typedef struct DoublyLinkedList{
	DoublyLinkedListNode root;//sentinel list element, only &root, root.prev, and root.next are used
	int length;
}DoublyLinkedList;

//��ʼ��˫������
DoublyLinkedList* DoublyLinkedList_Init();

//��������
void DoublyLinkedList_Destory(DoublyLinkedList* list);

//������
int DoublyLinkedList_Len(DoublyLinkedList* list);

//��ͷ�ڵ�
DoublyLinkedListNode* DoublyLinkedList_Front(DoublyLinkedList* list);

//��β�ڵ�
DoublyLinkedListNode* DoublyLinkedList_Back(DoublyLinkedList* list);

//��atλ�ú������e
DoublyLinkedListNode* DoublyLinkedList_InsertAfter(DoublyLinkedList* list, DoublyLinkedListNode* at,DoublyLinkedListNode* e);

//��atǰ�����e���ɹ�����e
DoublyLinkedListNode* DoublyLinkedList_InsertBefore(DoublyLinkedList* list, DoublyLinkedListNode* at, DoublyLinkedListNode* e);

//��ͷ������e
DoublyLinkedListNode* DoublyLinkedList_PushFront(DoublyLinkedList* list, DoublyLinkedListNode* e);

//��β������e
DoublyLinkedListNode* DoublyLinkedList_PushBack(DoublyLinkedList* list, DoublyLinkedListNode* e);

//ɾ���ڵ�e,�����ر�ɾ����e
DoublyLinkedListNode* DoublyLinkedList_Remove(DoublyLinkedList* list, DoublyLinkedListNode* e);

//��e�ƶ���ͷ��
void DoublyLinkedList_MoveFront(DoublyLinkedList* list, DoublyLinkedListNode* e);

//��e�ƶ���β��
void DoublyLinkedList_MoveBack(DoublyLinkedList* list, DoublyLinkedListNode* e);

#endif // DOUBLY_LINKED_LIST
