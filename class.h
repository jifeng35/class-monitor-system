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
	int age;//年龄
	string num;//学号
	string sex;//性别 男1 女0
	string name;//姓名
	string class1;//班级
	string class1num;//班内序号
	string hobby;//爱好
	string organ;//社团/学生组织
	struct birthday bth;//生日
	string home;//家乡
	string course;//课程
	string room;//宿舍
	string tell;//星座
};
int all()//班级总人数实现成功
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
	//cout << "班级总人数为： " << temp - 1 << endl;
	return temp;
}
struct monitor 
{
	struct student *ptr= new student[100];
	int size = all();
};
void read(struct monitor* s)//用于更新存储于结构体内的数据，成功 
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
	cout << "该学生的姓名\t\t" << s->ptr->name << endl;
	cout << "该学生的学号\t\t" << s->ptr->num << endl;
	cout << "该学生的性别\t\t" << s->ptr->sex << endl;
	cout << "该学生的班级\t\t" << s->ptr->class1 << endl;
	cout << "该学生的班内序号\t" << s->ptr->class1num << endl;
	cout << "该学生的爱好\t\t" << s->ptr->hobby << endl;
	cout << "该学生的加入组织\t" << s->ptr->organ << endl;
	cout << "该学生的生日\t\t" << s->ptr->bth.year << "年" << s->ptr->bth.month << "月" << s->ptr->bth.date << "日" << endl;
	cout << "该学生的家乡\t\t" << s->ptr->home << endl;
	cout << "该学生的课程\t\t" << s->ptr->course << endl;
	cout << "该学生的宿舍\t\t" << s->ptr->room << endl;
	for (int j = 0; j < i; j++)
	{
		s->ptr--;
	}
}
void hello()
{
	cout << "欢迎使用bupt学生管理系统！" << endl;
	cout << "请选择要使用的功能： " << endl;
	cout << "查询班级总人数\t请按1 " << endl;
	cout << "添加学生\t请按2" << endl;
	cout << "更改学生班号\t请按3" << endl;
	cout << "找老乡\t\t请按4" << endl;
	cout << "找舍友\t\t请按5" << endl;
	cout << "找同星座\t请按6" << endl;
	cout << "查询学生信息\t请按7" << endl; 
	cout << "查询学生星座\t请按8" << endl;
	cout << "按家乡寻找学生\t请按9" << endl;
	cout << "年龄升序排列\t请按10" << endl;
	cout << "退出程序\t请按0" << endl;
	//cout<<"如果程序出错，请输入10进行重置"<<endl;
}
void sort(struct monitor* s, int len)//年龄由大到小
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
		cout << "该学生的星座为白羊座"<<endl;
		return "白羊座";
	}
	else if (421 <= num&&num <= 521)
	{
		cout << "该学生的星座为金牛座" << endl;
		return "金牛座";
	}
	else if (522 <= num && num <= 621)
	{
		cout << "该学生的星座为双子座" << endl;
		return "双子座";
	}
	else if (622 <= num && num <= 722)
	{
		cout << "该学生的星座为巨蟹座" << endl;
		return "巨蟹座";
	}
	else if (723 <= num && num <= 823)
	{
		cout << "该学生的星座为狮子座" << endl;
		return "狮子座";
	}
	else if (824 <= num && num <= 923)
	{
		cout << "该学生的星座为处女座" << endl;
		return "处女座";
	}
	else if (924 <= num && num <= 1023)
	{
		cout << "该学生的星座为天秤座" << endl;
		return "天秤座";
	}
	else if (1024 <= num && num <= 1122)
	{
		cout << "该学生的星座为天蝎座" << endl;
		return "天蝎座";
	}
	else if (1123 <= num && num <= 1221)
	{
		cout << "该学生的星座为射手座" << endl;
		return "射手座";
	}
	else if (1222 <= num && num <= 1231)
	{
		cout << "该学生的星座为魔羯座" << endl;
		return "魔羯座";
	}
	else if (101 <= num && num <= 120)
	{
		cout << "该学生的星座为魔羯座" << endl;
		return "魔羯座";
	}
	else if (121 <= num && num <= 219)
	{
		cout << "该学生的星座为水瓶座" << endl;
		return "水瓶座";
	}
	else if (220 <= num && num <= 320)
	{
		cout << "该学生的星座为双鱼座" << endl;
		return "双鱼座";
	}
}
void add(struct monitor  *s)
{
	//cout << "如果想在输出过程中取消添加该学生信息请在任意信息中输入取消" << endl;
	s->ptr=s->ptr+all();
	string num;//学号
	cout << "请输入学号：" << endl;
	cin >> num;
	s->ptr->num = num;
	string sex;//性别 男1 女0
	while (true)
	{
		cout << "请输入性别：" << endl;
		cin >> sex;
		if (sex == "男" || sex == "女")
		{
			s->ptr->sex = sex;
			break;
		}
		else
		{
			cout << "输入有误！" << endl;
		}
	}
	string name;//姓名
	cout << "请输入姓名：" << endl;
	cin >> name;
	s->ptr->name = name;
	string class1;//班级
	cout << "请输入班级：" << endl;
	cin >> class1;
	s->ptr->class1 = class1;
	string class1num;//班内序号
	cout << "请输入班内序号：" << endl;
	cin >> class1num;
	s->ptr->class1num = class1num;
	string hobby;//爱好
	cout << "请输入爱好：" << endl;
	cin >> hobby;
	s->ptr->hobby = hobby;
	string organ;//社团/学生组织
	cout << "请输入学生组织：" << endl;
	cin >> organ;
	s->ptr->organ = organ;
	struct birthday bth;//生日
	int year, month, date;
	cout << "请输入生日：(年份)" << endl;
	cin >> year;
	s->ptr->bth.year = year;
	while(true)
	{
	cout << "请输入生日：(月份)" << endl;
	cin.clear();
	cin.ignore(8192,'\n');
	cin >> month;
		if (month >= 1 && month <= 12)
		{
			break;
		}
		else
		{
			cout << "输入月份非法！请重新输入！" << endl;
		}
	}
	s->ptr->bth.month = month;
	while (true)
	{
		cout << "请输入生日：(日期)" << endl;
		cin >> date;
		if (date >= 1 && date <= 31)
		{
			break;
		}
		else
		{
			cout << "输入日期非法！请重新输入！" << endl;
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
	cout << "该学生的年龄为" << s->ptr->age<<endl;
	string home;//家乡
	cout << "请输入家乡:" << endl;
	cin >> home;
	s->ptr->home = home;
	string course;//课程
	cout << "请输入课程:" << endl;
	cin >> course;
	s->ptr->course = course;
	string room;//宿舍
	cout << "请输入宿舍:" << endl;
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
			cout << "查无此人" << endl;
			break;
		}
	}
	return s->ptr->bth.month * 100 + s->ptr->bth.date;
}
int searchnum(struct monitor* s,string num)
//学号查询生日成功 
{
	int temp=0;
	while (s->ptr->num != num)
	{
		s->ptr++;
		temp++;
		if (temp > 100)
		{
			cout << "查无此人" << endl;
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
				cout<<"查无此人！"<<endl;
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
			cout << "查无此人！" << endl;
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
			cout << "ta与您来自同一地区，是您的老乡！" << endl;
			cout << s->ptr->name<<endl;
			temp2++;
		}
		s->ptr++;
	}
	if(temp2==0)
	cout<<"很遗憾！您没有老乡"<<endl;
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
			cout << "查无此人！" << endl;
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
				cout << "ta与您来自同一地区，是您的老乡！" << endl;
				cout << s->ptr->name << endl;
				temp2++;
			}
			s->ptr++;
		}
		if (temp2 == 0)
			cout << "很遗憾！您没有老乡" << endl;
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
			cout << "查无此人！" << endl;
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
				cout << "ta与您来自同一宿舍，是您的舍友！" << endl;
				cout << s->ptr->name << endl;
				temp2++;
			}
			s->ptr++;
		}
		if (temp2 == 0)
			cout << "很遗憾！您没有舍友" << endl;
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
			cout << "查无此人！" << endl;
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
				cout << "ta与您来自同一宿舍，是您的舍友！" << endl;
				cout << s->ptr->name << endl;
				temp2++;
			}
			s->ptr++;
		}
		if (temp2 == 0)
			cout << "很遗憾！您没有舍友" << endl;
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
			cout << "查无此人！" << endl;
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
				cout << "ta与您来自同一星座！" << endl;
				cout << s->ptr->name << endl;
				temp2++;
			}
			s->ptr++;
		}
		if (temp2 == 0)
			cout << "很遗憾！您没有同星座的人" << endl;
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
			cout << "查无此人！" << endl;
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
				cout << "ta与您来自同一星座！" << endl;
				cout << s->ptr->name << endl;
				temp2++;
			}
			s->ptr++;
		}
		if (temp2 == 0)
			cout << "很遗憾！您没有同星座的人" << endl;
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
			cout << "查无此人！" << endl;
			break;
		}
	}
	if (s->ptr->num == num)
	{
		cout << "请输入您要转入的班级" << endl;
		cin >> temp4;
		s->ptr->class1=temp4;
		cout << "修改成功！" << endl;
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
			cout << "查无此人！" << endl;
			break;
		}
	}
	if (s->ptr->name == name)
	{
		cout << "请输入您要转入的班级" << endl;
		cin >> temp4;
		s->ptr->class1=temp4;
		cout << "修改成功！" << endl;
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


