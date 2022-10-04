#ifndef CHECK_REPOSITORY_H_
#define CHECK_REPOSITORY_H_
#include "LinkList.h"
#include "express.h"

using namespace std;
template <typename T> class LinkList;
class Express;
void CheckSelectedRepository(LinkList<LinkList<Express>>* current,int id_store);
void CheckAllRepository(LinkList<LinkList<Express>>* first);
#endif // CHECK_REPOSITORY_H_
