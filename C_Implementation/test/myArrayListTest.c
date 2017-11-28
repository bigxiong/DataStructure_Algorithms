#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include"arrayList.h"

typedef struct Student{
	MyArrayListNode *node;
	int  id;
	char name[30];
}Stu;

int main() {

	MyArrayList* list = ArrayList_Create(5);
	Stu* stus = (Stu*)malloc(sizeof(Stu) * 6);
	printf("sizeof(struct Student):%d\n",sizeof(struct Student));
	printf("sizeof(stus):%d",sizeof(stus));
	printf("sizeof(*stus):%d", sizeof(*stus));

	for (int i = 0; i < 6; i++) {
		stus[i].id = i;
		sprintf(stus[i].name, "stu_%d", i);
		ArrayList_Insert(list, (MyArrayListNode*)&stus[i], 0);
	}
	for (int i = 0; i < 6; i++) {

		Stu *t = (Stu *)ArrayList_Get(list, i);
		printf("%d,%s\n",t->id,t->name);
	}


	system("pause");
	return 0;
}