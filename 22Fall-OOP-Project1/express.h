#pragma once
#include <iostream>
#include <cstring>
#include <vector>
#include "LinkList.h"

using namespace std;
template <typename T> class LinkList;
template <typename T> class Node;
class Express {
public:
	Express(const int& id_things = 0, const string& name = "NONAME") :id_things(id_things), name(name) {}
	friend ostream& operator<<(ostream& out, const Express& a);
	friend istream& operator>>(istream& in, Express& a);
	void SearchGlobal(LinkList<LinkList<Express>> link, int id_things);
	void SearchLocal(LinkList<Express> link, int id_things);
private:
	friend void CheckSelectedRepository(LinkList<LinkList<Express>>* current, int id_store);
	friend void CheckAllRepository(LinkList<LinkList<Express>>* first);
	static vector<Express> alllist;			// 所有商品的名字和id的字典
	int id_things;							// 种类编号
	string name;
};
