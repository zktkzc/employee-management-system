#pragma once // ��ֹͷ�ļ��ظ�����
#include<iostream> // �������������ͷ�ļ�
#include<fstream>
#include"Worker.h"
#include"Employee.h"
#include"Manager.h"
#include"Boss.h"

#define FILENAME "emFile.txt"

using namespace std; // ʹ�ñ�׼�����ռ�

class WorkerManager
{
public:

	// ���캯��
	WorkerManager();

	// չʾ�˵�
	void ShowMenu();

	// �˳�ϵͳ
	void ExitSystem();

	// ��¼ְ������
	int m_EmpNum;

	// ְ������ָ��
	Worker** m_EmpArray;

	// ���ְ��
	void addEmp();

	// �����ļ�
	void save();

	// ��������
	~WorkerManager();
};
