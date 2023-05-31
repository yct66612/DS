#include <iostream>

using namespace std;

// 循环单链表节点结构体
typedef struct LNode {
	int data;
	LNode* next;
}LNode,*LinkList;

// 初始化循环单链表
void initializeList(LinkList& L) {
	L = new LNode;
	L->next = L; // 头节点的 next 指针指向自身
}

// 在循环单链表末尾插入节点
void insertAtEnd(LinkList L, int newData) {
	LNode* newLNode = new LNode;
	newLNode->data = newData;
	newLNode->next = L; // 新节点的 next 指针指向头节点
	
	if (L == nullptr) {
		L = newLNode; // 空链表的情况下，头节点指向新节点
	} else {
		LNode* current = L;
		while (current->next != L) {
			current = current->next; // 寻找末尾节点
		}
		current->next = newLNode; // 末尾节点的 next 指针指向新节点
	}
}


// 在循环单链表中删除指定节点
void deleteLNode(LinkList L, int target) {
	if (L == nullptr) {
		return; // 空链表，无需删除
	}
	
	LNode* current = L;
	LNode* previous = nullptr;
	
	// 寻找要删除的节点和其前一个节点
	do {
		if (current->data == target) {
			break;
		}
		previous = current;
		current = current->next;
	} while (current != L); // 和while 循环前将头结点跳过一样的
	
	if (current == L) {
		L = L->next; // 删除头节点的情况
	}
	
	if (current != nullptr) {
		previous->next = current->next; // 将前一个节点的 next 指针跳过要删除的节点
		delete current; // 释放要删除节点的内存空间
	}
}

// 遍历循环单链表并打印节点数据
void printList(LNode* L) {
	if (L == nullptr) {
		cout << "空链表" << endl;
		return;
	}
	
	LNode* current = L->next;
	do {
		cout << current->data << " ";
		current = current->next;
	} while (current != L);
	
	cout << endl;
}

int main() {
	LNode* L = nullptr;
	
	initializeList(L);
	
	insertAtEnd(L, 1);
	insertAtEnd(L, 2);
	insertAtEnd(L, 3);
	
	printList(L);
	
	deleteLNode(L, 2);
	
	printList(L);
	
	return 0;
}

