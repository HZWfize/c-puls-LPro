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
	//�˵�����
	virtual void operMenu();

	//����ԤԼ
	void applyOrder();

    //�鿴�ҵ�ԤԼ
	void showMyOrder();

	//�鿴����ԤԼ
	void showAllOrder();

	//ȡ��ԤԼ
	void cancelOrder();

	vector<ComputerRoom>vCom;


	int m_Id;

};