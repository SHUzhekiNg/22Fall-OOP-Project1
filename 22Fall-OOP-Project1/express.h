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
	void SearchGlobal(LinkList<LinkList<Express>> link, int id_things, int storageid);			//ͨ����Ʒ��Ų��ң�storageid��0��Ϊȫ����ң�����������Ϊ��storageid���ֿ����
	void SearchGlobal(LinkList<LinkList<Express>> link, string name, int storageid);		//ͨ����Ʒ���Ʋ���
	int SearchLocal(LinkList<Express> link, int id_things);
	int SearchLocal(LinkList<Express> link, string name);
private:
	static vector<Express> alllist;			// ������Ʒ�����ֺ�id���ֵ�
	int id_things;							// ������
	string name;
};

