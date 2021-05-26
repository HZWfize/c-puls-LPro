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
	cout << "欢迎老师：" << this->m_Name << "登录" << endl;
	cout << "\t\t ------------------------------------\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|             1.查看所有预约         |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|             2.审核预约             |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t|             0.注销登录             |\n";
	cout << "\t\t|                                    |\n";
	cout << "\t\t ------------------------------------\n";
	cout << "请选择您的操作：";
}
void Teacher::showAllOrder()
{
	OrderFile of;
	if (of.m_Size == 0)
	{
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.m_Size; i++)
	{
		cout << i + 1 << "、";
		cout << "预约日期：周" << of.m_orderData[i]["date"];
		cout << " 时段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
		cout << " 机房：" << of.m_orderData[i]["roomId"];
		string status = "状态：";//1="审核中" 2="已预约" -1="预约失败" 0="取消的预约"
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "预约成功";
		}
		else if (of.m_orderData[i]["status"] == "-1")
		{
			status += "审核未通过，预约失败";
		}
		else if (of.m_orderData[i]["status"] == "0")
		{
			status += "预约已取消";
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
		cout << "无预约记录" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "请输入需要审核的记录:" << endl;

	for (int i = 0; i < of.m_Size; i++)
	{
		cout << i + 1 << "、";
		cout << "预约日期：周" << of.m_orderData[i]["date"];
		cout << " 时段：" << (of.m_orderData[i]["interval"] == "1" ? "上午" : "下午");
		cout << " 机房：" << of.m_orderData[i]["roomId"];
		string status = "状态：";//1="审核中" 2="已预约" -1="预约失败" 0="取消的预约"
		if (of.m_orderData[i]["status"] == "1")
		{
			status += "审核中";
		}
		else if (of.m_orderData[i]["status"] == "2")
		{
			status += "预约成功";
		}
		else if (of.m_orderData[i]["status"] == "-1")
		{
			status += "审核未通过，预约失败";
		}
		else if (of.m_orderData[i]["status"] == "0")
		{
			status += "预约已取消";
		}
		cout << status << endl;
	}

	cout << "请输入需要审核的记录编号，0为返回" << endl;
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
			cout << "请选择审核状态(1为审核通过，2为审核不通过）:" << endl;
			cin >> select2;
			if (select2 == 1)
			{
				of.m_orderData[select - 1]["status"] = "2";
				of.updateOrder();
				cout << "已成功改变审核状态为已预约" << endl;
				break;
			}
			else if (select == 2)
			{
				of.m_orderData[select - 1]["status"] = "-1";
				of.updateOrder();
				cout << "已成功改变审核状态为预约失败" << endl;
				break;
			}
			else
			{
				cout << "输入错误，请重新输入" << endl;
				break;
			}

		}
		cout << "输入有误，请重新输入" << endl;
	}
	system("pause");
	system("cls");
}