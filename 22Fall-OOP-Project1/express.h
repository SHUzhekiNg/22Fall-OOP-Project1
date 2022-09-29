#pragma once
#include <iostream>
#include <cstring>
#include "LinkList.h"
using namespace std;


class Express {
public:
	Express(const string& id = "NULL", const string& name = "NONAME") :id(id), name(name) {}
	friend ostream& operator<<(ostream& out, const Express& a);
	friend istream& operator>>(istream& in, Express& a);



private:
	string id;
	string name;
};

template <typename T>
void Search(LinkList<LinkList<Express>>& link, const T& t);