#include<stdio.h>
#include<stdlib.h>
#include"linkedList.h"

typedef struct BusinessNodeStruct {
    LinkedListNode node;
    int  id;
    char name[30];
}BusinessNode;
int main() {

    LinkedList* list = LinkedList_Create();
    BusinessNode t1 = {NULL,21,"Beijing1"};
    BusinessNode t2 = { NULL,31,"Beijing2" };
    BusinessNode t3 = { NULL,41,"Beijing3" };
    BusinessNode t4 = { NULL,51,"Beijing4" };
    LinkedList_Insert(list, (LinkedListNode*)&t2, 0);
    LinkedList_Insert(list, &t3.node, 0);
    LinkedList_Insert(list, (LinkedListNode*)&t4, 0);

    for (int i = 0; i < list->length; i++) {
        BusinessNode* bNode = (BusinessNode*)LinkedList_Get(list,i);
        printf("bNode->name:%s,bNode->id:%d\n",bNode->name,bNode->id);
    }
    LinkedList_Delete(list, 1);
    printf("-----------after delete------------");
    for (int i = 0; i < list->length; i++) {
        BusinessNode* bNode = (BusinessNode*)LinkedList_Get(list, i);
        printf("bNode->name:%s,bNode->id:%d\n", bNode->name, bNode->id);
    }

    system("pause");
    return 0;
}