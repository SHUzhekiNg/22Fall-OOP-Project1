// expressTest.cpp
#include "LinkList.h"
#include "express.h"
#include <conio.h>

const int MAX_SIZE = 30;			//�������ƺ�ID����󳤶�

void expressTest()
{
	LinkList<LinkList<Express>> WarehouseList;
	Node<Express> *tmp;
	char id[80], name[80], str[80];
	int choice;
	int numW,numC;

	/*
	for (int i = 24; i >= 1; i--)		
	{
		string s;
		char c = 'a';
		Express Ex(i, const string(s = c + i - 1));
		tmp = new Node<Express>(Ex);
		WarehouseList.Insert(*tmp);
	}*/
	while (true)
	{
		cout << endl;
		cout << "1 -- ���" << endl;
		cout << "2 -- ����" << endl;
		cout << "3 -- ȫ�ֲ�ѯ" << endl;
		cout << "4 -- ��ֲ�ѯ" << endl;
		cout << "0 -- ����" << endl;
		cout << "��ѡ��";
		choice = getche() - '0';
		cout << endl;
		if (choice <= 0) break;
		Express Ex1;
		switch (choice)
		{
		case 1:
			cout << "���������ֿ���: ";
			cin >> numW;
			cin.getline(str, 80);					// �������ַ�
			WarehouseList.GoTop();
			WarehouseList.Skip(numW - 1);
			//���
			break;
		case 2:	
			cout << "���������ֿ���: ";
			cin >> numW;
			cin.getline(str, 80);					// �������ַ�
			WarehouseList.GoTop();
			WarehouseList.Skip(numW - 1);
			//����
			break;
		case 3:
			cout << "��������Ҫ��ѯ����ĵ�ID: ";
			cin >> numC;
			cin.getline(str, 80);					// �������ַ�
			Ex1.SearchGlobal(WarehouseList,numC);
			break;
		case 4:
			cout << "��������Ҫ��ѯ����ĵ�ID: ";
			cin >> numC;
			cin.getline(str, 80);					// �������ַ�
			cout << "��������Ҫ��ѯ�Ĳֿ�: ";
			cin >> numW;
			cin.getline(str, 80);					// �������ַ�
			Express Ex1;
			WarehouseList.GoTop();
			WarehouseList.Skip(numW - 1);
			Ex1.SearchLocal((WarehouseList.CurNode())->Getdata(), numC);
			break;
		}
	}

	cout << "\n�Զ��������������ͷ����н�㣬������������\n" << endl;
}
