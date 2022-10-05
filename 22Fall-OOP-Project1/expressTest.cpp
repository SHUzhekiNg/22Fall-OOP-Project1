// expressTest.cpp
#include "LinkList.h"
#include "express.h"
#include "check_repository.h"
#include <conio.h>
#include <string>

const int MAX_SIZE = 30;			//�������ƺ�ID����󳤶�

void expressTest()
{
	LinkList<LinkList<Express>> WarehouseList;		//�ֿ������
	Node<Express> *tmp=nullptr;
	char id[80], name[80], str[80];
	int choice;
	int numW,numC;

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
			Express::Add(WarehouseList, numW, s);
			break;
		case 2:											//����
			cout << "���������ֿ���: ";
			cin >> numW;
			cin.getline(str, MAX_SIZE);					// �������ַ�
			//����
			Express::Delete(WarehouseList, numW, s);
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
