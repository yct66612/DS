#include<iostream>
#define MaxSize 10   //定义栈中元素最大的个数
using namespace std;

typedef struct {
	int data[MaxSize] ;  // 存放栈中元素
	int top ;            //栈顶指针
} SqStack;

//初始化一个空栈
void InitStack(SqStack& S) {
	S.top = -1 ;      //初始化栈顶指针
}
//销毁栈
void DestoryStack(SqStack& S) {
	S.top = -1 ;      // 这样让原来的栈无效
}
//入栈
bool Push(SqStack& S, int x ) {
	if (S.top == MaxSize - 1) //栈满了
		return false ;
	S.top = S.top + 1;
	S.data[S.top] = x;
	return true;
}
//出栈(若栈S非空，则弹出栈顶元素，并用x返回)
bool Pop(SqStack& S, int& x) {
	if (S.top == - 1) //栈满了
		return false ;
	S.top-- ;
	x = S.top ;
	return true ;
}
// 读取栈顶元素
bool GetTop(SqStack&S, int& x) {
	if (S.top == -1) //栈是空的
		return false;
	x = S.data[S.top];
	return true ;
}
bool StackEmpty(SqStack S)
{
	if(S.top = -1){
		return true ;
	}
	else 
		return false ;
}
int main() {
	SqStack S ;
	int x = 0;
	InitStack(S) ;   // 初始化栈
	//入栈
	Push(S, 1);
	Push(S, 2);
	Push(S, 3);
	Push(S, 4);
	
	GetTop(S,x);
	cout << x << endl;
	
	Pop(S,x) ;
	GetTop(S,x);
	cout << x << endl;
	return 0;
}
