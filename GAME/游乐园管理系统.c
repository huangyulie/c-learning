#include<stdio.h>//��׼ͷ�ļ� 
#include<malloc.h>//��̬�����ڴ� 
#include<stdlib.h>//ʹ��һЩsystem���� 
#include<stdbool.h>//��������������һ���߼�ֵ 
#include<string.h>//�ַ������� 
#include <conio.h>//ʹ��getch()���� 
#include <ctype.h>//ʹ��isprint�������ж��ַ��Ƿ��ܹ���ʾ���� 
#include <math.h>//���Ļ��� 

typedef struct Facility//������ʩ��ĵĽṹ�� 
{
	char Name[100];//��ʩ���� 
	int all;//�ܹ�ʹ�� 
	int use1;//��ͯʹ�� 
	int use2;//����ʹ�� 
	int use3;//����ѧ��ʹ�� 
	double total;//��������. 
}facility;

typedef struct Node//����ṹ�� 
{
	facility data1;
	int data;
	int data2;
	int sum;
	struct Node * pNext;
}NODE,*PNODE;


/////////////////////////////////////
PNODE pHead = NULL;               //
FILE*fp=NULL;                    //ȫ�ֱ��� 
char name[80] ,pas[80],temp[80];//
char textstring[80];           //
int ok=0;                     //
///////////////////////////////

void Creat_LinkList();//����ͷ��� 
int length_list(PNODE pHead);//�󳤶� 
void Menu();//������ 
void Menu11();
void menu1();//������ 
void print();//��¼���� 
void cost1();//���ѽ��� //������ʩ���� 
void traverse_list(PNODE pHead);//������� 
void traverse_list1(PNODE pHead);//���ص����� 
void sort1(PNODE pHead);//���� 
void traverse_list2(PNODE pHead);// 
void sort2(PNODE pHead);//
void traverse_list3(PNODE pHead);//
void sort3(PNODE pHead);//�Ƚ� 
void cmp(PNODE pHead);//�Ƚ� 
void traverse_list4(PNODE pHead);
void traverse_list5(PNODE pHead);
void traverse_list6(PNODE pHead);
void traverse_list7(PNODE pHead);
void traverse_lis(PNODE pHead);
void cmp1(PNODE pHead);
void cmp2(PNODE pHead);
////////////////////////////////////////
bool insert_list(PNODE pHead,int pos,char name[100],int data1,int data2,int data3,int data4);//��pHead��ָ�������ĵ�pos���ڵ��ǰ�����һ���µĽڵ㣬�ýڵ��ֵ��val������pos��ֵ 
bool delete_list(PNODE pHead,int pos,int *pVal1,int *pVal2,int *pVal3,int *pVal4);//ɾ�� 
////////////////////////////////////////
void ser(PNODE pHead,char name1[100]);//        
void printf(PNODE head);              //
///////////////////////////////////////
void Load_LinkList(PNODE pHead);     //�ļ����� 
PNODE Add_LinkList(PNODE pHead);     //�½��ڵ� 
void Scanf_LinkList(PNODE pTemp);//�������� 
void Scanf_LinkList1(PNODE pTemp);
void Save_LinkList(PNODE pHead);
PNODE Find_LinkList_Val(PNODE pHead, char name[100]);
//////////////////
void regist();//ע������ 
void login();//��¼���� 
void love();//����ͼ�� 
void printtt();//����Ա���û���¼; 

int main()
{
	system("color 90");//�ı���ɫ,��z���ɲ鿴������ɫ 
	
	Creat_LinkList();//����һ���½ڵ� 
	Load_LinkList(pHead);//
	PNODE pTemp=NULL;   //
	///////////////////// 
	
	char name[100],name1[100];
	int data1,data2,data3,data4,pos;
	int num,people,num2,num1,kkk,b,val,num3,q;
	int val1,val2,val3,val4,i,j,ddd,ccc,cp;
	int s=0;
	PNODE head;
	kkk=0;
	q=0;
	ddd=0;
	num2=9; 
	printtt();
	scanf("%d",&ccc);
	while(1)
	{
	if(ccc==0)
	{
	love();
	print();//��¼���� 
	scanf("%d",&s);
	fflush(stdin);//�������
	while(1)
	{
		if(s==1)
		{
	       regist();
	       break;
	   }
	    else if(s==0)
	    {
	        login();
	        break;
	    }
	    else if(s==2)
			exit(-1);
		else
		{
		printf("\t�������,ϵͳ�����˳�\n");   
		exit(-1); 
		}
	}
	system("cls");//���� 
	system("color b0");
	Menu();//���˵� 
	while(1)
	{
		num2=9; 
		scanf("%d",&num);
		if(num==1)
		{
			system("color 60");
			system("cls");
			cost1();
			printf("\t�����������밴0\n");
		} 
		else if(num==2)
		{
			pTemp=Add_LinkList(pHead);
			Scanf_LinkList(pTemp);
			kkk++,q++;//�ж����Ƿ����������; 
		}
		else if(num==3)
		{
		    Save_LinkList(pHead);
            printf("\n�ɹ�����%d����Ϣ��\n", pHead->data2);
            printf("\n�˳��밴0\n");
		} 
		else if(num==4)
		{
			traverse_list5(pHead);
			printf("\t�����밴0\n");
		}
		else if(num==5)//������������������� 
		{
			while(num2==9)
				{
				system("cls");
				menu1();
				scanf("%d",&num1);
				if(num1==3)
				{
				sort1(pHead);
				traverse_list1(pHead);
				printf("\n"); 
				}
				else if(num1==2)
				{
				sort3(pHead);
				traverse_list3(pHead);
				printf("\n"); 	
				}
				else if(num1==1)
				{
					sort2(pHead);
					traverse_list2(pHead);
					printf("\n"); 
				}
				else if(num1==4)//�����������豸�� 
				{
					cmp(pHead);
					traverse_list4(pHead);
					printf("\n"); 
				}
				else if(num1==5)
				{
					traverse_list5(pHead);
				}
				else if(num1==6)
				{
					traverse_list6(pHead);
				}
				printf("\t�����������밴0,����ʹ���밴9\n");
				scanf("%d",&num2);
				if(num2==0)
				{
					system("cls");
					Menu();
				} 
		    }
		}
		else if(num==6)//�������� 
		{
			printf("\t����������鿴��������ʩ����:\n");
			scanf("%s",name1);
			ser(pHead,name1);
		}
		else if(num==0)
		{
			system("color B0");
			system("cls");
			Menu();
		}
		else if(num==8)
		{
			printf("\t��ӭ�´�ʹ��\n") ;
			exit(-1); 
		}
		else if(num==7)//��ɾ 
		{
				printf("\t��ѡ�����ӻ���ɾ��:����1/ɾ��2/�޸İ�3\n");
				scanf("%d",&b);
			    if(b==1)
			    {
			    	printf("\t��������Ҫ�����λ�ü���ӵ���ʩ��������:");
			    	scanf("%d %s %d %d %d %d",&pos,name,&data1,&data2,&data3,&data4);
			    	insert_list(pHead,pos,name,data1,data2,data3,data4);
			    	printf("\t���ӳɹ�,��0����������\n"); 
				}
				else if(b==2) 
				{
					traverse_list5(pHead);
					printf("\t��������Ҫɾ������ʩλ��(�ڼ���)\n");
					scanf("%d",&pos);
					if(delete_list(pHead,pos,&val1,&val2,&val3,&val4))
					printf("\tɾ���ɹ�\n");
					else
					printf("\tɾ��ʧ��\n");
					printf("\t�����������밴0\n");
				}
				else if(b==3)
				{
					traverse_list5(pHead);
					printf("\t��������Ҫ�޸ĵ���ʩ����\n");
					scanf("%s",name); 
                    pTemp = Find_LinkList_Val(pHead, name);
                    Scanf_LinkList(pTemp);
                    printf("\t�޸ĳɹ�\n");
				}
		}
		else
		{
			printf("\t�����������0�˻�����������\n");
			scanf("%d",&num);
		} 
	}
    }
    else if(ccc==2)
	exit(-1);
	else if(ccc==1)
	{
	love();
	print();//��¼���� 
	scanf("%d",&s);
	fflush(stdin);//�������
	while(1)
	{
		if(s==1)
		{
	       regist();
	       break;
	   }
	    else if(s==0)
	    {
	        login();
	        break;
	    }
	    else if(s==2)
			exit(-1);
		else
		{
		printf("\t�������,ϵͳ�����˳�\n");   
		exit(-1); 
		}
	}
	system("cls");//���� 
	system("color A0");
	Menu11();//���˵� 
	while(1)
	{
		num2=9; 
		scanf("%d",&num);
		if(num==1)
		{
			system("color 60");
			system("cls");
			cost1();
			printf("\t�����������밴0\n");
		} 
		else if(num==2)
		{
			pTemp=Add_LinkList(pHead);
			Scanf_LinkList1(pTemp);
			kkk++,q++;//�ж����Ƿ����������; 
		}
		else if(num==3)
		{
			traverse_list7(pHead);
			printf("\t�����밴0\n");
		}
		else if(num==0)
		{
			system("color B0");
			system("cls");
			Menu11();
		}
		else if(num==5)
		{
			printf("\t��ӭ�´�ʹ��\n") ;
			exit(-1); 
		}
		else if(num==4)
		{
			Save_LinkList(pHead);
            printf("\n�ɹ�����%d����Ʊ��Ϣ��\n", pHead->data2);
            printf("\n�˳��밴0\n");
		}
		else
		{
			printf("\t�������0�˻�����������\n");
			scanf("%d",&num);
		} 
	}
	} 
	else{
    	printf("��ѡ�����������\n");	
    	scanf("%d",&ccc);
    }
	}
}

void Menu()
{
	printf("\n\n\n");
	printf("\t\t     _________________________________\n");
	printf("\t\t     |  *  �� �� �� ����Ա �� ��   * |\n");
	printf("\t\t     |  *��ӭʹ���ߺ�����԰����ϵͳ* |\n");
	printf("\t\t     |   *������������ʹ�����¹���*  |\n");
	printf("\t\t __________________________________________  \n");
	printf("\t\t|   1.*�鿴����԰����ʩ�շ����*             |\n");
	printf("\t\t|   2.*¼���������԰����������ʩʹ�����*   |\n");
	printf("\t\t|   3.*�����������԰����������ʩʹ�����*   |\n");
	printf("\t\t|   4.*�����ϴ�����԰����������ʩʹ�����*   |\n");
	printf("\t\t|   5.*�鿴��������԰����������ʩʹ�����*   |\n");
	printf("\t\t|   6.*������������԰����������ʩʹ�����*   |\n");
	printf("\t\t|   7.*��ɾ��������԰����������ʩʹ�����*   |\n");
	printf("\t\t|   8.*�˳��ߺ�����԰����ϵͳ�밴8       *   |\n");
	printf("\t\t __________________________________________  \n");
} 

void cost1()
{
	printf("\n\n\n");
	printf("\t|______________________________________________|\n");
	printf("\t| �ߺ�����԰��Ʊ:   ��ͯ:50Ԫ/�� ����:100Ԫ/�� |\n");
	printf("\t|  ������ʩ(��Ҫ)          �շѱ�׵            |\n");
	printf("\t|1.������           ��ͯ:��ֹ    ����:20Ԫ/��  |\n");
	printf("\t|2.����̽��         ��ͯ:��ֹ    ����:30Ԫ/��  |\n");
	printf("\t|3.��ɽ��           ��ͯ:��ֹ    ����:30Ԫ/��  |\n");
	printf("\t|4.������           ��ͯ:10Ԫ/�� ����:15Ԫ/��  |\n");
	printf("\t|5.��תľ��         ��ͯ:10Ԫ/�� ����:20Ԫ/��  |\n");
	printf("\t|6.Ħ����           ��ͯ:15Ԫ/�� ����:30Ԫ/��  |\n");
	printf("\t|7.ˮ����԰         ��ͯ:30Ԫ/�� ����:50Ԫ/��  |\n");
	printf("\t|*****   �ر�ע��:����������ʩ������̽���*****|\n");
	printf("\t|*****   �ر�ע��:��ͯ��ָ16�������µ���  *****|\n");
	printf("\t|*****   �ر�ע��:���˳�ʾѧ��֤ȫ������  *****|\n");
	printf("\t|______________________________________________|\n");
}

void traverse_list(PNODE pHead)
{
	int count=1;
	PNODE p = pHead->pNext;//�൱�ڶ���һ���µ� 
	printf("\t\t¼��ɹ�\n");
	printf("\t��ʩ  ��������� �������� ����ѧ������ ��ͯ����\n"); 
	while(p != NULL)
	{
		printf("\t%d.",count);
		count++; 
		printf("\t%-10s%-10d%-10d%-10d%-10d\n",p->data1.Name,p->data1.all,p->data1.use1,p->data1.use2,p->data1.use3);
		p = p->pNext;
	} 
	printf("\t�����������밴0\n");
}

void sort1(PNODE pHead)
{
	int i,j,t1,t2,t3,t4;
	char b[100];
	int len;
	len = length_list(pHead);
	PNODE p,q;
	for(i=0,p=pHead->pNext;i<len-1;++i,p=p->pNext)//ѡ������,���� 
	{
		for(j=i+1,q=p->pNext;j<len;++j,q=q->pNext)
		{
			if(p->data1.all<q->data1.all)
			{
				t1 = p->data1.all;
				t2 = p->data1.use1;
				t3 = p->data1.use2;
				t4 = p->data1.use3;
				strcpy(b,p->data1.Name);
				p->data1.all = q->data1.all;
				p->data1.use1 = q->data1.use1;
				p->data1.use2 = q->data1.use2;
				p->data1.use3 = q->data1.use3;
				strcpy(p->data1.Name,q->data1.Name);
				q->data1.all = t1;
				q->data1.use1 = t2;
				q->data1.use2 = t3;
				q->data1.use3 = t4;
				strcpy(q->data1.Name,b);
			}
		}
	}
	return;
} 
 
 
 void menu1()
 {
 	printf("\t ______________________ \n");
 	printf("\t| ��ѡ������֪���Ĳ��� |\n");
 	printf("\t|                      |\n");
	printf("\t|1.���ܳ��˻�ӭ����ʩ  |\n");
	printf("\t|2.���ܶ�ͯ��ӭ����ʩ  |\n");
	printf("\t|3.�����˻�ӭ����ʩ    |\n");
	printf("\t|4.����������ʩ      |\n");
	printf("\t|5.�鿴����            |\n");
	printf("\t|6.�鿴����������      |\n");
	printf("\t|����������������������|\n");
	printf("\t|______________________|\n");
 }
 
 int length_list(PNODE pHead)//�����˷���ֵ 
{
	int i;
	PNODE p = pHead->pNext;
	while(p != NULL)
	{
		++i;
		p = p->pNext;
	}
	return i;
}

void traverse_list1(PNODE pHead)
{
	int count=1;
	PNODE p = pHead->pNext;//�൱�ڶ���һ���µ� 
	while(p != NULL)
	{
		printf("\t�������ǻ�ӭ����%s\n",p->data1.Name);
		printf("\t�����������:%d",p->data1.all);
		p = p->pNext;
		break; 
	}
	printf("\n");
	printf("\t��ʩ    ���������   ��������   ����ѧ������   ��ͯ����\n"); 
	printf("\t____________________________________________________\n");
	while(p != NULL)
	{
		count++;
		printf("\t%d.|%-10s|%-10d|%-10d|%-10d|%-10d|\n",count,p->data1.Name,p->data1.all,p->data1.use1,p->data1.use2,p->data1.use3);
		printf("\t____________________________________________________\n");
		p = p->pNext;
	} 
	printf("\n");
}

void traverse_list2(PNODE pHead)
{
	int count=1;
	PNODE p = pHead->pNext;//�൱�ڶ���һ���µ� 
	while(p != NULL)
	{
		printf("\t���ܳ��˻�ӭ����%s\n",p->data1.Name);
		printf("\t�����������:%d",p->data1.use1);
		p = p->pNext;
		break; 
	} 
	printf("\n");
	printf("\t��ʩ    ���������   ��������   ����ѧ������   ��ͯ����\n"); 
		printf("\t____________________________________________________\n");
	while(p != NULL)
	{
		count++; 
		printf("\t%d.|%-10s|%-10d|%-10d|%-10d|%-10d|\n",count,p->data1.Name,p->data1.all,p->data1.use1,p->data1.use2,p->data1.use3);
		printf("\t____________________________________________________\n");
		p = p->pNext;
	} 
	printf("\n");
}

void sort2(PNODE pHead)
{
	int i,j,t1,t2,t3,t4;
	char b[100];
	int len;
	len = length_list(pHead);
	PNODE p,q;
	for(i=0,p=pHead->pNext;i<len-1;++i,p=p->pNext)//ѡ������,���� 
	{
		for(j=i+1,q=p->pNext;j<len;++j,q=q->pNext)
		{
			if(p->data1.use1<q->data1.use1)
			{
				t1 = p->data1.all;
				t2 = p->data1.use1;
				t3 = p->data1.use2;
				t4 = p->data1.use3;
				strcpy(b,p->data1.Name);
				p->data1.all = q->data1.all;
				p->data1.use1 = q->data1.use1;
				p->data1.use2 = q->data1.use2;
				p->data1.use3 = q->data1.use3;
				strcpy(p->data1.Name,q->data1.Name);
				q->data1.all = t1;
				q->data1.use1 = t2;
				q->data1.use2 = t3;
				q->data1.use3 = t4;
				strcpy(q->data1.Name,b);
			}
		}
	}
	return;
} 

void traverse_list3(PNODE pHead)
{
	int count=1;
	PNODE p = pHead->pNext;//�൱�ڶ���һ���µ� 
	while(p != NULL)
	{
		printf("\t���ܶ�ͯ��ӭ����%s\n",p->data1.Name);
		printf("\t�������ͯ��:%d",p->data1.use3);
		p = p->pNext;
		break; 
	} 
	printf("\n");
	printf("\t��ʩ    ���������   ��������   ����ѧ������   ��ͯ����\n"); 
	printf("\t____________________________________________________\n");
	while(p != NULL)
	{
		count++;
		printf("\t%d.|%-10s|%-10d|%-10d|%-10d|%-10d|\n",count,p->data1.Name,p->data1.all,p->data1.use1,p->data1.use2,p->data1.use3);
		printf("\t____________________________________________________\n");
		p = p->pNext;
	} 
	printf("\n");
}

void sort3(PNODE pHead)
{
	int i,j,t1,t2,t3,t4;
	char b[100];
	int len;
	len = length_list(pHead);
	PNODE p,q;
	for(i=0,p=pHead->pNext;i<len-1;++i,p=p->pNext)//ѡ������,���� 
	{
		for(j=i+1,q=p->pNext;j<len;++j,q=q->pNext)
		{
			if(p->data1.use3<q->data1.use3)
			{
				t1 = p->data1.all;
				t2 = p->data1.use1;
				t3 = p->data1.use2;
				t4 = p->data1.use3;
				strcpy(b,p->data1.Name);
				p->data1.all = q->data1.all;
				p->data1.use1 = q->data1.use1;
				p->data1.use2 = q->data1.use2;
				p->data1.use3 = q->data1.use3;
				strcpy(p->data1.Name,q->data1.Name);
				q->data1.all = t1;
				q->data1.use1 = t2;
				q->data1.use2 = t3;
				q->data1.use3 = t4;
				strcpy(q->data1.Name,b);
			}
		}
	}
	return;
} 

void cmp(PNODE pHead)
{
	PNODE p1 = pHead->pNext;//�൱�ڶ���һ���µ� 
	PNODE p,q;
	int i,j,t1,t2,t3,t4;
	double t5; 
	char b[100];
	int len;
	len = length_list(pHead);
	while(p1 != NULL)
	{
		if(strcmp(p1->data1.Name,"Ħ����")==0)
		{
			p1->data1.total=(p1->data1.use2)*0.8*30+(p1->data1.use3)*15+(p1->data1.use1-p1->data1.use2)*30; 
		} 
		else if(strcmp(p1->data1.Name,"ˮ����԰")==0)
		{
			p1->data1.total=(p1->data1.use2)*0.8*50+(p1->data1.use3)*30+(p1->data1.use1-p1->data1.use2)*50;
		}
		else if(strcmp(p1->data1.Name,"��תľ��")==0)
		{
			p1->data1.total=(p1->data1.use2)*0.8*20+(p1->data1.use3)*10+(p1->data1.use1-p1->data1.use2)*20;
		}
		else if(strcmp(p1->data1.Name,"������")==0)
		{
			p1->data1.total=(p1->data1.use2)*0.8*15+(p1->data1.use3)*10+(p1->data1.use1-p1->data1.use2)*15;
		}
		else if(strcmp(p1->data1.Name,"��ɽ��")==0)
		{
			p1->data1.total=(p1->data1.use2)*0.8*30+(p1->data1.use1-p1->data1.use2)*30;
		}
		else if(strcmp(p1->data1.Name,"������")==0)
		{
			p1->data1.total=(p1->data1.use2)*0.8*20+(p1->data1.use1-p1->data1.use2)*20;
		}
		else if(strcmp(p1->data1.Name,"����̽��")==0)
		{
			p1->data1.total=(p1->data1.use2)*0.8*30+(p1->data1.use1-p1->data1.use2)*30;
		}
		else
		{
			p1->data1.total=(p1->data1.use2)*66+(p1->data1.use3)*66+(p1->data1.use1-p1->data1.use2)*66;
		}
		p1 = p1->pNext;
	} 
	for(i=0,p=pHead->pNext;i<len-1;++i,p=p->pNext)//ѡ������,���� 
	{
		for(j=i+1,q=p->pNext;j<len;++j,q=q->pNext)
		{
			if((p->data1.total-q->data1.total)<0.0001)
			{
				t1 = p->data1.all;
				t2 = p->data1.use1;
				t3 = p->data1.use2;
				t4 = p->data1.use3;
				t5 = p->data1.total;
				strcpy(b,p->data1.Name);
				p->data1.all = q->data1.all;
				p->data1.use1 = q->data1.use1;
				p->data1.use2 = q->data1.use2;
				p->data1.use3 = q->data1.use3;
				p->data1.total= q->data1.total;
				strcpy(p->data1.Name,q->data1.Name);
				q->data1.all  = t1;
				q->data1.use1 = t2;
				q->data1.use2 = t3;
				q->data1.use3 = t4;
				q->data1.total= t5;
				strcpy(q->data1.Name,b);
			}
		}
	}
	printf("\n");
}

void traverse_list4(PNODE pHead)
{
	PNODE p = pHead->pNext;//�൱�ڶ���һ���µ� 
	int a;
	while(p != NULL)
	{
		printf("\t������ߵ���%s\n",p->data1.Name);
		printf("\t��������:%.2lf\n",p->data1.total);
		p = p->pNext;
		break; 
	}
	printf("\t�Ƿ�鿴ȫ���������:����1/����2/�ַ�������3/��0\n");
	scanf("%d",&a);
	if(a==1)
		traverse_lis(pHead);
	else if(a==2)
	{
		cmp1(pHead);
		traverse_lis(pHead);
	}
	else if(a==3)
	{
		cmp2(pHead);
		traverse_lis(pHead);
	} 
	printf("\n");
}

void traverse_list5(PNODE pHead)
{
	int count=1;
	PNODE p = pHead->pNext;//�൱�ڶ���һ���µ� 
	printf("\t��ʩ    ���������   ��������   ����ѧ������   ��ͯ����\n"); 
		printf("\t____________________________________________________\n");
	while(p != NULL)
	{
		printf("\t%d.|%-10s|%-10d|%-10d|%-10d|%-10d|\n",count,p->data1.Name,p->data1.all,p->data1.use1,p->data1.use2,p->data1.use3);
		printf("\t____________________________________________________\n");
		p = p->pNext;
		count++;
	} 
}

void traverse_lis(PNODE pHead)
{
	int count=0; 
	PNODE p = pHead->pNext;//�൱�ڶ���һ���µ� 
	while(p != NULL)
	{
		count++;
		printf("\t%d.������ʩ��%s\n",count,p->data1.Name);
		printf("\t\t��������:%.2lf\n",p->data1.total);
		p = p->pNext;
		printf("\n");
	}
	printf("\n");
}

bool insert_list(PNODE pHead,int pos,char name[100],int data1,int data2,int data3,int data4)
{
	int i = 0;
	PNODE p = pHead;
	
	while(p!=NULL && i<pos-1)
	{
		p=p->pNext;
		i++;
	}
	if(i>pos-1 || p == NULL)
	return false;
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	pNew->data1.all=data1;
	pNew->data1.use1=data2;
	pNew->data1.use2=data3;
	pNew->data1.use3=data4;
	strcpy(pNew->data1.Name,name);
	PNODE q;
	q = p->pNext;
	p->pNext=pNew;
	pNew->pNext=q;
	return true; 
}

bool delete_list(PNODE pHead,int pos,int *pVal1,int *pVal2,int *pVal3,int *pVal4)
{
	int i = 0;
	PNODE p = pHead;
	
	while(p->pNext!=NULL && i<pos-1)//ɾ������Ϊ��һ���ڵ� 
	{
		p=p->pNext;
		i++;
	}
	if(i>pos-1 || p->pNext == NULL)
	return false;
	
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	PNODE q;
	q=p->pNext;
	*pVal1=q->data1.all;
	*pVal2=q->data1.use1;
	*pVal3=q->data1.use2;
	*pVal4=q->data1.use3;
	p->pNext=p->pNext->pNext;
	free(q);
	q = NULL; 
	return true; 
}

void ser(PNODE pHead,char name1[100])
{
	PNODE p = pHead->pNext;
	cmp(pHead);
	int i=0;
	while(p!=NULL)
	{
		if(strcmp(p->data1.Name,name1)==0)//��һ������Ϊ�� 
		{
			printf("\t��ʩ��%s,������Ϊ%d ������Ϊ%d ����ѧ����Ϊ%d ��ͯ��Ϊ%d ������Ϊ%.2lf\n",p->data1.Name,p->data1.all,p->data1.use1,p->data1.use2,p->data1.use3,p->data1.total);
			i++;
		}
		p=p->pNext;
	}
	printf("\t����ʹ���밴6,�����밴0\n");
	if(i==0)
	{
		printf("\t��������û��¼��,�밴6��������\n");
	}
}

void printf(PNODE head)
{
	PNODE stu;
	for(stu=head->pNext;stu->pNext!=NULL;stu=stu->pNext)
	{
		printf("\t��ʩ��%s,������Ϊ%d,������Ϊ%d,����ѧ����Ϊ%d,��ͯ��Ϊ%d\n",stu->data1.Name,stu->data1.all,stu->data1.use1,stu->data1.use2,stu->data1.use3);
	}
}

void Creat_LinkList()
{
    pHead = (PNODE)malloc(sizeof(NODE));
    if(pHead)
    {
        pHead->pNext= NULL;
        pHead->data2= 0;
    }
    return ;
}

void Load_LinkList(PNODE pHead)
{
    PNODE p = NULL, pTemp = NULL;
    pTemp = (PNODE)malloc(sizeof(NODE));
    pTemp->pNext = NULL;
    fp = fopen("D:/�γ����/happy1.txt", "rt");

    while(1)
    {
        /*������һ���м��㣬��ʱ���棬fread��һ�β��ܾ����Ƿ���ӽ�㣬ֱ����p��ӽ�����󣬱�����ǿ��ļ�ʱ����һ����㣬�������ֵ����fread������һ���ڴ���ܶ�*/
        if((fread(pTemp, sizeof(NODE), 1, fp)) != 0)
        {
            p = Add_LinkList(pHead);
            p->data1.all=pTemp->data1.all;
            p->data1.use1=pTemp->data1.use1;
            p->data1.use2=pTemp->data1.use2;
            p->data1.use3=pTemp->data1.use3;
			strcpy(p->data1.Name,pTemp->data1.Name);
        }
        else
            break;
    }
    free(pTemp);
    fclose(fp);
    return ;
}    

PNODE Add_LinkList(PNODE pHead)
{
	PNODE q = pHead;
    while(q->pNext != NULL)
    q = q->pNext;
    q->pNext = (PNODE)malloc(sizeof(NODE));
    q->pNext->sum = 0;
    q->pNext->pNext = NULL;
    pHead->data2++;
    return q->pNext;
}

void Scanf_LinkList(PNODE pTemp)
{
	if(pTemp == NULL)
    {
        return ;
    }
    printf("\n\t������������ʩ���֣�");
    scanf("%s", pTemp->data1.Name);
    printf("\t��������������");
    scanf("%d", &pTemp->data1.all);
    printf("\t�������������");
    scanf("%d", &pTemp->data1.use1);
    printf("\t���������ѧ������");
    scanf("%d", &pTemp->data1.use2);
    printf("\t�������ͯ����");
    scanf("%d", &pTemp->data1.use3);
    printf("\t¼��ɹ��������밴0\n");
}

void Save_LinkList(PNODE pHead)
{
	PNODE p = pHead->pNext;
    if(p == NULL)
    {
        /*���������һ�£����������б���������ݣ�����ɾ����֮�󣬲�����fwrite��ֻ�������������wb����ļ�*/
        fp = fopen("D:/�γ����/happy1.txt", "wt");
        pHead->data2 = 0;
        fclose(fp);
        return ;
    }
    fp = fopen("D:/�γ����/happy1.txt", "wt");
    while(p != NULL)
    {
        fwrite(p, sizeof(NODE), 1, fp);
        p = p->pNext;
    }
    fclose(fp);
    return ;
}

PNODE Find_LinkList_Val(PNODE pHead, char name[100])
{
	PNODE p = pHead;
    while(strcmp(p->data1.Name, name) != 0  &&  p->pNext != NULL)
    {
        p = p->pNext;
    }
    if(p->pNext == NULL && strcmp(p->data1.Name, name) != 0)
    {
        printf("û�д���ʩ!");
        return NULL;
        getch();
    }
    return p;
}

void print()
{
    printf("   			_______________________________________\n");
    printf("   			|                                      |\n");
    printf("   			|         �ߺ�����԰��ӭ���ĵ���       |\n");
    printf("   			|                ��ѡ��                |\n");
    printf("   			|                                      |\n");
    printf("   			|                                      |\n");
    printf("   			|         ����ע���-----�밴 0        |\n");
    printf("   			|                                      |\n");
    printf("   			|         �������û�-----�밴 1        |\n");
    printf("  			|                                      |\n");
    printf("   			|           �˳�    -----�밴 2        |\n");
    printf("   			|                                      |\n");
    printf("   			|______________________________________|\n");
    printf("������");
}

void regist()
{
    FILE *fp=fopen("user1.txt","a");/*��дģʽ("w")���ļ�user.txt,���������,���Զ�����*/
    printf("�������˺�");
    gets(name);
    printf("����������");
    gets(pas); /*�������ƺ�����*/
    fputs(name,fp);
    fputs(pas,fp);/*�����ƺ��������ַ�����ʽд���ļ�*/
    fputs("\n",fp);
    fflush(stdin);//�������
    fclose(fp);/*�ر��ļ�*/
    printf("���������¼����\n");
    login();//ע����ת����¼����
}

void login()
{
	int j,i,k;
	char c;
    printf("��¼����,(������Σ���ǿ���˳�)\n");
    printf("�������˺�");
    gets(name);
    for(k=0;k<3;++k)
    {
        printf("����������");
		while((c=getch())!='\r')//getch������Ӽ��̶�ȡ������ʾ����Ļ�� 
		{
			if(i<20&&isprint(c))//isprint�ж��ַ��Ƿ���Դ�ӡ�������򷵻ط���ֵ�������Ծͷ���0 
			{
				pas[i]=c;
				i++;
				putchar('*');
			}
			else if(i>0&&c=='\b')
			{
				i--;//��һ����¼�� 
				putchar('\b');//�˸�� 
				putchar(' ');
				putchar('\b');
			}
		}
    strcat(name,pas);//�ϲ��ַ�
    strcat(name,"\n");//��ӻ����ַ�
    FILE *fp = fopen("user1.txt", "r");
    if(NULL == fp)
    {
        printf("failed to open dos.txt\n");
        return;
    }
    while(!feof(fp))
    {
        memset(textstring, 0, sizeof(textstring));//memset�ڴ��ʼ�� 
        fgets(textstring, sizeof(textstring) - 1, fp); // ������\n
        if(strcmp(name,textstring)==0){//�ж��ַ��Ƿ����
           ok=1;
           break;
        }
    }
    printf("\n");
    if(ok){
      printf("��¼OK\n");
      system("pause");
      break;
  }
    else
    {
    	printf("��¼����\n");
    	printf("������%d�λ���",2-k);
    }
   }
   if(k==3) 
   {
   	printf("����������Σ���ǿ���˳�\n");
   	exit(-1);
	}	
    fclose(fp);
}

void love()
{
	float y, x, a;
	for (y = 1.5f;y > -1.5f;y -= 0.1f)
	{
		for (x = -1.5f;x < 1.5f;x += 0.05f)
		{
			a = x*x + y*y - 1;
			putchar(a*a*a - x*x*y*y*y <= 0.0f ? '*' : ' ');
		}
		putchar('\n');
	}
}

void traverse_list6(PNODE pHead)
{
	PNODE p = pHead->pNext;
	double ww=0.0;
	double w=0.0;
	cmp(pHead);
	while(p!=NULL)
	{
		ww=ww+(p->data1.use1)*100.0+(p->data1.use3)*50.0;
		w=w+ww+(p->data1.total);
		p = p->pNext;
	}
	printf("\t������Ʊ������Ϊ%.2lf\n",ww);
	printf("\t����������Ϊ%.2lf\n",w);	
}

void printtt()
{
	printf("   			_______________________________________\n");
    printf("   			|                                      |\n");
    printf("   			|         �ߺ�����԰��ӭ���ĵ���       |\n");
    printf("   			|             ��ѡ���¼��ʽ           |\n");
    printf("   			|                                      |\n");
    printf("   			|                                      |\n");
    printf("   			|         ����Ա��¼-----�밴 0        |\n");
    printf("   			|                                      |\n");
    printf("   			|          �ο͵�¼ -----�밴 1        |\n");
    printf("  			|                                      |\n");
    printf("   			|           �˳�    -----�밴 2        |\n");
    printf("   			|                                      |\n");
    printf("   			|______________________________________|\n");
    printf("������");
}

void Menu11()
{
	printf("\n\n\n");
	printf("\t\t     _________________________________\n");
	printf("\t\t     |  *   �� �� �� �� �� �� ��   * |\n");
	printf("\t\t     |  *��ӭʹ���ߺ�����԰��Ʊϵͳ* |\n");
	printf("\t\t     |   *������������ʹ�����¹���*  |\n");
	printf("\t\t __________________________________________  \n");
	printf("\t\t|   1.*�鿴����԰����ʩ�շ����          *   |\n");
	printf("\t\t|   2.*������Ʊ�Լ���Ҫ�����ʩ          *   |\n");
	printf("\t\t|   3.*��ѯ������Ʊ��������Ϣ            *   |\n");
	printf("\t\t|   4.*����������Ʊ��������Ϣ(����ر���)*   |\n");
	printf("\t\t|   5.*�˳�ϵͳ                          *   |\n");
	printf("\t\t __________________________________________  \n");
}

void traverse_list7(PNODE pHead)
{
	PNODE p = pHead->pNext;//�൱�ڶ���һ���µ�
	int i=0;
	int sum;
	while(p != NULL)
	{
		cmp(pHead);
		sum=(p->data1.use1)*100+(p->data1.use3)*50;
		printf("\t������Ʊ��%d��,���г���%d��,��ͯ%d��,��Ʊ������%dԪ\n",p->data1.all,p->data1.use1,p->data1.use3,sum);
		p = p->pNext;
		i++;
	}
	if(i==0)
	{
		printf("\tû�й�Ʊ��Ϣ\n");
		printf("\t�����밴0\n");
    }
}

void Scanf_LinkList1(PNODE pTemp)
{
	if(pTemp == NULL)
    {
        return ;
    }
    printf("\n\t������������Ҫ����Ʊ��");
    scanf("%d", &pTemp->data1.all);
    printf("\t���������г�������");
    scanf("%d", &pTemp->data1.use1);
    printf("\t���������г�������ѧ��֤����������");
    scanf("%d", &pTemp->data1.use2);
    printf("\t�������ͯ����");
    scanf("%d", &pTemp->data1.use3);
    printf("\t��������Ҫ���������ʩ:");
	 scanf("%s", pTemp->data1.Name);
    printf("\t�����ɹ��������밴0\n");
}

void cmp1(PNODE pHead)
{
	PNODE p1 = pHead->pNext;//�൱�ڶ���һ���µ� 
	PNODE p,q;
	int i,j,t1,t2,t3,t4;
	double t5; 
	char b[100];
	int len;
	len = length_list(pHead);
	for(i=0,p=pHead->pNext;i<len-1;++i,p=p->pNext)//ѡ������,���� 
	{
		for(j=i+1,q=p->pNext;j<len;++j,q=q->pNext)
		{
			if((p->data1.total-q->data1.total)>0.0001)
			{
				t1 = p->data1.all;
				t2 = p->data1.use1;
				t3 = p->data1.use2;
				t4 = p->data1.use3;
				t5 = p->data1.total;
				strcpy(b,p->data1.Name);
				p->data1.all = q->data1.all;
				p->data1.use1 = q->data1.use1;
				p->data1.use2 = q->data1.use2;
				p->data1.use3 = q->data1.use3;
				p->data1.total= q->data1.total;
				strcpy(p->data1.Name,q->data1.Name);
				q->data1.all  = t1;
				q->data1.use1 = t2;
				q->data1.use2 = t3;
				q->data1.use3 = t4;
				q->data1.total= t5;
				strcpy(q->data1.Name,b);
			}
		}
	}
	printf("\n");
}

void cmp2(PNODE pHead)
{
	PNODE p1 = pHead->pNext;//�൱�ڶ���һ���µ� 
	PNODE p,q;
	int i,j,t1,t2,t3,t4;
	double t5; 
	char b[100];
	int len;
	len = length_list(pHead);
	for(i=0,p=pHead->pNext;i<len-1;++i,p=p->pNext)//ѡ������,���� 
	{
		for(j=i+1,q=p->pNext;j<len;++j,q=q->pNext)
		{
			if(strcmp(p->data1.Name,q->data1.Name)>0)
			{
				t1 = p->data1.all;
				t2 = p->data1.use1;
				t3 = p->data1.use2;
				t4 = p->data1.use3;
				t5 = p->data1.total;
				strcpy(b,p->data1.Name);
				p->data1.all = q->data1.all;
				p->data1.use1 = q->data1.use1;
				p->data1.use2 = q->data1.use2;
				p->data1.use3 = q->data1.use3;
				p->data1.total= q->data1.total;
				strcpy(p->data1.Name,q->data1.Name);
				q->data1.all  = t1;
				q->data1.use1 = t2;
				q->data1.use2 = t3;
				q->data1.use3 = t4;
				q->data1.total= t5;
				strcpy(q->data1.Name,b);
			}
		}
	}
	printf("\n");
}
