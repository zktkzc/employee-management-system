#include "WorkerManager.h"

WorkerManager::WorkerManager()
{
	// 初始化属性
	this->m_EmpNum = 0;
	this->m_EmpArray = NULL;
}

void WorkerManager::ShowMenu()
{
	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

// 退出系统
void WorkerManager::ExitSystem()
{
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0); // 退出程序
}

// 添加职工
void WorkerManager::addEmp()
{
	cout << "请输入添加职工的数量：" << endl;
	int addNum;
	cin >> addNum;
	if (addNum > 0)
	{
		// 添加
		// 计算添加新空间大小
		int newSize = this->m_EmpNum + addNum; // 新空间的人数 = 原来记录的人数 + 新增人数

		// 开辟新空间
		Worker** newSpace = new Worker * [newSize];

		// 将原来空间下的数据，拷贝到新空间下
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		// 批量添加新数据
		for (int i = 0; i < addNum; i++)
		{
			int id; // 职工编号
			string name; // 职工姓名
			int dId; // 部门编号

			cout << "请输入第" << i + 1 << "个职工编号：" << endl;
			cin >> id;
			cout << "请输入第" << i + 1 << "个职工姓名：" << endl;
			cin >> name;
			cout << "请选择该职工岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、总裁" << endl;
			cin >> dId;

			Worker* worker = NULL;
			switch (dId)
			{
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}

			// 将创建的职工指针保存到数组中
			newSpace[this->m_EmpNum + i] = worker;
		}

		// 释放原有的空间
		delete[] this->m_EmpArray;

		// 更改新空间的指向
		this->m_EmpArray = newSpace;

		// 更新新的职工人数
		this->m_EmpNum = newSize;

		cout << "成功添加" << addNum << "名新职工" << endl;
	}
	else
	{
		cout << "输入数据有误，请重新输入" << endl;
	}

	system("pause");
	system("cls");
}

WorkerManager::~WorkerManager()
{

}