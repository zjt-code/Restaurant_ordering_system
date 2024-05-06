#include"myhead.h"

int Num = 0;//餐位个数
int Num2 = 0;//顾客个数
int Num3 = 0;//流水账个数

void show1();//打印餐饮业排队叫号系统选择的菜单
void show1()//打印餐饮业排队叫号系统选择的菜单
{
	printf("\n         餐饮业排队叫号系统\n");
	printf("           ---------\n");
	printf("          - 1.管理员操作页面\n");
	printf("          - 2.顾客操作页面\n");
	printf("          - 3.顾客自助取号\n");
	printf("          - 4.叫号\n");
	printf("          - 0.退出系统\n");
	printf("请选择(0-3):");
}
void show2();//打印管理员功能选择的菜单
void show2()//打印管理员功能选择的菜单
{
	printf("\n         管理员操作页面\n");
	printf("           ---------\n");
	printf("          - 1.饭店餐位信息管理\n");
	printf("          - 2.统计指定日期段各类型餐位使用情况\n");
	printf("          - 0.返回上一页\n");
	printf("请选择(0-2):");
}
void show3();//打印餐桌功能选择的菜单
void show3()//打印餐桌功能选择的菜单
{
	printf("\n         饭店餐位信息管理\n");
	printf("           ---------\n");
	printf("          - 1.添加餐桌信息\n");
	printf("          - 2.展示所有餐桌信息\n");
	printf("          - 3.查找某个餐桌信息\n");
	printf("          - 4.修改某个餐桌信息\n");
	printf("          - 5.删除某个餐桌信息\n");
	printf("          - 0.返回上一页\n");
	printf("请选择(0-3):");
}

void Statictisc_Show_Menu()
{

	printf("\n         信息统计选择页面\n");
	printf("           ---------\n");
	printf("          - 1.所有订单信息显示\n");
	printf("          - 2.统计指定日期段各类型餐位使用情况\n");
	printf("          - 0.返回上一页\n");
	printf("请选择(0-2):");


}
void Statistics()//统计指定日期段各类型餐位使用情况
{
	int  n;

	system("cls");//清屏

	while (1)//死循环
	{
		Statictisc_Show_Menu();	
		scanf("%d", &n);
		system("cls");//清屏
		switch (n)//选择
		{
		case 0:
			return ;
		case 1:
			//main_Admin();//管理员操作页面
			All_Repast_Show(NULL, true);
			break;
		case 2:
			All_Prepast_SelDay();//顾客操作页面
			break;	
		default:
			printf("输入错误， 按任意键返回主菜单");
			break;
		}
	
		system("pause");//暂停菜单
		system("cls");//清屏
	}


}
void Input();//餐位录入函数
void Input()//餐位录入函数
{
	int i = 0, j = 0, k = 0;//同时定义i, j, k要用的时候随时取出
	Table t;//定义一个结构体t, t的信息包括餐位编号、餐位类型(小桌、中桌、大桌)、可容纳就餐人数等
	printf("请输入餐位编号：");
	scanf("%s", t.TableNo);
	for (j = 0; j < Num; j++) {//循环系统所有的信息
		if (strcmp(tables[j].TableNo, t.TableNo) == 0) {//判断餐位编号是否重复
			printf("系统已有该餐位编号！\n");
			return;
		}
	}
	getchar();
	printf("餐台类型（A-小桌、B-中桌、C-大桌）：");
	scanf("%c", &t.TableType);
	if (t.TableType == 'A')
	{
		t.MaxSeat = 4;
	}
	else if (t.TableType == 'B')
	{
		t.MaxSeat = 6;
	}
	else if (t.TableType == 'C')
	{
		t.MaxSeat = 8;
	}
	else
	{
		printf("餐台类型填写错误！\n");
		return;
	}
	strcpy(t.TableState, "NULL");//餐台初始状态为"NULL"-空
	tables[Num] = t;//将餐位信息放在结构体数组的尾端
	Num++; //餐位信息+1
	printf("录入成功，当前共有餐位个数:%d。\n", Num);

	// 保存餐位信息到file01.dat
	Save_Restaurant_Table(&t);
}
void All();//餐位浏览函数
void All() {//餐位浏览函数
	int i = 0, j = 0, k = 0;
	printf("----------------------------------------------------\n");
	printf("%-10s%-15s%-15s%-15s%-15s\n", "名次", "餐位编号", "餐台类型", "最大座位数", "餐台状态");
	for (i = 0; i < Num; i++) {//输出结构体数组里的所有信息
		printf("%-10d%-15s%-15c%-15d%-15s\t\n", i + 1, tables[i].TableNo, tables[i].TableType, tables[i].MaxSeat, tables[i].TableState);//浏览数据
	}
	printf("----------------------------------------------------\n");
}
void que_All(int i);//餐位
void que_All(int i)//餐位
{
	printf("%-10s%-15s%-15s%-15s%-15s\n", "名次", "餐位编号", "餐台类型", "最大座位数", "餐台状态");
	printf("%-10d%-15s%-15c%-15d%-15s\t\n", i + 1, tables[i].TableNo, tables[i].TableType, tables[i].MaxSeat, tables[i].TableState);//浏览数据
}
void Que();//餐位查找函数
void Que()//餐位查找函数
{
	int i = 0, j = 0, k = 0;
	printf("\n         餐位查找功能\n");
	printf("           ---------\n");
	printf("          - 1.按餐位编号查找\n");
	printf("          - 2.按餐台类型查找\n");
	printf("          - 0.退出系统\n");
	printf("请选择(0-5):");
	scanf("%d", &i);
	if (i == 1)
	{
		printf("请输入餐位编号：");
		scanf("%s", tables[Num].TableNo);
		for (i = 0; i < Num; i++)
		{
			if (strcmp(tables[i].TableNo, tables[Num].TableNo) == 0) {
				que_All(i);//打印查找到的餐位信息
				k = 1;
				printf("查找成功！\n");
			}
		}
		if (k == 0) {//没有找到数据则给出提示
			printf("未找到餐位编号信息！\n");
			return;
		}
	}
	else if (i == 2)
	{
		printf("请输入餐台类型(A-小桌、B-中桌、C-大桌)：");
		getchar();
		scanf("%c", &tables[Num].TableType);
		for (i = 0; i < Num; i++)
		{
			if (tables[i].TableType == tables[Num].TableType) {

				que_All(i);//打印查找到的餐位信息
				k = 1;
			}
		}
		if (k == 0) {//没有找到数据则给出提示
			printf("未找到餐台类型信息！\n");
			return;
		}
		else
		{
			printf("查找成功！\n");
		}
	}
}
void Mod();//餐位修改函数
void Mod()//餐位修改函数
{
	int i = 0, j = 0, k = 0;
	printf("请输入餐位编号：");
	scanf("%s", tables[Num].TableNo);
	for (i = 0; i < Num; i++)
	{
		if (strcmp(tables[i].TableNo, tables[Num].TableNo) == 0) {

			que_All(i);//打印查找到的餐位信息
			if (strcmp(tables[i].TableState, "NULL") != 0)//判断餐桌是否正在使用，正在使用无法修改
			{
				printf("该餐桌正在使用，无法修改！\n");
				return;
			}
			printf("查找成功，是否修改（1/0）\n");
			scanf("%d", &k);
			if (k == 1)
			{
				printf("\n         餐位修改功能\n");
				printf("           ---------\n");
				printf("          - 1.修改餐台类型\n");
				printf("          - 2.修改最大座位数\n");
				printf("          - 0.修改取消\n");
				printf("请选择(0-3):");
				scanf("%d", &k);
				if (k == 1)
				{
					getchar();
					printf("餐台类型（A-小桌、B-中桌、C-大桌）：");
					scanf("%c", &tables[i].TableType);
				}
				else if (k == 2)
				{
					printf("最大座位数：");
					scanf("%d", &tables[i].MaxSeat);
				}
				else {
					printf("修改取消");
					return;
				}
				printf("修改成功");
				return;
			}
			else {
				printf("修改取消");
			}
			return;//返回
		}
	}
	printf("未找到餐位编号信息！\n");
}
void Del();//餐位删除函数
void Del()//餐位删除函数
{
	int i = 0, j = 0, k = 0;
	printf("请输入餐位编号：");
	scanf("%s", tables[Num].TableNo);
	for (i = 0; i < Num; i++)
	{
		if (strcmp(tables[i].TableNo, tables[Num].TableNo) == 0) {

			que_All(i);//打印查找到的餐位信息
			if (strcmp(tables[i].TableState, "NULL") != 0)//判断餐桌是否正在使用，正在使用无法删除
			{
				printf("该餐桌正在使用，无法删除！\n");
				return;
			}
			printf("查找成功，是否删除（1/0）\n");
			scanf("%d", &k);
			if (k == 1)
			{
				for (; i < Num - 1; i++)//将i+1覆盖i中， 循环
					tables[i] = tables[i + 1];
				Num--;//删除后数量-1
				printf("删除成功！\n");
				return;
			}
			else {
				printf("删除取消");
			}
			return;//返回
		}
	}
	printf("未找到餐位编号信息！\n");
}
void Save_Journals();//流水账保存函数
void Save_Journals()//流水账保存函数
{
	int i = 0, j = 0, k = 0;
	FILE* fp = fopen("file03.dat", "w+");//打开文件+清除文件内信息
	for (i = 0; i < Num3; i++) {//从1循环到Num3， 将教工数据逐个录入 "流水账数据.txt" 文本内
		fprintf(fp, "%s %c %d %d %d\n", Journals[i].TableNo, Journals[i].TableType, Journals[i].Time.year, Journals[i].Time.mon, Journals[i].Time.day);//保存数据
	}
	fclose(fp);//关闭文件
}
void Read_Journals();//流水账读取函数
void Read_Journals()//流水账读取函数
{
	int i = 0, j = 0, k = 0;
	FILE* file = fopen("file03.dat", "r");//以只读方式打开文件
	if (file == NULL) {//当文件不存在，则为真
		return;//返回上一个函数
	}
	Num3 = 0;//Num3为当前系统的录入流水账的总数， 读入文件前将总数置为0，以防有残留数据
	while (fgetc(file) != EOF) {//当下一个字符不为空时
		fseek(file, -1, 1);//每一次循环， 定位在当前行的-1位置，也就是最左边的位置
		i = fscanf(file, "%s %c %d %d %d\n", Journals[Num3].TableNo, &Journals[Num3].TableType, &Journals[Num3].Time.year, &Journals[Num3].Time.mon, &Journals[Num3].Time.day);//保存数据
		if (i == 0)//当i等于0时，代表没读取到有效的数据
		{
			break;
		}
		Num3++;//每一次循环，流水账的总数 + 1
	}
	fclose(file);//关闭
}


void Save_user(Repast * c_user)//客户取号保存函数
{
	int i = 0, j = 0, k = 0;
	FILE* fp = fopen("file02.dat", "a");//创建/打开文件追加信息

	if(fp){
			size_t  res = fwrite(c_user,sizeof(Repast),1,fp);
			if(res != 1){
				printf("客户信息保存失败\r\n");
				}
			else
				printf("客户信息保存成功\r\n");
			fclose(fp);//关闭文件
		}
	else{

		printf("客户信息保存失败\r\n");
	}
	
}

void Read_user()//客户取号读取函数
{
	int i = 0, j = 0, k = 0;
	FILE* file = fopen("file02.dat", "r");//以只读方式打开文件
	if (file == NULL) {//当文件不存在，则为真
		return;//返回上一个函数
	}
	Num2 = 0;//Num2为当前系统的当日录入客户取号的总数， 读入文件前将总数置为0，以防有残留数据
	size_t res2 =0;
	Repast tmp_repast, *p_repast;

	while (res2 = fread(&tmp_repast,sizeof(Repast),1,file)) // 判断是否读取到数据
	{
		/* code */
		// printf("res2 = %d\r\n",res2);
		
		//Show_One_Customer(&tmp_repast); // 显示出来读出的用户数据

		p_repast =(Repast *) calloc(1, sizeof(Repast));
		memcpy(p_repast,&tmp_repast,sizeof(Repast));
		//printf("P_repast = %d\r\n",p_repast);

		All_Repast_Append(p_repast);

		if(compare_time_with_local(&tmp_repast.Time))
			{
				repasts[Num2]=tmp_repast;   // file02.dat 中当天的用户数据保存到repasts 中
				if(Num2 < CUSTOMER_MAX)	Num2++;
			}
	}	

	fclose(file);//关闭	

}


void Save_Restaurant_Table(Table *table)//餐位保存函数
{
	int i = 0, j = 0, k = 0;
	FILE* fp = fopen("file01.dat", "a");//打开文件/追加文件信息

	if(fp)
	{
		size_t res =  fwrite(table,sizeof(Table),1, fp);
		if( res != 1)
		{
				printf("餐位信息保存失败\r\n");
		}
		fclose(fp);//关闭文件
	}

	// for (i = 0; i < Num; i++) {//从1循环到Num， 将教工数据逐个录入 "餐位数据.txt" 文本内
	// 	fprintf(fp, "%s %c %d %s\n", tables[i].TableNo, tables[i].TableType, tables[i].MaxSeat, tables[i].TableState);//保存数据
	// }

}
// 从file01.dat 读取餐位信息并保存到tables[]
void Read_Restaurant_Table()//餐位读取函数
{
	int i = 0, j = 0, k = 0;
	FILE* file = fopen("file01.dat", "r");//以只读方式打开文件
	if (file == NULL) {//当文件不存在，则为真
		return;//返回上一个函数
	}
	Num = 0;//Num为当前系统的录入餐位的总数， 读入文件前将总数置为0，以防有残留数据
	/* 查找文件的开头 */
    fseek(file, 0, SEEK_SET);

	size_t res=0;
	while (res =fread(&tables[Num],sizeof(Table),1,file))
	{
		if(Num >= TABLE_MAX) return;
		else
		Num++;
	}	

	fclose(file);//关闭

// #if debug

// 	printf("从File01.dat 读取餐位信息\r\n");

// 	if(Num)
// 	{
// 		for(int x=0; x<Num; x++)
// 		{

// 			printf("%s,%s, %d,%c,total = %d",
// 			tables[Num].TableNo,tables[Num].TableState,tables[Num].MaxSeat,tables[Num].TableType,Num);

// 		}

// 	}
// 	else
// 	printf("无餐位信息\r\n");

// #endif

}
void main_table();//餐桌主菜单
void main_table()//餐桌主菜单
{
	int n = 1;
	while (n != 0)//死循环
	{
		show3();//显示菜单
		scanf("%d", &n);
		switch (n)//选择
		{
		case 0:
			return;
		case 1:
			Input();//餐位录入函数
			break;
		case 2:
			All();//餐位浏览函数
			break;
		case 3:
			Que();//餐位查找函数
			break;
		case 4:
			Mod();//餐位修改函数
			break;
		case 5:
			Del();//餐位删除函数
			break;
		default:
			printf("输入错误， 按任意键返回主菜单");
			break;
		}
		
		system("pause");
		system("cls");
	}
}
void main_Admin();//管理员操作页面
void main_Admin()//管理员操作页面
{
	int n = 1;
	while (n != 0)//死循环
	{
		show2();//显示菜单
		scanf("%d", &n);
		system("cls");//清屏
		switch (n)//选择
		{
		case 0:
			return;
		case 1:
			main_table();//餐桌主菜单
			break;
		case 2:
			Statistics();//统计指定日期段各类型餐位使用情况
			break;
		default:
			printf("输入错误， 按任意键返回主菜单");
			break;
		}
		system("pause");
		system("cls");
	}
}

void show4();//打印客户功能选择的菜单
void show4()//打印客户功能选择的菜单
{
	printf("\n         饭店餐位信息管理\n");
	printf("           ---------\n");
	printf("          - 1.添加餐桌信息\n");
	printf("          - 2.展示所有餐桌信息\n");
	printf("          - 3.查找某个餐桌信息\n");
	printf("          - 4.修改某个餐桌信息\n");
	printf("          - 5.删除某个餐桌信息\n");
	printf("          - 0.返回上一页\n");
	printf("请选择(0-3):");
}

void balance();//结算
void balance()//结算
{
	int i = 0, j = 0, k = 0;
	Repast t;//定义一个结构体t, t的信息包括手机号码、就餐人数，系统按就餐人数自动分配餐位类型，并打印输出等位信息单;

	printf("请输入手机号：");
	scanf("%s", t.CustomerPhone);
	for (i = 0; i < Num; i++)
	{
		if (strcmp(tables[i].TableState, t.CustomerPhone) == 0) {
			que_All(i);//打印查找到的餐位信息
			printf("查找成功，是否结算（1/0）:");
			scanf("%d", &k);
			if (k == 1)
			{
				strcpy(tables[i].TableState, "NULL");//餐台初始状态为"NULL"-空
				printf("结算成功！\n");
				return;
			}
			else {
				printf("结算取消");
			}
			return;//返回
		}
	}
	printf("查找失败，无法结算。\n");
}

void main_user();//顾客操作页面
void main_user()//顾客操作页面
{
	int n = 1;
	while (n != 0)//死循环
	{
		show2();//显示菜单
		scanf("%d", &n);
		system("cls");//清屏
		switch (n)//选择
		{
		case 0:
			return;
		case 1:
			main_table();//餐桌主菜单
			break;
		case 2:
			Statistics();//统计指定日期段各类型餐位使用情况
			break;
		default:
			printf("输入错误， 按任意键返回主菜单");
			break;
		}
		system("pause");
		system("cls");
	}



}
void out_uset();//模拟餐位叫号过程
void out_uset()//模拟餐位叫号过程
{
	int i = 0, j = 0, k = 0;

	if (Num2 <= 0)
	{
		printf("当前无客户取号，无法叫号。\n");
		return;
	}
	printf("当前信息单是:%s\n是否叫号（1/0）:", repasts[0].WaitNum);
	scanf("%d", &k);
	if (k == 1)
	{
		for (i = 0; i < Num; i++)
		{
			if (strcmp(tables[i].TableNo, repasts[0].TableNo) == 0) {
				strcpy(tables[i].TableState, repasts[0].CustomerPhone);//餐台初始状态为顾客手机号
			}
		}


		printf("餐桌:%s， 信息单：%s\n", repasts[0].TableNo, repasts[0].WaitNum);

		for (i = 0; i < Num2 - 1; i++)//将i+1覆盖i中， 循环
			tables[i] = tables[i + 1];
		Num2--;//删除后数量-1
		printf("叫号成功！\n");
		return;
	}
	else {
		printf("叫号取消，请按就餐进程及时叫号，分配餐位;\n");
	}
}

void Show_One_Customer(Repast *c)
{
	printf("%d/%d/%d , %d:%d, %c, %d, %s, %s\r\n",c->Time.mon,c->Time.day,c->Time.year,c->Time.hour,c->Time.min,
	c->Times,c->NumberOfMeals,c->WaitNum,c->TableNo);
}



void Input_user()//顾客等位自助取号
{
	int i = 0, j = 0, k = 0;//同时定义i, j, k要用的时候随时取出
	Repast t;//定义一个结构体t, t的信息包括手机号码、就餐人数，系统按就餐人数自动分配餐位类型，并打印输出等位信息单;
	printf("请输入手机号：");
	scanf("%s", t.CustomerPhone);

	for (j = 0; j < Num; j++) {//循环系统所有的信息
		if (strcmp(repasts[j].CustomerPhone, t.CustomerPhone) == 0) {//判断餐位编号是否重复
			printf("手机号请勿重复输入！\n");
			return;
		}
	}
	
	for (j = 0; j < Num; j++) {//循环系统所有的信息
		if (strcmp(tables[j].TableState, t.CustomerPhone) == 0) {//判断餐位编号是否重复
			printf("手机号请勿重复输入！\n");
			return;
		}
	}

    // 添加用餐时间
	time_t ts = time(NULL);
	struct tm *mylocaltime = localtime(&ts);
	t.Time.year = 	mylocaltime->tm_year + 1900;
	t.Time.mon = 	mylocaltime->tm_mon + 1;
	t.Time.day = 	mylocaltime->tm_mday;
	t.Time.hour =  	mylocaltime->tm_hour;
	t.Time.min = 	mylocaltime->tm_min;
	
	
	getchar();
	printf("就餐时段(L-午餐  D-晚餐)：");
	scanf("%c", &t.Times);
	printf("就餐人数：");
	scanf("%d", &t.NumberOfMeals);
	strcpy(t.TableNo, "000");
	if (t.NumberOfMeals >0 && t.NumberOfMeals <=4)
	{
		for (i = 0; i < Num; i++)
		{
			if (strcmp(tables[i].TableState, "NULL") == 0 && tables[i].TableType == 'A') {
				strcpy(t.TableNo, tables[i].TableNo);
				strcpy(t.WaitNum, "A");
				strcat(t.WaitNum, t.TableNo);
			}
		}
	}
	else if (t.NumberOfMeals > 4 && t.NumberOfMeals <= 6)
	{
		for (i = 0; i < Num; i++)
		{
			if (strcmp(tables[i].TableState, "NULL") == 0 && tables[i].TableType == 'B') {
				strcpy(t.TableNo, tables[i].TableNo);
				strcpy(t.WaitNum, "B");
				strcat(t.WaitNum, t.TableNo);
			}
		}
	}
	else if (t.NumberOfMeals > 6 && t.NumberOfMeals <= 8)
	{
		for (i = 0; i < Num; i++)
		{
			if (strcmp(tables[i].TableState, "NULL") == 0 && tables[i].TableType == 'C') {
				strcpy(t.TableNo, tables[i].TableNo);
				strcpy(t.WaitNum, "C");
				strcat(t.WaitNum, t.TableNo);
			}
		}
	}
	else
	{
		printf("餐台人数填写错误（1人 - 8人）！\n");
		return;
	}
	
	if (strcmp(t.TableNo, "000") == 0)
	{
		printf("暂无餐桌，请稍后再来\n");
	}
	else
	{
		repasts[Num2] = t;//将餐位信息放在结构体数组的尾端
		Num2++; //餐位信息+1
		printf("取号成功，您的餐桌是%s， 信息单是：%s。\n请耐心等待叫号\n", t.TableNo, t.WaitNum);

		//
		Save_user(&t);// 保存客户下单信息file02.dat
		All_Repast_Append(&t);//追加到数据链表
		// Show_One_Customer(&t);//显示当前客户信息

	}
}

int main()
{
	int n = 1;
	Read_Restaurant_Table();//餐位读取函数
	Read_user();//客户取号读取函数
	Read_Journals();//流水账读取函数
	while (n != 0)//死循环
	{
		show1();//打印餐饮业排队叫号系统选择的菜单
		scanf("%d", &n);
		system("cls");//清屏
		switch (n)//选择
		{
		case 0:
			return 0;
		case 1:
			main_Admin();//管理员操作页面
			break;
		case 2:
			main_user();//顾客操作页面
			break;
		case 3:
			Input_user();//顾客等位自助取号
			break;
		case 4:
			out_uset();//模拟餐位叫号过程
			break;
		case 5:
			break;
		case 6:
			break;
		default:
			printf("输入错误， 按任意键返回主菜单");
			break;
		}
		Save_Journals();//流水账保存函数
	    ///Save_user();//客户取号保存函数
		system("pause");//暂停菜单
		system("cls");//清屏
	}
}

bool compare_time_with_local( Dates * date)
{

	time_t ts = time(NULL);
	struct tm *mylocaltime = localtime(&ts);
	if( (mylocaltime->tm_year +1900)== date->year && 
		(mylocaltime->tm_mon + 1) == date->mon && 
		mylocaltime->tm_mday == date->day)
		return true;
	else
		return false;	
}

// *Repast *all_repasts; 操作函数

void All_Repast_Append(Repast *new_element)
{
	Repast *next = &all_repasts_head;

	// printf("all_head = %d\r\n", next);
	//printf("all_head_next = %d\r\n", all_repasts_head.next);

	// printf("new_element = %d\r\n",new_element);

	// 找到最后一个节点
	while (next->next !=NULL){
		next = next->next;
	}

	  new_element->next = NULL;//下个地址置空
	  next->next = new_element; // 最后一个元素执行新的元素空间	
	  all_repast_count++;

	 // printf("total = %d,all_head_next = %d\r\n,", all_repast_count,all_repasts_head.next);
}

void All_Repast_Show(Dates *datetime, bool all)
{
	Repast *next = all_repasts_head.next;

	int cnt=0;

	 if(next ==NULL)
		 printf("无记录\r\n");
	 else
	 {
	 	printf("记录序号-------日期、时间------就餐时间段----人数---------手机号--------排队号-------桌号\r\n");
			while(next !=NULL)
			{
				if(!all)//显示选定日期记录
				{  
				
				if(datetime->year == next->Time.year && datetime->mon == next->Time.mon &&
					datetime->day == next->Time.day)  // 判断日期是否匹配
				printf("%d,    %6d/%02d/%04d,%02d:%d%10c,%10d,%20s,%7s,%11s\r\n",cnt++,next->Time.mon,next->Time.day,next->Time.year,next->Time.hour,next->Time.min,
					next->Times,next->NumberOfMeals,next->CustomerPhone,next->WaitNum,next->TableNo);

				}
				else
				{ // 显示所有日期记录

							printf("%d,    %6d/%02d/%04d,%02d:%d%10c,%10d,%20s,%7s,%11s\r\n",cnt++,next->Time.mon,next->Time.day,next->Time.year,next->Time.hour,next->Time.min,
					next->Times,next->NumberOfMeals,next->CustomerPhone,next->WaitNum,next->TableNo);

				}
				next =next->next; //指向下一个元素
			}

			if( !cnt)printf("无匹配的记录\r\n");
		}
}


void All_Prepast_SelDay()
{

		Dates datetime;
		system("CLS");
		printf("请输入年份：");
		scanf("%u",&datetime.year);
		printf("请输入月份：");
		scanf("%u",&datetime.mon);
		printf("请输入日期：");
		scanf("%u",&datetime.day);		
		
		// 此处可以增加带判断输入是否合法

		All_Repast_Show(&datetime,false);
}