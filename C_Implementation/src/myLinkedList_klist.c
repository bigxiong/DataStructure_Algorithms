#include "klist.h"

/*
 * list_head
 *
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

void MyLinkedList_Node_init(MyLinkedList* list){
    INIT_LIST_HEAD(&list->head);
}

void MyLinkedList_add_tail(MyLinkedList* list,struct list_head* n){
    list_add_tail(n,&list->head);
    list->length++;
}

void MyLinkedList_add_front(MyLinkedList* list,struct list_head* n){
    list_add(n,&list->head);
    list->length++;
}

void MyLinkedList_move_front(MyLinkedList* list,struct list_head* n){
    list_move(n,&list->head);
}

void MyLinkedList_move_tail(MyLinkedList* list,struct list_head* n){
    list_move_tail(n,&list->head);
}

void MyLinkedList_del(MyLinkedList* list,struct list_head* n){
    list_del(n);
    list->length--;
}

void MyLinkedList_del_init(MyLinkedList* list,struct list_head* n){
    list_del_init(n);
    list->length--;
}

void MyLinkedList_replace(MyLinkedList* list,struct list_head* old,struct list_head* new){
list_replace(old,new);
list->length--;
}

void MyLinkedList_replace_init(MyLinkedList* list,struct list_head* old,struct list_head* new){
list_replace_init(old,new);
list->length--;
}


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

void MyLinkedList_iterate_from_front2SafeDel(MyLinkedList* list){
    BNode* pos  = NULL;
    BNode* next = NULL;
    list_for_each_entry_safe(pos,next,&list->head,listNode){
        MyLinkedList_del(list,&pos->listNode);
    }
}

void MyLinkedList_iterate_from_tailSafeDel(MyLinkedList* list){
    BNode* pos  = NULL;
    BNode* next = NULL;
    list_for_each_entry_safe_reverse(pos,next,&list->head,listNode){
        MyLinkedList_del(list,&pos->listNode);
    }
}

int MyLinkedList_is_last(MyLinkedList* list,struct list_head* n){
    return list_is_last(n,&list->head);
}

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

int MyLinkedList_is_empty1(MyLinkedList* list){
    return list_empty(&list->head);
}

int MyLinkedList_is_empty2(MyLinkedList* list){
    return list->length == 0;
}

int MyLinkedList_is_empty_careful(MyLinkedList* list){
    return list_empty_careful(&list->head);
}

int MyLinkedList_is_singular(MyLinkedList* list){
    return list_is_singular(&list->head);
}

MyLinkedList* MyLinkedList_cut_position(MyLinkedList* list, struct list_head* n){
    struct list_head* newHead;
    list_cut_position(newHead,&list->head,n);
    MyLinkedList* newMyLinkedList = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    newMyLinkedList->head = *newHead;
    return newMyLinkedList;

}

void MyLinkedList_splice_front(MyLinkedList* list,struct list_head* n){
    list_splice(n,&list->head);
}

void MyLinkedList_splice_front_init(MyLinkedList* list,struct list_head* n){
    list_splice_init(n,&list->head);
}

void MyLinkedList_splice_tail(MyLinkedList* list,struct list_head* n){
    list_splice_tail(n,&list->head);
}
void MyLinkedList_splice_tail_init(MyLinkedList* list,struct list_head* n){
    list_splice_tail_init(n,&list->head);
}
