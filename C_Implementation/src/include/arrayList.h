#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H
#include<stdio.h>
#include<stdlib.h>
#include<memory.h>

typedef void MyArrayListNode;
typedef struct _ArrayList {
	int length;         //��ǰ����
	int capacity;      //����
	unsigned int** data;//����ָ��
}MyArrayList;

//�������ҷ���һ���յ�ArrayList
MyArrayList* ArrayList_Create(int cap);

//����һ�����Ա�ArrayList
void ArrayList_Destroy(MyArrayList* list);

//��һ�����Ա�ArrayList�е�����Ԫ�����
void ArrayList_Clear(MyArrayList* list);

//����һ�����Ա�ArrayList�е�����Ԫ�ظ���
int ArrayList_Length(MyArrayList* list);

//��һ�����Ա�ArrayList��posλ�ô�������Ԫ��node
int ArrayList_Insert(MyArrayList* list, MyArrayListNode* node, int pos);

//��ȡһ�����Ա�ArrayList��posλ�ô���Ԫ��
MyArrayListNode* ArrayList_Get(MyArrayList* list, int pos);

//ɾ��һ�����Ա�ArrayList��posλ�ô���Ԫ��  ����ֵΪ��ɾ����Ԫ�أ�NULL��ʾɾ��ʧ��
MyArrayListNode* ArrayList_Delete(MyArrayList* list, int pos);

//����ArrayList �ռ��С�������¿ռ��С
int grow(MyArrayList* list, int size);
#endif // !ARRAY_LIST_H