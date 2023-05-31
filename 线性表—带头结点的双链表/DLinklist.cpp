#include<iostream>

using namespace std ;
typedef struct DNode{
	int data;
	struct DNode *prior,*next ;
}DNode,*DLinklist;
//初始化一个双链表
bool InitList(DLinklist&L){
	L = (DNode*)malloc(sizeof(DNode));
	if(L==NULL)
		return false;
	L->prior = NULL ;
	L->next = NULL ;
	return true;
}
//尾插法建立双链表
void List_TailInsert(DLinklist&L)
{
	int x = 0;
	DNode* pTail  = L ;
	cin >> x ;
	while(x != 9999){
		DNode* NewNode = new DNode ;
		pTail->next = NewNode ;
		NewNode->data = x;
		NewNode->prior = pTail ;
		
		pTail = pTail->next ;
		pTail->next = nullptr ;
		cin >> x ;
		
	}
	
	
}
//头插法建立双链表
void List_HeadInsert(DLinklist&L)
{
	int x = 0;
	cin >> x ;
	while(x != 9999){
		DNode* NewNode = new DNode ;
		NewNode->next = L->next ;
		NewNode->data = x ;
		L->next = NewNode ;
		NewNode->prior = L ;
		cin >> x ;
	}
	
	
}
//判断双链表是否为空
bool Empty(DLinklist L)
{
	if(L->next==NULL){
		return true;
	}
	return false ;
}
//双链表的插入操作(在p结点之后插入s结点	)
bool InsertNextDNode(DNode* p ,DNode* s)
{
	if(p == NULL || s == NULL)
		return false;
	if(p->next == NULL){
		s->next = p->next ;
		p->next = s ;
		s->prior = p ;
		return true ;
	}
	s->next = p->next ;
	p->next->prior = s;
	p->next = s;
	s->prior = p ;
	return true ;
}
//向后遍历
void PrintList(DLinklist L) {
	L=L->next; //因为头结点不存储有效数据
	
	while (L != NULL) {
		cout << L->data << endl ;
		L = L->next;
	}
}
//向前遍历
void HeadPrintList(DLinklist L) {
	if (L == nullptr) {
		return;
	}
	
	// 找到链表尾部节点
	DNode* tail = L->next;
	while (tail->next!= nullptr) {
		tail = tail->next;
	}
	
	// 从尾部向前遍历
	while (tail->prior != nullptr) {
		cout << tail->data << " ";
		tail = tail->prior;
	}
}
//删除后继结点
bool DeleteNextDNode(DNode*p)
{
	if(p = nullptr){
		return false ;
	}
	DNode *q = p->next;
	if(q = nullptr){
		return false ; //没有后继结点
	}
	p->next = q->next ;
	
	if(p->next!=nullptr){   //如果q不是最后一个结点
		q->next->prior = p ;
	}
	
	free(q) ;
	return true ;
}
//删除整个链表（遍历之后一个一个的删除）
void DestoryList(DLinklist &L)
{
	while(L->next != nullptr){
		
		DeleteNextDNode(L); 
	}
}

int main()
{
	DLinklist L;//头结点

	InitList(L);
	DNode*s = (DNode*)malloc(sizeof(DNode));
	s->data = 100 ;
	InsertNextDNode(L,s);
	List_TailInsert(L);
	
	HeadPrintList(L) ;  //前向遍历跳过了头结点
	
	DestoryList(L); // 摧毁链表
	return 0 ;
}
