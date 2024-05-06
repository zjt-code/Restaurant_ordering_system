#pragma once
#include<stdio.h>//studio ָ ��stuandard input & output"����׼���������(���õĺ�����fopen()��fflush()��fwrite()��scanf()��fscanf()��fprintf()��sprintf()��perror())
#include<string.h>//������һ���������͡�һ����͸��ֲ����ַ�����ĺ��������õĺ�����sturcpy()��sturcat()��sturchr()��sturcmp()��sturlen()��sturcspn()��sturdup()��sturerror()��sturncmp()��
#include<stdlib.h>//�������������͡�һЩ���ͨ�ù��ߺ���(���õĺ�����malloc()��calloc()��realloc()��free()��systuem()��atoi()��atol()��rand()��srand()��exit())
#include<time.h>
#include<stdbool.h>

#pragma warning (disable:4996) //��������(�ر�VS2010�İ�ȫ���棬 ��ΪVS2020��C++���)

#define TABLE_MAX   		200
#define CUSTOMER_MAX 		200
#define JOURNAL_MAX    		200



//����
typedef struct Dates
{
	int year;//��
	int mon;//��
	int day;//��
	int hour;
	int min;
}Dates;

//��̨����
typedef struct Table
{
	char TableNo[20];			//��̨��ţ���������001,002,003...
	char TableType;				//��̨���ͣ�A-С����B-������C-���� �ֱ���4�� 6�� 8��
	int MaxSeat;				//�����λ�����ɸ��ݲ�λ�����Զ���������λ��
	char TableState[20];		//��̨״̬��"NULL"-�� �˿��ֻ�����-ռ��
}Table;
Table tables[TABLE_MAX];//����ṹ�����飬 �����洢����Ϊ200

//�ͲͰ���
//ͬһ���ڡ�ͬһ�Ͳ�ʱ���ֻ�����Ψһ
typedef struct Repast
{
	char CustomerPhone[15];		//�˿��ֻ�����
	Dates Time;					//�Ͳ����ڣ���2015 05 02
	char Times;					//�Ͳ�ʱ�Σ�L-���  D-���
	int NumberOfMeals;			//�Ͳ�����
	char TableNo[20];			//��̨��ţ�Ĭ��Ϊ"000",��ʾδ���Ų�λ
	char TableType;				//��̨���ͣ�A-С����B-������C-���� �ֱ���4�� 6�� 8��
	char WaitNum[20];				//��λ��ţ��ɲ�λ����+��λ��Ź��ɣ���A012��B044
	struct Repast *next;
	
}Repast;
Repast repasts[CUSTOMER_MAX];//����ṹ�����飬 ���չ˿������洢����Ϊ200

// ����file02 �еļ�¼�������������ڵ�
Repast all_repasts_head={.next=NULL};
int all_repast_count =0;


//�ͲͰ���
//ͬһ���ڡ�ͬһ�Ͳ�ʱ���ֻ�����Ψһ
typedef struct Journal
{
	Dates Time;					//�Ͳ����ڣ���2015 05 02
	char TableNo[20];			//��̨��ţ�Ĭ��Ϊ"000",��ʾδ���Ų�λ
	char TableType;				//��̨���ͣ�A-С����B-������C-���� �ֱ���4�� 6�� 8��
}Journal;
Journal Journals[JOURNAL_MAX];//����ṹ�����飬 ��ˮ�˴洢����Ϊ200

// ������λ��Ϣ��������
void Save_Restaurant_Table(Table *table);//��λ���溯��
void Read_Restaurant_Table();//��λ��ȡ����

// �û���Ϣ���ݲ�����صĺ���

void Input_user();//�˿͵�λ����ȡ��
void Read_user();//�ͻ�ȡ�Ŷ�ȡ����
void Save_user(Repast * c_user);//�ͻ�ȡ�ű��溯��

// ��������
void Show_One_Customer(Repast *c);
bool compare_time_with_local( Dates * date);


// �û���Ϣ�б��������,��file02.dat ��ȡ������
void All_Repast_Append(Repast *new_element);// �б�����һ��Ԫ��
void All_Repast_Show(Dates *datetime, bool all);  // ��ʾ���еĶ�����¼

void All_Prepast_SelDay();

// ������


void Statistics();//ͳ��������
void Statictisc_Show_Menu();// ��ʾͳ�Ʋ˵�ѡ��
#define debug 	1

