#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
#include"identity.h"

class Teacher:public Identity
{
public:
	Teacher();
	Teacher(int empId, string name, string pwd);
	virtual void operMenu();
	void showAllOrder();//�鿴ԤԼ
	void vaildOrder();//���ԤԼ
	int m_EmpId;

};