#include "express.h"

vector<Express> Express::alllist;


void SetTextColor(int bkcolor, int color)
{
	HANDLE hStdOut;
	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, bkcolor | color);
}

ostream& operator<<(ostream& out, const Express& a)
{
	SetTextColor(0, 9);
	out << "#";
	SetTextColor(0, 15);
	out << a.id_things << "\t" << a.name;
	return out;
}

istream& operator>>(istream& in, Express& a)
{
	in >> a.id_things >> a.name;
	return in;
}
bool Express::operator!=(Express a)
{
	return this->name==a.name ? 0 : 1;
}
/*
	全局查找功能，调用单个仓库查找
	参数：link是保存仓库的链表，id_things是要查找商品的编号，storageid是要查找的仓库编号。
*/
void Express::SearchGlobal(LinkList<LinkList<Express>> &link, int id_things,int storageid)
{
	int allcount = 0;
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
			allcount += SearchLocal(q, id_things, i+1);
		}
		cout << "所有仓库中共有" << allcount << "个." << endl;
	}
	else
	{
		Node<LinkList<Express>>* p = link.Go(storageid-1);
		LinkList<Express> q = p->Getdata();
		allcount += SearchLocal(q, id_things, storageid);
	}
	
}
/*
	单个仓库查找功能
*/
void Express::SearchGlobal(LinkList<LinkList<Express>> &link, string name,int storageid)
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
			allcount += SearchLocal(q, name, i+1);
		}
		cout << "所有仓库中共有" << allcount << "个." << endl;
	}
	else
	{
		Node<LinkList<Express>>* p = link.Go(storageid - 1);
		LinkList<Express> q = p->Getdata();
		allcount += SearchLocal(q, name,storageid);
	}
}
int Express::SearchLocal(LinkList<Express> &link, int id_things,int storageid)
{
	int goodscnt = link.NumNodes();
	for (int i = 0; i < goodscnt; i++)
	{
		Node<Express>* p = link.Go(i);
		Express q = p->Getdata();
		if (q.id_things == id_things)
		{
			cout << "第" << storageid << "个库中:";
			cout << q << '\t' << link.Getcnt(id_things) << "个" << endl;
			return link.Getcnt(id_things);
		}
	}
	return 0;
}


int Express::SearchLocal(LinkList<Express> &link, string name,int storageid)
{
	int goodscnt = link.NumNodes();
	for (int i = 0; i < goodscnt; i++)
	{
		Node<Express>* p = link.Go(i);
		Express q = p->Getdata();
		if (q.name == name)
		{
			cout << "第" << storageid << "个库中:";
			cout << q << '\t' << link.Getcnt(q.id_things) << "个" << endl;
			return link.Getcnt(q.id_things);
		}
	}
	return 0;
}


void Express::Add(LinkList<LinkList<Express>>& link, const int& numW, string& s) {
	cout << "请输入商品名称: ";
	cin >> s;
	
	int id_name = -1;
	for (int i = 0; i < alllist.size(); i++) {
		if (alllist[i].name == s) {
			id_name = alllist[i].id_things;
			break;
		}
	}
	if (id_name == -1) { 
		id_name = alllist.size()+1;
		alllist.push_back(Express(id_name, s));	
	}
	Express ex(id_name, s);
	if (numW > link.NumNodes()) {
		LinkList<Express>* a = new LinkList<Express>;
		a->Append(ex);
		link.Append(*a);
		link.ModifyCnt(link.NumNodes(), 1);
		link.CurNode()->Getdata().ModifyCnt(id_name, 1);
	}
	else {
		link.GoTop();
		link.Skip(numW - 1);
		link.CurNode()->Getdata().Append(ex);
		link.CurNode()->Getdata().ModifyCnt(id_name, 1);
	}
}

void Express::Delete(LinkList<LinkList<Express>>& link, const int& numW, string& s) {
	cout << "请输入商品名称: ";
	cin >> s;
	int id_name = -1;
	for (int i = 0; i < alllist.size(); i++) {
		if (alllist[i].name == s) {
			id_name = alllist[i].id_things;
			break;
		}
	}
	if (id_name == -1) return;
	Express dx(id_name, s);
	link.GoTop();
	link.Skip(numW - 1);
	auto& xx = link.CurNode()->Getdata();
	Node<Express>* x = xx.Locate(dx, true);
	xx.ModifyCnt(id_name, -1);
	xx.DeleteCurNode();
}
