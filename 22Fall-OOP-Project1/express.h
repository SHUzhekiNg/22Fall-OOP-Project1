#pragma once
#include <iostream>
#include <cstring>
#include <vector>
#include <windows.h>
#include "LinkList.h"

using namespace std;
template <typename T> class LinkList;
template <typename T> class Node;
class Express {
public:
	Express(int id_things = 0, string name = "NONAME") :id_things(id_things), name(name) {}
	static void Add(LinkList<LinkList<Express>>& link, const int& storageid, string& name);
	static int Delete(LinkList<LinkList<Express>>& link, const int& storageid, string& name);		//����ֵΪ-1���ʾɾ��ʧ��
	friend ostream& operator<<(ostream& out, const Express& a);
	friend istream& operator>>(istream& in, Express& a);		
	bool operator!=(Express a);
	static void SearchGlobal(LinkList<LinkList<Express>> &link, int id_things, int storageid);		//ͨ����Ʒ��Ų��ң�storageid��0��Ϊȫ����ң�����������Ϊ��storageid���ֿ����
	static void SearchGlobal(LinkList<LinkList<Express>> &link, string name, int storageid);		//ͨ����Ʒ���Ʋ���
	static int SearchLocal(LinkList<Express> &link, int id_things,int storageid);
	static int SearchLocal(LinkList<Express> &link, string name,int storageid);
private:
	friend void CheckSelectedRepository(LinkList<LinkList<Express>>* current, int id_store);
	friend void CheckAllRepository(LinkList<LinkList<Express>>* first);
	static vector<Express> alllist;			// ������Ʒ�����ֺ�id���ֵ�
	int id_things;							// ������
	string name;
};

void SetTextColor(int bkcolor, int color);