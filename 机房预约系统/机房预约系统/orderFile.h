#pragma once
#include<iostream>
using namespace std;
#include<map>
#include"globalFile.h"

class OrderFile
{
public:
	OrderFile();
	//����ԤԼ��¼
	void updateOrder();

	//��¼������ key----��¼������ value----�����¼�ļ�ֵ����Ϣ
	map<int, map<string, string>>m_orderData;

	int m_Size; 
};