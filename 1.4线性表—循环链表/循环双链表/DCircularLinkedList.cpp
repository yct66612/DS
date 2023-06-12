#include <iostream>
using namespace std;

typedef struct DNode {
	int data;
	struct DNode* prior, * next;
} DNode, * DLinklist;

// 初始化一个循环双链表
bool InitList(DLinklist& L) {
	L = (DNode*)malloc(sizeof(DNode));
	if (L == NULL)
		return false;
	L->prior = L;
	L->next = L;
	return true;
}

// 尾插法建立循环双链表
void List_TailInsert(DLinklist& L) {
	int x = 0;
	DNode* pTail = L;
	cin >> x;
	while (x != 9999) {
		DNode* NewNode = new DNode;
		pTail->next = NewNode;
		NewNode->data = x;
		NewNode->prior = pTail;
		
		pTail = pTail->next;
		pTail->next = nullptr;
		cin >> x;
	}
	
	// 尾部节点的next指针指向头节点
	pTail->next = L;
	L->prior = pTail;
}

// 头插法建立双链表
void List_HeadInsert(DLinklist& L) {
	int x = 0;
	cin >> x;
	while (x != 9999) {
		DNode* NewNode = new DNode;
		NewNode->next = L->next;
		NewNode->data = x;
		L->next = NewNode;
		NewNode->prior = L;
		cin >> x;
	}
}

// 判断循环双链表是否为空
bool Empty(DLinklist L) {
	if (L->next == L) {
		return true;
	}
	return false;
}

// 循环双链表的插入操作(在p结点之后插入s结点)
bool InsertNextDNode(DNode* p, DNode* s) {
	if (p == NULL || s == NULL)
		return false;
	if (p->next == NULL) {
		s->next = p->next;
		p->next = s;
		s->prior = p;
		return true;
	}
	s->next = p->next;
	p->next->prior = s;
	p->next = s;
	s->prior = p;
	return true;
}

// 向后遍历
void PrintList(DLinklist L) {
	DLinklist p = L->next; //因为头结点不存储有效数据
	while (p != L) {
		cout << p->data << endl;
		p = p->next;
	}
}

// 向前遍历
void HeadPrintList(DLinklist L) {
	DLinklist p = L->prior; //因为头结点不存储有效数据
	while (p != L) {
		cout << p->data << endl;
		p = p->prior;
	}
}

// 删除后继结点
bool DeleteNextDNode(DNode* p) {
	if (p == nullptr) {
		return false;
	}
	DNode* q = p->next;
	if (q == nullptr) {
		return false; // 没有后继结点
	}
	p->next = q->next;
	
	if (p->next != nullptr) {   // 如果q不是最后一个结点
		q->next->prior = p;
	}
	
	free(q);
	return true;
}

// 删除整个链表（遍历之后一个一个的删除）
void DestroyList(DLinklist& L) {
	while (L->next != L) {
		DeleteNextDNode(L);
	}
	free(L); // 释放头节点
	L = NULL;
}

int main() {
	DLinklist L; // 头结点
	
	InitList(L);
	DNode* s = (DNode*)malloc(sizeof(DNode));
	s->data = 100;
	InsertNextDNode(L, s);
	List_TailInsert(L);
	
	HeadPrintList(L);  // 前向遍历跳过了头结点
	
	DestroyList(L); // 摧毁链表
	return 0;
}

