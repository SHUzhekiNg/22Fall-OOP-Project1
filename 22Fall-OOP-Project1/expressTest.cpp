// expressTest.cpp
#include "LinkList.h"
#include "express.h"
#include "check_repository.h"
#include <conio.h>
#include <string>

const int MAX_SIZE = 30;			//�������ƺ�ID����󳤶�
const int WAREHOUSE_NUM = 24;		//�ֿ����

void WarehouseInitialize(LinkList<LinkList<Express>>& WarehouseList, int num)		//��ʼ��24���ֿ�
{
	for (int i = 0; i < num; i++)
	{
		LinkList<Express>* a = new LinkList<Express>;
		WarehouseList.Append(*a);
		WarehouseList.ModifyCnt(WarehouseList.NumNodes(), 1);
	}
}

void expressTest()
{
	LinkList<LinkList<Express>> WarehouseList;		//�ֿ������
	Node<Express> *tmp=nullptr;
	char id[MAX_SIZE], name[MAX_SIZE], str[MAX_SIZE];
	int choice;
	int numW,numC;


	WarehouseInitialize(WarehouseList, WAREHOUSE_NUM);	//��ʼ���ֿ�
	while (true)
	{
		cout << endl;
		cout << "1 -- ���" << endl;
		cout << "2 -- ����" << endl;
		cout << "3 -- ��ѯ" << endl;
		cout << "4 -- �̵�" << endl;
		cout << "0 -- ����" << endl;
		cout << "��ѡ��";
		choice = getche() - '0';
		cout << endl;
		if (choice <= 0) break;
		string s;
		switch (choice)
		{
		case 1:											//���
			cout << "���������ֿ���: ";
			cin >> numW;
			cin.getline(str, MAX_SIZE);					// �������ַ�
			//���
			if (numW >= 1 && numW <= WAREHOUSE_NUM) Express::Add(WarehouseList, numW, s);
			else cerr << "�ܹ�ֻ��" << WAREHOUSE_NUM << "���ֿ⣬���ʧ�ܣ�" << endl;		//�ֿ���Ŀ������ʾ
			break;
		case 2:											//����
			cout << "���������ֿ���: ";
			cin >> numW;
			cin.getline(str, MAX_SIZE);					// �������ַ�
			//����
			if (numW >= 1 && numW <= WAREHOUSE_NUM)
			{
				if (Express::Delete(WarehouseList, numW, s) == -1)cerr << "δ�ҵ��û��ɾ��ʧ�ܣ�" << endl;	//�Ҳ���Ҫɾ���Ľڵ���ʾ
			}
			else cerr << "�ܹ�ֻ��" << WAREHOUSE_NUM << "���ֿ⣬����ʧ�ܣ�" << endl;		//�ֿ���Ŀ������ʾ
			
			break;
		case 3:											//��ѯ
			cout << "��������Ҫ��ѯ�Ĳֿ�: (����0�Բ�ѯ���вֿ�)";
			cin >> numW;
			cin.getline(str, MAX_SIZE);
			cout << "��������Ҫ��ѯ����ĵ�ID������:";
			cin >> s;
			cin.getline(str, MAX_SIZE);					// �������ַ�
			if (s[0] >= '0' && s[0] <= '9')
			{
				numC = stoi(s);
				Express::SearchGlobal(WarehouseList, numC, numW);
			}
			else Express::SearchGlobal(WarehouseList, s, numW);
			break;
		case 4:											//�̵�
			cout << "��������Ҫ�̵�Ĳֿ�: (����0�Բ�ѯ���вֿ�)";
			cin >> numW;
			cin.getline(str, MAX_SIZE);
			if (numW == 0)
			{
				CheckAllRepository(&WarehouseList);
			}
			else
			{
				CheckSelectedRepository(&WarehouseList, numW);
			}

			break;
		}
	}

	cout << "\n�Զ��������������ͷ����н�㣬������������\n" << endl;
}
