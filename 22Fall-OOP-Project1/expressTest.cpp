// expressTest.cpp
#include "LinkList.h"
#include "express.h"
#include "check_repository.h"
#include <conio.h>
#include <string>

const int MAX_SIZE = 30;			//货物名称和ID的最大长度
const int WAREHOUSE_NUM = 24;		//仓库个数

void WarehouseInitialize(LinkList<LinkList<Express>>& WarehouseList, int num)		//初始化24个仓库
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
	LinkList<LinkList<Express>> WarehouseList;		//仓库的链表
	Node<Express> *tmp=nullptr;
	char id[MAX_SIZE], name[MAX_SIZE], str[MAX_SIZE];
	int choice;
	int numW,numC;


	WarehouseInitialize(WarehouseList, WAREHOUSE_NUM);	//初始化仓库
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
			if (numW >= 1 && numW <= WAREHOUSE_NUM) Express::Add(WarehouseList, numW, s);
			else cerr << "总共只有" << WAREHOUSE_NUM << "个仓库，入库失败！" << endl;		//仓库数目不够提示
			break;
		case 2:											//出库
			cout << "请输入出库仓库编号: ";
			cin >> numW;
			cin.getline(str, MAX_SIZE);					// 处理换行字符
			//出库
			if (numW >= 1 && numW <= WAREHOUSE_NUM)
			{
				if (Express::Delete(WarehouseList, numW, s) == -1)cerr << "未找到该货物，删除失败！" << endl;	//找不到要删除的节点提示
			}
			else cerr << "总共只有" << WAREHOUSE_NUM << "个仓库，出库失败！" << endl;		//仓库数目不够提示
			
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
