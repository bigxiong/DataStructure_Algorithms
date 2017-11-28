#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

typedef void MyArrayListNode;
typedef struct _ArrayList {
	int length;         //当前长度
	int capacity;      //容量
	unsigned int** data;//数组指针
}MyArrayList;

//创建并且返回一个空的ArrayList
MyArrayList* ArrayList_Create(int cap);

//销毁一个线性表ArrayList
void ArrayList_Destroy(MyArrayList* list);

//将一个线性表ArrayList中的所有元素清空
void ArrayList_Clear(MyArrayList* list);

//返回一个线性表ArrayList中的所有元素个数
int ArrayList_Length(MyArrayList* list);

//向一个线性表ArrayList的pos位置处插入新元素node
int ArrayList_Insert(MyArrayList* list, MyArrayListNode* node, int pos);

//获取一个线性表ArrayList的pos位置处的元素
MyArrayListNode* ArrayList_Get(MyArrayList* list, int pos);

//删除一个线性表ArrayList的pos位置处的元素  返回值为被删除的元素，NULL表示删除失败
MyArrayListNode* ArrayList_Delete(MyArrayList* list, int pos);

//增加ArrayList 空间大小，返回新空间大小
int grow(MyArrayList* list, int size);
#endif // !ARRAY_LIST_H