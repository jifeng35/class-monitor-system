#include"class.h"
int main()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_INTENSITY | FOREGROUND_GREEN | FOREGROUND_BLUE);
    int i;
    int i1 = 0;
    struct monitor arr;
    read(&arr);
    //cout << sizeof((&arr)->ptr[0]);
    //cout << "halo"<<(&arr)->ptr->name<<"what the hell";
   	//coutinf(&arr, 1);
    while (true)
    {
        hello();// 欢迎并提示操作的界面
        cin >> i;
        switch (i)
        {
        case 0://退出程序
            cout << "欢迎下次再来" << endl;
            system("pause");
            return 0;
        case 1://班级总人数
            i1=all();
            cout << "班级总人数为：" << i1 << endl;
            break;
        case 2:
        	add(&arr); 
            cout << "您转入的信息为" << endl;
            coutinf(&arr,all()-1);//转入学生
            break;
        case 3:
        	while (true)
			{
				cout<<"请输入您想改变学生的信息（1为学号查询/2为姓名查询）" <<endl;
				int i0;
				cin >> i0;
					if (i0 == 2)
					{
						cout << "请输入该学生名字" << endl;
						string name6;
						cin >> name6;
						changeclass(&arr, name6);
						break;
					}
					else if(i0==1)
					{
						cout << "请输入该学生学号" << endl;
						string num6; 
						cin >> num6;
						changeclassn(&arr,num6);
						break;

					}
					else
					{
						cout << "输入有误，请重新输入！" << endl;
					}
			}
			break;//班级转出学生 
        case 4:
        {
			while (true)
			{
				int iq;
				cout << "请选择查询方式：（1为学号查询/2为姓名查询）" << endl;
				cin >> iq;
					if (iq == 2)
					{
						cout << "请输入您的名字" << endl;
						string name3;
						cin >> name3;
						findhome(&arr, name3);
						break;
					}
					else if(iq==1)
					{
						cout << "请输入您的学号" << endl;
						string num3;
						cin >> num3;
						findhomen(&arr,num3);
						break;

					}
					else
					{
						cout << "输入有误，请重新输入！" << endl;
					}
			}
		}
			break;//找老乡
        case 5:
		{
			while (true)
			{
				cout << "请选择查询方式：（1为学号查询/2为姓名查询）" << endl;
				int iq;
				cin >> iq;
				if (iq == 2)
				{
					cout << "请输入您的名字" << endl;
					string name4;
					cin >> name4;
					findroom(&arr, name4);
					break;
				}
				else if (iq == 1)
				{
					cout << "请输入您的学号" << endl;
					string num4;
					cin >> num4;
					findroomn(&arr, num4);
					break;

				}
				else
				{
					cout << "输入有误，请重新输入！" << endl;
				}
			}
		}
			break;//找舍友
        case 6:
		{
			while (true)
			{
				cout << "请选择查询方式：（1为学号查询/2为姓名查询）" << endl;
				int iq;
				cin >> iq;
				if (iq == 2)
				{
					cout << "请输入您的名字" << endl;
					string name5;
					cin >> name5;
					findtell(&arr, name5);
					break;
				}
				else if (iq == 1)
				{
					cout << "请输入您的学号" << endl;
					string num5;
					cin >> num5;
					findtelln(&arr, num5);
					break;

				}
				else
				{
					cout << "输入有误，请重新输入！" << endl;
				}
			}
		}
			break;//找同星座
        case 7:
			while(true)
			{
				cout << "请选择查询方式：（1为学号查询/2为姓名查询）" << endl;
		 		int t;
				cin>>t;
                if (t == 1)
                {                                       	            
	                        cout << "请输入学生学号：" << endl;
	                        string num1;
	                        cin >> num1;
	                        int t1 = 0;
	                        while ((&arr)->ptr->num != num1)
	                        {
	                            if (t1 > all())
	                            {	                                    
	                                break;
	                            }	                                
	                                (&arr)->ptr++; 
	                                t1++;
	                        }
	                            if((&arr)->ptr->num == num1)
	                            {
									coutinf(&arr,0);									
									break;
								}
	                            else
	                            {
	                            	cout << "查无此人!" << endl;
	                            	system("pause"); 
	                            	(&arr)->ptr-=t1;
								}
	                    
                    break;
                }
				else if (t==2)
				{
                   
	                        cout << "请输入学生姓名：" << endl;
	                        string name1;
	                        cin >> name1;
	                        int t2 = 0;
	                        while ((&arr)->ptr->name != name1)
	                        {
	                            if (t2 > all())
	                            {	                                    
	                                break;
	                            }	                                
	                                (&arr)->ptr++;
	                                t2++;
	                        	}
	                            if((&arr)->ptr->name == name1)
	                            {
									coutinf(&arr,0);
									break;
								}
	                            else
	                            {
	                            	cout << "查无此人!" << endl;
	                            	system("pause"); 
	                            	(&arr)->ptr-=t2;	                        		                           	
								}	                    
                    			break;
				}
				else
				{
					cout<<"输入有误！请重新输入！"<<endl;
				}
			}
			break;//查寻学生信息成功 
        case 8:
        	while(true) 
        {
			cout << "请选择查询方式：（1为学号查询/2为姓名查询）" << endl;
            int temp;
            cin >> temp;
            if (temp == 1)
            {
                cout << "请输入学生学号：" << endl;
                string num;
                cin >> num;
                judtell(searchnum(&arr, num));
                
            }
            else if (temp == 2)
            {
                cout << "请输入学生姓名：" << endl;
                string name;
                cin >> name;
                judtell(searchname(&arr, name));       
            }
            else
            {
            	cout<<"输入查询方式有误！请重新输入！"<<endl;
			}
        }
            break;//查询学生星座
        case 9:
		{
			cout << "请输入您的家乡" << endl;
			string home;
			cin >> home;
			findhomeinf(&arr, home);
		}
			break;//按家乡寻找学生
		case 10:
			sort(&arr, all());
			int i = 1;
			while (i < all()+1)
			{
				coutinf(&arr, 0);
				cout<<endl;
				i++;
				(&arr)->ptr++;
			}
			read(&arr);
            break;
        }
        system("pause");
        system("cls");
    }
    delete []  (&arr)->ptr;
}
