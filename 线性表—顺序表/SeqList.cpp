#include <iostream>

using namespace std;
#define InitSize 100
typedef struct {
	int* data ;
	int MaxSize;
	int length;
} SeqList;

//初始化顺序表
void InitList(SeqList&L){
	L.data= (int*)malloc(sizeof(int)*InitSize) ;
	
}
//求表长
int Length(SeqList &L)
{
	return L.length;
}

//按值查找
int LocateElem(SeqList&L,int e)
{
	for(int i = 0 ; i < L.length;i++)
	{
		if(e  == L.data[i])
		{
			return e;
		}
		else return -1;
	}
}
//按位查找
int GetElem(SeqList&L,int i )
{
	if(i<0 || i > L.length)
	{
		cout<< "查找失败，你输入的数据不合法"<< endl;
	}
	else return L.data[i-1];

}
//插入操作

bool ListInsert(SeqList&L,int i , int e )
{
	if(i<0 || i > L.length+1)
	{
		return false;
	}
	
	if(L.length ==InitSize ){
		return false;
	}
	for(int j=L.length;j >= i;j--){
		L.data[j] = L.data[j-1] ;
	}
	L.data[i-1] = e;
	L.length++;
	return true ;
}

// 删除操作
bool ListDelete(SeqList&L,int i , int& e )
{
	if(i<0 || i > L.length)
	{
		return false;
	}
	
	e=L.data[i-1];
	for(int j=i;j<L.length;j++){
		L.data[j-1] = L.data[j];
		L.length--;
		return true ;
	}
	
}
//输出操作
void PrintList(SeqList&L)
{
	for(int i=0;i<L.length;i++){
		cout<< L.data[i] << " " ;
	}
	cout << endl;
}
//判空操作
bool Empty(SeqList&L)
{
	if(L.length == 0)
	{
		return true;
	}
	return false;
}
//销毁操作
void  Destroy(SeqList&L,int &e)
{
	for(int i=0;i<L.length;i++){
		ListDelete(L,i , e ) ;
	}
	
	free(L.data);
	L.data = NULL ;
}
int main()
{
	SeqList L;
	
	InitList(L);
	ListInsert(L,1,100);
	ListInsert(L,2,100);
	ListInsert(L,3,100);
	ListInsert(L,4,100);
	ListInsert(L,5,100);
	
	PrintList(L);
	int e = 0;
	ListDelete(L,1,e);
	PrintList(L);
	cout << e << endl;
	
	ListInsert(L,1,121);
	PrintList(L);
	return 0;
}

