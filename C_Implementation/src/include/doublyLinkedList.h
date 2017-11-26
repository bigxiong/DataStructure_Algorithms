#ifndef DOUBLY_LINKED_LIST
#define DOUBLY_LINKED_LIST
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

/*链表节点*/
typedef struct DoublyLinkedListNodeS{
	struct DoublyLinkedListNodeS *prev,*next;
}DoublyLinkedListNode;

typedef struct DoublyLinkedList{
	DoublyLinkedListNode root;//sentinel list element, only &root, root.prev, and root.next are used
	int length;
}DoublyLinkedList;

//初始化双向链表
DoublyLinkedList* DoublyLinkedList_Init();

//销毁链表
void DoublyLinkedList_Destory(DoublyLinkedList* list);

//链表长度
int DoublyLinkedList_Len(DoublyLinkedList* list);

//求头节点
DoublyLinkedListNode* DoublyLinkedList_Front(DoublyLinkedList* list);

//求尾节点
DoublyLinkedListNode* DoublyLinkedList_Back(DoublyLinkedList* list);

//在at位置后面插入e
DoublyLinkedListNode* DoublyLinkedList_InsertAfter(DoublyLinkedList* list, DoublyLinkedListNode* at,DoublyLinkedListNode* e);

//在at前面插入e，成功返回e
DoublyLinkedListNode* DoublyLinkedList_InsertBefore(DoublyLinkedList* list, DoublyLinkedListNode* at, DoublyLinkedListNode* e);

//在头部插入e
DoublyLinkedListNode* DoublyLinkedList_PushFront(DoublyLinkedList* list, DoublyLinkedListNode* e);

//在尾部插入e
DoublyLinkedListNode* DoublyLinkedList_PushBack(DoublyLinkedList* list, DoublyLinkedListNode* e);

//删除节点e,并返回被删除的e
DoublyLinkedListNode* DoublyLinkedList_Remove(DoublyLinkedList* list, DoublyLinkedListNode* e);

//将e移动到头部
void DoublyLinkedList_MoveFront(DoublyLinkedList* list, DoublyLinkedListNode* e);

//将e移动到尾部
void DoublyLinkedList_MoveBack(DoublyLinkedList* list, DoublyLinkedListNode* e);

#endif // DOUBLY_LINKED_LIST
