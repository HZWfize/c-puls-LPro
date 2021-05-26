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

		if (select == 1)//添加账号
		{
			cout << "添加账号"<<endl;
			man->addPerson();
		}
		else if (select == 2)//查看账号
		{
			cout << "查看账号"<<endl;
			man->showPerson();
		}
		else if (select == 3)//查看机房
		{
			cout << "查看机房" << endl;
			man->showComputer();
		}
		else if (select == 4)//清空预约
		{
			cout << "清空预约" << endl;
			man->cleanFile();
		}
		else if (select == 0)//注销登录
		{
			delete manager;
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "输入错误，请重新输入" << endl;
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

		if (select == 1)//申请预约
		{
			cout << "申请预约" << endl;
			stu->applyOrder();
		}
		else if (select == 2)//查看自身预约
		{
			cout << "查看自身预约" << endl;
			stu->showMyOrder();
		}
		else if (select == 3)//查看所有预约
		{
			cout << "查看所有预约" << endl;
			stu->showAllOrder();
		}
		else if (select == 4)//取消预约
		{
			cout << "取消预约" << endl;
			stu->cancelOrder();
		}
		else if (select == 0)//注销登录
		{
			delete student;
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "输入错误，请重新输入" << endl;
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

		
		if (select == 1)//查看所有预约
		{
			cout << "查看所有预约" << endl;
			tea->showAllOrder();
		}
		else if (select == 2)//取消预约
		{
			cout << "审核预约" << endl;
			tea->vaildOrder();
		}
		else if (select == 0)//注销登录
		{
			delete teacher;
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
		else
		{
			cout << "输入错误，请重新输入" << endl;
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
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}
	int id = 0;
	string name;
	string pwd;
	if (type == 1)
	{
		cout << "请输入你的学号：";
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "请输入你的职工号：";
		cin >> id;
	}
	cout << "请输入用户名：";
	cin >> name;
	cout << "请输入密码：";
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
				cout << "学生验证登录成功!" << endl;
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);
				//进入学生子菜单
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
				cout << "教师验证登录成功!" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);
				//进入教师子菜单
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
				cout << "管理员验证登录成功!" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);
				//进入管理员子菜单
				managerMenu(person);

				return;
			}
		}
	}
	cout << "登录验证失败！" << endl;
	system("pause");
	system("cls");
	return;
}





int main()
{
	while (true)
	{
		int select = 0;
		cout << "======================  欢迎来到机房预约系统  =============================" << endl;
		cout << endl << "请输入您的身份：" << endl;
		cout << "\t\t ------------------------------------\n";
		cout << "\t\t|                                    |\n";
		cout << "\t\t|             1.学生代表             |\n";
		cout << "\t\t|                                    |\n";
		cout << "\t\t|             2.老    师             |\n";
		cout << "\t\t|                                    |\n";
		cout << "\t\t|             3.管 理 员             |\n";
		cout << "\t\t|                                    |\n";
		cout << "\t\t|             0.退    出             |\n";
		cout << "\t\t|                                    |\n";
		cout << "\t\t ------------------------------------\n";
		cout << "输入您的选择：";
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
			cout << "欢迎下次使用！" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误，请重新输入！";
			system("pause");
			system("cls");
			break;
		}
	}
	











	system("pause");
	return 0;

}