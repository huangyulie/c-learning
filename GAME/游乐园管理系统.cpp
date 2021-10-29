#include<stdio.h>//标准头文件 
#include<malloc.h>//动态分配内存 
#include<stdlib.h>//使用一些system函数 
#include<stdbool.h>//布尔函数，返回一个逻辑值 
#include<string.h>//字符串函数 
#include <conio.h>//使用getch()函数 
#include <ctype.h>//使用isprint函数能判断字符是否能够显示出来 
#include <math.h>//爱心花纹 

typedef struct Facility//游乐设施里的的结构体 
{
	char Name[100];//设施名字 
	int all;//总共使用 
	int use1;//儿童使用 
	int use2;//成人使用 
	int use3;//成人学生使用 
	double total;//计算利润. 
}facility;

typedef struct Node//链表结构体 
{
	facility data1;
	int data;
	int data2;
	int sum;
	struct Node * pNext;
}NODE,*PNODE;


/////////////////////////////////////
PNODE pHead = NULL;               //
FILE*fp=NULL;                    //全局变量 
char name[80] ,pas[80],temp[80];//
char textstring[80];           //
int ok=0;                     //
///////////////////////////////

void Creat_LinkList();//创建头结点 
int length_list(PNODE pHead);//求长度 
void Menu();//主界面 
void Menu11();
void menu1();//副界面 
void print();//登录界面 
void cost1();//花费界面 //创建设施链表 
void traverse_list(PNODE pHead);//遍历输出 
void traverse_list1(PNODE pHead);//独特的排序 
void sort1(PNODE pHead);//排序 
void traverse_list2(PNODE pHead);// 
void sort2(PNODE pHead);//
void traverse_list3(PNODE pHead);//
void sort3(PNODE pHead);//比较 
void cmp(PNODE pHead);//比较 
void traverse_list4(PNODE pHead);
void traverse_list5(PNODE pHead);
void traverse_list6(PNODE pHead);
void traverse_list7(PNODE pHead);
void traverse_lis(PNODE pHead);
void cmp1(PNODE pHead);
void cmp2(PNODE pHead);
////////////////////////////////////////
bool insert_list(PNODE pHead,int pos,char name[100],int data1,int data2,int data3,int data4);//在pHead所指向的链表的第pos个节点的前面插入一个新的节点，该节点的值是val，并且pos的值 
bool delete_list(PNODE pHead,int pos,int *pVal1,int *pVal2,int *pVal3,int *pVal4);//删除 
////////////////////////////////////////
void ser(PNODE pHead,char name1[100]);//        
void printf(PNODE head);              //
///////////////////////////////////////
void Load_LinkList(PNODE pHead);     //文件操作 
PNODE Add_LinkList(PNODE pHead);     //新建节点 
void Scanf_LinkList(PNODE pTemp);//输入数据 
void Scanf_LinkList1(PNODE pTemp);
void Save_LinkList(PNODE pHead);
PNODE Find_LinkList_Val(PNODE pHead, char name[100]);
//////////////////
void regist();//注册设置 
void login();//登录设置 
void love();//爱心图像 
void printtt();//管理员和用户登录; 

int main()
{
	system("color 90");//改变颜色,按z即可查看所有颜色 
	
	Creat_LinkList();//创建一个新节点 
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
	print();//登录界面 
	scanf("%d",&s);
	fflush(stdin);//清除缓存
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
		printf("\t输入错误,系统即将退出\n");   
		exit(-1); 
		}
	}
	system("cls");//清屏 
	system("color b0");
	Menu();//主菜单 
	while(1)
	{
		num2=9; 
		scanf("%d",&num);
		if(num==1)
		{
			system("color 60");
			system("cls");
			cost1();
			printf("\t返回主界面请按0\n");
		} 
		else if(num==2)
		{
			pTemp=Add_LinkList(pHead);
			Scanf_LinkList(pTemp);
			kkk++,q++;//判断你是否插入数据了; 
		}
		else if(num==3)
		{
		    Save_LinkList(pHead);
            printf("\n成功保存%d条信息！\n", pHead->data2);
            printf("\n退出请按0\n");
		} 
		else if(num==4)
		{
			traverse_list5(pHead);
			printf("\t返回请按0\n");
		}
		else if(num==5)//跳出界面进行其他操作 
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
				else if(num1==4)//求收益最多的设备。 
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
				printf("\t返回主界面请按0,继续使用请按9\n");
				scanf("%d",&num2);
				if(num2==0)
				{
					system("cls");
					Menu();
				} 
		    }
		}
		else if(num==6)//搜索功能 
		{
			printf("\t请输入你想查看的游乐设施详情:\n");
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
			printf("\t欢迎下次使用\n") ;
			exit(-1); 
		}
		else if(num==7)//增删 
		{
				printf("\t请选择增加还是删除:增按1/删按2/修改按3\n");
				scanf("%d",&b);
			    if(b==1)
			    {
			    	printf("\t请输入你要插入的位置及添加的设施和人流量:");
			    	scanf("%d %s %d %d %d %d",&pos,name,&data1,&data2,&data3,&data4);
			    	insert_list(pHead,pos,name,data1,data2,data3,data4);
			    	printf("\t增加成功,按0返回主界面\n"); 
				}
				else if(b==2) 
				{
					traverse_list5(pHead);
					printf("\t请输入你要删除的设施位置(第几行)\n");
					scanf("%d",&pos);
					if(delete_list(pHead,pos,&val1,&val2,&val3,&val4))
					printf("\t删除成功\n");
					else
					printf("\t删除失败\n");
					printf("\t返回主界面请按0\n");
				}
				else if(b==3)
				{
					traverse_list5(pHead);
					printf("\t请输入你要修改的设施名字\n");
					scanf("%s",name); 
                    pTemp = Find_LinkList_Val(pHead, name);
                    Scanf_LinkList(pTemp);
                    printf("\t修改成功\n");
				}
		}
		else
		{
			printf("\t输入错误按两次0退回主界面重输\n");
			scanf("%d",&num);
		} 
	}
    }
    else if(ccc==2)
	exit(-1);
	else if(ccc==1)
	{
	love();
	print();//登录界面 
	scanf("%d",&s);
	fflush(stdin);//清除缓存
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
		printf("\t输入错误,系统即将退出\n");   
		exit(-1); 
		}
	}
	system("cls");//清屏 
	system("color A0");
	Menu11();//主菜单 
	while(1)
	{
		num2=9; 
		scanf("%d",&num);
		if(num==1)
		{
			system("color 60");
			system("cls");
			cost1();
			printf("\t返回主界面请按0\n");
		} 
		else if(num==2)
		{
			pTemp=Add_LinkList(pHead);
			Scanf_LinkList1(pTemp);
			kkk++,q++;//判断你是否插入数据了; 
		}
		else if(num==3)
		{
			traverse_list7(pHead);
			printf("\t返回请按0\n");
		}
		else if(num==0)
		{
			system("color B0");
			system("cls");
			Menu11();
		}
		else if(num==5)
		{
			printf("\t欢迎下次使用\n") ;
			exit(-1); 
		}
		else if(num==4)
		{
			Save_LinkList(pHead);
            printf("\n成功保存%d条门票信息！\n", pHead->data2);
            printf("\n退出请按0\n");
		}
		else
		{
			printf("\t输入错误按0退回主界面重输\n");
			scanf("%d",&num);
		} 
	}
	} 
	else{
    	printf("无选项，请重新输入\n");	
    	scanf("%d",&ccc);
    }
	}
}

void Menu()
{
	printf("\n\n\n");
	printf("\t\t     _________________________________\n");
	printf("\t\t     |  *  尊 贵 的 管理员 您 好   * |\n");
	printf("\t\t     |  *欢迎使用芜湖游乐园管理系统* |\n");
	printf("\t\t     |   *请输入数字来使用以下功能*  |\n");
	printf("\t\t __________________________________________  \n");
	printf("\t\t|   1.*查看游乐园内设施收费情况*             |\n");
	printf("\t\t|   2.*录入今天游乐园人流量和设施使用情况*   |\n");
	printf("\t\t|   3.*保存今天游乐园人流量和设施使用情况*   |\n");
	printf("\t\t|   4.*读入上次游乐园人流量和设施使用情况*   |\n");
	printf("\t\t|   5.*查看今天游乐园人流量和设施使用情况*   |\n");
	printf("\t\t|   6.*搜索今天游乐园人流量和设施使用情况*   |\n");
	printf("\t\t|   7.*增删今天游乐园人流量和设施使用情况*   |\n");
	printf("\t\t|   8.*退出芜湖游乐园管理系统请按8       *   |\n");
	printf("\t\t __________________________________________  \n");
} 

void cost1()
{
	printf("\n\n\n");
	printf("\t|______________________________________________|\n");
	printf("\t| 芜湖游乐园门票:   儿童:50元/人 成人:100元/人 |\n");
	printf("\t|  游乐设施(主要)          收费标椎            |\n");
	printf("\t|1.海盗船           儿童:禁止    成人:20元/人  |\n");
	printf("\t|2.鬼屋探险         儿童:禁止    成人:30元/人  |\n");
	printf("\t|3.过山车           儿童:禁止    成人:30元/人  |\n");
	printf("\t|4.碰碰车           儿童:10元/人 成人:15元/人  |\n");
	printf("\t|5.旋转木马         儿童:10元/人 成人:20元/人  |\n");
	printf("\t|6.摩天轮           儿童:15元/人 成人:30元/人  |\n");
	printf("\t|7.水上乐园         儿童:30元/人 成人:50元/人  |\n");
	printf("\t|*****   特别注意:其他游乐设施请自行探索喔*****|\n");
	printf("\t|*****   特别注意:儿童是指16周岁以下的人  *****|\n");
	printf("\t|*****   特别注意:成人出示学生证全部八折  *****|\n");
	printf("\t|______________________________________________|\n");
}

void traverse_list(PNODE pHead)
{
	int count=1;
	PNODE p = pHead->pNext;//相当于定义一个新的 
	printf("\t\t录入成功\n");
	printf("\t设施  浏览总人数 成人人数 成人学生人数 儿童人数\n"); 
	while(p != NULL)
	{
		printf("\t%d.",count);
		count++; 
		printf("\t%-10s%-10d%-10d%-10d%-10d\n",p->data1.Name,p->data1.all,p->data1.use1,p->data1.use2,p->data1.use3);
		p = p->pNext;
	} 
	printf("\t返回主界面请按0\n");
}

void sort1(PNODE pHead)
{
	int i,j,t1,t2,t3,t4;
	char b[100];
	int len;
	len = length_list(pHead);
	PNODE p,q;
	for(i=0,p=pHead->pNext;i<len-1;++i,p=p->pNext)//选择排序,泛型 
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
 	printf("\t| 请选择你想知道的部分 |\n");
 	printf("\t|                      |\n");
	printf("\t|1.最受成人欢迎的设施  |\n");
	printf("\t|2.最受儿童欢迎的设施  |\n");
	printf("\t|3.最受人欢迎的设施    |\n");
	printf("\t|4.收益最多的设施      |\n");
	printf("\t|5.查看详情            |\n");
	printf("\t|6.查看今日总收益      |\n");
	printf("\t|返回主界面请输入两次零|\n");
	printf("\t|______________________|\n");
 }
 
 int length_list(PNODE pHead)//勿忘了返回值 
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
	PNODE p = pHead->pNext;//相当于定义一个新的 
	while(p != NULL)
	{
		printf("\t最受人们欢迎的是%s\n",p->data1.Name);
		printf("\t其浏览总人数:%d",p->data1.all);
		p = p->pNext;
		break; 
	}
	printf("\n");
	printf("\t设施    浏览总人数   成人人数   成人学生人数   儿童人数\n"); 
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
	PNODE p = pHead->pNext;//相当于定义一个新的 
	while(p != NULL)
	{
		printf("\t最受成人欢迎的是%s\n",p->data1.Name);
		printf("\t其浏览成人数:%d",p->data1.use1);
		p = p->pNext;
		break; 
	} 
	printf("\n");
	printf("\t设施    浏览总人数   成人人数   成人学生人数   儿童人数\n"); 
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
	for(i=0,p=pHead->pNext;i<len-1;++i,p=p->pNext)//选择排序,泛型 
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
	PNODE p = pHead->pNext;//相当于定义一个新的 
	while(p != NULL)
	{
		printf("\t最受儿童欢迎的是%s\n",p->data1.Name);
		printf("\t其浏览儿童数:%d",p->data1.use3);
		p = p->pNext;
		break; 
	} 
	printf("\n");
	printf("\t设施    浏览总人数   成人人数   成人学生人数   儿童人数\n"); 
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
	for(i=0,p=pHead->pNext;i<len-1;++i,p=p->pNext)//选择排序,泛型 
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
	PNODE p1 = pHead->pNext;//相当于定义一个新的 
	PNODE p,q;
	int i,j,t1,t2,t3,t4;
	double t5; 
	char b[100];
	int len;
	len = length_list(pHead);
	while(p1 != NULL)
	{
		if(strcmp(p1->data1.Name,"摩天轮")==0)
		{
			p1->data1.total=(p1->data1.use2)*0.8*30+(p1->data1.use3)*15+(p1->data1.use1-p1->data1.use2)*30; 
		} 
		else if(strcmp(p1->data1.Name,"水上乐园")==0)
		{
			p1->data1.total=(p1->data1.use2)*0.8*50+(p1->data1.use3)*30+(p1->data1.use1-p1->data1.use2)*50;
		}
		else if(strcmp(p1->data1.Name,"旋转木马")==0)
		{
			p1->data1.total=(p1->data1.use2)*0.8*20+(p1->data1.use3)*10+(p1->data1.use1-p1->data1.use2)*20;
		}
		else if(strcmp(p1->data1.Name,"碰碰车")==0)
		{
			p1->data1.total=(p1->data1.use2)*0.8*15+(p1->data1.use3)*10+(p1->data1.use1-p1->data1.use2)*15;
		}
		else if(strcmp(p1->data1.Name,"过山车")==0)
		{
			p1->data1.total=(p1->data1.use2)*0.8*30+(p1->data1.use1-p1->data1.use2)*30;
		}
		else if(strcmp(p1->data1.Name,"海盗船")==0)
		{
			p1->data1.total=(p1->data1.use2)*0.8*20+(p1->data1.use1-p1->data1.use2)*20;
		}
		else if(strcmp(p1->data1.Name,"鬼屋探险")==0)
		{
			p1->data1.total=(p1->data1.use2)*0.8*30+(p1->data1.use1-p1->data1.use2)*30;
		}
		else
		{
			p1->data1.total=(p1->data1.use2)*66+(p1->data1.use3)*66+(p1->data1.use1-p1->data1.use2)*66;
		}
		p1 = p1->pNext;
	} 
	for(i=0,p=pHead->pNext;i<len-1;++i,p=p->pNext)//选择排序,泛型 
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
	PNODE p = pHead->pNext;//相当于定义一个新的 
	int a;
	while(p != NULL)
	{
		printf("\t收益最高的是%s\n",p->data1.Name);
		printf("\t其收益是:%.2lf\n",p->data1.total);
		p = p->pNext;
		break; 
	}
	printf("\t是否查看全部收益情况:降序按1/升序按2/字符串排序按3/否按0\n");
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
	PNODE p = pHead->pNext;//相当于定义一个新的 
	printf("\t设施    浏览总人数   成人人数   成人学生人数   儿童人数\n"); 
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
	PNODE p = pHead->pNext;//相当于定义一个新的 
	while(p != NULL)
	{
		count++;
		printf("\t%d.游乐设施是%s\n",count,p->data1.Name);
		printf("\t\t其收益是:%.2lf\n",p->data1.total);
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
	
	while(p->pNext!=NULL && i<pos-1)//删除不能为第一个节点 
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
		if(strcmp(p->data1.Name,name1)==0)//第一个不能为空 
		{
			printf("\t设施是%s,总人数为%d 成人数为%d 成人学生数为%d 儿童数为%d 总收益为%.2lf\n",p->data1.Name,p->data1.all,p->data1.use1,p->data1.use2,p->data1.use3,p->data1.total);
			i++;
		}
		p=p->pNext;
	}
	printf("\t继续使用请按6,返回请按0\n");
	if(i==0)
	{
		printf("\t输入错误或没有录入,请按6重新输入\n");
	}
}

void printf(PNODE head)
{
	PNODE stu;
	for(stu=head->pNext;stu->pNext!=NULL;stu=stu->pNext)
	{
		printf("\t设施是%s,总人数为%d,成人数为%d,成人学生数为%d,儿童数为%d\n",stu->data1.Name,stu->data1.all,stu->data1.use1,stu->data1.use2,stu->data1.use3);
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
    fp = fopen("D:/课程设计/happy1.txt", "rt");

    while(1)
    {
        /*这里用一个中间结点，临时储存，fread读一次才能决定是否添加结点，直接用p添加结点会错误，本身就是空文件时会多出一个结点，存的垃圾值，而fread必须有一块内存才能读*/
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
    printf("\n\t请输入游乐设施名字：");
    scanf("%s", pTemp->data1.Name);
    printf("\t请输入总人数：");
    scanf("%d", &pTemp->data1.all);
    printf("\t请输入成人数：");
    scanf("%d", &pTemp->data1.use1);
    printf("\t请输入成人学生数：");
    scanf("%d", &pTemp->data1.use2);
    printf("\t请输入儿童数：");
    scanf("%d", &pTemp->data1.use3);
    printf("\t录入成功，返回请按0\n");
}

void Save_LinkList(PNODE pHead)
{
	PNODE p = pHead->pNext;
    if(p == NULL)
    {
        /*这里是清空一下，假如链表中保存的有数据，调用删除完之后，不能用fwrite，只是这种情况下用wb清空文件*/
        fp = fopen("D:/课程设计/happy1.txt", "wt");
        pHead->data2 = 0;
        fclose(fp);
        return ;
    }
    fp = fopen("D:/课程设计/happy1.txt", "wt");
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
        printf("没有此设施!");
        return NULL;
        getch();
    }
    return p;
}

void print()
{
    printf("   			_______________________________________\n");
    printf("   			|                                      |\n");
    printf("   			|         芜湖游乐园欢迎您的到来       |\n");
    printf("   			|                请选择                |\n");
    printf("   			|                                      |\n");
    printf("   			|                                      |\n");
    printf("   			|         我已注册过-----请按 0        |\n");
    printf("   			|                                      |\n");
    printf("   			|         我是新用户-----请按 1        |\n");
    printf("  			|                                      |\n");
    printf("   			|           退出    -----请按 2        |\n");
    printf("   			|                                      |\n");
    printf("   			|______________________________________|\n");
    printf("请输入");
}

void regist()
{
    FILE *fp=fopen("user1.txt","a");/*以写模式("w")打开文件user.txt,如果不存在,会自动创建*/
    printf("请输入账号");
    gets(name);
    printf("请输入密码");
    gets(pas); /*输入名称和密码*/
    fputs(name,fp);
    fputs(pas,fp);/*将名称和密码以字符串形式写入文件*/
    fputs("\n",fp);
    fflush(stdin);//清除缓存
    fclose(fp);/*关闭文件*/
    printf("您将进入登录界面\n");
    login();//注册完转到登录界面
}

void login()
{
	int j,i,k;
	char c;
    printf("登录界面,(输错三次，将强制退出)\n");
    printf("请输入账号");
    gets(name);
    for(k=0;k<3;++k)
    {
        printf("请输入密码");
		while((c=getch())!='\r')//getch函数会从键盘读取但不显示在屏幕上 
		{
			if(i<20&&isprint(c))//isprint判断字符是否可以打印，可以则返回非零值，不可以就返回0 
			{
				pas[i]=c;
				i++;
				putchar('*');
			}
			else if(i>0&&c=='\b')
			{
				i--;//减一重新录入 
				putchar('\b');//退格符 
				putchar(' ');
				putchar('\b');
			}
		}
    strcat(name,pas);//合并字符
    strcat(name,"\n");//添加换行字符
    FILE *fp = fopen("user1.txt", "r");
    if(NULL == fp)
    {
        printf("failed to open dos.txt\n");
        return;
    }
    while(!feof(fp))
    {
        memset(textstring, 0, sizeof(textstring));//memset内存初始化 
        fgets(textstring, sizeof(textstring) - 1, fp); // 包含了\n
        if(strcmp(name,textstring)==0){//判断字符是否相等
           ok=1;
           break;
        }
    }
    printf("\n");
    if(ok){
      printf("登录OK\n");
      system("pause");
      break;
  }
    else
    {
    	printf("登录错误\n");
    	printf("您还有%d次机会",2-k);
    }
   }
   if(k==3) 
   {
   	printf("您已输错三次，将强制退出\n");
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
	printf("\t今日门票总收益为%.2lf\n",ww);
	printf("\t今日总收益为%.2lf\n",w);	
}

void printtt()
{
	printf("   			_______________________________________\n");
    printf("   			|                                      |\n");
    printf("   			|         芜湖游乐园欢迎您的到来       |\n");
    printf("   			|             请选择登录方式           |\n");
    printf("   			|                                      |\n");
    printf("   			|                                      |\n");
    printf("   			|         管理员登录-----请按 0        |\n");
    printf("   			|                                      |\n");
    printf("   			|          游客登录 -----请按 1        |\n");
    printf("  			|                                      |\n");
    printf("   			|           退出    -----请按 2        |\n");
    printf("   			|                                      |\n");
    printf("   			|______________________________________|\n");
    printf("请输入");
}

void Menu11()
{
	printf("\n\n\n");
	printf("\t\t     _________________________________\n");
	printf("\t\t     |  *   尊 贵 的 游 客 您 好   * |\n");
	printf("\t\t     |  *欢迎使用芜湖游乐园订票系统* |\n");
	printf("\t\t     |   *请输入数字来使用以下功能*  |\n");
	printf("\t\t __________________________________________  \n");
	printf("\t\t|   1.*查看游乐园内设施收费情况          *   |\n");
	printf("\t\t|   2.*订购门票以及您要玩的设施          *   |\n");
	printf("\t\t|   3.*查询您的门票及其他信息            *   |\n");
	printf("\t\t|   4.*保存您的门票及其他信息(请务必保存)*   |\n");
	printf("\t\t|   5.*退出系统                          *   |\n");
	printf("\t\t __________________________________________  \n");
}

void traverse_list7(PNODE pHead)
{
	PNODE p = pHead->pNext;//相当于定义一个新的
	int i=0;
	int sum;
	while(p != NULL)
	{
		cmp(pHead);
		sum=(p->data1.use1)*100+(p->data1.use3)*50;
		printf("\t您的门票是%d张,其中成人%d张,儿童%d张,门票共花费%d元\n",p->data1.all,p->data1.use1,p->data1.use3,sum);
		p = p->pNext;
		i++;
	}
	if(i==0)
	{
		printf("\t没有购票信息\n");
		printf("\t返回请按0\n");
    }
}

void Scanf_LinkList1(PNODE pTemp)
{
	if(pTemp == NULL)
    {
        return ;
    }
    printf("\n\t请输入您所需要的门票数");
    scanf("%d", &pTemp->data1.all);
    printf("\t请输入其中成人数：");
    scanf("%d", &pTemp->data1.use1);
    printf("\t请输入其中成人里有学生证的人数数：");
    scanf("%d", &pTemp->data1.use2);
    printf("\t请输入儿童数：");
    scanf("%d", &pTemp->data1.use3);
    printf("\t请输入主要想游玩的设施:");
	 scanf("%s", pTemp->data1.Name);
    printf("\t订购成功，返回请按0\n");
}

void cmp1(PNODE pHead)
{
	PNODE p1 = pHead->pNext;//相当于定义一个新的 
	PNODE p,q;
	int i,j,t1,t2,t3,t4;
	double t5; 
	char b[100];
	int len;
	len = length_list(pHead);
	for(i=0,p=pHead->pNext;i<len-1;++i,p=p->pNext)//选择排序,泛型 
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
	PNODE p1 = pHead->pNext;//相当于定义一个新的 
	PNODE p,q;
	int i,j,t1,t2,t3,t4;
	double t5; 
	char b[100];
	int len;
	len = length_list(pHead);
	for(i=0,p=pHead->pNext;i<len-1;++i,p=p->pNext)//选择排序,泛型 
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
