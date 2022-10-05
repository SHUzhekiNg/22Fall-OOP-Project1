// expressTest.cpp
#include "LinkList.h"
#include "express.h"
#include "check_repository.h"
#include <conio.h>
#include <string>

const int MAX_SIZE = 30;			//货物名称和ID的最大长度

void expressTest()
{
	LinkList<LinkList<Express>> WarehouseList;		//仓库的链表
	Node<Express> *tmp=nullptr;
	char id[80], name[80], str[80];
	int choice;
	int numW,numC;

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
			cin.getline(str, MAX_SIZE);					// 处理换行字符
			//入库
			Express::Add(WarehouseList, numW, s);
			break;
		case 2:											//出库
			cout << "请输入出库仓库编号: ";
			cin >> numW;
			cin.getline(str, MAX_SIZE);					// 处理换行字符
			//出库
			Express::Delete(WarehouseList, numW, s);
			break;
		case 3:											//查询
			cout << "请输入所要查询的仓库: (输入0以查询所有仓库)";
			cin >> numW;
			cin.getline(str, MAX_SIZE);
			cout << "请输入所要查询货物的的ID或名称:";
			cin >> s;
			cin.getline(str, MAX_SIZE);					// 处理换行字符
			if (s[0] >= '0' && s[0] <= '9')
			{
				numC = stoi(s);
				Express::SearchGlobal(WarehouseList, numC, numW);
			}
			else Express::SearchGlobal(WarehouseList, s, numW);
			break;
		case 4:											//盘点
			cout << "请输入所要盘点的仓库: (输入0以查询所有仓库)";
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

	cout << "\n自动调用析构函数释放所有结点，返回主函数。\n" << endl;
}
