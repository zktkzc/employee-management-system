#pragma once
#include<iostream>
#include"Worker.h"
using namespace std;

// ������
class Boss : public Worker
{
public:

	// ���캯��
	Boss(int id, string name, int dId);

	// ��ʾ������Ϣ
	virtual void showInfo() = 0;

	// ��ȡ��λ����
	virtual string getDeptName() = 0;
};