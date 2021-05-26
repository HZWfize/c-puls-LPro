#include"manager.h"
#include<fstream>
#include"globalFile.h"
#include"student.h"
#include"teacher.h"
#include<algorithm>
Manager::Manager()
{
	
}
Manager::Manager(string name, string pwd)
{
	this->m_Name = name;
	this->m_Pwd = pwd;

	this->initVector();
	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);
	ComputerRoom c;
	while (ifs >> c.m_ComId && ifs >> c.m_MaxNum)
	{
		vCom.push_back(c);
	}
	cout << "��ǰ��������Ϊ" << vCom.size() << endl;
	ifs.close();
}

void Manager::operMenu()
{
	cout << "��ӭ����Ա��"<<this->m_Name<<"��¼"<< endl;
	cout << "\t\t ------------------------------------\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|             1.����˺�             |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|             2.�鿴�˺�             |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|             3.�鿴����             |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|             4.���ԤԼ             |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|             0.ע����¼             |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t ------------------------------------\n";
	cout << "��ѡ�����Ĳ�����";
}

//����˺�
void Manager::addPerson()
{
	cout << "����������˺ŵ����ͣ�" << endl;
	cout << "1�����ѧ��" << endl;
	cout << "2�������ʦ" << endl;

	string fileName;
	string tip;
	string error;
	ofstream ofs;
	int select = 0;
	cin >> select;
	
	if (select == 1)
	{
		fileName = STUDENT_FILE;
		tip = "������ѧ�ţ�";
		error = "ѧ���ظ�������������";
	}
	else if (select == 2)
	{
		fileName = TECHER_FILE;
		tip = "������ְ���ţ�";
		error = "ְ�����ظ�������������";
	}
	else
	{
		cout << "��Ч����������������" << endl;
		system("pause");
		system("cls");
		return;
	}
	ofs.open(fileName, ios::out | ios::app);
	int id;
	string name;
	string pwd;
	cout << tip << endl;
	while (true)
	{
		cin >> id;
		bool ret = this->checkRepeat(id, select);
		if (ret)
		{
			cout << error << endl;
		}
		else
		{
			break;
		}
	}
	cout << "�������û�����"<<endl;
	cin >> name;
	cout << "���������룺"<<endl;
	cin >> pwd;
	ofs << id << " " << name << " " << pwd << " " << endl;
	cout << "��ӳɹ���" << endl;

	system("pause");
	system("cls");

	ofs.close();

	this->initVector();
}

void printStudent(Student& s)
{
	cout << "ѧ�ţ�" << s.m_Id << " ������" << s.m_Name << " ���룺" << s.m_Pwd << endl;
}

void printTeacher(Teacher& t)
{
	cout << "ѧ�ţ�" << t.m_EmpId << " ������" << t.m_Name << " ���룺" << t.m_Pwd << endl;
}


//�鿴�˺�
void Manager::showPerson()
{
	cout << "��ѡ��鿴���ݣ�" << endl;
	cout << "1���鿴����ѧ��" << endl;
	cout << "2���鿴���н�ʦ" << endl;
	int select = 0;
	cin >> select;
	if (select == 1)
	{
		cout << "����ѧ����Ϣ���£�" << endl;
		for_each(vStu.begin(), vStu.end(), printStudent);

	}
	else
	{
		cout << "���н�ʦ��Ϣ���£�" << endl;
		for_each(vTea.begin(), vTea.end(), printTeacher);
	}
	system("pause");
	system("cls");
}

//�鿴������Ϣ
void Manager::showComputer()
{
	cout << "������Ϣ���£�" << endl;
	for (vector<ComputerRoom>::iterator it = vCom.begin(); it != vCom.end(); it++)
	{
		cout << "������ţ�" << it->m_ComId << " ����������" << it->m_MaxNum << endl;
	}
	system("pause");
	system("cls");
}

//���ԤԼ��¼
void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();
	cout << "��ճɹ���" << endl;
	system("pause");
	system("cls");
}

void Manager::initVector()
{
	vStu.clear();
	vTea.clear();
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ�ܣ�" << endl;
		return;
	}
	Student s;
	while (ifs >> s.m_Id && ifs >> s.m_Name && ifs >> s.m_Pwd)
	{
		vStu.push_back(s);

	}
	cout << "��ǰѧ������Ϊ��" << vStu.size() << endl;
	ifs.close();

	ifs.open(TECHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "�ļ���ȡʧ�ܣ�" << endl;
		return;
	}
	Teacher t;
	while (ifs >> t.m_EmpId && ifs >> t.m_Name && ifs >> t.m_Pwd)
	{
		vTea.push_back(t);

	}
	cout << "��ǰ��ʦ����Ϊ��" << vTea.size() << endl;
	ifs.close();


}

bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		for (vector<Student>::iterator it = vStu.begin(); it != vStu.end(); it++)
		{
			if (id == it->m_Id)
			{
				return true;
			}
		}
	}
	else if (type == 2)
	{
		for (vector<Teacher>::iterator it = vTea.begin(); it != vTea.end(); it++)
		{
			if (id == it->m_EmpId)
			{
				return true;
			}
		}
	}
	return false;
}


