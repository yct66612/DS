#include<iostream>

using namespace std;

typedef struct LNode {
	int data;
	struct LNode *next;
} LNode, *LinkList; //隐藏含义，LNode代表 某个结点，LinkList代表整个链表


//初始化头节点(空的)
LNode* InitList(LinkList L) {
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL ;
	return L ;
}
//按序号查找
LNode* GetElem(LinkList L,int i) {
	if(i<1){
		return NULL;
	}
	int j = 1;
	LNode* p = L->next;
	while(p!=NULL && j <i ){
		p = p->next ;
		j++ ;
	}
	return p ;
}

//按值查找
LNode* LocateElem(LinkList L,int e) {
	LNode* p = L->next;
	while(p!=NULL && p->data!= e){
		if(p->data == e){
			return p;
		}
		p = p->next ;	
	}
	return NULL ;
}
//插入操作(指定结点的后插操作)
bool InsertNextNode(LinkList &L,LNode*p,int e)
{
	if(p == NULL){
		return false;
	}
	LNode*s =(LNode*) malloc(sizeof(LNode)) ;
	if(s == NULL)
		return false ;
	s->data = e;
	s->next = p->next;
	p->next = s;
	return true ;
}
//插入操作(指定结点的前插操作)(O（1）复杂度)
bool InsertPriorNode(LNode*p,int e)
{
	if(p == NULL) 
		return false;
	LNode* s = (LNode*)malloc(sizeof(LNode));
	if(s == NULL)
		return false ;
	s->next = p->next ;
	s->data = p->data;
	p->next = s;
	p->data = e;
	return true ;
}
//插入操作(在第i个位置插入元素e)
bool ListInsert(LinkList L,int i ,int e){
	if(i<1)
		return false ;
	LNode* p; //表示当前扫描结点
	p = GetElem(L,i-1) ;//获取了当前扫描结点	
	
	return InsertNextNode(L,p,e);
}


//求表长
int Length(LinkList L) {
	return 0;

}



//头插法建立单链表
LinkList List_HeadInsert(LinkList L ) {
	L = InitList(L); //创建头结点
	LNode* s ;
	//LNode* ptail = L ;
	int x;

	cin >> x ;
	while (x != 9999) {

		s = (LNode*)malloc(sizeof(LNode)) ;
		s->data = x ;
		s->next = L->next;
		L->next = s;
		cin >> x ;
	}


	return L ;
}
//尾插法建立单链表
LinkList List_TailInsert(LinkList L )
{
	
	int x;
	LinkList pTail = L;
	cin >> x ;
	while(x != 9999)
	{
		LinkList s = (LNode*)malloc(sizeof(LNode)) ;
		s->data = x;
		pTail->next = s;
		
		pTail = pTail ->next ;
		cin >> x ;
	}
	pTail->next = NULL ; //尾结点置空
	return L;
}
// 删除操作(删除第i个位置的 元素)
bool ListDelete(LinkList&L,int i,int &e ) {
	if(i<1)
		return false;
	LNode* p ;
	p = GetElem(L,i-1); // 获取到它前一个的位置
	if(p==NULL)
		return false ;
	LNode* q = p->next ;
	e = q->data;
	p->next = q->next;
	
	free(q);
	return true ;

}
//指定结点的删除(p是最后一个结点)
bool DeleteNode(LNode*p,LinkList&L)
{
	
	L= L->next;
	while(L->next!=NULL){
		L=L->next ;
	}
	L->next = NULL ;
	free(p) ;
	return true ;
}
////指定结点的删除(p是不最后一个结点)
bool DeleteNode(LNode*p)
{
	if(p == NULL)
		return false ;
	LNode*q = p->next ;
	p->data = q->data;
	p->next = q->next ;
	free(q) ;
	return true ;
}

//输出操作
void PrintList(LinkList L) {
	L=L->next; //因为头结点不存储有效数据
	
	while (L != NULL) {
		cout << L->data << endl ;
		L = L->next;
	}
}
//判空操作
bool Empty(LinkList&L) {
	return true;
}
//销毁操作
void  Destroy(LinkList&L) {

}

int main() {
	LinkList L =  NULL ;
	LinkList L1 =  NULL ;
	int e = 0 ;
	L1 = InitList(L1); //创建头结点
//	L = List_HeadInsert(L); // 头插法  
//	PrintList(L);
//	cout << endl;
	List_TailInsert(L1); //尾插法
	//PrintList(L1);//遍历
	cout << endl;
	
	ListInsert(L1,2,10);
	PrintList(L1);
	cout << endl;
//	InsertNextNode(L1,L1->next,5);
//	
//	PrintList(L1);	
//	cout<< endl;
	ListDelete(L1,2,e);
	PrintList(L1);
	cout<< endl;
	
	DeleteNode(L1->next);
	PrintList(L1);
	cout<< endl;
	return 0 ;
}
