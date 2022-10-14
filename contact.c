#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "contact.h"



// ����ʵ��

// ���Һ�����ʵ��
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

// 1.��ʼ��ͨѶ¼
void InitContact(struct Contact* ps)
{
	memset(ps->data, 0, sizeof(ps->data));
	ps->sz = 0;// ����ͨѶ¼�����ֻ��0��Ԫ��
};

// 2.���һ����Ϣ��ͨѶ¼
void AddContact(struct Contact* ps)
{
	if (ps->sz == MAX)
	{
		printf("ͨѶ¼����,�޷����!\n");
	}
	else
	{
		printf("����������:>");
		scanf("%s", ps->data[ps->sz].name);
		printf("����������:>");
		scanf("%d", &(ps->data[ps->sz].age));
		printf("�������Ա�:>");
		scanf("%s", ps->data[ps->sz].sex);
		printf("���������:>");
		scanf("%s", ps->data[ps->sz].tele);
		printf("�������ַ:>");
		scanf("%s", ps->data[ps->sz].addr);
		ps->sz++;
		printf("��ӳɹ�!��ǰ��%d����Ϣ��\n",ps->sz);
		Sleep(1200);
	}
}

// 3.��ӡͨѶ¼�����Ϣ
void ShowContact(const struct Contact* ps)
{
	if (ps->sz == 0)
	{
		printf("ͨѶ¼Ϊ��!\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-13s\t%-20s\n", "����", "����", "�Ա�", "����", "��ַ");
		//  ��ӡ����
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

// 4.ɾ��ͨѶ¼��ĳ��ָ������Ϣ
void DelContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫɾ���û�������:");
	scanf("%s", name);
	//  ���������û���λ��
	int ret=FindBy_name(ps, name);
	//  ɾ����Ϣ
	if (ret==-1)
	{	// �Ѿ����˻�û�ҵ�
		printf("���޴���!\n");
	}
	else
	{
		int j = 0;
		for (j = ret; j < ps->sz - 1; j++)
		{// j=i,���ҵ���λ�ÿ�ʼ��5��4λ�ã�6��5λ�ã����ֱ�����
			ps->data[j] = ps->data[j + 1];
		}
		ps->sz--;// ���һ��λ��--�����һ��λ��ɾ�����ܷ���
		printf("ɾ���ɹ�!\n");
	}
	Sleep(1200);
}

//  5.����ָ����ϵ�˵���Ϣ
void SeacherContact(const struct Contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫ�����û�������:");
	scanf("%s", name);
	//  ���������û���λ��
	int ret = FindBy_name(ps, name);
	if (ret == -1)
	{
		printf("���޴���!\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-13s\t%-20s\n", "����", "����", "�Ա�", "����", "��ַ");
		printf("%-20s\t%-4d\t%-5s\t%-13s\t%-20s\n",
			ps->data[ret].name,
			ps->data[ret].age,
			ps->data[ret].sex,
			ps->data[ret].tele,	
			ps->data[ret].addr);		
	}
	Sleep(2000);
}

//  6.�޸�ָ����ϵ�˵���Ϣ
void ModifyContact(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("������Ҫ�޸��û�������:");
	scanf("%s", name);
	//  ���������û���λ��
	int ret = FindBy_name(ps, name);
	if (ret == -1)
	{
		printf("���޴���!\n");
	}
	else
	{
		printf("����������:>");
		scanf("%s", ps->data[ret].name);
		printf("����������:>");
		scanf("%d", &(ps->data[ret].age));
		printf("�������Ա�:>");
		scanf("%s", ps->data[ret].sex);
		printf("���������:>");
		scanf("%s", ps->data[ret].tele);
		printf("�������ַ:>");
		scanf("%s", ps->data[ret].addr);
		printf("�޸ĳɹ�!\n");
	}
	Sleep(500);
}