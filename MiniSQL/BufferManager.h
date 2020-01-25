#ifndef __BUFFER_H__
#define __BUFFER_H__

#include<iostream>
#include<fstream>
#include<vector>

#define MAX_BLOCK_NUM 1000 //预先分配的文件块的数目
#define BLOCKSIZE 4096	

class BufferManage {
public:
	friend class Leaf;
	friend class Branch;
	friend class BPLUSTREE;
	friend class RecordManager;
	friend class IndexManager;

	buffer BufferBlock[MAX_BLOCK_NUM];
	void flashback(int buffer_num) {
		if (!BufferBlock[buffer_num].isWritten)return;
		string  Filename = BufferBlock[buffer_name].filename;
		fstream fout(file.)
	}

	BufferManager() {
		for (int i = 0; i < MAX_BLOCK_NUM; i++) {
			BufferBlock[i].initialize();
		}
	}
	~BufferManager() {
		for (int i = 0; i < MAX_BLOCK_NUM; i++) {
			flashBack(i);
		}
	}

};


#endif