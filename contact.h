#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define MAX 1000
#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_TELE 12
#define MAX_ADDR 30
#include <string.h>

// 创建一个通讯录内的信息
struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};

//	创建一个工具箱枚举，使switch语句内方便写
enum option
{
	Exit,
	Add,
	Del,
	Seacher,
	Modify,
	Show,
	Sort,
};

// 通讯录类型的创建，只是一个类型 
struct Contact
{
	struct PeoInfo data[MAX];// 存放一个信息
	int sz;// 记录当前已有元素个数
};

// 声明函数


// 1.初始化通讯录
void InitContact(struct Contact* ps);

// 2.添加一个信息到通讯录
void AddContact(struct Contact *ps);

// 3.打印通讯录里的信息
void ShowContact(const struct Contact *ps);

// 4.删除通讯录内某个指定的信息
void DelContact(struct Contact *ps);

// 5.查找通讯录内指定的联系人信息
void SeacherContact(const struct Contact* ps);

// 6.修改通讯录内指定联系人的信息
void ModifyContact(struct Contact* ps);

// 7.排序通讯录内指定联系人信息
void SortContact(struct Contact* ps);