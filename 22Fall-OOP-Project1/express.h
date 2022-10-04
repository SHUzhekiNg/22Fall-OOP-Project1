#pragma once
#include <iostream>
#include <cstring>
#include <vector>
#include "LinkList.h"
using namespace std;

class Express {
public:
	Express(const int& id_things = 0, const string& name = "NONAME") :id_things(id_things), name(name) {}
	friend ostream& operator<<(ostream& out, const Express& a);
	friend istream& operator>>(istream& in, Express& a);
	void Search(LinkList<LinkList<Express>> link, int id_things);
	void Search(LinkList<Express> link, int id_things);
private:
	static vector<Express> alllist;			// 所有商品的名字和id的字典
	int id_things;							// 种类编号
	string name;
};
/*
void Express::Search(LinkList<LinkList<Express>> link, int id_things)
{
	int allcount = 0;
	int storagecnt = link.NumNodes();
	if (storagecnt == 0)
	{
		cout << "当前没有仓库";
		return;
	}
	for (int i = 0; i < storagecnt; i++)
	{
		Node<LinkList<Express>>* p = link.Go(i);
		LinkList<Express> q = p->Getdata;
		Search(q, id_things);
	}
}

void Express::Search(LinkList<Express> link, int id_things)
{
	int goodscnt = link.NumNodes();
	for (int i = 0; i < goodscnt; i++)
	{
		Node<Express>* p = link.Go(i);
		Express q = p->Getdata;
		if (q.id_things == id_things)
		{

		}
	}
}
*/
