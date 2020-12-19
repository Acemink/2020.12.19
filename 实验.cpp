#include<iostream>
#include <fstream>
#include <cstdlib>
#include<windows.h>
#include <conio.h>
#include <stdlib.h>
#include<cstring>
#include<iomanip>
using namespace std;

int j;  //��ʾѧ������; 
struct student
{
	char num[20];
	char name[20];
	float score[4];
	float pinjun;
}stud[30];

void menu()    //�˵��� 
{
	cout<<"************************************************\n";
	cout<<"*       ��ӭʹ��ѧ���ɼ�����ϵͳ3.0            *\n";
	cout<<"*           1��¼��ѧ��������Ϣ                *\n";
	cout<<"*           2������ƽ���ɼ�                    *\n";
	cout<<"*           3����ʾȫ��ѧ����������Ϣ          *\n";
	cout<<"*           4������������ĳѧ���ɼ�            *\n";
	cout<<"*           5���������ƽ����                  *\n";
	cout<<"*           6����ʾĳ�ſγ̵�����ѧ���ɼ�      *\n";
	cout<<"*           7����ѧ�Ų���ѧ���ɼ�              *\n";
	cout<<"*           8����ƽ���ַ�������                *\n";
	cout<<"*           9���޸���Ϣ                        *\n";
	cout<<"*           10���ɼ�ˮƽ����                   *\n";  //�ɼ�ˮƽ���������š��������񡢲�����ȼ�ͳ���������÷ֲַ� ��
	cout<<"*           11������ȫ��ѧ����������Ϣ         *\n";
	cout<<"*           0���˳�                            *\n";
	cout<<"*         ���������ѡ��(0-11)��               *\n";
	cout<<"************************************************\n";
}

void input(char x[20])    //���ļ��������� 
{
	int i;
	ifstream infile;
	infile.open(x);
	infile>>j;            // �ȵ���ѧ������ 
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

void pinjun()   // ����ƽ����; 
{
	int i;
	for(i=0;i<j;i++)
	{
		stud[i].pinjun=(stud[i].score[0]+stud[i].score[1]+stud[i].score[2]+stud[i].score[3])/4;
	}
	cout<<setw(10) <<"ѧ��"<<setw(20) <<"����";
	cout<<setw(10) <<"����"<<setw(10) <<"��ѧ";
	cout<<setw(10) <<"����"<<setw(10) <<"�������"<<setw(10) <<"ƽ����"<<endl;
	for(i=0;i<j;i++)
	{
		cout<<setw(10) <<stud[i].num<<setw(20) <<stud[i].name;
		cout<<setw(10) <<stud[i].score[0]<<setw(10) <<stud[i].score[1];
		cout<<setw(10) <<stud[i].score[2]<<setw(10) <<stud[i].score[3]<<setw(10) <<stud[i].pinjun<<endl;
	} 
	
	
}

void print()  //��ʾȫ��ѧ����������Ϣ
{
	int i;
	for(i=0;i<j;i++)
	{
		stud[i].pinjun=(stud[i].score[0]+stud[i].score[1]+stud[i].score[2]+stud[i].score[3])/4;
	}
	cout<<setw(10) <<"ѧ��"<<setw(20) <<"����";
	cout<<setw(10) <<"����"<<setw(10) <<"��ѧ";
	cout<<setw(10) <<"����"<<setw(10) <<"�������"<<setw(10) <<"ƽ����"<<endl;
	for(i=0;i<j;i++)
	{
		cout<<setw(10) <<stud[i].num<<setw(20) <<stud[i].name;
		cout<<setw(10) <<stud[i].score[0]<<setw(10) <<stud[i].score[1];
		cout<<setw(10) <<stud[i].score[2]<<setw(10) <<stud[i].score[3]<<setw(10) <<stud[i].pinjun<<endl;
	}
}

void find(char name[20])     //�ҵ�ĳ�����ض�ѧ�� 
{
	int i,k=1;
	for(i=0;i<j;i++)
	{
		if(strcmp(name,stud[i].name)==0)
		{
			k=0;
			cout<<setw(10) <<"ѧ��"<<setw(20) <<"����";
			cout<<setw(10) <<"����"<<setw(10) <<"��ѧ";
			cout<<setw(10) <<"����"<<setw(10) <<"�������"<<setw(10) <<"ƽ����"<<endl;
			cout<<setw(10) <<stud[i].num<<setw(20) <<stud[i].name;
			cout<<setw(10) <<stud[i].score[0]<<setw(10) <<stud[i].score[1];
			cout<<setw(10) <<stud[i].score[2]<<setw(10) <<stud[i].score[3]<<setw(10) <<stud[i].pinjun<<endl;
			break;
		}
	}
	if(k==1) cout<<"���޴��ˣ�"; 
}

void ahigh()   //��ƽ������߷� 
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
	cout<<"ƽ������ߵ�ͬѧΪ��"<<name<<endl;
	cout<<"����Ϊ��"<<max<<endl; 
}

void object(int number)  //����ĳһ��Ŀ�ɼ� 
{
	int i;
	switch(number)
	{
		case 1:cout<<"���ĳɼ���"<<endl;
			   for(i=0;i<j;i++) cout<<stud[i].name<<setw(20)<<stud[i].score[0]<<endl;
			   break;
		case 2:cout<<"��ѧ�ɼ���"<<endl;
			   for(i=0;i<j;i++) cout<<stud[i].name<<setw(20)<<stud[i].score[1]<<endl;
			   break;
		case 3:cout<<"����ɼ���"<<endl;
			   for(i=0;i<j;i++) cout<<stud[i].name<<setw(20)<<stud[i].score[2]<<endl;
			   break;
		case 4:cout<<"������Ƴɼ���"<<endl;
			   for(i=0;i<j;i++) cout<<stud[i].name<<setw(20)<<stud[i].score[3]<<endl;
			   break;
	}
}

xuehaofind(char xuehao[20])  //��ѧ�Ų���ѧ���ɼ�
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
			cout<<setw(10) <<"ѧ��"<<setw(20) <<"����";
			cout<<setw(10) <<"����"<<setw(10) <<"��ѧ";
			cout<<setw(10) <<"����"<<setw(10) <<"�������"<<setw(10) <<"ƽ����"<<endl;
			cout<<setw(10) <<stud[i].num<<setw(20) <<stud[i].name;
			cout<<setw(10) <<stud[i].score[0]<<setw(10) <<stud[i].score[1];
			cout<<setw(10) <<stud[i].score[2]<<setw(10) <<stud[i].score[3]<<setw(10) <<stud[i].pinjun<<endl;
			break;
		}
	}
	if(k==1) cout<<"�޴�ѧ��ѧ����";
	
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
	cout<<"���ĳɼ�������"<<endl;
	cout<<"�ţ�"<<x0<<" "<<"����"<<x1<<" "<<"����"<<x2<<" "<<"������"<<x3<<" "<<endl;
	
	for(y=0;y<j;y++)
	{
		if(stud[y].score[1]>=90) y0++;
		else if(stud[y].score[1]>=80) y1++;
		else if(stud[y].score[1]>=60) y2++;
		else y3++;
	}
	cout<<"��ѧ�ɼ�������"<<endl;
	cout<<"�ţ�"<<y0<<" "<<"����"<<y1<<" "<<"����"<<y2<<" "<<"������"<<y3<<" "<<endl;
	
	for(z=0;z<j;z++)
	{
		if(stud[z].score[2]>=90) z0++;
		else if(stud[z].score[2]>=80) z1++;
		else if(stud[z].score[2]>=60) z2++;
		else z3++;
	}
	cout<<"����ɼ�������"<<endl;
	cout<<"�ţ�"<<z0<<" "<<"����"<<z1<<" "<<"����"<<z2<<" "<<"������"<<z3<<" "<<endl;
	
	for(q=0;q<j;q++)
	{
		if(stud[q].score[3]>=90) q0++;
		else if(stud[q].score[3]>=80) q1++;
		else if(stud[q].score[3]>=60) q2++;
		else q3++;
	}
	cout<<"������Ƴɼ�������"<<endl;
	cout<<"�ţ�"<<z0<<" "<<"����"<<z1<<" "<<"����"<<x2<<" "<<"������"<<x3<<" "<<endl;
} 


void daochu()   //�����ļ��� 
{
	ofstream  outfile;
	int i;
	
	for(i=0;i<j;i++)  //����Ļ����ʾ����; 
	{
		stud[i].pinjun=(stud[i].score[0]+stud[i].score[1]+stud[i].score[2]+stud[i].score[3])/4;
	}
	cout<<setw(10) <<"ѧ��"<<setw(20) <<"����";
	cout<<setw(10) <<"����"<<setw(10) <<"��ѧ";
	cout<<setw(10) <<"����"<<setw(10) <<"�������"<<setw(10) <<"ƽ����"<<endl;
	for(i=0;i<j;i++)
	{
		cout<<setw(10) <<stud[i].num<<setw(20) <<stud[i].name;
		cout<<setw(10) <<stud[i].score[0]<<setw(10) <<stud[i].score[1];
		cout<<setw(10) <<stud[i].score[2]<<setw(10) <<stud[i].score[3]<<setw(10) <<stud[i].pinjun<<endl;
	}
	
	//�ɼ��������ļ�
    outfile.open("cj11-out.txt"); 
    outfile<< setw(12) << "ѧ��" << setw(20) << "����" ;
    outfile << setw(10) << "��ѧ�ɼ�"<<setw(10)<<"Ӣ��ɼ�" ;
    outfile << setw(13)<< "������Ƴɼ�"<<setw(10)<<"����ɼ�"<<setw(10)<<"ƽ���ɼ�"<<endl;
	for(i=0; i<j; i++)      //  �ļ����ݶ��뵽�ṹ������ 
    {  
	outfile<<setw(12) <<stud[i].num<<setw(20) <<stud[i].name<<setw(10) <<stud[i].score[0];
	outfile<<setw(10) <<stud[i].score[1]<<setw(13)<<stud[i].score[2];
	outfile<<setw(10)<<stud[i].score[3]<<setw(10)<<stud[i].pinjun<<endl;
     
     }
    cout<<"\n�ļ������ɹ���\n"; 
	outfile.close();
}


int main()
{
	int need,i,j,number;
	char filename[20],name[20],xuehao[20];
	cout<<"************************************************\n";
	cout<<"*        ��ӭʹ��ѧ���ɼ�����ϵͳ3.0           *\n";
	cout<<"*           �߾�ͮ  20201003195   ʵ�鱨��     *\n";      //��ӭ���棻 
	cout<<"*           ������  20201002999     ����       *\n";
	cout<<"*        �����2003��   2020.12.19             *\n";
	cout<<"************************************************\n";
	
	cout<<"                                                \n";
	cout<<"                                                \n";
	cout<<"                                                \n";     //���������Ͳ˵��� 
	cout<<"                                                \n";
	
	input("cj11.txt");    
	menu();     //����˵���
	
	cout<<"��������0~11��ѡ�����ķ�������(���������):";
	cin>>need;
	while(need!=0)
	{
		switch(need)
	  {
		case 1:
			cout<<"���ķ���������1��¼��ѧ��������Ϣ"<<endl;
			cout<<"�������ļ�����"; 
			cin>>filename;
			input(filename);  
			break;
			
		case 2:
			cout<<"���ķ���������2������ƽ���ɼ�"<<endl;
			pinjun();
			break;
			
		case 3:
			cout<<"���ķ���������3����ʾȫ��ѧ����������Ϣ"<<endl;
			print();
			break;
			
		case 4:
			cout<<"���ķ���������4������������ĳѧ���ɼ�"<<endl;
			cout<<"������ѧ��������"; 
			cin>>name;
			find(name);
			break;
			
		case 5:
			cout<<"���ķ���������5���������ƽ����"<<endl;
			ahigh();
			break;
			
		case 6:
			cout<<"���ķ���������6����ʾĳ�ſγ̵�����ѧ���ɼ�"<<endl;
			cout<<"�������Ŀ��Ӧ�����֣�1�����ģ�2����ѧ��3������4��������ƣ���" ;
			cin>>number;
			object(number); 
			break;
			
		case 7:
			cout<<"���ķ���������7����ѧ�Ų���ѧ���ɼ�"<<endl;
			cout<<"�����������ѯ��ѧ�ţ�";
			cin>>xuehao;
			xuehaofind(xuehao); 
			break;
			
		case 8:
			cout<<"���ķ���������8����ƽ���ַ�������"<<endl;
			break;
			
		case 9:
			cout<<"���ķ���������9���޸���Ϣ"<<endl;
			cout<<"�������µ��ļ�����"; 
			cin>>filename;
			input(filename); 
			break;
			
		case 10:
			cout<<"���ķ���������10���ɼ�ˮƽ����"<<endl;
			fenxi();
			break;
		
		case 11:
			cout<<"���ķ���������11������ȫ��ѧ����������Ϣ"<<endl;
			daochu();
			break;
	    }
	    system ("pause");
	    system ("CLS");
	    menu();
	    cout<<"��������0~11��ѡ�����ķ�������(���������):";
	    cin>>need;
	}
	 
	return 0;
}
