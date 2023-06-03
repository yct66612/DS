#include<iostream>
#define MaxSize 100   //定义栈中元素最大的个数
using namespace std;

typedef struct {
	int data[MaxSize] ;  //存放栈中元素
	int top0 ;           //0号栈顶指针
	int top1 ; 			 //1号栈顶指针
} ShStack;

//初始化栈
void InitStack(ShStack& S) {
	S.top0 = -1 ;      	//初始化0号栈顶指针
	S.top1 = MaxSize ;	//初始化1号栈顶指针
}

//判断共享栈是否为空
bool StackEmpty(ShStack S) {
	if(S.top0 == -1 && S.top1 == MaxSize)  // 当0号栈和1号栈都为空时，栈为空
		return true;
	else
		return false;
}

// 入栈
bool Push(ShStack& S, int stackNum, int x) {
	if (S.top0 + 1 == S.top1) {  // 栈已满，无法入栈
		return false;
	}
	
	if (stackNum == 0) {  // 0号栈
		S.data[++S.top0] = x;
	} else if (stackNum == 1) {  // 1号栈
		S.data[--S.top1] = x;
	} else {  // 栈编号错误
		return false;
	}
	
	return true;
}

// 出栈
bool Pop(ShStack& S, int stackNum, int& x) {
	if (stackNum == 0) {  // 0号栈
		if (S.top0 == -1) {  // 栈已空，无法出栈
			return false;
		}
		x = S.data[S.top0--];
	} else if (stackNum == 1) {  // 1号栈
		if (S.top1 == MaxSize) {  // 栈已空，无法出栈
			return false;
		}
		x = S.data[S.top1++];
	} else {  // 栈编号错误
		return false;
	}
	
	return true;
}

// 获取栈顶元素
bool GetTop(ShStack S, int stackNum, int& x) {
	if (stackNum == 0) {  // 0号栈
		if (S.top0 == -1) {  // 栈为空
			return false;
		}
		x = S.data[S.top0];
	} else if (stackNum == 1) {  // 1号栈
		if (S.top1 == MaxSize) {  // 栈为空
			return false;
		}
		x = S.data[S.top1];
	} else {  // 栈编号错误
		return false;
	}
	
	return true;
}

// 清空栈
void ClearStack(ShStack& S) {
	S.top0 = -1;
	S.top1 = MaxSize;
}

int main() {
	ShStack S;
	InitStack(S);
	//测试下入栈
	Push(S, 0, 3);
	Push(S, 0, 2);
	Push(S, 0, 4);
	Push(S, 0, 5);
	Push(S, 0, 8);
	Push(S, 1, 600);
	Push(S, 1, 6700);
	Push(S, 1, 800);
	
	int x1, x2;
	GetTop(S, 0, x1);
	GetTop(S, 1, x2);
	cout << x1 << endl;
	cout << x2 << endl;
	cout << "------------Pop之前------------" << endl;
	//测试下出栈
	Pop(S,0,x1);
	Pop(S,0,x1);	
	Pop(S,1,x2);	
	Pop(S,1,x2);	
	Pop(S,1,x2);	
	
	// 测试最后的栈顶元素是啥
	GetTop(S, 0, x1);
	GetTop(S, 1, x2);
	cout << x1 << endl;
	cout << x2 << endl;
	return 0;
}

