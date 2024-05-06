#pragma once
#include<stdio.h>//studio 指 “stuandard input & output"（标准输入输出）(常用的函数如fopen()、fflush()、fwrite()、scanf()、fscanf()、fprintf()、sprintf()、perror())
#include<string.h>//定义了一个变量类型、一个宏和各种操作字符数组的函数（常用的函数如sturcpy()、sturcat()、sturchr()、sturcmp()、sturlen()、sturcspn()、sturdup()、sturerror()、sturncmp()）
#include<stdlib.h>//定义了五种类型、一些宏和通用工具函数(常用的函数如malloc()、calloc()、realloc()、free()、systuem()、atoi()、atol()、rand()、srand()、exit())
#include<time.h>
#include<stdbool.h>

#pragma warning (disable:4996) //消除警告(关闭VS2010的安全警告， 因为VS2020是C++软件)

#define TABLE_MAX   		200
#define CUSTOMER_MAX 		200
#define JOURNAL_MAX    		200



//日期
typedef struct Dates
{
	int year;//年
	int mon;//月
	int day;//日
	int hour;
	int min;
}Dates;

//餐台定义
typedef struct Table
{
	char TableNo[20];			//餐台编号，主键，如001,002,003...
	char TableType;				//餐台类型：A-小桌、B-中桌、C-大桌 分别是4， 6， 8人
	int MaxSeat;				//最大座位数，可根据餐位类型自动填充最大座位数
	char TableState[20];		//餐台状态："NULL"-空 顾客手机号码-占用
}Table;
Table tables[TABLE_MAX];//定义结构体数组， 餐桌存储上限为200

//就餐安排
//同一日期、同一就餐时段手机号码唯一
typedef struct Repast
{
	char CustomerPhone[15];		//顾客手机号码
	Dates Time;					//就餐日期，如2015 05 02
	char Times;					//就餐时段：L-午餐  D-晚餐
	int NumberOfMeals;			//就餐人数
	char TableNo[20];			//餐台编号，默认为"000",表示未安排餐位
	char TableType;				//餐台类型：A-小桌、B-中桌、C-大桌 分别是4， 6， 8人
	char WaitNum[20];				//等位编号，由餐位类型+等位序号构成，如A012，B044
	struct Repast *next;
	
}Repast;
Repast repasts[CUSTOMER_MAX];//定义结构体数组， 当日顾客人数存储上限为200

// 所有file02 中的记录，包括所有日期的
Repast all_repasts_head={.next=NULL};
int all_repast_count =0;


//就餐安排
//同一日期、同一就餐时段手机号码唯一
typedef struct Journal
{
	Dates Time;					//就餐日期，如2015 05 02
	char TableNo[20];			//餐台编号，默认为"000",表示未安排餐位
	char TableType;				//餐台类型：A-小桌、B-中桌、C-大桌 分别是4， 6， 8人
}Journal;
Journal Journals[JOURNAL_MAX];//定义结构体数组， 流水账存储上限为200

// 餐厅桌位信息操作函数
void Save_Restaurant_Table(Table *table);//餐位保存函数
void Read_Restaurant_Table();//餐位读取函数

// 用户信息数据操作相关的函数

void Input_user();//顾客等位自助取号
void Read_user();//客户取号读取函数
void Save_user(Repast * c_user);//客户取号保存函数

// 函数声明
void Show_One_Customer(Repast *c);
bool compare_time_with_local( Dates * date);


// 用户信息列表操作函数,从file02.dat 读取的数据
void All_Repast_Append(Repast *new_element);// 列表增加一个元素
void All_Repast_Show(Dates *datetime, bool all);  // 显示所有的订单记录

void All_Prepast_SelDay();

// 调试用


void Statistics();//统计主函数
void Statictisc_Show_Menu();// 显示统计菜单选型
#define debug 	1

