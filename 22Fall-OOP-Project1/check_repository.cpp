#include "check_repository.h"
void CheckSelectedRepository(LinkList<LinkList<Express>>* current, int id_store)
{
	int num = 1;
	Node<LinkList<Express>>* p;
	for (p = current->head; p != nullptr; p = p->next) {
		if (num == id_store) break;
		else ++num;
	}
	for (Node<Express>* com = p->data.head; com != nullptr; com = com->next)
		cout << com->data << (p->data).cnt[com->data.id_things] << endl;

}

void CheckAllRepository(LinkList<LinkList<Express>>* first)
{
	int cnt_store = 0;
	Node<LinkList<Express>>* p;
	for (p = first->head; p != nullptr; p = p->next) ++cnt_store;
	cout << "共盘点" << cnt_store << "个仓库" << endl << "共存储有商品:" << endl;
	for (int i = 0; i <= Express::alllist.size(); i++) {
		int num = 0;
		for (p = first->head; p != nullptr; p = p->next) {
			for (Node<Express>* com = p->data.head; com != nullptr; com = com->next) {
				if (com->data.name == Express::alllist[i].name) {
					num += (p->data).cnt[com->data.id_things];
				}
			}
		}
		cout << Express::alllist[i].name << num << endl;
	}
}
