#include<stdio.h>
#include<stdlib.h>
#include "myLinkedList_klist.c"
int main() {

    BNode* pos;
    MyLinkedList *myList = (MyLinkedList*)malloc(sizeof(MyLinkedList));
    MyLinkedList_Node_init(myList);//1.初始化链表,dummy_node
    printf("init_head: list_is_singular: %d\n",MyLinkedList_is_singular(myList));
    printf("init_head: list_is_empty   : %d\n",MyLinkedList_is_empty1(myList));

    BNode* bNodes = (BNode*)malloc(sizeof(BNode));
    int i = 0;
    for(i = 0; i < 5; i++){
        bNodes[i].id = i;
        sprintf(bNodes[i].strData,"BusinessNode-%d",i);
    }


    //2.insert an tail
    for(i = 0; i < 5; i++){
        MyLinkedList_add_tail(myList,&bNodes[i].listNode);
        printf("list_is_singular after insert %d: %d\n",i,list_is_singular(&myList->head));
    }

    printf("b1 isLastNode: %d\n",list_is_last(&bNodes[1].listNode,&myList->head));
    printf("b5 isLastNode: %d\n",list_is_last(&bNodes[5].listNode,&myList->head));
    MyLinkedList_iterate_from_front1(myList);

    printf("---Move first node to tail:---\n");
    MyLinkedList_move_tail(myList,&bNodes[0].listNode);
    MyLinkedList_iterate_from_front2(myList);


    printf("---MyLinkedList_iterate_from_front2SafeDel:---\n");
    MyLinkedList_iterate_from_front2SafeDel(myList);
    MyLinkedList_iterate_from_front2(myList);

#if 0
    printf("---Destroy myLinkedList:---\n");
    MyLinkedList_destroy(myList);
    MyLinkedList_iterate_from_front2(myList);
#endif

}

