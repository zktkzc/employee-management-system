#pragma once
#include<iostream>
#include"Worker.h"
using namespace std;

class Employee : public Worker
{
	// ���캯��
	Employee(int id, string name, int dId);

	// ��ʾ������Ϣ
	virtual void showInfo() = 0;

	// ��ȡ��λ����
	virtual string getDeptName() = 0;
};