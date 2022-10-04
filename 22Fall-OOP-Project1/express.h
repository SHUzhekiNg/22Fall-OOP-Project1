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
	void SearchGlobal(LinkList<LinkList<Express>> link, int id_things, int storageid);			//通过商品编号查找，storageid是0则为全库查找，其他数字则为第storageid个仓库查找
	void SearchGlobal(LinkList<LinkList<Express>> link, string name, int storageid);		//通过商品名称查找
	int SearchLocal(LinkList<Express> link, int id_things);
	int SearchLocal(LinkList<Express> link, string name);
private:
	static vector<Express> alllist;			// 所有商品的名字和id的字典
	int id_things;							// 种类编号
	string name;
};

