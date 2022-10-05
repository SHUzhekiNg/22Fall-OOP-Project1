#include "check_repository.h"
//盘点指定仓库中的所有商品
void CheckSelectedRepository(LinkList<LinkList<Express>>* current, int id_store) //传入两个参数,前者为链表的链表(即首个仓库的指针),后者为需要盘点的指定仓库编号
{
	int num = 1; //计数器,用以寻找外层链表中对应编号的仓库结点
	Node<LinkList<Express>>* p;
	for (p = current->head; p != nullptr; p = p->next) //外层链表遍历(仓库遍历)
	{
		if (num == id_store) break; //寻找到目标仓库
		else ++num;
	}
	if (p == nullptr) //特殊情况(无仓库/无对应编号仓库)处理
		cout << "不存在该编号仓库!";
	else
	{
		map<string, int> record; //记录已经盘点完的商品
		for (Node<Express>* com = p->data.head; com != nullptr; com = com->next) //内层链表遍历(仓库内部商品遍历)
		{
			if (!record[com->data.name]) //商品未被盘点
			{
				cout << com->data << "\t存储个数: " << (p->data).cnt[com->data.id_things] << endl;
				++record[com->data.name];
			}
			else
				continue;
		}
	}
}
//盘点全部仓库的所有商品
void CheckAllRepository(LinkList<LinkList<Express>>* first)
{
	int cnt_store = 0; //仓库数记录
	Node<LinkList<Express>>* p;
	for (p = first->head; p != nullptr; p = p->next) ++cnt_store; //外层链表遍历(仓库遍历)
	cout << "共盘点" << cnt_store << "个仓库" << endl;
	if (!cnt_store) //无仓库情况处理
		return;
	cout << "共存储有商品:" << endl;
	for (int i = 0; i < Express::alllist.size(); i++) //静态成员变量vector容器遍历(总商品目录)
	{
		int num = 0; //记录当前商品数
		for (p = first->head; p != nullptr; p = p->next) //外层链表遍历(依次遍历每个仓库)
		{
			for (Node<Express>* com = p->data.head; com != nullptr; com = com->next) //内层链表遍历(仓库内部商品遍历)
			{
				if (com->data.name == Express::alllist[i].name) //寻找目标商品,成功则商品数递增
				{
					num += 1;
				}
			}
		}
		cout << Express::alllist[i] << "\t存储个数: " << num << endl;
	}
}