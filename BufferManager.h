#ifndef _BUFFERMANAGER_H_
#define _BUFFERMANAGER_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<vector>
#include<list>
#include<iostream>

using namespace std;

#define MAX_BLOCK_SIZE 4096

struct Block{
	int offset;
	string tablename;
	char *record;
	bool written;
	bool accessed;
};

class BufferManager{
	public:
		Block* Buffer[64]={0};
		BufferManager(){}
		bool init();
		bool schema1(int offset,string tablename);
		bool schema2(int offset,string tablename);
		bool exchange(int offset,string tablename,Block *replacement);
		bool drop(string tablename);
		
		Block *GBlock();
		Block *GetBlock(int offset,string tablename,int flag);
		
		void  clearBuffer();
		~BufferManager();
};

int Block_Num(string filename);
#endif;
 
