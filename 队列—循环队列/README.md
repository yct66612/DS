## 循环队列

### 将顺序队列臆想改造为一个环形的空间（即把存储队列元素的表上视为一个环，称为循环队列）。

#### 有以下要点：

#### 循环队列的判空：

三种处理方法：这三种方法对应我的三个 `cpp`文件：

### Step1：牺牲一个单元来区分队满还是队空

------

对应代码如下：` Q.rear = (Q.rear + 1) % MaxSize;`

### Step2：类型中增设表示元素个数的数据成员

------



```
typedef struct {
	int data[MaxSize]; // 存放队列元素
	int front, rear;   // 队头指针和队尾指针
	int size;          // 队列当前元素个数
} SqQueue;
```

```
// 队列判空
bool QueueEmpty(SqQueue& Q) {
	return (Q.size == 0);
}

// 队列判满
bool QueueFull(SqQueue& Q) {
	return (Q.size == MaxSize);
}

```

### Step3: 类型中增设tag数据成员：

------

注意：插入操作不会导致队列空，删除操作也不会导致 队满。

```
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
```

