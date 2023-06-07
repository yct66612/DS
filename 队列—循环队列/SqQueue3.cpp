#include <iostream>
#define MaxSize 50     //定义队列中最大元素个数
using namespace std;

typedef struct {
	int data[MaxSize]; // 存放队列元素
	int front, rear;   // 队头指针和队尾指针
	bool tag;          // 标记最近进行的操作（false: 删除，true: 插入）
} SqQueue;

// 初始化队列
void InitQueue(SqQueue& Q) {
	Q.front = 0;
	Q.rear = 0;
	Q.tag = false;  // 初始化为删除操作
}

// 队列判空
bool QueueEmpty(SqQueue& Q) {
	if(Q.tag)
		return false;
	return (Q.tag && Q.front == Q.rear) ;
}


// 队列判满
bool QueueFull(SqQueue& Q) {

	if(Q.tag)
		return (Q.front == Q.rear  && Q.tag);
	return false ;
	
}

// 入队
bool EnQueue(SqQueue& Q, int x) {
	if (QueueFull(Q)) {  // 队列满了
		return false;
	}
	Q.data[Q.rear] = x;
	Q.rear = (Q.rear + 1) % MaxSize;
	Q.tag = true;  // 更新最近操作为插入
	return true;
}

// 出队
bool DeQueue(SqQueue& Q, int& x) {
	if (QueueEmpty(Q)) {
		return false;
	}
	x = Q.data[Q.front];
	Q.front = (Q.front + 1) % MaxSize;
	Q.tag = false;  // 更新最近操作为删除
	return true;
}

// 读取队头元素(查)
bool GetHead(SqQueue& Q, int& x) {
	if (QueueEmpty(Q)) {  // 队列为空返回false;
		return false;
	}
	x = Q.data[Q.front];
	return true;
}

int main() {
	SqQueue Q;
	int x = 0;
	InitQueue(Q);   // 初始化队列
	EnQueue(Q, 15); // 入队测试
	EnQueue(Q, 10); // 入队测试
	EnQueue(Q, 1);  // 入队测试
	EnQueue(Q, 888); // 入队测试
	
	GetHead(Q, x);
	cout << "队头元素为: " << x << endl;
	
	cout << "------出队测试-------" << endl;
	DeQueue(Q, x);
	DeQueue(Q, x);
	GetHead(Q, x);
	cout << "队头元素为: " << x << endl;
	
	cout << "最近操作为: " << (Q.tag ? "插入" : "删除") << endl;
	
	return 0;
}

