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
	ȫ�ֲ��ҹ��ܣ����õ����ֿ����
*/
void Express::SearchGlobal(LinkList<LinkList<Express>> link, int id_things,int storageid)
{
	if (storageid == 0)
	{
		int allcount = 0;
		int storagecnt = link.NumNodes();
		if (storagecnt == 0)
		{
			cout << "��ǰû�вֿ�";
			return;
		}
		for (int i = 0; i < storagecnt; i++)
		{
			Node<LinkList<Express>>* p = link.Go(i);
			LinkList<Express> q = p->Getdata();
			allcount += SearchLocal(q, id_things);
		}
		cout << "���вֿ��й���" << allcount << "��." << endl;
	}
	else
	{
		Node<LinkList<Express>>* p = link.Go(storageid-1);
		LinkList<Express> q = p->Getdata();
	}
	
}
/*
	�����ֿ���ҹ���
*/
void Express::SearchGlobal(LinkList<LinkList<Express>> link, string name,int storageid)
{
	int allcount = 0;
	int storagecnt = link.NumNodes();
	if (storageid == 0)
	{
		if (storagecnt == 0)
		{
			cout << "��ǰû�вֿ�";
			return;
		}
		for (int i = 0; i < storagecnt; i++)
		{
			Node<LinkList<Express>>* p = link.Go(i);
			LinkList<Express> q = p->Getdata();
			allcount += SearchLocal(q, name);
		}
		cout << "���вֿ��й���" << allcount << "��." << endl;
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
			cout << "��" << i + 1 << "������:";
			cout << q << '\t' << link.Getcnt(i) << "��" << endl;
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
			cout << "��" << i + 1 << "������:";
			cout << q << '\t' << link.Getcnt(i) << "��" << endl;
			return link.Getcnt(i);
		}
	}
}