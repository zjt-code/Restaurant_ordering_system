#include"myhead.h"

int Num = 0;//��λ����
int Num2 = 0;//�˿͸���
int Num3 = 0;//��ˮ�˸���

void show1();//��ӡ����ҵ�Ŷӽк�ϵͳѡ��Ĳ˵�
void show1()//��ӡ����ҵ�Ŷӽк�ϵͳѡ��Ĳ˵�
{
	printf("\n         ����ҵ�Ŷӽк�ϵͳ\n");
	printf("           ---------\n");
	printf("          - 1.����Ա����ҳ��\n");
	printf("          - 2.�˿Ͳ���ҳ��\n");
	printf("          - 3.�˿�����ȡ��\n");
	printf("          - 4.�к�\n");
	printf("          - 0.�˳�ϵͳ\n");
	printf("��ѡ��(0-3):");
}
void show2();//��ӡ����Ա����ѡ��Ĳ˵�
void show2()//��ӡ����Ա����ѡ��Ĳ˵�
{
	printf("\n         ����Ա����ҳ��\n");
	printf("           ---------\n");
	printf("          - 1.�����λ��Ϣ����\n");
	printf("          - 2.ͳ��ָ�����ڶθ����Ͳ�λʹ�����\n");
	printf("          - 0.������һҳ\n");
	printf("��ѡ��(0-2):");
}
void show3();//��ӡ��������ѡ��Ĳ˵�
void show3()//��ӡ��������ѡ��Ĳ˵�
{
	printf("\n         �����λ��Ϣ����\n");
	printf("           ---------\n");
	printf("          - 1.��Ӳ�����Ϣ\n");
	printf("          - 2.չʾ���в�����Ϣ\n");
	printf("          - 3.����ĳ��������Ϣ\n");
	printf("          - 4.�޸�ĳ��������Ϣ\n");
	printf("          - 5.ɾ��ĳ��������Ϣ\n");
	printf("          - 0.������һҳ\n");
	printf("��ѡ��(0-3):");
}

void Statictisc_Show_Menu()
{

	printf("\n         ��Ϣͳ��ѡ��ҳ��\n");
	printf("           ---------\n");
	printf("          - 1.���ж�����Ϣ��ʾ\n");
	printf("          - 2.ͳ��ָ�����ڶθ����Ͳ�λʹ�����\n");
	printf("          - 0.������һҳ\n");
	printf("��ѡ��(0-2):");


}
void Statistics()//ͳ��ָ�����ڶθ����Ͳ�λʹ�����
{
	int  n;

	system("cls");//����

	while (1)//��ѭ��
	{
		Statictisc_Show_Menu();	
		scanf("%d", &n);
		system("cls");//����
		switch (n)//ѡ��
		{
		case 0:
			return ;
		case 1:
			//main_Admin();//����Ա����ҳ��
			All_Repast_Show(NULL, true);
			break;
		case 2:
			All_Prepast_SelDay();//�˿Ͳ���ҳ��
			break;	
		default:
			printf("������� ��������������˵�");
			break;
		}
	
		system("pause");//��ͣ�˵�
		system("cls");//����
	}


}
void Input();//��λ¼�뺯��
void Input()//��λ¼�뺯��
{
	int i = 0, j = 0, k = 0;//ͬʱ����i, j, kҪ�õ�ʱ����ʱȡ��
	Table t;//����һ���ṹ��t, t����Ϣ������λ��š���λ����(С��������������)�������ɾͲ�������
	printf("�������λ��ţ�");
	scanf("%s", t.TableNo);
	for (j = 0; j < Num; j++) {//ѭ��ϵͳ���е���Ϣ
		if (strcmp(tables[j].TableNo, t.TableNo) == 0) {//�жϲ�λ����Ƿ��ظ�
			printf("ϵͳ���иò�λ��ţ�\n");
			return;
		}
	}
	getchar();
	printf("��̨���ͣ�A-С����B-������C-��������");
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
		printf("��̨������д����\n");
		return;
	}
	strcpy(t.TableState, "NULL");//��̨��ʼ״̬Ϊ"NULL"-��
	tables[Num] = t;//����λ��Ϣ���ڽṹ�������β��
	Num++; //��λ��Ϣ+1
	printf("¼��ɹ�����ǰ���в�λ����:%d��\n", Num);

	// �����λ��Ϣ��file01.dat
	Save_Restaurant_Table(&t);
}
void All();//��λ�������
void All() {//��λ�������
	int i = 0, j = 0, k = 0;
	printf("----------------------------------------------------\n");
	printf("%-10s%-15s%-15s%-15s%-15s\n", "����", "��λ���", "��̨����", "�����λ��", "��̨״̬");
	for (i = 0; i < Num; i++) {//����ṹ���������������Ϣ
		printf("%-10d%-15s%-15c%-15d%-15s\t\n", i + 1, tables[i].TableNo, tables[i].TableType, tables[i].MaxSeat, tables[i].TableState);//�������
	}
	printf("----------------------------------------------------\n");
}
void que_All(int i);//��λ
void que_All(int i)//��λ
{
	printf("%-10s%-15s%-15s%-15s%-15s\n", "����", "��λ���", "��̨����", "�����λ��", "��̨״̬");
	printf("%-10d%-15s%-15c%-15d%-15s\t\n", i + 1, tables[i].TableNo, tables[i].TableType, tables[i].MaxSeat, tables[i].TableState);//�������
}
void Que();//��λ���Һ���
void Que()//��λ���Һ���
{
	int i = 0, j = 0, k = 0;
	printf("\n         ��λ���ҹ���\n");
	printf("           ---------\n");
	printf("          - 1.����λ��Ų���\n");
	printf("          - 2.����̨���Ͳ���\n");
	printf("          - 0.�˳�ϵͳ\n");
	printf("��ѡ��(0-5):");
	scanf("%d", &i);
	if (i == 1)
	{
		printf("�������λ��ţ�");
		scanf("%s", tables[Num].TableNo);
		for (i = 0; i < Num; i++)
		{
			if (strcmp(tables[i].TableNo, tables[Num].TableNo) == 0) {
				que_All(i);//��ӡ���ҵ��Ĳ�λ��Ϣ
				k = 1;
				printf("���ҳɹ���\n");
			}
		}
		if (k == 0) {//û���ҵ������������ʾ
			printf("δ�ҵ���λ�����Ϣ��\n");
			return;
		}
	}
	else if (i == 2)
	{
		printf("�������̨����(A-С����B-������C-����)��");
		getchar();
		scanf("%c", &tables[Num].TableType);
		for (i = 0; i < Num; i++)
		{
			if (tables[i].TableType == tables[Num].TableType) {

				que_All(i);//��ӡ���ҵ��Ĳ�λ��Ϣ
				k = 1;
			}
		}
		if (k == 0) {//û���ҵ������������ʾ
			printf("δ�ҵ���̨������Ϣ��\n");
			return;
		}
		else
		{
			printf("���ҳɹ���\n");
		}
	}
}
void Mod();//��λ�޸ĺ���
void Mod()//��λ�޸ĺ���
{
	int i = 0, j = 0, k = 0;
	printf("�������λ��ţ�");
	scanf("%s", tables[Num].TableNo);
	for (i = 0; i < Num; i++)
	{
		if (strcmp(tables[i].TableNo, tables[Num].TableNo) == 0) {

			que_All(i);//��ӡ���ҵ��Ĳ�λ��Ϣ
			if (strcmp(tables[i].TableState, "NULL") != 0)//�жϲ����Ƿ�����ʹ�ã�����ʹ���޷��޸�
			{
				printf("�ò�������ʹ�ã��޷��޸ģ�\n");
				return;
			}
			printf("���ҳɹ����Ƿ��޸ģ�1/0��\n");
			scanf("%d", &k);
			if (k == 1)
			{
				printf("\n         ��λ�޸Ĺ���\n");
				printf("           ---------\n");
				printf("          - 1.�޸Ĳ�̨����\n");
				printf("          - 2.�޸������λ��\n");
				printf("          - 0.�޸�ȡ��\n");
				printf("��ѡ��(0-3):");
				scanf("%d", &k);
				if (k == 1)
				{
					getchar();
					printf("��̨���ͣ�A-С����B-������C-��������");
					scanf("%c", &tables[i].TableType);
				}
				else if (k == 2)
				{
					printf("�����λ����");
					scanf("%d", &tables[i].MaxSeat);
				}
				else {
					printf("�޸�ȡ��");
					return;
				}
				printf("�޸ĳɹ�");
				return;
			}
			else {
				printf("�޸�ȡ��");
			}
			return;//����
		}
	}
	printf("δ�ҵ���λ�����Ϣ��\n");
}
void Del();//��λɾ������
void Del()//��λɾ������
{
	int i = 0, j = 0, k = 0;
	printf("�������λ��ţ�");
	scanf("%s", tables[Num].TableNo);
	for (i = 0; i < Num; i++)
	{
		if (strcmp(tables[i].TableNo, tables[Num].TableNo) == 0) {

			que_All(i);//��ӡ���ҵ��Ĳ�λ��Ϣ
			if (strcmp(tables[i].TableState, "NULL") != 0)//�жϲ����Ƿ�����ʹ�ã�����ʹ���޷�ɾ��
			{
				printf("�ò�������ʹ�ã��޷�ɾ����\n");
				return;
			}
			printf("���ҳɹ����Ƿ�ɾ����1/0��\n");
			scanf("%d", &k);
			if (k == 1)
			{
				for (; i < Num - 1; i++)//��i+1����i�У� ѭ��
					tables[i] = tables[i + 1];
				Num--;//ɾ��������-1
				printf("ɾ���ɹ���\n");
				return;
			}
			else {
				printf("ɾ��ȡ��");
			}
			return;//����
		}
	}
	printf("δ�ҵ���λ�����Ϣ��\n");
}
void Save_Journals();//��ˮ�˱��溯��
void Save_Journals()//��ˮ�˱��溯��
{
	int i = 0, j = 0, k = 0;
	FILE* fp = fopen("file03.dat", "w+");//���ļ�+����ļ�����Ϣ
	for (i = 0; i < Num3; i++) {//��1ѭ����Num3�� ���̹��������¼�� "��ˮ������.txt" �ı���
		fprintf(fp, "%s %c %d %d %d\n", Journals[i].TableNo, Journals[i].TableType, Journals[i].Time.year, Journals[i].Time.mon, Journals[i].Time.day);//��������
	}
	fclose(fp);//�ر��ļ�
}
void Read_Journals();//��ˮ�˶�ȡ����
void Read_Journals()//��ˮ�˶�ȡ����
{
	int i = 0, j = 0, k = 0;
	FILE* file = fopen("file03.dat", "r");//��ֻ����ʽ���ļ�
	if (file == NULL) {//���ļ������ڣ���Ϊ��
		return;//������һ������
	}
	Num3 = 0;//Num3Ϊ��ǰϵͳ��¼����ˮ�˵������� �����ļ�ǰ��������Ϊ0���Է��в�������
	while (fgetc(file) != EOF) {//����һ���ַ���Ϊ��ʱ
		fseek(file, -1, 1);//ÿһ��ѭ���� ��λ�ڵ�ǰ�е�-1λ�ã�Ҳ��������ߵ�λ��
		i = fscanf(file, "%s %c %d %d %d\n", Journals[Num3].TableNo, &Journals[Num3].TableType, &Journals[Num3].Time.year, &Journals[Num3].Time.mon, &Journals[Num3].Time.day);//��������
		if (i == 0)//��i����0ʱ������û��ȡ����Ч������
		{
			break;
		}
		Num3++;//ÿһ��ѭ������ˮ�˵����� + 1
	}
	fclose(file);//�ر�
}


void Save_user(Repast * c_user)//�ͻ�ȡ�ű��溯��
{
	int i = 0, j = 0, k = 0;
	FILE* fp = fopen("file02.dat", "a");//����/���ļ�׷����Ϣ

	if(fp){
			size_t  res = fwrite(c_user,sizeof(Repast),1,fp);
			if(res != 1){
				printf("�ͻ���Ϣ����ʧ��\r\n");
				}
			else
				printf("�ͻ���Ϣ����ɹ�\r\n");
			fclose(fp);//�ر��ļ�
		}
	else{

		printf("�ͻ���Ϣ����ʧ��\r\n");
	}
	
}

void Read_user()//�ͻ�ȡ�Ŷ�ȡ����
{
	int i = 0, j = 0, k = 0;
	FILE* file = fopen("file02.dat", "r");//��ֻ����ʽ���ļ�
	if (file == NULL) {//���ļ������ڣ���Ϊ��
		return;//������һ������
	}
	Num2 = 0;//Num2Ϊ��ǰϵͳ�ĵ���¼��ͻ�ȡ�ŵ������� �����ļ�ǰ��������Ϊ0���Է��в�������
	size_t res2 =0;
	Repast tmp_repast, *p_repast;

	while (res2 = fread(&tmp_repast,sizeof(Repast),1,file)) // �ж��Ƿ��ȡ������
	{
		/* code */
		// printf("res2 = %d\r\n",res2);
		
		//Show_One_Customer(&tmp_repast); // ��ʾ�����������û�����

		p_repast =(Repast *) calloc(1, sizeof(Repast));
		memcpy(p_repast,&tmp_repast,sizeof(Repast));
		//printf("P_repast = %d\r\n",p_repast);

		All_Repast_Append(p_repast);

		if(compare_time_with_local(&tmp_repast.Time))
			{
				repasts[Num2]=tmp_repast;   // file02.dat �е�����û����ݱ��浽repasts ��
				if(Num2 < CUSTOMER_MAX)	Num2++;
			}
	}	

	fclose(file);//�ر�	

}


void Save_Restaurant_Table(Table *table)//��λ���溯��
{
	int i = 0, j = 0, k = 0;
	FILE* fp = fopen("file01.dat", "a");//���ļ�/׷���ļ���Ϣ

	if(fp)
	{
		size_t res =  fwrite(table,sizeof(Table),1, fp);
		if( res != 1)
		{
				printf("��λ��Ϣ����ʧ��\r\n");
		}
		fclose(fp);//�ر��ļ�
	}

	// for (i = 0; i < Num; i++) {//��1ѭ����Num�� ���̹��������¼�� "��λ����.txt" �ı���
	// 	fprintf(fp, "%s %c %d %s\n", tables[i].TableNo, tables[i].TableType, tables[i].MaxSeat, tables[i].TableState);//��������
	// }

}
// ��file01.dat ��ȡ��λ��Ϣ�����浽tables[]
void Read_Restaurant_Table()//��λ��ȡ����
{
	int i = 0, j = 0, k = 0;
	FILE* file = fopen("file01.dat", "r");//��ֻ����ʽ���ļ�
	if (file == NULL) {//���ļ������ڣ���Ϊ��
		return;//������һ������
	}
	Num = 0;//NumΪ��ǰϵͳ��¼���λ�������� �����ļ�ǰ��������Ϊ0���Է��в�������
	/* �����ļ��Ŀ�ͷ */
    fseek(file, 0, SEEK_SET);

	size_t res=0;
	while (res =fread(&tables[Num],sizeof(Table),1,file))
	{
		if(Num >= TABLE_MAX) return;
		else
		Num++;
	}	

	fclose(file);//�ر�

// #if debug

// 	printf("��File01.dat ��ȡ��λ��Ϣ\r\n");

// 	if(Num)
// 	{
// 		for(int x=0; x<Num; x++)
// 		{

// 			printf("%s,%s, %d,%c,total = %d",
// 			tables[Num].TableNo,tables[Num].TableState,tables[Num].MaxSeat,tables[Num].TableType,Num);

// 		}

// 	}
// 	else
// 	printf("�޲�λ��Ϣ\r\n");

// #endif

}
void main_table();//�������˵�
void main_table()//�������˵�
{
	int n = 1;
	while (n != 0)//��ѭ��
	{
		show3();//��ʾ�˵�
		scanf("%d", &n);
		switch (n)//ѡ��
		{
		case 0:
			return;
		case 1:
			Input();//��λ¼�뺯��
			break;
		case 2:
			All();//��λ�������
			break;
		case 3:
			Que();//��λ���Һ���
			break;
		case 4:
			Mod();//��λ�޸ĺ���
			break;
		case 5:
			Del();//��λɾ������
			break;
		default:
			printf("������� ��������������˵�");
			break;
		}
		
		system("pause");
		system("cls");
	}
}
void main_Admin();//����Ա����ҳ��
void main_Admin()//����Ա����ҳ��
{
	int n = 1;
	while (n != 0)//��ѭ��
	{
		show2();//��ʾ�˵�
		scanf("%d", &n);
		system("cls");//����
		switch (n)//ѡ��
		{
		case 0:
			return;
		case 1:
			main_table();//�������˵�
			break;
		case 2:
			Statistics();//ͳ��ָ�����ڶθ����Ͳ�λʹ�����
			break;
		default:
			printf("������� ��������������˵�");
			break;
		}
		system("pause");
		system("cls");
	}
}

void show4();//��ӡ�ͻ�����ѡ��Ĳ˵�
void show4()//��ӡ�ͻ�����ѡ��Ĳ˵�
{
	printf("\n         �����λ��Ϣ����\n");
	printf("           ---------\n");
	printf("          - 1.��Ӳ�����Ϣ\n");
	printf("          - 2.չʾ���в�����Ϣ\n");
	printf("          - 3.����ĳ��������Ϣ\n");
	printf("          - 4.�޸�ĳ��������Ϣ\n");
	printf("          - 5.ɾ��ĳ��������Ϣ\n");
	printf("          - 0.������һҳ\n");
	printf("��ѡ��(0-3):");
}

void balance();//����
void balance()//����
{
	int i = 0, j = 0, k = 0;
	Repast t;//����һ���ṹ��t, t����Ϣ�����ֻ����롢�Ͳ�������ϵͳ���Ͳ������Զ������λ���ͣ�����ӡ�����λ��Ϣ��;

	printf("�������ֻ��ţ�");
	scanf("%s", t.CustomerPhone);
	for (i = 0; i < Num; i++)
	{
		if (strcmp(tables[i].TableState, t.CustomerPhone) == 0) {
			que_All(i);//��ӡ���ҵ��Ĳ�λ��Ϣ
			printf("���ҳɹ����Ƿ���㣨1/0��:");
			scanf("%d", &k);
			if (k == 1)
			{
				strcpy(tables[i].TableState, "NULL");//��̨��ʼ״̬Ϊ"NULL"-��
				printf("����ɹ���\n");
				return;
			}
			else {
				printf("����ȡ��");
			}
			return;//����
		}
	}
	printf("����ʧ�ܣ��޷����㡣\n");
}

void main_user();//�˿Ͳ���ҳ��
void main_user()//�˿Ͳ���ҳ��
{
	int n = 1;
	while (n != 0)//��ѭ��
	{
		show2();//��ʾ�˵�
		scanf("%d", &n);
		system("cls");//����
		switch (n)//ѡ��
		{
		case 0:
			return;
		case 1:
			main_table();//�������˵�
			break;
		case 2:
			Statistics();//ͳ��ָ�����ڶθ����Ͳ�λʹ�����
			break;
		default:
			printf("������� ��������������˵�");
			break;
		}
		system("pause");
		system("cls");
	}



}
void out_uset();//ģ���λ�кŹ���
void out_uset()//ģ���λ�кŹ���
{
	int i = 0, j = 0, k = 0;

	if (Num2 <= 0)
	{
		printf("��ǰ�޿ͻ�ȡ�ţ��޷��кš�\n");
		return;
	}
	printf("��ǰ��Ϣ����:%s\n�Ƿ�кţ�1/0��:", repasts[0].WaitNum);
	scanf("%d", &k);
	if (k == 1)
	{
		for (i = 0; i < Num; i++)
		{
			if (strcmp(tables[i].TableNo, repasts[0].TableNo) == 0) {
				strcpy(tables[i].TableState, repasts[0].CustomerPhone);//��̨��ʼ״̬Ϊ�˿��ֻ���
			}
		}


		printf("����:%s�� ��Ϣ����%s\n", repasts[0].TableNo, repasts[0].WaitNum);

		for (i = 0; i < Num2 - 1; i++)//��i+1����i�У� ѭ��
			tables[i] = tables[i + 1];
		Num2--;//ɾ��������-1
		printf("�кųɹ���\n");
		return;
	}
	else {
		printf("�к�ȡ�����밴�Ͳͽ��̼�ʱ�кţ������λ;\n");
	}
}

void Show_One_Customer(Repast *c)
{
	printf("%d/%d/%d , %d:%d, %c, %d, %s, %s\r\n",c->Time.mon,c->Time.day,c->Time.year,c->Time.hour,c->Time.min,
	c->Times,c->NumberOfMeals,c->WaitNum,c->TableNo);
}



void Input_user()//�˿͵�λ����ȡ��
{
	int i = 0, j = 0, k = 0;//ͬʱ����i, j, kҪ�õ�ʱ����ʱȡ��
	Repast t;//����һ���ṹ��t, t����Ϣ�����ֻ����롢�Ͳ�������ϵͳ���Ͳ������Զ������λ���ͣ�����ӡ�����λ��Ϣ��;
	printf("�������ֻ��ţ�");
	scanf("%s", t.CustomerPhone);

	for (j = 0; j < Num; j++) {//ѭ��ϵͳ���е���Ϣ
		if (strcmp(repasts[j].CustomerPhone, t.CustomerPhone) == 0) {//�жϲ�λ����Ƿ��ظ�
			printf("�ֻ��������ظ����룡\n");
			return;
		}
	}
	
	for (j = 0; j < Num; j++) {//ѭ��ϵͳ���е���Ϣ
		if (strcmp(tables[j].TableState, t.CustomerPhone) == 0) {//�жϲ�λ����Ƿ��ظ�
			printf("�ֻ��������ظ����룡\n");
			return;
		}
	}

    // ����ò�ʱ��
	time_t ts = time(NULL);
	struct tm *mylocaltime = localtime(&ts);
	t.Time.year = 	mylocaltime->tm_year + 1900;
	t.Time.mon = 	mylocaltime->tm_mon + 1;
	t.Time.day = 	mylocaltime->tm_mday;
	t.Time.hour =  	mylocaltime->tm_hour;
	t.Time.min = 	mylocaltime->tm_min;
	
	
	getchar();
	printf("�Ͳ�ʱ��(L-���  D-���)��");
	scanf("%c", &t.Times);
	printf("�Ͳ�������");
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
		printf("��̨������д����1�� - 8�ˣ���\n");
		return;
	}
	
	if (strcmp(t.TableNo, "000") == 0)
	{
		printf("���޲��������Ժ�����\n");
	}
	else
	{
		repasts[Num2] = t;//����λ��Ϣ���ڽṹ�������β��
		Num2++; //��λ��Ϣ+1
		printf("ȡ�ųɹ������Ĳ�����%s�� ��Ϣ���ǣ�%s��\n�����ĵȴ��к�\n", t.TableNo, t.WaitNum);

		//
		Save_user(&t);// ����ͻ��µ���Ϣfile02.dat
		All_Repast_Append(&t);//׷�ӵ���������
		// Show_One_Customer(&t);//��ʾ��ǰ�ͻ���Ϣ

	}
}

int main()
{
	int n = 1;
	Read_Restaurant_Table();//��λ��ȡ����
	Read_user();//�ͻ�ȡ�Ŷ�ȡ����
	Read_Journals();//��ˮ�˶�ȡ����
	while (n != 0)//��ѭ��
	{
		show1();//��ӡ����ҵ�Ŷӽк�ϵͳѡ��Ĳ˵�
		scanf("%d", &n);
		system("cls");//����
		switch (n)//ѡ��
		{
		case 0:
			return 0;
		case 1:
			main_Admin();//����Ա����ҳ��
			break;
		case 2:
			main_user();//�˿Ͳ���ҳ��
			break;
		case 3:
			Input_user();//�˿͵�λ����ȡ��
			break;
		case 4:
			out_uset();//ģ���λ�кŹ���
			break;
		case 5:
			break;
		case 6:
			break;
		default:
			printf("������� ��������������˵�");
			break;
		}
		Save_Journals();//��ˮ�˱��溯��
	    ///Save_user();//�ͻ�ȡ�ű��溯��
		system("pause");//��ͣ�˵�
		system("cls");//����
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

// *Repast *all_repasts; ��������

void All_Repast_Append(Repast *new_element)
{
	Repast *next = &all_repasts_head;

	// printf("all_head = %d\r\n", next);
	//printf("all_head_next = %d\r\n", all_repasts_head.next);

	// printf("new_element = %d\r\n",new_element);

	// �ҵ����һ���ڵ�
	while (next->next !=NULL){
		next = next->next;
	}

	  new_element->next = NULL;//�¸���ַ�ÿ�
	  next->next = new_element; // ���һ��Ԫ��ִ���µ�Ԫ�ؿռ�	
	  all_repast_count++;

	 // printf("total = %d,all_head_next = %d\r\n,", all_repast_count,all_repasts_head.next);
}

void All_Repast_Show(Dates *datetime, bool all)
{
	Repast *next = all_repasts_head.next;

	int cnt=0;

	 if(next ==NULL)
		 printf("�޼�¼\r\n");
	 else
	 {
	 	printf("��¼���-------���ڡ�ʱ��------�Ͳ�ʱ���----����---------�ֻ���--------�ŶӺ�-------����\r\n");
			while(next !=NULL)
			{
				if(!all)//��ʾѡ�����ڼ�¼
				{  
				
				if(datetime->year == next->Time.year && datetime->mon == next->Time.mon &&
					datetime->day == next->Time.day)  // �ж������Ƿ�ƥ��
				printf("%d,    %6d/%02d/%04d,%02d:%d%10c,%10d,%20s,%7s,%11s\r\n",cnt++,next->Time.mon,next->Time.day,next->Time.year,next->Time.hour,next->Time.min,
					next->Times,next->NumberOfMeals,next->CustomerPhone,next->WaitNum,next->TableNo);

				}
				else
				{ // ��ʾ�������ڼ�¼

							printf("%d,    %6d/%02d/%04d,%02d:%d%10c,%10d,%20s,%7s,%11s\r\n",cnt++,next->Time.mon,next->Time.day,next->Time.year,next->Time.hour,next->Time.min,
					next->Times,next->NumberOfMeals,next->CustomerPhone,next->WaitNum,next->TableNo);

				}
				next =next->next; //ָ����һ��Ԫ��
			}

			if( !cnt)printf("��ƥ��ļ�¼\r\n");
		}
}


void All_Prepast_SelDay()
{

		Dates datetime;
		system("CLS");
		printf("��������ݣ�");
		scanf("%u",&datetime.year);
		printf("�������·ݣ�");
		scanf("%u",&datetime.mon);
		printf("���������ڣ�");
		scanf("%u",&datetime.day);		
		
		// �˴��������Ӵ��ж������Ƿ�Ϸ�

		All_Repast_Show(&datetime,false);
}