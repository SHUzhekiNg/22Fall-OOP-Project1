#include "check_repository.h"
void CheckSelectedRepository(LinkList<LinkList<Express>>* current, int id_store)
{
	int num = 1;
	Node<LinkList<Express>>* p;
	for (p = current->head; p != nullptr; p = p->next) {
		if (num == id_store) break;
		else ++num;
	}
	if (p == nullptr) {
		cout << "不存在该编号仓库！";
	}
	else {
		map<string, int> record;
		for (Node<Express>* com = p->data.head; com != nullptr; com = com->next) {
			if (!record[com->data.name]) {
				cout << com->data << "\t 数量为：" << (p->data).cnt[com->data.id_things] << endl;
				++record[com->data.name];
			}
			else continue;			
		}
	}
}

void CheckAllRepository(LinkList<LinkList<Express>>* first)
{
	int cnt_store = 0;
	Node<LinkList<Express>>* p;
	for (p = first->head; p != nullptr; p = p->next) ++cnt_store;
	cout << "共盘点" << cnt_store << "个仓库" << endl << "共存储有商品:" << endl;
	if (!cnt_store) return;
	for (int i = 0; i < Express::alllist.size(); i++) {
		int num = 0;
		for (p = first->head; p != nullptr; p = p->next) {
			for (Node<Express>* com = p->data.head; com != nullptr; com = com->next) {
				if (com->data.name == Express::alllist[i].name) {
					++num; // (p->data).cnt[com->data.id_things];
				}
			}
		}
		cout << Express::alllist[i] << "\t存储个数：" << num << endl;
	}
}
