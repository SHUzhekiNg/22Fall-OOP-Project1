// expressTest.cpp
#include "LinkList.h"
#include "express.h"
#include <conio.h>

const int MAX_SIZE = 30;			//货物名称和ID的最大长度

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
		cout << "1 -- 入库" << endl;
		cout << "2 -- 出库" << endl;
		cout << "3 -- 全局查询" << endl;
		cout << "4 -- 逐仓查询" << endl;
		cout << "0 -- 返回" << endl;
		cout << "请选择：";
		choice = getche() - '0';
		cout << endl;
		if (choice <= 0) break;
		Express Ex1;
		switch (choice)
		{
		case 1:
			cout << "请输入入库仓库编号: ";
			cin >> numW;
			cin.getline(str, 80);					// 处理换行字符
			WarehouseList.GoTop();
			WarehouseList.Skip(numW - 1);
			//入库
			break;
		case 2:	
			cout << "请输入出库仓库编号: ";
			cin >> numW;
			cin.getline(str, 80);					// 处理换行字符
			WarehouseList.GoTop();
			WarehouseList.Skip(numW - 1);
			//出库
			break;
		case 3:
			cout << "请输入所要查询货物的的ID: ";
			cin >> numC;
			cin.getline(str, 80);					// 处理换行字符
			Ex1.SearchGlobal(WarehouseList,numC);
			break;
		case 4:
			cout << "请输入所要查询货物的的ID: ";
			cin >> numC;
			cin.getline(str, 80);					// 处理换行字符
			cout << "请输入所要查询的仓库: ";
			cin >> numW;
			cin.getline(str, 80);					// 处理换行字符
			Express Ex1;
			WarehouseList.GoTop();
			WarehouseList.Skip(numW - 1);
			Ex1.SearchLocal((WarehouseList.CurNode())->Getdata(), numC);
			break;
		}
	}

	cout << "\n自动调用析构函数释放所有结点，返回主函数。\n" << endl;
}
