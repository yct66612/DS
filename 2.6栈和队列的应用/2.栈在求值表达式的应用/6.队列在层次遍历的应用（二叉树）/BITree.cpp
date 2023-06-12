#include <iostream>
#include <queue>

using namespace std;

typedef struct BiTNode{
	int data;         				//数据域
	struct BiTNode *lchild,*rchild;	//左右孩子指针
}BiTNode,*BiTree;

void LevelOrder(BiTree T)
{
	if (T == nullptr)
		return;
	
	queue<BiTNode*> Q;       // 定义了一个初始队列
	Q.push(T);
	
	while (!Q.empty()) {
		BiTNode* current = Q.front();    //访问队列的front 也就是要出队的结点std::queue 的 front() 方法用于访问队列的头部元素，即队列中最早进入的元素，但不会移除该元素。
		cout << current->data << " ";
		
		if (current->lchild != nullptr)
			Q.push(current->lchild);
		if (current->rchild != nullptr)
			Q.push(current->rchild);
		
		Q.pop();
	}
}

int main()
{
	// 构建二叉树
	BiTNode* root = new BiTNode{1, nullptr, nullptr};
	BiTNode* node2 = new BiTNode{3, nullptr, nullptr};
	BiTNode* node3 = new BiTNode{4, nullptr, nullptr};
	BiTNode* node4 = new BiTNode{5, nullptr, nullptr};
	BiTNode* node5 = new BiTNode{8, nullptr, nullptr};
	BiTNode* node6 = new BiTNode{9, nullptr, nullptr};
	
	root->lchild = node2;
	root->rchild = node3;
	node2->lchild = node4;
	node2->rchild = node5;
	node3->rchild = node6;
	
	cout << "层序遍历: ";
	LevelOrder(root);
	cout << endl;
	
	return 0;
}

