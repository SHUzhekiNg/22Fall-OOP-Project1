#include "express.h"

vector<Express> Express::alllist;
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

void Express::SearchGlobal(LinkList<LinkList<Express>> link, int id_things)
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
		SearchLocal(q, id_things);
	}
}

void Express::SearchLocal(LinkList<Express> link, int id_things)
{
	int goodscnt = link.NumNodes();
	for (int i = 0; i < goodscnt; i++)
	{
		Node<Express>* p = link.Go(i);
		Express q = p->Getdata();
		if (q.id_things == id_things)
		{

		}
	}
}
