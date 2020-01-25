#ifndef _RECORDMANAGER_H_
#define _RECORDMANAGER_H_

#include "BufferManager.h"
#include "MiniSQL.h"

bool Delete_tuple(vector<int> offsetlist, Table table, Condition_list list);
bool Select_tuple(vector<int> offsetlist, Table table, Condition_list list);

int Insert(Tuple &tuple);
char* Convertvalue(Tuple &tuple); 

#endif
