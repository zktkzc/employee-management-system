#include "WorkerManager.h"

WorkerManager::WorkerManager()
{
	// �ļ�������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		// �ļ�������
		cout << "�ļ�������" << endl;

		// ��ʼ������
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		// ��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	// �ļ����ڣ�������Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		// �ļ�Ϊ��
		cout << "�ļ�Ϊ��" << endl;
		// ��ʼ������
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		// ��ʼ���ļ��Ƿ�Ϊ��
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	// �ļ����Ҽ�¼����
	int num = this->getEmpNum();
	cout << "ְ��������Ϊ��" << num << "��" << endl;
	this->m_EmpNum = num;

	// ���ٿռ�
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	// ���ļ��е����ݴ浽������
	this->initEmp();

	// ���Դ���
	//for (int i = 0; i < this->m_EmpNum; i++)
	//{
	//	cout << "ְ����ţ�" << this->m_EmpArray[i]->m_Id << " "
	//		<< "ְ��������" << this->m_EmpArray[i]->m_Name << " "
	//		<< "���ű�ţ�" << this->m_EmpArray[i]->m_DeptId << endl;
	//}
}

void WorkerManager::ShowMenu()
{
	cout << "********************************************" << endl;
	cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
	cout << "*************  0.�˳��������  *************" << endl;
	cout << "*************  1.����ְ����Ϣ  *************" << endl;
	cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
	cout << "*************  3.ɾ����ְְ��  *************" << endl;
	cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
	cout << "*************  5.����ְ����Ϣ  *************" << endl;
	cout << "*************  6.���ձ������  *************" << endl;
	cout << "*************  7.��������ĵ�  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}

// �˳�ϵͳ
void WorkerManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ�ã�" << endl;
	system("pause");
	exit(0); // �˳�����
}

// ���ְ��
void WorkerManager::addEmp()
{
	cout << "���������ְ����������" << endl;
	int addNum;
	cin >> addNum;
	if (addNum > 0)
	{
		// ���
		// ��������¿ռ��С
		int newSize = this->m_EmpNum + addNum; // �¿ռ������ = ԭ����¼������ + ��������

		// �����¿ռ�
		Worker** newSpace = new Worker * [newSize];

		// ��ԭ���ռ��µ����ݣ��������¿ռ���
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}

		// �������������
		for (int i = 0; i < addNum; i++)
		{
			int id; // ְ�����
			string name; // ְ������
			int dId; // ���ű��

			cout << "�������" << i + 1 << "��ְ����ţ�" << endl;
			cin >> id;
			cout << "�������" << i + 1 << "��ְ��������" << endl;
			cin >> name;
			cout << "��ѡ���ְ����λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ܲ�" << endl;
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

			// ��������ְ��ָ�뱣�浽������
			newSpace[this->m_EmpNum + i] = worker;
		}

		// �ͷ�ԭ�еĿռ�
		delete[] this->m_EmpArray;

		// �����¿ռ��ָ��
		this->m_EmpArray = newSpace;

		// �����µ�ְ������
		this->m_EmpNum = newSize;

		// ����ְ����Ϊ�յı�־
		this->m_FileIsEmpty = false;

		cout << "�ɹ����" << addNum << "����ְ��" << endl;

		// �������ݵ��ļ���
		this->save();
	}
	else
	{
		cout << "����������������������" << endl;
	}

	system("pause");
	system("cls");
}

// �����ļ�
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out); // ������ķ�ʽ���ļ� ����д�ļ�

	// ��ÿ���˵�����д�뵽�ļ���
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}

	// �ر��ļ�
	ofs.close();
}

// ͳ���ļ��е�����
int WorkerManager::getEmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		// ͳ�������ı���
		num++;
	}
	return num;
}

// ��ʼ��Ա��
void WorkerManager::initEmp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		Worker* worker = NULL;
		if (dId == 1)
		{
			// ��ͨԱ��
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2)
		{
			// ����
			worker = new Manager(id, name, dId);
		}
		else
		{
			// �ܲ�
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}

	ifs.close();
}

WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}