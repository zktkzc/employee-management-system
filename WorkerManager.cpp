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
	int addNum = 0;
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
	ifs.close();
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

// ��ʾְ��
void WorkerManager::showEmp()
{
	// �ж��ļ��Ƿ�Ϊ��
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ�����Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			// ���ö�̬���ó���ӿ�
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

// ɾ��ְ��
void WorkerManager::delEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "��������Ҫɾ����ְ����ţ�" << endl;
		int id = 0;
		cin >> id;
		int res = this->isExist(id);
		if (res != -1)
		{
			for (int i = res; i < this->m_EmpNum-1; i++)
			{
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--; // ���������м�¼����Ա����
			// ����ͬ�����µ��ļ���
			this->save();
			cout << "ɾ���ɹ���" << endl;
		}
		else
		{
			cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��" << endl;
		}
		system("pause");
		system("cls");
	}
}

// �ж�ְ���Ƿ����
int WorkerManager::isExist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
		{
			// �ҵ�ְ��
			index = 1;
			break;
		}
	}
	return index;
}

// �޸�ְ��
void WorkerManager::modEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "������Ҫ�޸ĵ�ְ����ţ�" << endl;
		int id;
		cin >> id;

		int res = this->isExist(id);
		if (res!= -1)
		{
			// �ҵ�ְ��
			delete this->m_EmpArray[res];

			int newId = 0;
			string newName = " ";
			int newDId = 0;

			cout << "�鵽idΪ" << id << "�ŵ�ְ�����������µ�ְ����ţ�" << endl;
			cin >> newId;
			cout << "�������µ�ְ��������" << endl;
			cin >> newName;
			cout << "�������µĲ��ű�ţ�" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ܲ�" << endl;
			cin >> newDId;

			Worker* worker = NULL;
			if (newDId == 1)
			{
				// ��ͨԱ��
				worker = new Employee(newId, newName, newDId);
			}
			else if (newDId == 2)
			{
				// ����
				worker = new Manager(newId, newName, newDId);
			}
			else
			{
				// �ܲ�
				worker = new Boss(newId, newName, newDId);
			}
			this->m_EmpArray[res] = worker;
			
			cout << "�޸ĳɹ���" << endl;

			// ���浽�ļ���
			this->save();
		}
		else
		{
			cout << "�޸�ʧ�ܣ����޴���" << endl;
		}
	}
	system("pause");
	system("cls");
}

// ����ְ��
void WorkerManager::findEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
	}
	else
	{
		cout << "��������ҵķ�ʽ��" << endl;
		cout << "1������ְ����Ų���" << endl;
		cout << "2������ְ����������" << endl;
		int select = 0;
		cin >> select;
		if (select == 1)
		{
			// ����ְ����Ų���
			int id;
			cout << "��������ҵ�ְ����ţ�" << endl;
			cin >> id;
			int res = isExist(id);
			if (res != -1)
			{
				// �ҵ�ְ��
				cout << "���ҳɹ�����ְ������Ϣ���£�" << endl;
				this->m_EmpArray[res]->showInfo();
			}
			else
			{
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else if (select == 2)
		{
			// ����ְ����������
			string name;
			cout << "������Ҫ���ҵ�ְ��������" << endl;
			cin >> name;

			// �ж��Ƿ��ҵ��ı�־
			bool flag = false; // Ĭ��δ�ҵ�

			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					flag = true;

					cout << "���ҳɹ���ְ�����Ϊ��" << this->m_EmpArray[i]->m_Id << endl;
					cout << "ְ����Ϣ���£�" << endl;
					this->m_EmpArray[i]->showInfo();
				}
			}
			if (flag == false)
			{
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else
		{
			cout << "����ѡ���������������룡" << endl;
		}
	}

	system("pause");
	system("cls");
}

// ����ְ����Ž�������
void WorkerManager::sortEmp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ��" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ��" << endl;
		cout << "1������ְ�������������" << endl;
		cout << "2������ְ����Ž�������" << endl;
		int select;
		cin >> select;

		for (int i = 0; i < this->m_EmpNum; i++)
		{
			int minOrMax = i; // ������Сֵ�����ֵ�±�
			for (int j = i+1; j < this->m_EmpNum; j++)
			{
				if (select == 1)
				{
					// ����
					if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
				else
				{
					// ����
					if (this->m_EmpArray[minOrMax]->m_Id < this->m_EmpArray[j]->m_Id)
					{
						minOrMax = j;
					}
				}
			}

			// �ж�һ��ʼ�϶�����Сֵ�����ֵ�Ƿ��Ǽ������Сֵ�����ֵ��������ǣ���������
			if (i != minOrMax)
			{
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = temp;
			}
		}

		cout << "����ɹ��������Ľ��Ϊ��" << endl;
		this->save(); // �������Ľ�����浽�ļ���
		this->showEmp(); // չʾ����ְ��
	}
}

// �������
void WorkerManager::cleanFile()
{
	cout << "ȷ�������" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2��ȡ��" << endl;

	int select = 0;
	cin >> select;
	if (select == 1)
	{
		// ����ļ�
		ofstream ofs(FILENAME, ios::trunc); // ɾ���ļ������´���
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			// ɾ��������ÿ��ְ������
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
			// ɾ����������ָ��
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}

		cout << "��ճɹ���" << endl;
	}
	system("pause");
	system("cls");
}

WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}