#include<iostream>
#include "WorkerManager.h"
#include"Worker.h"
#include"Employee.h"
#include"Boss.h"
using namespace std;



int main() {

	// 实例化管理者对象
	WorkerManager wm;

	int choice = 0;

	while (true)
	{
		// 调用展示菜单成员函数
		wm.ShowMenu();
		cout << "请输入您的选择：" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0: //退出系统
			wm.ExitSystem();
			break;
		case 1: //添加职工
			wm.addEmp();
			break;
		case 2: //显示职工
			wm.showEmp();
			break;
		case 3: //删除职工
			wm.delEmp();
			break;
		case 4: //修改职工
			wm.modEmp();
			break;
		case 5: //查找职工
			wm.findEmp();
			break;
		case 6: //排序职工
			wm.sortEmp();
			break;
		case 7: //清空文件
			wm.cleanFile();
			break;
		default:
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}