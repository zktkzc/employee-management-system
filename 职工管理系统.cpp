#include<iostream>
#include "WorkerManager.h"
#include"Worker.h"
#include"Employee.h"
#include"Boss.h"
using namespace std;



int main() {

	// ʵ���������߶���
	WorkerManager wm;

	int choice = 0;

	while (true)
	{
		// ����չʾ�˵���Ա����
		wm.ShowMenu();
		cout << "����������ѡ��" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0: //�˳�ϵͳ
			wm.ExitSystem();
			break;
		case 1: //���ְ��
			wm.addEmp();
			break;
		case 2: //��ʾְ��
			wm.showEmp();
			break;
		case 3: //ɾ��ְ��
			wm.delEmp();
			break;
		case 4: //�޸�ְ��
			wm.modEmp();
			break;
		case 5: //����ְ��
			wm.findEmp();
			break;
		case 6: //����ְ��
			wm.sortEmp();
			break;
		case 7: //����ļ�
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