#pragma once
#include<iostream>
#include<fstream>
#include<sstream>
#include<cstdlib>
#include<cstring>
#include<iomanip>
#include<Windows.h>
#include<locale>
#include<ctime> 
#include<stdio.h>
#include<vector>
using namespace std;
struct birthday
{
	int year;
	int month;
	int date;
};
struct student
{
	int age;//����
	string num;//ѧ��
	string sex;//�Ա� ��1 Ů0
	string name;//����
	string class1;//�༶
	string class1num;//�������
	string hobby;//����
	string organ;//����/ѧ����֯
	struct birthday bth;//����
	string home;//����
	string course;//�γ�
	string room;//����
	string tell;//����
};
int all()//�༶������ʵ�ֳɹ�
{
	ifstream inf;
	string sline;
	string s1, s11, s12;
	int temp = 0;
	inf.open("data1.txt", ios::in);
	while (getline(inf, s1))
	{
		istringstream sin(sline);
		temp++;
		sin >> s11 >> s12;
	}
	//cout << "�༶������Ϊ�� " << temp - 1 << endl;
	return temp;
}
struct monitor 
{
	struct student *ptr= new student[100];
	int size = all();
};
void read(struct monitor* s)//���ڸ��´洢�ڽṹ���ڵ����ݣ��ɹ� 
{
	string s0;
	int temp = all();
	ifstream inf;
	string sline;
	string a[1000][11];
	int b[1000][11];
	inf.open("data1.txt", ios::in);
	if (!inf)
	{
		cerr << "Open Error!" << endl;
		exit(1);
	}
	//cout << "i see name" << endl;//debug
	for (int i = 0; i < all(); i++)
	{
		for (int j = 0; j < 11; j++)
		{
			if (j != 5)
				inf >> a[i][j];
			else
				inf >> b[i][j];
		}
	}
	for (int i1 = 0; i1 < all(); i1++)
	{
		s->ptr->class1 = a[i1][0];
		//cout << "i see name" << endl;//debug
		s->ptr->num = a[i1][1];
		s->ptr->name = a[i1][2];
		s->ptr->class1num = a[i1][3];
		s->ptr->bth.year = b[i1][5] / 10000;
		s->ptr->bth.month = b[i1][5] % 10000 / 100;
		s->ptr->bth.date = b[i1][5] % 10000 % 100;
		s->ptr->sex = a[i1][4];
		s->ptr->home = a[i1][6];
		s->ptr->room = a[i1][7];
		s->ptr->course = a[i1][8];
		s->ptr->hobby = a[i1][9];
		s->ptr->organ = a[i1][10];
		s->ptr++;
	}
		inf.close();
		for (int temp1=0;temp1<all();temp1++)
		{
			s->ptr--;
		}
}
void coutinf(struct monitor *s,int i)
{
	for (int j = 0; j < i; j++) 
	{ 
		s->ptr++;
	}
	cout << "��ѧ��������\t\t" << s->ptr->name << endl;
	cout << "��ѧ����ѧ��\t\t" << s->ptr->num << endl;
	cout << "��ѧ�����Ա�\t\t" << s->ptr->sex << endl;
	cout << "��ѧ���İ༶\t\t" << s->ptr->class1 << endl;
	cout << "��ѧ���İ������\t" << s->ptr->class1num << endl;
	cout << "��ѧ���İ���\t\t" << s->ptr->hobby << endl;
	cout << "��ѧ���ļ�����֯\t" << s->ptr->organ << endl;
	cout << "��ѧ��������\t\t" << s->ptr->bth.year << "��" << s->ptr->bth.month << "��" << s->ptr->bth.date << "��" << endl;
	cout << "��ѧ���ļ���\t\t" << s->ptr->home << endl;
	cout << "��ѧ���Ŀγ�\t\t" << s->ptr->course << endl;
	cout << "��ѧ��������\t\t" << s->ptr->room << endl;
	for (int j = 0; j < i; j++)
	{
		s->ptr--;
	}
}
void hello()
{
	cout << "��ӭʹ��buptѧ������ϵͳ��" << endl;
	cout << "��ѡ��Ҫʹ�õĹ��ܣ� " << endl;
	cout << "��ѯ�༶������\t�밴1 " << endl;
	cout << "���ѧ��\t�밴2" << endl;
	cout << "����ѧ�����\t�밴3" << endl;
	cout << "������\t\t�밴4" << endl;
	cout << "������\t\t�밴5" << endl;
	cout << "��ͬ����\t�밴6" << endl;
	cout << "��ѯѧ����Ϣ\t�밴7" << endl; 
	cout << "��ѯѧ������\t�밴8" << endl;
	cout << "������Ѱ��ѧ��\t�밴9" << endl;
	cout << "������������\t�밴10" << endl;
	cout << "�˳�����\t�밴0" << endl;
	//cout<<"����������������10��������"<<endl;
}
void sort(struct monitor* s, int len)//�����ɴ�С
{
	for (int i = 0; i < len-1; i++)
	{
		for (int j = 0; j < len - i - 1; j++)
		{
			if (s->ptr->bth.year > s->ptr->bth.year)
			{
				struct student temp = s->ptr[j];
				s->ptr[j] = s->ptr[j+1];
				s->ptr[j + 1] = temp;
			}
			else if (s->ptr[j].bth.year == s->ptr[j + 1].bth.year)
			{
				if (s->ptr[j].bth.month > s->ptr[j + 1].bth.month)
				{
					struct student temp1 = s->ptr[j];
					s->ptr[j] = s->ptr[j + 1];
					s->ptr[j + 1] = temp1;
				}
				else if (s->ptr[j].bth.month == s->ptr[j + 1].bth.month)
				{
					if (s->ptr[j].bth.date > s->ptr[j + 1].bth.date)
					{
						struct student temp2 = s->ptr[j];
						s->ptr[j] = s->ptr[j + 1];
						s->ptr[j + 1] = temp2;
					}
				}

			}
		}
	}
}
void write(struct monitor* s)
{
	ofstream out;
	out.open("data1.txt", ios::app);
	out <<endl<< s->ptr->class1 << "	" << s->ptr->num << "	" << s->ptr->name << "		" << s->ptr->class1num << "		" 
		<< s->ptr->sex << "		" <<s->ptr->bth.date + s->ptr->bth.month * 100 + s->ptr->bth.year * 10000<<
		"	"<< s->ptr->home<<"		"<< s->ptr->room<<"		"<< s->ptr->course<<"		"<< s->ptr->hobby<<"		"<< s->ptr->organ;
	out.close();
}
void writes(struct monitor* s)
{
	ofstream out;
	out.open("data1.txt", ios::app);
	out << s->ptr->class1 << "	" << s->ptr->num << "	" << s->ptr->name << "		" << s->ptr->class1num << "		" 
		<< s->ptr->sex << "		" <<s->ptr->bth.date + s->ptr->bth.month * 100 + s->ptr->bth.year * 10000<<
		"	"<< s->ptr->home<<"		"<< s->ptr->room<<"		"<< s->ptr->course<<"		"<< s->ptr->hobby<<"		"<< s->ptr->organ;
	out.close();
}
string judtell(int num)
{
	if (num <= 420 && num>=320)
	{
		cout << "��ѧ��������Ϊ������"<<endl;
		return "������";
	}
	else if (421 <= num&&num <= 521)
	{
		cout << "��ѧ��������Ϊ��ţ��" << endl;
		return "��ţ��";
	}
	else if (522 <= num && num <= 621)
	{
		cout << "��ѧ��������Ϊ˫����" << endl;
		return "˫����";
	}
	else if (622 <= num && num <= 722)
	{
		cout << "��ѧ��������Ϊ��з��" << endl;
		return "��з��";
	}
	else if (723 <= num && num <= 823)
	{
		cout << "��ѧ��������Ϊʨ����" << endl;
		return "ʨ����";
	}
	else if (824 <= num && num <= 923)
	{
		cout << "��ѧ��������Ϊ��Ů��" << endl;
		return "��Ů��";
	}
	else if (924 <= num && num <= 1023)
	{
		cout << "��ѧ��������Ϊ�����" << endl;
		return "�����";
	}
	else if (1024 <= num && num <= 1122)
	{
		cout << "��ѧ��������Ϊ��Ы��" << endl;
		return "��Ы��";
	}
	else if (1123 <= num && num <= 1221)
	{
		cout << "��ѧ��������Ϊ������" << endl;
		return "������";
	}
	else if (1222 <= num && num <= 1231)
	{
		cout << "��ѧ��������Ϊħ����" << endl;
		return "ħ����";
	}
	else if (101 <= num && num <= 120)
	{
		cout << "��ѧ��������Ϊħ����" << endl;
		return "ħ����";
	}
	else if (121 <= num && num <= 219)
	{
		cout << "��ѧ��������Ϊˮƿ��" << endl;
		return "ˮƿ��";
	}
	else if (220 <= num && num <= 320)
	{
		cout << "��ѧ��������Ϊ˫����" << endl;
		return "˫����";
	}
}
void add(struct monitor  *s)
{
	//cout << "����������������ȡ����Ӹ�ѧ����Ϣ����������Ϣ������ȡ��" << endl;
	s->ptr=s->ptr+all();
	string num;//ѧ��
	cout << "������ѧ�ţ�" << endl;
	cin >> num;
	s->ptr->num = num;
	string sex;//�Ա� ��1 Ů0
	while (true)
	{
		cout << "�������Ա�" << endl;
		cin >> sex;
		if (sex == "��" || sex == "Ů")
		{
			s->ptr->sex = sex;
			break;
		}
		else
		{
			cout << "��������" << endl;
		}
	}
	string name;//����
	cout << "������������" << endl;
	cin >> name;
	s->ptr->name = name;
	string class1;//�༶
	cout << "������༶��" << endl;
	cin >> class1;
	s->ptr->class1 = class1;
	string class1num;//�������
	cout << "�����������ţ�" << endl;
	cin >> class1num;
	s->ptr->class1num = class1num;
	string hobby;//����
	cout << "�����밮�ã�" << endl;
	cin >> hobby;
	s->ptr->hobby = hobby;
	string organ;//����/ѧ����֯
	cout << "������ѧ����֯��" << endl;
	cin >> organ;
	s->ptr->organ = organ;
	struct birthday bth;//����
	int year, month, date;
	cout << "���������գ�(���)" << endl;
	cin >> year;
	s->ptr->bth.year = year;
	while(true)
	{
	cout << "���������գ�(�·�)" << endl;
	cin.clear();
	cin.ignore(8192,'\n');
	cin >> month;
		if (month >= 1 && month <= 12)
		{
			break;
		}
		else
		{
			cout << "�����·ݷǷ������������룡" << endl;
		}
	}
	s->ptr->bth.month = month;
	while (true)
	{
		cout << "���������գ�(����)" << endl;
		cin >> date;
		if (date >= 1 && date <= 31)
		{
			break;
		}
		else
		{
			cout << "�������ڷǷ������������룡" << endl;
		}
	}
	s->ptr->bth.date = date;
	if ((s->ptr->bth.date + s->ptr->bth.month * 100)>= 1210)
	{
		s->ptr->age = -(s->ptr->bth.year - 2020+1);
	}
	else
	{
		s->ptr->age = -(s->ptr->bth.year - 2020);
	}
	cout << "��ѧ��������Ϊ" << s->ptr->age<<endl;
	string home;//����
	cout << "���������:" << endl;
	cin >> home;
	s->ptr->home = home;
	string course;//�γ�
	cout << "������γ�:" << endl;
	cin >> course;
	s->ptr->course = course;
	string room;//����
	cout << "����������:" << endl;
	cin >> room;
	s->ptr->room = room;
	s->ptr->tell = judtell(s->ptr->bth.date+s->ptr->bth.month*100);
	write(s);
	s->ptr = s->ptr - all()+1;
	read(s);
}
int searchname(struct monitor*s,string name)
{
	int temp=0;
	while (s->ptr->name != name)
	{
		s->ptr++;
		temp++;
		if (temp > 100)
		{
			cout << "���޴���" << endl;
			break;
		}
	}
	return s->ptr->bth.month * 100 + s->ptr->bth.date;
}
int searchnum(struct monitor* s,string num)
//ѧ�Ų�ѯ���ճɹ� 
{
	int temp=0;
	while (s->ptr->num != num)
	{
		s->ptr++;
		temp++;
		if (temp > 100)
		{
			cout << "���޴���" << endl;
			break;
		}
	}
	return s->ptr->bth.month * 100 + s->ptr->bth.date;
}
void findhomeinf(monitor *s,string home)
{
	int temp2 = 0;
	int temp3 = 0;
	int temp1 = 0;
	while(true)
	{
		s->ptr++;
		temp2++;
		if(s->ptr->home==home)
		{
			coutinf(s,0);
			temp3++;
		}
		else if(temp2>all())
		{
			if(temp3!=0)
			{
			s->ptr-=temp2;
			break;
			}
			else
			{
				cout<<"���޴��ˣ�"<<endl;
				s->ptr-=temp2;
				break;
			}
		}
	}
}
void findhome(monitor* s,string name)
{
	string home;
	string sname;
	int temp2 = 0;
	int temp3 = 0;
	int temp1 = 0;
	while(s->ptr->name != name)
	{
		s->ptr++;
		temp1++;
		if (temp1 > all())
		{
			cout << "���޴��ˣ�" << endl;
			break;
		}
	}
	if (s->ptr->name == name)
	{
		home = s->ptr->home;
		sname=s->ptr->name;
		s->ptr -= temp1;
		while (temp3<=all())
	{
		temp3++;
		if (s->ptr->home == home&&s->ptr->name!=sname)
		{
			cout << "ta��������ͬһ���������������磡" << endl;
			cout << s->ptr->name<<endl;
			temp2++;
		}
		s->ptr++;
	}
	if(temp2==0)
	cout<<"���ź�����û������"<<endl;
	s->ptr-=temp3;
	}
	else 
	{
		s->ptr -= temp1;
	}
}
void findhomen(monitor* s, string num)
{
	string home;
	string snum;
	int temp2 = 0;
	int temp3 = 0;
	int temp1 = 0;
	while (s->ptr->num != num)
	{
		s->ptr++;
		temp1++;
		if (temp1 > all())
		{
			cout << "���޴��ˣ�" << endl;
			break;
		}
	}
	if (s->ptr->num == num)
	{
		home = s->ptr->home;
		snum=s->ptr->num;
		s->ptr -= temp1;
		while (temp3 <= all())
		{
			temp3++;
			if (s->ptr->home == home&&s->ptr->num!=snum)
			{
				cout << "ta��������ͬһ���������������磡" << endl;
				cout << s->ptr->name << endl;
				temp2++;
			}
			s->ptr++;
		}
		if (temp2 == 0)
			cout << "���ź�����û������" << endl;
		s->ptr -= temp3;
	}
	else
	{
		s->ptr -= temp1;
	}
}
void findroomn(monitor* s, string num)
{
	string room;
	string snum; 
	int temp2 = 0;
	int temp3 = 0;
	int temp1 = 0;
	while (s->ptr->num != num)
	{
		s->ptr++;
		temp1++;
		if (temp1 > all())
		{
			cout << "���޴��ˣ�" << endl;
			break;
		}
	}
	if (s->ptr->num == num)
	{
		room = s->ptr->room;
		snum=s->ptr->num;
		s->ptr -= temp1;
		while (temp3 <= all())
		{
			temp3++;
			if (s->ptr->room == room&&snum!=s->ptr->num)
			{
				cout << "ta��������ͬһ���ᣬ���������ѣ�" << endl;
				cout << s->ptr->name << endl;
				temp2++;
			}
			s->ptr++;
		}
		if (temp2 == 0)
			cout << "���ź�����û������" << endl;
		s->ptr -= temp3;
	}
	else
	{
		s->ptr -= temp1;
	}
}
void findroom(monitor* s, string name)
{
	string room;
	string sname;
	int temp2 = 0;
	int temp3 = 0;
	int temp1 = 0;
	while (s->ptr->name != name)
	{
		s->ptr++;
		temp1++;
		if (temp1 > all())
		{
			cout << "���޴��ˣ�" << endl;
			break;
		}
	}
	if (s->ptr->name == name)
	{
		room = s->ptr->room;
		sname=s->ptr->name;
		s->ptr -= temp1;
		while (temp3 <= all())
		{
			temp3++;
			if (s->ptr->room == room&&s->ptr->name!=sname)
			{
				cout << "ta��������ͬһ���ᣬ���������ѣ�" << endl;
				cout << s->ptr->name << endl;
				temp2++;
			}
			s->ptr++;
		}
		if (temp2 == 0)
			cout << "���ź�����û������" << endl;
		s->ptr -= temp3;
	}
	else
	{
		s->ptr -= temp1;
	}
}
void findtell(monitor* s, string name)
{
	string tell;
	string sname;
	int temp2 = 0;
	int temp3 = 0;
	int temp1 = 0;
	while (s->ptr->name != name)
	{
		s->ptr++;
		temp1++;
		if (temp1 > all())
		{
			cout << "���޴��ˣ�" << endl;
			break;
		}
	}
	if (s->ptr->name == name)
	{
		tell = s->ptr->tell;
		sname=s->ptr->name;
		s->ptr -= temp1;
		while (temp3 <= all())
		{
			temp3++;
			if (s->ptr->tell == tell&&sname!=s->ptr->name)
			{
				cout << "ta��������ͬһ������" << endl;
				cout << s->ptr->name << endl;
				temp2++;
			}
			s->ptr++;
		}
		if (temp2 == 0)
			cout << "���ź�����û��ͬ��������" << endl;
		s->ptr -= temp3;
	}
	else
	{
		s->ptr -= temp1;
	}
}
void findtelln(monitor* s, string num)
{
	string tell;
	string snum;
	int temp2 = 0;
	int temp3 = 0;
	int temp1 = 0;
	while (s->ptr->num != num)
	{
		s->ptr++;
		temp1++;
		if (temp1 > all())
		{
			cout << "���޴��ˣ�" << endl;
			break;
		}
	}
	if (s->ptr->num == num)
	{
		tell = s->ptr->tell;
		snum=s->ptr->num;
		s->ptr -= temp1;
		while (temp3 <= all())
		{
			temp3++;
			if (s->ptr->tell == tell&&s->ptr->num!=snum)
			{
				cout << "ta��������ͬһ������" << endl;
				cout << s->ptr->name << endl;
				temp2++;
			}
			s->ptr++;
		}
		if (temp2 == 0)
			cout << "���ź�����û��ͬ��������" << endl;
		s->ptr -= temp3;
	}
	else
	{
		s->ptr -= temp1;
	}
}
void changeclassn(monitor* s, string num)
{
	string temp4;
	int temp2 = 0;
	int temp3 = 0;
	int temp1 = 0;
	while (s->ptr->num != num)
	{
		s->ptr++;
		temp1++;
		if (temp1 > all())
		{
			cout << "���޴��ˣ�" << endl;
			break;
		}
	}
	if (s->ptr->num == num)
	{
		cout << "��������Ҫת��İ༶" << endl;
		cin >> temp4;
		s->ptr->class1=temp4;
		cout << "�޸ĳɹ���" << endl;
		s->ptr -= temp1;
		int i3=all(); 
		fstream file("data1.txt", ios::out);
		file.close();
		int i; 
		for (i = 0; i < i3; i++)
		{
			if(i==0)
			{
				writes(s);
			}
			else
			{
				write(s);
			}
			s->ptr++;
		}
		s->ptr-=i;
	}

	else
	{
		s->ptr -= temp1;
	}
}
void changeclass(monitor* s, string name)
{
	string temp4;
	int temp2 = 0;
	int temp3 = 0;
	int temp1 = 0;
	while (s->ptr->name != name)
	{
		s->ptr++;
		temp1++;
		if (temp1 > all())
		{
			cout << "���޴��ˣ�" << endl;
			break;
		}
	}
	if (s->ptr->name == name)
	{
		cout << "��������Ҫת��İ༶" << endl;
		cin >> temp4;
		s->ptr->class1=temp4;
		cout << "�޸ĳɹ���" << endl;
		s->ptr -= temp1;
		int i3=all(); 
		fstream file("data1.txt", ios::out);
		file.close();
		int i2=0;
		for (; i2 < i3; )
		{
			if(i2==0)
			{
				writes(s);
			}
			else
			{
				write(s);
			}
			//cout<<"halo"<<endl;
			s->ptr++;
			i2++;
		}
		s->ptr-=i2;
	}
	else
	{
		s->ptr -= temp1;
	}
}


