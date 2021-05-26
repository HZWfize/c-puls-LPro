#include"teacher.h"
#include"orderFile.h"
Teacher::Teacher()
{

}

Teacher::Teacher(int empId, string name, string pwd)
{
	this->m_EmpId = empId;
	this->m_Name = name;
	this->m_Pwd = pwd;
}

void Teacher::operMenu()
{
	cout << "��ӭ��ʦ��" << this->m_Name << "��¼" << endl;
	cout << "\t\t ------------------------------------\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|             1.�鿴����ԤԼ         |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|             2.���ԤԼ             |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|             0.ע����¼             |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t ------------------------------------\n";
	cout << "��ѡ�����Ĳ�����";
}
void Teacher::showAllOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_Size; i++)
	{
		cout << i + 1 << "��";
		cout << "ԤԼ���ڣ���" << of.m_orderData[i]["date"];
		cout << " ʱ�Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
		cout << " ������" << of.m_orderData[i]["roomId"];
		string status = "״̬��";//1="�����" 2="��ԤԼ" -1="ԤԼʧ��" 0="ȡ����ԤԼ"
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "�����";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "ԤԼ�ɹ�";
		}
		else if (of.m_orderData[i]["status"] == "-1")
		{
			status += "���δͨ����ԤԼʧ��";
		}
		else if (of.m_orderData[i]["status"] == "0")
		{
			status += "ԤԼ��ȡ��";
		}
		cout << status << endl;
	}
	system("pause");
	system("cls");
}

void Teacher::vaildOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "��������Ҫ��˵ļ�¼:" << endl;

	for (int i = 0; i < of.m_Size; i++)
	{
		cout << i + 1 << "��";
		cout << "ԤԼ���ڣ���" << of.m_orderData[i]["date"];
		cout << " ʱ�Σ�" << (of.m_orderData[i]["interval"] == "1" ? "����" : "����");
		cout << " ������" << of.m_orderData[i]["roomId"];
		string status = "״̬��";//1="�����" 2="��ԤԼ" -1="ԤԼʧ��" 0="ȡ����ԤԼ"
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "�����";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "ԤԼ�ɹ�";
		}
		else if (of.m_orderData[i]["status"] == "-1")
		{
			status += "���δͨ����ԤԼʧ��";
		}
		else if (of.m_orderData[i]["status"] == "0")
		{
			status += "ԤԼ��ȡ��";
		}
		cout << status << endl;
	}

	cout << "��������Ҫ��˵ļ�¼��ţ�0Ϊ����" << endl;
	int select = 0;
	int select2 = 0;
	while (true)
	{
		cin >> select;
		if (select == 0)
		{
			break;
		}
		else
		{
			cout << "��ѡ�����״̬(1Ϊ���ͨ����2Ϊ��˲�ͨ����:" << endl;
			cin >> select2;
			if (select2 == 1)
			{
				of.m_orderData[select - 1]["status"] = "2";
				of.updateOrder();
				cout << "�ѳɹ��ı����״̬Ϊ��ԤԼ" << endl;
				break;
			}
			else if (select == 2)
			{
				of.m_orderData[select - 1]["status"] = "-1";
				of.updateOrder();
				cout << "�ѳɹ��ı����״̬ΪԤԼʧ��" << endl;
				break;
			}
			else
			{
				cout << "�����������������" << endl;
				break;
			}

		}
		cout << "������������������" << endl;
	}
	system("pause");
	system("cls");
}