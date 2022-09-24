#pragma once // 防止头文件重复包含
#include<iostream> // 包含输入输出流头文件
#include<fstream>
#include"Worker.h"
#include"Employee.h"
#include"Manager.h"
#include"Boss.h"

#define FILENAME "emFile.txt"

using namespace std; // 使用标准命名空间

class WorkerManager
{
public:

	// 构造函数
	WorkerManager();

	// 展示菜单
	void ShowMenu();

	// 退出系统
	void ExitSystem();

	// 记录职工人数
	int m_EmpNum;

	// 职工数组指针
	Worker** m_EmpArray;

	//标志文件是否为空
	bool m_FileIsEmpty;

	// 添加职工
	void addEmp();

	// 保存文件
	void save();

	// 统计文件中的人数
	int getEmpNum();

	// 初始化员工
	void initEmp();

	// 显示职工
	void showEmp();

	// 删除职工
	void delEmp();

	// 判断职工是否存在
	int isExist(int id);

	// 析构函数
	~WorkerManager();
};
