#include <iostream>

using namespace std ;

typedef struct LinkNode{  //建立了链式队列的结点
	int data;
	struct LinkNode* next ;
	
}LinkNode;

typedef struct{  				//链式队列
	LinkNode* front,*rear ; 	//队列的队头和队尾指针
}LinkQueue;

void InitQueue(LinkQueue& Q)              //构造空队列
{
	//初始时front,rear都指向头结点
	Q.front=Q.rear = new LinkNode();
}
void DestroyQueue(LinkQueue Q);               //销毁队列
void ClearQueue(LinkQueue S);                 //清空队列
bool QueueEmpty;                  //判空.空-TRUE

//GetHead(LinkQueue, int&e);                 //取队头元素
void EnQueue(LinkQueue&Q, int x)               //入队列
{
	LinkNode * newNode = (LinkNode*) malloc(sizeof(LinkNode));    //创建一个新结点
	newNode->data = x;
	newNode->next = Q.rear->next;
	Q.rear->next = newNode;
	
	Q.rear = newNode;
	Q.rear->next = nullptr ;
}
bool DeQueue(LinkQueue& Q, int &x)               //出队列
{
	if(Q.front == Q.rear)  return false ;   // 空队列返回false
	LinkNode* p = (LinkNode*) malloc(sizeof(LinkNode)) ;
	p = Q.front->next;
	x = p->data ; 							//x接受带回去的值
	Q.front->next = p->next ;              //让头结点重新指
	
	if(Q.rear==p)                        //此次删除的是最后一个结点
		Q.rear = Q.front;
	free(p) ;                            // 释放该结点
	return true;
}

int main()
{
	LinkQueue Q ; // 声明一个队列
	int x = 0 ;
	InitQueue(Q); //初始化队列
	
	EnQueue(Q,500) ;  // 入队
	EnQueue(Q,34) ;  // 入队
	EnQueue(Q,36) ;  // 入队
	EnQueue(Q,19) ;  // 入队
	EnQueue(Q,89) ;  // 入队
	
	while(DeQueue(Q,x) )     //当队列不为空一直出队
	{
		cout << "出队元素是" << x << endl;
	}
	
	return 0;
}
