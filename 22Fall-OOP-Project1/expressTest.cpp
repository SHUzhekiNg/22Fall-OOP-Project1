// expressTest.cpp
#include "LinkList.h"
#include "express.h"
#include <conio.h>
#include <string>

const int MAX_SIZE = 30;			//�������ƺ�ID����󳤶�

void expressTest()
{
	using std::cout;
	LinkList<LinkList<Express>> WarehouseList;
	Node<Express> *tmp=nullptr;
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
		cout << "3 -- ��ѯ" << endl;
		cout << "4 -- �̵�" << endl;
		cout << "0 -- ����" << endl;
		cout << "��ѡ��";
		choice = getche() - '0';
		cout << endl;
		if (choice <= 0) break;
		Express Ex1;
		string s;
		switch (choice)
		{
		case 1:											//���
			cout << "���������ֿ���: ";
			cin >> numW;
			cin.getline(str, 80);					// ���������ַ�
			WarehouseList.GoTop();
			WarehouseList.Skip(numW - 1);
			//���
			break;
		case 2:											//����
			cout << "���������ֿ���: ";
			cin >> numW;
			cin.getline(str, 80);					// ���������ַ�
			WarehouseList.GoTop();
			WarehouseList.Skip(numW - 1);
			//����
			break;
		case 3:											//��ѯ
			cout << "��������Ҫ��ѯ�Ĳֿ�: (����0�Բ�ѯ���вֿ�)";
			cin >> numW;
			cin.getline(str, 80);
			cout << "��������Ҫ��ѯ����ĵ�ID������:";
			cin >> s;
			cin.getline(str, 80);					// ���������ַ�
			if (s[0] >= '0' && s[0] <= '9')
			{
				numC = stoi(s);
				Ex1.SearchGlobal(WarehouseList, numC, numW);
			}
			else Ex1.SearchGlobal(WarehouseList, s, numW);
			/*
			WarehouseList.GoTop();
			WarehouseList.Skip(numW - 1);
			Ex1.SearchLocal((WarehouseList.CurNode())->Getdata(), numC);
			break;
			*/
			break;
		case 4:											//�̵�
			cout << "��������Ҫ�̵�Ĳֿ�: (����0�Բ�ѯ���вֿ�)";
			cin >> numW;
			cin.getline(str, 80);
			cout << "��������Ҫ��ѯ����ĵ�ID������:";
			cin >> s;
			cin.getline(str, 80);					// ���������ַ�
			WarehouseList.GoTop();
			WarehouseList.Skip(numW - 1);
			Ex1.SearchLocal((WarehouseList.CurNode())->Getdata(), numC);

			if (s[0] >= '0' && s[0] <= '9')
			{
				numC = stoi(s);
				Ex1.SearchLocal((WarehouseList.CurNode())->Getdata(), numC);
			}
			else Ex1.SearchLocal((WarehouseList.CurNode())->Getdata(), s);
		}
	}

	cout << "\n�Զ��������������ͷ����н�㣬������������\n" << endl;
}