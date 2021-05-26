#pragma once
#include<iostream>
using namespace std;
#include "identity.h"
#include<vector>
#include"computerRoom.h"

class Student:public Identity
{
public:
	Student();
	Student(int id, string name, string pwd);
	//菜单界面
	virtual void operMenu();

	//申请预约
	void applyOrder();

    //查看我的预约
	void showMyOrder();

	//查看所有预约
	void showAllOrder();

	//取消预约
	void cancelOrder();

	vector<ComputerRoom>vCom;


	int m_Id;

};