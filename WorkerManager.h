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

	//��־�ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;

	// ���ְ��
	void addEmp();

	// �����ļ�
	void save();

	// ͳ���ļ��е�����
	int getEmpNum();

	// ��ʼ��Ա��
	void initEmp();

	// ��ʾְ��
	void showEmp();

	// ɾ��ְ��
	void delEmp();

	// �ж�ְ���Ƿ����
	int isExist(int id);

	// ��������
	~WorkerManager();
};
