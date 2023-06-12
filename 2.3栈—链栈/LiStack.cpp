#include <iostream>

using namespace std;

typedef struct Linknode {
	int data;              // 数据域
	struct Linknode* next; // 指针域
} * LiStack;

// 初始化链式栈
void InitStack(LiStack& S) {
	S = NULL;  // 将栈顶指针初始化为空
}

// 判断链式栈是否为空
bool StackEmpty(LiStack S) {
	return (S == NULL);  // 若栈顶指针为空，则栈为空
}

// 入栈
bool Push(LiStack& S, int x) {
	Linknode* newNode = new Linknode;  // 创建新节点
	newNode->data = x;  // 赋值数据
	newNode->next = S;  // 新节点指向原栈顶节点
	S = newNode;  // 更新栈顶指针
	return true;
}

// 出栈
bool Pop(LiStack& S, int& x) {
	if (S == NULL) {  // 栈为空，无法出栈
		return false;
	}
	Linknode* p = S;  // 保存栈顶节点
	x = p->data;  // 获取栈顶元素
	S = S->next;  // 更新栈顶指针
	delete p;  // 释放栈顶节点内存
	return true;
}

// 获取栈顶元素
bool GetTop(LiStack S, int& x) {
	if (S == NULL) {  // 栈为空
		return false;
	}
	x = S->data;  // 获取栈顶元素
	return true;
}

int main() {
	LiStack S;
	InitStack(S);
	
	Push(S, 3);
	Push(S, 5);
	Push(S, 7);
	
	int x;
	if (GetTop(S, x)) {
		cout << "栈顶元素: " << x << endl;
	} else {
		cout << "栈空了" << endl;
	}
	
	while (!StackEmpty(S)) {
		if (Pop(S, x)) {
			cout << "出栈元素: " << x << endl;
		}
	}
	
	if (StackEmpty(S)) {
		cout << "栈空了" << endl;
	}
	
	return 0;
}

