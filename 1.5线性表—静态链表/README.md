## 静态链表

### 静态链表借助数组来描述线性表的链式存储结构，这里的指针是结点空间的相对地址（数组下标），又称游标。



------

这个插入操作的实现其实有一点麻烦，看看我的：

```
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

```

1. 首先，代码检查要插入的位置是否超出了静态链表的范围，如果是，则返回false表示插入失败。
2. 接下来，代码检查静态链表是否为空。如果为空，表示链表中还没有元素，可以直接将新元素插入到链表的首位置（即L[0].next），并将新元素的next设置为-1表示末尾节点。然后返回true表示插入成功。
3. 如果静态链表不为空，那么代码会遍历整个链表，找到最后一个节点。这是通过维护两个指针实现的：current和previous。current指向当前节点，而previous指向current的前一个节点。
4. 在遍历过程中，代码将current节点的下标赋给previous，并将current节点的next指向的下一个节点的下标赋给current。这样，当遍历结束时，previous就指向了最后一个节点。
5. 接下来，代码将最后一个节点的next指向要插入的位置，即将新元素插入到链表的末尾。然后将新元素的data设置为要插入的元素，next设置为-1表示末尾节点。
6. 最后，代码返回true表示插入成功。

需要注意的是，我没有对静态链表的容量进行动态扩展或回收，只是简单地将新元素插入到链表的末尾。如果静态链表已满或者存在删除操作，可能会导致插入失败或链表结构混乱。（懒得弄了）。

