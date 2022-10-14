#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "contact.h"



// 函数实现

// 查找函数的实现
static int FindBy_name(const struct Contact* ps, char name[MAX_NAME])
{
	int i = 0;
	for (i = 0; i < ps->sz; i++)
	{
		if (strcmp(ps->data[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}

// 1.初始化通讯录
void InitContact(struct Contact* ps)
{
	memset(ps->data, 0, sizeof(ps->data));
	ps->sz = 0;// 设置通讯录里最初只有0个元素
};

// 2.添加一个信息到通讯录
void AddContact(struct Contact* ps)
{
	if (ps->sz == MAX)
	{
		printf("通讯录已满,无法添加!\n");
	}
	else
	{
		printf("请输入名字:>");
		scanf("%s", ps->data[ps->sz].name);
		printf("请输入年龄:>");
		scanf("%d", &(ps->data[ps->sz].age));
		printf("请输入性别:>");
		scanf("%s", ps->data[ps->sz].sex);
		printf("请输入号码:>");
		scanf("%s", ps->data[ps->sz].tele);
		printf("请输入地址:>");
		scanf("%s", ps->data[ps->sz].addr);
		ps->sz++;
		printf("添加成功!当前共%d个信息。\n",ps->sz);
		Sleep(1200);
	}
}

// 3.打印通讯录里的信息
void ShowContact(const struct Contact* ps)
{
	if (ps->sz == 0)
	{
		printf("通讯录为空!\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-13s\t%-20s\n", "姓名", "年龄", "性别", "号码", "地址");
		//  打印标题
		int i = 0;
		for (i = 0; i < ps->sz; i++)
		{
			printf("%-20s\t%-4d\t%-5s\t%-13s\t%-20s\n", 
				ps->data[i].name,
				ps->data[i].age,
				ps->data[i].sex,
				ps->data[i].tele,
				ps->data[i].addr );
		}
	}
	Sleep(1200);
}

// 4.删除通讯录内某个指定的信息
void DelContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要删除用户的名字:");
	scanf("%s", name);
	//  查找所需用户的位置
	int ret=FindBy_name(ps, name);
	//  删除信息
	if (ret==-1)
	{	// 已经满了还没找到
		printf("查无此人!\n");
	}
	else
	{
		int j = 0;
		for (j = ret; j < ps->sz - 1; j++)
		{// j=i,从找到的位置开始，5放4位置，6放5位置，如此直到最后
			ps->data[j] = ps->data[j + 1];
		}
		ps->sz--;// 最后一个位置--，最后一个位置删除不能访问
		printf("删除成功!\n");
	}
	Sleep(1200);
}

//  5.查找指定联系人的信息
void SeacherContact(const struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要查找用户的名字:");
	scanf("%s", name);
	//  查找所需用户的位置
	int ret = FindBy_name(ps, name);
	if (ret == -1)
	{
		printf("查无此人!\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-13s\t%-20s\n", "姓名", "年龄", "性别", "号码", "地址");
		printf("%-20s\t%-4d\t%-5s\t%-13s\t%-20s\n",
			ps->data[ret].name,
			ps->data[ret].age,
			ps->data[ret].sex,
			ps->data[ret].tele,	
			ps->data[ret].addr);		
	}
	Sleep(2000);
}

//  6.修改指定联系人的信息
void ModifyContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入要修改用户的名字:");
	scanf("%s", name);
	//  查找所需用户的位置
	int ret = FindBy_name(ps, name);
	if (ret == -1)
	{
		printf("查无此人!\n");
	}
	else
	{
		printf("请输入名字:>");
		scanf("%s", ps->data[ret].name);
		printf("请输入年龄:>");
		scanf("%d", &(ps->data[ret].age));
		printf("请输入性别:>");
		scanf("%s", ps->data[ret].sex);
		printf("请输入号码:>");
		scanf("%s", ps->data[ret].tele);
		printf("请输入地址:>");
		scanf("%s", ps->data[ret].addr);
		printf("修改成功!\n");
	}
	Sleep(500);
}