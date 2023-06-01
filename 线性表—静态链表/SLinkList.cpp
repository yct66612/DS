#include <iostream>
#define MaxSize 50 // 静态链表的最大长度
using namespace std;

typedef struct {
	int data;  // 存储数据的元素
	int next;  // 下一个元素的数组下标
} SLinkList[MaxSize];

// 初始化静态链表
void InitList(SLinkList& L) {
	L[0] = {-1, -1};  // 使用列表初始化语法初始化头结点
}

// 在静态链表中插入元素 (双指针)
bool Insert(SLinkList& L, int position, int element) {
	if (position < 1 || position > MaxSize - 1) {
		// 位置超出范围
		return false;
	}
	
	if (L[0].next == -1) {
		L[0].next = position;
		L[position] = {element, -1};
		return true;
	}
	
	int current = L[0].next;  // 当前节点的下标
	int previous = 0;  // 当前节点的前一个节点的下标
	
	while (current != -1) {
		previous = current;
		current = L[current].next;
	}
	
	L[previous].next = position;
	L[position] = {element, -1};

	return true;
}

// 打印静态链表
void PrintList(SLinkList L) {
	int i = L[0].next;
	while (i != -1) {
		cout << L[i].data << " ";
		i = L[i].next;
	}
	cout << endl;
}

int main() {
	SLinkList L;  // 静态链表
	InitList(L);
	int count = 0;
	// 插入元素
	Insert(L, 1, 1);
	Insert(L, 8, 2);
	Insert(L, 9, 3);
	Insert(L, 4, 4);
	
	// 打印静态链表
	PrintList(L);
	
	return 0;
}

