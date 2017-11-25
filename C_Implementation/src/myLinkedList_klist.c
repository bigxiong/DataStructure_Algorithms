#include "klist.h"
#include <stdlib.h>
#include <stdio.h>
/*
 * MyLinkedList 为双向链表的哨兵节点
 * head->next 为头节点
 * head->prev 为尾节点
 * */ 
typedef struct MyLinkedListStruct{
    struct list_head head;
    int              length;
}MyLinkedList;

typedef struct business_node {
    struct list_head listNode;
    int  id; //业务节点数据域
    char strData[30];
}BNode;

//初始化链表
void MyLinkedList_Node_init(MyLinkedList* list){
    INIT_LIST_HEAD(&list->head);
}

//在尾部插入元素n
void MyLinkedList_add_tail(MyLinkedList* list,struct list_head* n){
    list_add_tail(n,&list->head);
    list->length++;
}
//在头部插入元素n
void MyLinkedList_add_front(MyLinkedList* list,struct list_head* n){
    list_add(n,&list->head);
    list->length++;
}
//移动节点到头部
void MyLinkedList_move_front(MyLinkedList* list,struct list_head* n){
    list_move(n,&list->head);
}
//移动节点到尾部
void MyLinkedList_move_tail(MyLinkedList* list,struct list_head* n){
    list_move_tail(n,&list->head);
}
//删除节点
void MyLinkedList_del(MyLinkedList* list,struct list_head* n){
    list_del(n);
    list->length--;
}
//删除节点，并初始化被删除的节点
void MyLinkedList_del_init(MyLinkedList* list,struct list_head* n){
    list_del_init(n);
    list->length--;
}
//将old节点替换为new
void MyLinkedList_replace(MyLinkedList* list,struct list_head* old,struct list_head* new){
list_replace(old,new);
list->length--;
}
//将old节点替换为new,并且初始化old节点（摘除）
void MyLinkedList_replace_init(MyLinkedList* list,struct list_head* old,struct list_head* new){
list_replace_init(old,new);
list->length--;
}

//从头部开始遍历打印链表
void MyLinkedList_iterate_from_front1(MyLinkedList* list){
    //3.iterate node
    struct list_head *pos = NULL;
    BNode *tmpBNode = NULL;
    /*
     * for (pos = (head)->next; pos != (head); pos = pos->next)
     * */
    list_for_each(pos,&list->head){
        tmpBNode = list_entry(pos,BNode,listNode);//
        printf("BNode->id:%d,BNode->strData:%s\n",tmpBNode->id,tmpBNode->strData);
    }
}
//从头部开始遍历打印链表2
void MyLinkedList_iterate_from_front2(MyLinkedList* list){

    BNode* pos = NULL;
    //struct list_head* head = &list->head;
    /*
     * for (pos = list_entry((head)->next, typeof(*pos), member);  \
			&pos->member != (head);    \
			pos = list_entry(pos->member.next, typeof(*pos), member))
     *
     */
    list_for_each_entry(pos,&list->head,listNode){
        printf("BNode->id:%d,BNode->strData:%s\n",pos->id,pos->strData);
    }

//    for (pos = list_entry((head)->next, BNode, listNode);&pos->listNode != (head);pos = list_entry(pos->listNode.next,BNode, listNode)){
//        printf("BNode->id:%d,BNode->strData:%s\n",pos->id,pos->strData);
//    }

}
////从尾部开始遍历打印链表
void MyLinkedList_iterate_from_tail(MyLinkedList* list){

    BNode* pos = NULL;
    //struct list_head* head = &list->head;
    /*
     * for (pos = list_entry((head)->next, typeof(*pos), member);  \
			&pos->member != (head);    \
			pos = list_entry(pos->member.next, typeof(*pos), member))
     *
     */
    list_for_each_entry_reverse(pos,&list->head,listNode){
        printf("BNode->id:%d,BNode->strData:%s\n",pos->id,pos->strData);
    }

//    for (pos = list_entry((head)->next, BNode, listNode);&pos->listNode != (head);pos = list_entry(pos->listNode.next,BNode, listNode)){
//        printf("BNode->id:%d,BNode->strData:%s\n",pos->id,pos->strData);
//    }

}
//从头部开始遍历并删除链表节点
void MyLinkedList_iterate_from_front2SafeDel(MyLinkedList* list){
    BNode* pos  = NULL;
    BNode* next = NULL;
    list_for_each_entry_safe(pos,next,&list->head,listNode){
        MyLinkedList_del(list,&pos->listNode);
    }
}
//从尾部开始遍历并删除链表节点
void MyLinkedList_iterate_from_tailSafeDel(MyLinkedList* list){
    BNode* pos  = NULL;
    BNode* next = NULL;
    list_for_each_entry_safe_reverse(pos,next,&list->head,listNode){
        MyLinkedList_del(list,&pos->listNode);
    }
}
//是否是最后一个节点
int MyLinkedList_is_last(MyLinkedList* list,struct list_head* n){
    return list_is_last(n,&list->head);
}
//销毁链表
void MyLinkedList_destroy(MyLinkedList* list){
    struct list_head* pos  = list->head.next;
    struct list_head* next = NULL;
    while(!MyLinkedList_is_empty1(list)){
        next = pos->next;
        list_del(pos);
        pos = next;
        MyLinkedList_del(list,pos);
    }

}
//链表是否为空
int MyLinkedList_is_empty1(MyLinkedList* list){
    return list_empty(&list->head);
}
//链表是否为空
int MyLinkedList_is_empty2(MyLinkedList* list){
    return list->length == 0;
}
//链表是否为空
int MyLinkedList_is_empty_careful(MyLinkedList* list){
    return list_empty_careful(&list->head);
}
//链表是否只有一个节点
int MyLinkedList_is_singular(MyLinkedList* list){
    return list_is_singular(&list->head);
}
//从n位置截断链表，并返回被分割后的另一半链表
MyLinkedList* MyLinkedList_cut_position(MyLinkedList* list, struct list_head* n){
    struct list_head* newHead;
    list_cut_position(newHead,&list->head,n);
    MyLinkedList* newMyLinkedList = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    newMyLinkedList->head = *newHead;
    return newMyLinkedList;

}
//将n链表连接到头部
void MyLinkedList_splice_front(MyLinkedList* list,struct list_head* n){
    list_splice(n,&list->head);
}
//将n链表连接到头部，并初始化list指针
void MyLinkedList_splice_front_init(MyLinkedList* list,struct list_head* n){
    list_splice_init(n,&list->head);
}
//将n链表连接到尾部
void MyLinkedList_splice_tail(MyLinkedList* list,struct list_head* n){
    list_splice_tail(n,&list->head);
}
//将n链表连接到尾部，并初始化list指针
void MyLinkedList_splice_tail_init(MyLinkedList* list,struct list_head* n){
    list_splice_tail_init(n,&list->head);
}
