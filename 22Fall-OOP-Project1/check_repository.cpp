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
		cout << "�����ڸñ�Ųֿ⣡";
	}
	else {
		map<string, int> record;
		for (Node<Express>* com = p->data.head; com != nullptr; com = com->next) {
			if (!record[com->data.name]) {
				cout << com->data << "\t ����Ϊ��" << (p->data).cnt[com->data.id_things] << endl;
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
	cout << "���̵�" << cnt_store << "���ֿ�" << endl << "���洢����Ʒ:" << endl;
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
		cout << Express::alllist[i] << "\t�洢������" << num << endl;
	}
}
