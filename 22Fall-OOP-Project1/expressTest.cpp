// expressTest.cpp
#include "LinkList.h"
#include "express.h"
#include "check_repository.h"
#include <conio.h>
#include <string>

const int MAX_SIZE = 30;			//货物名称和ID的最大长度

void expressTest()
{
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
		cout << "1 -- 入库" << endl;
		cout << "2 -- 出库" << endl;
		cout << "3 -- 查询" << endl;
		cout << "4 -- 盘点" << endl;
		cout << "0 -- 返回" << endl;
		cout << "请选择：";
		choice = getche() - '0';
		cout << endl;
		if (choice <= 0) break;
		string s;
		switch (choice)
		{
		case 1:											//入库
			cout << "请输入入库仓库编号: ";
			cin >> numW;
			cin.getline(str, 80);					// 处理换行字符
			//入库
			Express::Add(WarehouseList, numW, s);
			break;
		case 2:											//出库
			cout << "请输入出库仓库编号: ";
			cin >> numW;
			cin.getline(str, 80);					// 处理换行字符

			//出库
			Express::Delete(WarehouseList, numW, s);





			break;
		case 3:											//查询
			cout << "请输入所要查询的仓库: (输入0以查询所有仓库)";
			cin >> numW;
			cin.getline(str, 80);
			cout << "请输入所要查询货物的的ID或名称:";
			cin >> s;
			cin.getline(str, 80);					// 处理换行字符
			if (s[0] >= '0' && s[0] <= '9')
			{
				numC = stoi(s);
				Express::SearchGlobal(WarehouseList, numC, numW);
			}
			else Express::SearchGlobal(WarehouseList, s, numW);
			/*
			WarehouseList.GoTop();
			WarehouseList.Skip(numW - 1);
			Ex1.SearchLocal((WarehouseList.CurNode())->Getdata(), numC);
			break;
			*/
			break;
		case 4:											//盘点
			cout << "请输入所要盘点的仓库: (输入0以查询所有仓库)";
			cin >> numW;
			cin.getline(str, 80);
			if (numW == 0)
			{
				CheckAllRepository(&WarehouseList);
			}
			else
			{
				cout << "请输入所要查询货物的的ID:";
				cin >> numC;
				cin.getline(str, 80);					// 处理换行字符
				CheckSelectedRepository(&WarehouseList, numC);
			}

			break;
		}
	}

	cout << "\n自动调用析构函数释放所有结点，返回主函数。\n" << endl;
}
