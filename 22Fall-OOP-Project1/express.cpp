#include "express.h"

ostream& operator<<(ostream& out, const Express& a)
{
	out << "ID:" << a.id_things << '\t' << a.name;
	return out;
}

istream& operator>>(istream& in, Express& a)
{
	in >> a.id_things >> a.name;
	return in;
}
/*
	全局查找功能，调用单个仓库查找
*/
void Express::SearchGlobal(LinkList<LinkList<Express>> link, int id_things,int storageid)
{
	if (storageid == 0)
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
			LinkList<Express> q = p->Getdata();
			allcount += SearchLocal(q, id_things);
		}
		cout << "所有仓库中共有" << allcount << "个." << endl;
	}
	else
	{
		Node<LinkList<Express>>* p = link.Go(storageid-1);
		LinkList<Express> q = p->Getdata();
	}
	
}
/*
	单个仓库查找功能
*/
void Express::SearchGlobal(LinkList<LinkList<Express>> link, string name,int storageid)
{
	int allcount = 0;
	int storagecnt = link.NumNodes();
	if (storageid == 0)
	{
		if (storagecnt == 0)
		{
			cout << "当前没有仓库";
			return;
		}
		for (int i = 0; i < storagecnt; i++)
		{
			Node<LinkList<Express>>* p = link.Go(i);
			LinkList<Express> q = p->Getdata();
			allcount += SearchLocal(q, name);
		}
		cout << "所有仓库中共有" << allcount << "个." << endl;
	}
	else
	{
		Node<LinkList<Express>>* p = link.Go(storageid - 1);
		LinkList<Express> q = p->Getdata();
		allcount += SearchLocal(q, name);
	}
}
int Express::SearchLocal(LinkList<Express> link, int id_things)
{
	int goodscnt = link.NumNodes();
	for (int i = 0; i < goodscnt; i++)
	{
		Node<Express>* p = link.Go(i);
		Express q = p->Getdata();
		if (q.id_things == id_things)
		{
			cout << "第" << i + 1 << "个库中:";
			cout << q << '\t' << link.Getcnt(i) << "个" << endl;
			return link.Getcnt(i); 
		}
	}
}


int Express::SearchLocal(LinkList<Express> link, string name)
{
	int goodscnt = link.NumNodes();
	for (int i = 0; i < goodscnt; i++)
	{
		Node<Express>* p = link.Go(i);
		Express q = p->Getdata();
		if (q.name == name)
		{
			cout << "第" << i + 1 << "个库中:";
			cout << q << '\t' << link.Getcnt(i) << "个" << endl;
			return link.Getcnt(i);
		}
	}
}