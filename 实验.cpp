#include<iostream>
#include <fstream>
#include <cstdlib>
#include<windows.h>
#include <conio.h>
#include <stdlib.h>
#include<cstring>
#include<iomanip>
using namespace std;

int j;  //表示学生个数; 
struct student
{
	char num[20];
	char name[20];
	float score[4];
	float pinjun;
}stud[30];

void menu()    //菜单； 
{
	cout<<"************************************************\n";
	cout<<"*       欢迎使用学生成绩管理系统3.0            *\n";
	cout<<"*           1、录入学生基本信息                *\n";
	cout<<"*           2、计算平均成绩                    *\n";
	cout<<"*           3、显示全部学生的所有信息          *\n";
	cout<<"*           4、按姓名查找某学生成绩            *\n";
	cout<<"*           5、查找最高平均分                  *\n";
	cout<<"*           6、显示某门课程的所有学生成绩      *\n";
	cout<<"*           7、按学号查找学生成绩              *\n";
	cout<<"*           8、按平均分分数排序                *\n";
	cout<<"*           9、修改信息                        *\n";
	cout<<"*           10、成绩水平分析                   *\n";  //成绩水平分析包括优、良、及格、不及格等级统计人数，得分分布 ；
	cout<<"*           11、导出全部学生的所有信息         *\n";
	cout<<"*           0、退出                            *\n";
	cout<<"*         请输入你的选择(0-11)：               *\n";
	cout<<"************************************************\n";
}

void input(char x[20])    //以文件名做参数 
{
	int i;
	ifstream infile;
	infile.open(x);
	infile>>j;            // 先导入学生个数 
	for(i=0;i<j;i++)
	{
		infile>>stud[i].num;
		infile>>stud[i].name;
		infile>>stud[i].score[0];
		infile>>stud[i].score[1];
		infile>>stud[i].score[2];
		infile>>stud[i].score[3];
	}
	infile.close();
}

void pinjun()   // 计算平均分; 
{
	int i;
	for(i=0;i<j;i++)
	{
		stud[i].pinjun=(stud[i].score[0]+stud[i].score[1]+stud[i].score[2]+stud[i].score[3])/4;
	}
	cout<<setw(10) <<"学号"<<setw(20) <<"姓名";
	cout<<setw(10) <<"语文"<<setw(10) <<"数学";
	cout<<setw(10) <<"物理"<<setw(10) <<"程序设计"<<setw(10) <<"平均分"<<endl;
	for(i=0;i<j;i++)
	{
		cout<<setw(10) <<stud[i].num<<setw(20) <<stud[i].name;
		cout<<setw(10) <<stud[i].score[0]<<setw(10) <<stud[i].score[1];
		cout<<setw(10) <<stud[i].score[2]<<setw(10) <<stud[i].score[3]<<setw(10) <<stud[i].pinjun<<endl;
	} 
	
	
}

void print()  //显示全部学生的所有信息
{
	int i;
	for(i=0;i<j;i++)
	{
		stud[i].pinjun=(stud[i].score[0]+stud[i].score[1]+stud[i].score[2]+stud[i].score[3])/4;
	}
	cout<<setw(10) <<"学号"<<setw(20) <<"姓名";
	cout<<setw(10) <<"语文"<<setw(10) <<"数学";
	cout<<setw(10) <<"物理"<<setw(10) <<"程序设计"<<setw(10) <<"平均分"<<endl;
	for(i=0;i<j;i++)
	{
		cout<<setw(10) <<stud[i].num<<setw(20) <<stud[i].name;
		cout<<setw(10) <<stud[i].score[0]<<setw(10) <<stud[i].score[1];
		cout<<setw(10) <<stud[i].score[2]<<setw(10) <<stud[i].score[3]<<setw(10) <<stud[i].pinjun<<endl;
	}
}

void find(char name[20])     //找到某个其特定学生 
{
	int i,k=1;
	for(i=0;i<j;i++)
	{
		if(strcmp(name,stud[i].name)==0)
		{
			k=0;
			cout<<setw(10) <<"学号"<<setw(20) <<"姓名";
			cout<<setw(10) <<"语文"<<setw(10) <<"数学";
			cout<<setw(10) <<"物理"<<setw(10) <<"程序设计"<<setw(10) <<"平均分"<<endl;
			cout<<setw(10) <<stud[i].num<<setw(20) <<stud[i].name;
			cout<<setw(10) <<stud[i].score[0]<<setw(10) <<stud[i].score[1];
			cout<<setw(10) <<stud[i].score[2]<<setw(10) <<stud[i].score[3]<<setw(10) <<stud[i].pinjun<<endl;
			break;
		}
	}
	if(k==1) cout<<"查无此人！"; 
}

void ahigh()   //求平均分最高分 
{
	int i,max;
	char name[20];
	for(i=0;i<j;i++)
	{
		stud[i].pinjun=(stud[i].score[0]+stud[i].score[1]+stud[i].score[2]+stud[i].score[3])/4;
	}
	max=stud[0].pinjun;
	strcpy(name,stud[0].name);
	for(i=1;i<j;i++)
	{
		if(stud[i].pinjun>max) max=stud[i].pinjun,strcpy(name,stud[i].name);
	}
	cout<<"平均分最高的同学为："<<name<<endl;
	cout<<"分数为："<<max<<endl; 
}

void object(int number)  //查找某一科目成绩 
{
	int i;
	switch(number)
	{
		case 1:cout<<"语文成绩："<<endl;
			   for(i=0;i<j;i++) cout<<stud[i].name<<setw(20)<<stud[i].score[0]<<endl;
			   break;
		case 2:cout<<"数学成绩："<<endl;
			   for(i=0;i<j;i++) cout<<stud[i].name<<setw(20)<<stud[i].score[1]<<endl;
			   break;
		case 3:cout<<"物理成绩："<<endl;
			   for(i=0;i<j;i++) cout<<stud[i].name<<setw(20)<<stud[i].score[2]<<endl;
			   break;
		case 4:cout<<"程序设计成绩："<<endl;
			   for(i=0;i<j;i++) cout<<stud[i].name<<setw(20)<<stud[i].score[3]<<endl;
			   break;
	}
}

xuehaofind(char xuehao[20])  //按学号查找学生成绩
{
	int i,k=1;	
	for(i=0;i<j;i++)
	{
		stud[i].pinjun=(stud[i].score[0]+stud[i].score[1]+stud[i].score[2]+stud[i].score[3])/4;
	}
	for(i=0;i<j;i++)
	{
		if(strcmp(xuehao,stud[i].num)==0)
		{
			k=0;
			cout<<setw(10) <<"学号"<<setw(20) <<"姓名";
			cout<<setw(10) <<"语文"<<setw(10) <<"数学";
			cout<<setw(10) <<"物理"<<setw(10) <<"程序设计"<<setw(10) <<"平均分"<<endl;
			cout<<setw(10) <<stud[i].num<<setw(20) <<stud[i].name;
			cout<<setw(10) <<stud[i].score[0]<<setw(10) <<stud[i].score[1];
			cout<<setw(10) <<stud[i].score[2]<<setw(10) <<stud[i].score[3]<<setw(10) <<stud[i].pinjun<<endl;
			break;
		}
	}
	if(k==1) cout<<"无此学号学生！";
	
} 

void fenxi()
{
	int x,y,z,q,x0=0,x1=0,x2=0,x3=0,y0=0,y1=0,y2=0,y3=0,z0=0,z1=0,z2=0,z3=0,q0=0,q1=0,q2=0,q3=0;
	for(x=0;x<j;x++)
	{
		if(stud[x].score[0]>=90) x0++;
		else if(stud[x].score[0]>=80) x1++;
		else if(stud[x].score[0]>=60) x2++;
		else x3++;
	}
	cout<<"语文成绩分析："<<endl;
	cout<<"优："<<x0<<" "<<"良："<<x1<<" "<<"及格："<<x2<<" "<<"不及格："<<x3<<" "<<endl;
	
	for(y=0;y<j;y++)
	{
		if(stud[y].score[1]>=90) y0++;
		else if(stud[y].score[1]>=80) y1++;
		else if(stud[y].score[1]>=60) y2++;
		else y3++;
	}
	cout<<"数学成绩分析："<<endl;
	cout<<"优："<<y0<<" "<<"良："<<y1<<" "<<"及格："<<y2<<" "<<"不及格："<<y3<<" "<<endl;
	
	for(z=0;z<j;z++)
	{
		if(stud[z].score[2]>=90) z0++;
		else if(stud[z].score[2]>=80) z1++;
		else if(stud[z].score[2]>=60) z2++;
		else z3++;
	}
	cout<<"物理成绩分析："<<endl;
	cout<<"优："<<z0<<" "<<"良："<<z1<<" "<<"及格："<<z2<<" "<<"不及格："<<z3<<" "<<endl;
	
	for(q=0;q<j;q++)
	{
		if(stud[q].score[3]>=90) q0++;
		else if(stud[q].score[3]>=80) q1++;
		else if(stud[q].score[3]>=60) q2++;
		else q3++;
	}
	cout<<"程序设计成绩分析："<<endl;
	cout<<"优："<<z0<<" "<<"良："<<z1<<" "<<"及格："<<x2<<" "<<"不及格："<<x3<<" "<<endl;
} 


void daochu()   //导出文件； 
{
	ofstream  outfile;
	int i;
	
	for(i=0;i<j;i++)  //在屏幕上显示数据; 
	{
		stud[i].pinjun=(stud[i].score[0]+stud[i].score[1]+stud[i].score[2]+stud[i].score[3])/4;
	}
	cout<<setw(10) <<"学号"<<setw(20) <<"姓名";
	cout<<setw(10) <<"语文"<<setw(10) <<"数学";
	cout<<setw(10) <<"物理"<<setw(10) <<"程序设计"<<setw(10) <<"平均分"<<endl;
	for(i=0;i<j;i++)
	{
		cout<<setw(10) <<stud[i].num<<setw(20) <<stud[i].name;
		cout<<setw(10) <<stud[i].score[0]<<setw(10) <<stud[i].score[1];
		cout<<setw(10) <<stud[i].score[2]<<setw(10) <<stud[i].score[3]<<setw(10) <<stud[i].pinjun<<endl;
	}
	
	//成绩表导出到文件
    outfile.open("cj11-out.txt"); 
    outfile<< setw(12) << "学号" << setw(20) << "姓名" ;
    outfile << setw(10) << "数学成绩"<<setw(10)<<"英语成绩" ;
    outfile << setw(13)<< "程序设计成绩"<<setw(10)<<"物理成绩"<<setw(10)<<"平均成绩"<<endl;
	for(i=0; i<j; i++)      //  文件数据读入到结构体数组 
    {  
	outfile<<setw(12) <<stud[i].num<<setw(20) <<stud[i].name<<setw(10) <<stud[i].score[0];
	outfile<<setw(10) <<stud[i].score[1]<<setw(13)<<stud[i].score[2];
	outfile<<setw(10)<<stud[i].score[3]<<setw(10)<<stud[i].pinjun<<endl;
     
     }
    cout<<"\n文件导出成功！\n"; 
	outfile.close();
}


int main()
{
	int need,i,j,number;
	char filename[20],name[20],xuehao[20];
	cout<<"************************************************\n";
	cout<<"*        欢迎使用学生成绩管理系统3.0           *\n";
	cout<<"*           高静彤  20201003195   实验报告     *\n";      //欢迎界面； 
	cout<<"*           陈雅琳  20201002999     代码       *\n";
	cout<<"*        计算机2003班   2020.12.19             *\n";
	cout<<"************************************************\n";
	
	cout<<"                                                \n";
	cout<<"                                                \n";
	cout<<"                                                \n";     //间隔开界面和菜单； 
	cout<<"                                                \n";
	
	input("cj11.txt");    
	menu();     //输出菜单；
	
	cout<<"请从上面的0~11中选择您的服务需求(即输入序号):";
	cin>>need;
	while(need!=0)
	{
		switch(need)
	  {
		case 1:
			cout<<"您的服务需求是1：录入学生基本信息"<<endl;
			cout<<"请输入文件名："; 
			cin>>filename;
			input(filename);  
			break;
			
		case 2:
			cout<<"您的服务需求是2：计算平均成绩"<<endl;
			pinjun();
			break;
			
		case 3:
			cout<<"您的服务需求是3：显示全部学生的所有信息"<<endl;
			print();
			break;
			
		case 4:
			cout<<"您的服务需求是4：按姓名查找某学生成绩"<<endl;
			cout<<"请输入学生姓名："; 
			cin>>name;
			find(name);
			break;
			
		case 5:
			cout<<"您的服务需求是5：查找最高平均分"<<endl;
			ahigh();
			break;
			
		case 6:
			cout<<"您的服务需求是6：显示某门课程的所有学生成绩"<<endl;
			cout<<"请输入科目对应的数字（1：语文，2：数学，3：物理，4：程序设计）：" ;
			cin>>number;
			object(number); 
			break;
			
		case 7:
			cout<<"您的服务需求是7：按学号查找学生成绩"<<endl;
			cout<<"请输入您想查询的学号：";
			cin>>xuehao;
			xuehaofind(xuehao); 
			break;
			
		case 8:
			cout<<"您的服务需求是8：按平均分分数排序"<<endl;
			break;
			
		case 9:
			cout<<"您的服务需求是9：修改信息"<<endl;
			cout<<"请输入新的文件名："; 
			cin>>filename;
			input(filename); 
			break;
			
		case 10:
			cout<<"您的服务需求是10：成绩水平分析"<<endl;
			fenxi();
			break;
		
		case 11:
			cout<<"您的服务需求是11：导出全部学生的所有信息"<<endl;
			daochu();
			break;
	    }
	    system ("pause");
	    system ("CLS");
	    menu();
	    cout<<"请从上面的0~11中选择您的服务需求(即输入序号):";
	    cin>>need;
	}
	 
	return 0;
}
