#include "check_repository.h"
//�̵�ָ���ֿ��е�������Ʒ
void CheckSelectedRepository(LinkList<LinkList<Express>>* current, int id_store) //������������,ǰ��Ϊ���������(���׸��ֿ��ָ��),����Ϊ��Ҫ�̵��ָ���ֿ���
{
	int num = 1; //������,����Ѱ����������ж�Ӧ��ŵĲֿ���
	Node<LinkList<Express>>* p;
	for (p = current->head; p != nullptr; p = p->next) //����������(�ֿ����)
	{
		if (num == id_store) break; //Ѱ�ҵ�Ŀ��ֿ�
		else ++num;
	}
	if (p == nullptr) //�������(�޲ֿ�/�޶�Ӧ��Ųֿ�)����
		cout << "�����ڸñ�Ųֿ�!";
	else
	{
		map<string, int> record; //��¼�Ѿ��̵������Ʒ
		for (Node<Express>* com = p->data.head; com != nullptr; com = com->next) //�ڲ��������(�ֿ��ڲ���Ʒ����)
		{
			if (!record[com->data.name]) //��Ʒδ���̵�
			{
				cout << com->data << "\t�洢����: " << (p->data).cnt[com->data.id_things] << endl;
				++record[com->data.name];
			}
			else
				continue;
		}
	}
}
//�̵�ȫ���ֿ��������Ʒ
void CheckAllRepository(LinkList<LinkList<Express>>* first)
{
	int cnt_store = 0; //�ֿ�����¼
	Node<LinkList<Express>>* p;
	for (p = first->head; p != nullptr; p = p->next) ++cnt_store; //����������(�ֿ����)
	cout << "���̵�" << cnt_store << "���ֿ�" << endl;
	if (!cnt_store) //�޲ֿ��������
		return;
	cout << "���洢����Ʒ:" << endl;
	for (int i = 0; i < Express::alllist.size(); i++) //��̬��Ա����vector��������(����ƷĿ¼)
	{
		int num = 0; //��¼��ǰ��Ʒ��
		for (p = first->head; p != nullptr; p = p->next) //����������(���α���ÿ���ֿ�)
		{
			for (Node<Express>* com = p->data.head; com != nullptr; com = com->next) //�ڲ��������(�ֿ��ڲ���Ʒ����)
			{
				if (com->data.name == Express::alllist[i].name) //Ѱ��Ŀ����Ʒ,�ɹ�����Ʒ������
				{
					num += 1;
				}
			}
		}
		cout << Express::alllist[i] << "\t�洢����: " << num << endl;
	}
}