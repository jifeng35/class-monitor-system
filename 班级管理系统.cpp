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
        hello();// ��ӭ����ʾ�����Ľ���
        cin >> i;
        switch (i)
        {
        case 0://�˳�����
            cout << "��ӭ�´�����" << endl;
            system("pause");
            return 0;
        case 1://�༶������
            i1=all();
            cout << "�༶������Ϊ��" << i1 << endl;
            break;
        case 2:
        	add(&arr); 
            cout << "��ת�����ϢΪ" << endl;
            coutinf(&arr,all()-1);//ת��ѧ��
            break;
        case 3:
        	while (true)
			{
				cout<<"����������ı�ѧ������Ϣ��1Ϊѧ�Ų�ѯ/2Ϊ������ѯ��" <<endl;
				int i0;
				cin >> i0;
					if (i0 == 2)
					{
						cout << "�������ѧ������" << endl;
						string name6;
						cin >> name6;
						changeclass(&arr, name6);
						break;
					}
					else if(i0==1)
					{
						cout << "�������ѧ��ѧ��" << endl;
						string num6; 
						cin >> num6;
						changeclassn(&arr,num6);
						break;

					}
					else
					{
						cout << "�����������������룡" << endl;
					}
			}
			break;//�༶ת��ѧ�� 
        case 4:
        {
			while (true)
			{
				int iq;
				cout << "��ѡ���ѯ��ʽ����1Ϊѧ�Ų�ѯ/2Ϊ������ѯ��" << endl;
				cin >> iq;
					if (iq == 2)
					{
						cout << "��������������" << endl;
						string name3;
						cin >> name3;
						findhome(&arr, name3);
						break;
					}
					else if(iq==1)
					{
						cout << "����������ѧ��" << endl;
						string num3;
						cin >> num3;
						findhomen(&arr,num3);
						break;

					}
					else
					{
						cout << "�����������������룡" << endl;
					}
			}
		}
			break;//������
        case 5:
		{
			while (true)
			{
				cout << "��ѡ���ѯ��ʽ����1Ϊѧ�Ų�ѯ/2Ϊ������ѯ��" << endl;
				int iq;
				cin >> iq;
				if (iq == 2)
				{
					cout << "��������������" << endl;
					string name4;
					cin >> name4;
					findroom(&arr, name4);
					break;
				}
				else if (iq == 1)
				{
					cout << "����������ѧ��" << endl;
					string num4;
					cin >> num4;
					findroomn(&arr, num4);
					break;

				}
				else
				{
					cout << "�����������������룡" << endl;
				}
			}
		}
			break;//������
        case 6:
		{
			while (true)
			{
				cout << "��ѡ���ѯ��ʽ����1Ϊѧ�Ų�ѯ/2Ϊ������ѯ��" << endl;
				int iq;
				cin >> iq;
				if (iq == 2)
				{
					cout << "��������������" << endl;
					string name5;
					cin >> name5;
					findtell(&arr, name5);
					break;
				}
				else if (iq == 1)
				{
					cout << "����������ѧ��" << endl;
					string num5;
					cin >> num5;
					findtelln(&arr, num5);
					break;

				}
				else
				{
					cout << "�����������������룡" << endl;
				}
			}
		}
			break;//��ͬ����
        case 7:
			while(true)
			{
				cout << "��ѡ���ѯ��ʽ����1Ϊѧ�Ų�ѯ/2Ϊ������ѯ��" << endl;
		 		int t;
				cin>>t;
                if (t == 1)
                {                                       	            
	                        cout << "������ѧ��ѧ�ţ�" << endl;
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
	                            	cout << "���޴���!" << endl;
	                            	system("pause"); 
	                            	(&arr)->ptr-=t1;
								}
	                    
                    break;
                }
				else if (t==2)
				{
                   
	                        cout << "������ѧ��������" << endl;
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
	                            	cout << "���޴���!" << endl;
	                            	system("pause"); 
	                            	(&arr)->ptr-=t2;	                        		                           	
								}	                    
                    			break;
				}
				else
				{
					cout<<"�����������������룡"<<endl;
				}
			}
			break;//��Ѱѧ����Ϣ�ɹ� 
        case 8:
        	while(true) 
        {
			cout << "��ѡ���ѯ��ʽ����1Ϊѧ�Ų�ѯ/2Ϊ������ѯ��" << endl;
            int temp;
            cin >> temp;
            if (temp == 1)
            {
                cout << "������ѧ��ѧ�ţ�" << endl;
                string num;
                cin >> num;
                judtell(searchnum(&arr, num));
                
            }
            else if (temp == 2)
            {
                cout << "������ѧ��������" << endl;
                string name;
                cin >> name;
                judtell(searchname(&arr, name));       
            }
            else
            {
            	cout<<"�����ѯ��ʽ�������������룡"<<endl;
			}
        }
            break;//��ѯѧ������
        case 9:
		{
			cout << "���������ļ���" << endl;
			string home;
			cin >> home;
			findhomeinf(&arr, home);
		}
			break;//������Ѱ��ѧ��
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
