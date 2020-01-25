#include "BufferManager.h"

bool BufferManager::init(){
	int i=0;
	for(i=0;i<64;i++){
		Buffer[i]=Gblock();
		if(Buffer[i]==NULL||Buffer[i]->record)break;
	}
	if(i==64)return true;
	else return false;
}

bool BufferManager::schema1(int offset,string tablename){
	int i=0;
	for(i=0;i<64;i++){
		if(Buffer[i]->tablename=="")break;
	}
	
	int j;
	if(i==64){
		j=0;
		while(true){
			if(Buffer[j]->accessed==false)break;
			else Buffer[j]->accessed=false;
			j++;
			if(j==64)j=0;
		}
	}
	exchange(offset,tablename,Buffer[i]);
	if(Buffer[i]!=NULL)return true;
	else return false; 
}

bool BufferManager::schema2(int offset,string tablename){
	int i=0;
	for(i=0;i<64;i++){
		if(Buffer[i]->tablename=="")break;
	}
	int j;
	if(i==64){
		j=0;
		while(true){
			if(Buffer[j]->accessed==false)break;
			else Buffer[j]->accessed=false;
			j++;
			if(j==64)j=0;
		}
	}
	
	exchange("",-1,Buffer[j]);
	Buffer[j]->offset=offset;
	Buffer[j]->tablename=tablename;
	Buffer[j]->written=true;
	Buffer[j]->accessed=true;
	memeset(Buffer[i]->record,0,MAX_BLOCK_SIZE);
	exchange("",-1,Buffer[j]);
	if(Buffer[j]!=NULL)return true;
	else return false;
}

bool BufferManager::exchange(int offset,string tablename,Block *replacement){
	FILE* fp;
	char filename[64];
	memset(filename,0,sizeof(filename));
	int length=0;
	length=replacement->tablename.size();
	if(length!=0){
		for(i=0;i<length;i++){
			filename[i]=replacement->tablename.at(i);
		}
		if(fp=fopen(filename,"rb+")==NULL){
			cout<<"Writing data error"<<endl;
			return false;
		}
		fseek(fp,replacement->offset *MAX_BLOCK_SIZE,SEEK_SET);
		fwrite(replacement->record,MAX_BLOACK_SIZE,1,fp);
		fclose(fp);
	}
	memset(filename,0,sizeof(filename));
	if(offset!=-1){
		length=tablename.size();
		for(i=0;i<length;i++){
			filename[i]=tablename.at(i);
		}
		if((fp=fopen(filename,"rb"))==NULL){
			cout<<"Reading data error"<<endl;
			return false;
		}
		
		fseek(fp,MAX_BLOCK_SIZE*offset,SEEK_SET);
		fread(Replaced->record,BlockSize,1,fp);		
		fclose(fp);
		replacement->offset = offset;
		replacement->tablename = tablename;
		replacement->accessed = true;
	
		return true;
	}
	else return true;
}
