#include<iostream>
#include"globalFile.h"
#include"identity.h"
#include<fstream>
#include<string>
#include"student.h"
#include"teacher.h"
#include"manager.h"

void managerMenu(Identity*& manager)
{
	while (true)
	{
		manager->operMenu();

		Manager* man = (Manager*)manager;

		int select = 0;
		cin >> select;

		if (select == 1)//����˺�
		{
			cout << "����˺�"<<endl;
			man->addPerson();
		}
		else if (select == 2)//�鿴�˺�
		{
			cout << "�鿴�˺�"<<endl;
			man->showPerson();
		}
		else if (select == 3)//�鿴����
		{
			cout << "�鿴����" << endl;
			man->showComputer();
		}
		else if (select == 4)//���ԤԼ
		{
			cout << "���ԤԼ" << endl;
			man->cleanFile();
		}
		else if (select == 0)//ע����¼
		{
			delete manager;
			cout << "ע���ɹ���" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "�����������������" << endl;
			system("pause");
			system("cls");
		}
		
	}
}

void studentMenu(Identity*& student)
{
	while (true)
	{
		student->operMenu();

		Student* stu = (Student*)student;

		int select = 0;
		cin >> select;

		if (select == 1)//����ԤԼ
		{
			cout << "����ԤԼ" << endl;
			stu->applyOrder();
		}
		else if (select == 2)//�鿴����ԤԼ
		{
			cout << "�鿴����ԤԼ" << endl;
			stu->showMyOrder();
		}
		else if (select == 3)//�鿴����ԤԼ
		{
			cout << "�鿴����ԤԼ" << endl;
			stu->showAllOrder();
		}
		else if (select == 4)//ȡ��ԤԼ
		{
			cout << "ȡ��ԤԼ" << endl;
			stu->cancelOrder();
		}
		else if (select == 0)//ע����¼
		{
			delete student;
			cout << "ע���ɹ���" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "�����������������" << endl;
			system("pause");
			system("cls");
		}

	}
}

void TeacherMenu(Identity*& teacher)
{
	while (true)
	{
		teacher->operMenu();

		Teacher* tea = (Teacher*)teacher;

		int select = 0;
		cin >> select;

		
		if (select == 1)//�鿴����ԤԼ
		{
			cout << "�鿴����ԤԼ" << endl;
			tea->showAllOrder();
		}
		else if (select == 2)//ȡ��ԤԼ
		{
			cout << "���ԤԼ" << endl;
			tea->vaildOrder();
		}
		else if (select == 0)//ע����¼
		{
			delete teacher;
			cout << "ע���ɹ���" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "�����������������" << endl;
			system("pause");
			system("cls");
		}

	}
}



void LoginIn(string fileName, int type)
{
	Identity* person = NULL;
	ifstream ifs;
	ifs.open(fileName, ios::in);

	if (!ifs.is_open())
	{
		cout << "�ļ�������" << endl;
		ifs.close();
		return;
	}
	int id = 0;
	string name;
	string pwd;
	if (type == 1)
	{
		cout << "���������ѧ�ţ�";
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "���������ְ���ţ�";
		cin >> id;
	}
	cout << "�������û�����";
	cin >> name;
	cout << "���������룺";
	cin >> pwd;

	if (type == 1)
	{
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (id == fId && name == fName && pwd == fPwd)
			{
				cout << "ѧ����֤��¼�ɹ�!" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//����ѧ���Ӳ˵�
				studentMenu(person);

				return;
			}
		}

	}
	else if (type == 2)
	{
		int fId;
		string fName;
		string fPwd;
		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			if (id == fId && name == fName && pwd == fPwd)
			{
				cout << "��ʦ��֤��¼�ɹ�!" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//�����ʦ�Ӳ˵�
				TeacherMenu(person);

				return;
			}
		}
	}
	else if (type == 3)
	{
		string fName;
		string fPwd;
		while (ifs >> fName && ifs >> fPwd)
		{
			if (name == fName && pwd == fPwd)
			{
				cout << "����Ա��֤��¼�ɹ�!" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//�������Ա�Ӳ˵�
				managerMenu(person);

				return;
			}
		}
	}
	cout << "��¼��֤ʧ�ܣ�" << endl;
	system("pause");
	system("cls");
	return;
}





int main()
{
	while (true)
	{
		int select = 0;
		cout << "======================  ��ӭ��������ԤԼϵͳ  =============================" << endl;
		cout << endl << "������������ݣ�" << endl;
		cout << "\t\t ------------------------------------\n";
		cout << "\t\t|                                    |\n";
		cout << "\t\t|             1.ѧ������             |\n";
		cout << "\t\t|                                    |\n";
		cout << "\t\t|             2.��    ʦ             |\n";
		cout << "\t\t|                                    |\n";
		cout << "\t\t|             3.�� �� Ա             |\n";
		cout << "\t\t|                                    |\n";
		cout << "\t\t|             0.��    ��             |\n";
		cout << "\t\t|                                    |\n";
		cout << "\t\t ------------------------------------\n";
		cout << "��������ѡ��";
		cin >> select;
		switch (select)
		{
		case 1:
			LoginIn(STUDENT_FILE, 1);
			break;
		case 2:
			LoginIn(TECHER_FILE, 2);
			break;
		case 3:
			LoginIn(ADMIN_FILE, 3);
			break;
		case 0:
			cout << "��ӭ�´�ʹ�ã�" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "�����������������룡";
			system("pause");
			system("cls");
			break;
		}
	}
	











	system("pause");
	return 0;

}