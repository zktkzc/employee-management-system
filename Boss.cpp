#include"Boss.h"

// 构造函数
Boss::Boss(int id, string name, int dId)
{
	this->m_DeptId = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

// 显示个人信息
void Boss::showInfo()
{
	cout << "职工编号：" << this->m_Id << "\t"
		<< "职工姓名：" << this->m_Name << "\t"
		<< "岗位：" << this->getDeptName() << "\t"
		<< "岗位职责：管理公司所有的事务" << endl;
}

// 获取岗位名称
string Boss::getDeptName()
{
	return string("总裁");
}