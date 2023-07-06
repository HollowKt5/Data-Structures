////LinkedList
//#include<iostream>
//using namespace std;
//template<class T>
//struct linkedNode
//{
//	T data;
//	linkedNode<T>* link;
//	linkedNode(linkedNode<T>* p = NULL) { link = p; }
//	linkedNode(const T& e, linkedNode<T>* p = NULL) { data = e; link = p; }
//};
//
//template<class T>
//class list
//{
//protected:
//	linkedNode<T>* firstNode;//头指针
//public:
//	list() { firstNode = new linkedNode<T>; }//构造函数
//	list(const T& x) { firstNode = new linkedNode<T>(x); }//构造函数
//	list(list<T>& L);//复制构造函数
//	~list() { makeEmpty(); }//析构函数
//	void makeEmpty();//删除链表中元素
//	int Lenth();//返回链表长度
//	linkedNode<T>* getHead() { return firstNode; }//返回附加头指针的地址
//	linkedNode<T>* Search(T x);//查找元素x
//	linkedNode<T>* Locate(int i);//搜索第i个元素的地址
//	bool getData(int i, T& x);//取出第i个元素的值
//	void setData(int i, T& x);//改变第i个元素的值
//	bool Insert(int i, T& e);//在第i个节点后插入e
//	bool Remove(int i, T& e);//删除第i个元素并用e返回该元素值
//	bool isEmpty() { return firstNode->link == NULL ? true : false; }
//	bool isFull() { return false; }
//	//void sort();//排序
//	void inputFront(T endTag);//前插法建立链表
//	void inputRear(T endTag);//尾插法建立链表
//	void output();//输出
//	void reverse();
//	list<T>& operator = (list<T>& L);
//};
//
//template<class T>
//list<T>::list(list<T>& L)//复制构造函数
//{
//	T value;
//	linkedNode* p = L.firstNode;
//	linkedNode* s = firstNode = new linkedNode<T>;
//	while (p->link != NULL)
//	{
//		value = p->link->data;
//		s->link = new linkedNode<T>(value);
//		p = p->link;
//		s = s->link;
//	}
//	s->link = NULL;
//}
//
//template<class T>
//void list<T>::makeEmpty()
//{
//	linkedNode<T>* p = firstNode;
//	linkedNode<T>* mid = p->link;
//	while (mid != NULL)
//	{
//		mid = p->link;
//		delete p;
//		p = mid;
//	}
//	firstNode->link = NULL;
//	/*while (firstNode->link != NULL) //another way
//	{
//		p = firstNode->link;
//		firstNode->link = p->link;
//		delete p;
//	}*/
//}
//
//template<class T>
//int list<T>::Lenth()
//{
//	linkedNode<T>* n = firstNode->link;
//	int i;
//	while (n != NULL)
//	{
//		n = n->link;
//		++i;
//	}
//	return i;
//}
//
//template<class T>
//linkedNode<T>* list<T>::Search(T x)
//{
//	linkedNode<T>* n = firstNode->link;
//	while (n != NULL)
//	{
//		if (n->data == x)
//			return n;
//		n = n->link;
//	}
//	cout << "No exist";
//	return NULL;
//}
//
//template<class T>
//linkedNode<T>* list<T>::Locate(int i)
//{
//	if (i < 0)
//		return NULL;
//	linkedNode<T>* n = firstNode->link;
//	while (n != NULL)
//	{
//		if (i--<=0)
//			return n;
//		n = n->link;	
//	}
//	cout << "No exist";
//	return NULL;
//}
//
//template<class T>
//bool list<T>::getData(int i, T& x)
//{
//	if (i <= 0)
//		return false;
//	linkedNode<T>* p = Locate(i);
//	if (p == NULL)
//		return false;
//	else { x = p->data; return true; }
//}
//
//template<class T>
//void list<T>::setData(int i, T& x)
//{
//	if (i <= 0)return;
//	linkedNode<T>* p = Locate(i);
//	if (p == NULL)
//		return;
//	else { p->data = x; }
//}
//
//template<class T>
//bool list<T>::Insert(int i, T& e)
//{
//	linkedNode<T>* p = Locate(i);
//	if (p == NULL)return false;
//	linkedNode<T>* n = new linkedNode<T>;
//	if (n == NULL) {
//		cout << "error: allocate wrong space";
//		return false;
//	}
//	n->link = p->link;
//	p->link = n;
//	n->data = e;
//}
//
//template<class T>
//bool list<T>::Remove(int i, T& e)
//{
//	linkedNode<T>* p = Locate(i - 1);
//	if (p == NULL || p->link == NULL)return false;
//	linkedNode<T>* n = p->link;
//	p->link = n->link;
//	delete n;
//	return true;
//}
//
//template<class T>
//void list<T>::output()
//{
//	if (firstNode->link == NULL)
//		cout << "No data here"<<endl;
//	linkedNode<T>* p = firstNode->link;
//	while (p != NULL)
//	{
//		cout << p->data << " ";
//		p = p->link;
//	}
//	cout << endl;
//}
//
//template<class T>
//list<T>& list<T>::operator=(list<T>& L)
//{
//	T value;
//	linkedNode<T>* srcptr = L.getHead();//形参L的头指针是protected不能直接访问
//	linkedNode<T>* destptr = firstNode;
//	while (srcptr->link != NULL)
//	{
//		value = srcptr->data;
//		destptr->link = new linkedNode<T>(value);
//		destptr = destptr->link;
//		srcptr = srcptr->link;
//	}
//	destptr->link = NULL;
//	return *this;
//}
//
//template<class T>
//void list<T>::inputFront(T endTag)
////endTag是结束的标志
//{
//	linkedNode<T>* n;
//	T value;
//	makeEmpty();
//	cin >> value;
//	while(value != endTag)
//	{
//		n = new linkedNode<T>(value);
//		if (n == NULL)
//			cout << "allocate wrong space" << endl;
//		n->link = firstNode->link;
//		firstNode->link = n->link;
//		cin >> value;
//	}
//}
//
//template<class T>
//void list<T>::inputRear(T endTag)
//{
//	linkedNode<T>* n, * last;
//	T value;
//	makeEmpty();
//	cin >> value;
//	last = firstNode;
//	while (value != endTag)
//	{
//		n = new linkedNode<T>(value);
//		if (n == NULL)
//			cout << "allocate wrong space" << endl;
//		last->link = n;
//		last = n;
//		
//		cin >> value;
//	}
//	last->link = NULL;
//}
//
//template<class T>
//void list<T>::reverse()
//{
//	linkedNode<T> * m, * h;
//	m = firstNode->link->link;
//	firstNode->link->link = NULL;
//	while (m->link != NULL)
//	{
//		h = m->link;
//		m->link = firstNode->link;
//		firstNode->link = m;
//		m = h;
//	}
//	m->link = firstNode->link;
//	firstNode->link = m;
//}
//
//int main()
//{
//	list<int> l;
//	l.inputRear(9);
//	l.output();
//	l.reverse();
//	l.output();
//}

////Stack
////seqList
//#include<assert.h>
//#include<iostream>
//using namespace std;
//
//const int maxStack = 20;
//const int stackIncreament = 20;//栈溢出时拓展空间的增量
//template<class T>
//class seqStack
//{
//public:
//	seqStack(int sz = 50);
//	~seqStack() { delete[] elements; }
//	void push(T e);
//	bool pop(T& e);
//	bool getTop(T& x)const;//通过引用参数得到栈顶的值
//	bool isEmpty()const { return(top == -1) ? true : false; }
//	bool isFull()const { return (top == maxsize - 1) ? true : false; }
//	int getSize() const{return top + 1;}
//	void makeEmpty() { top = -1; }
//	template<class T> friend ostream& operator <<(ostream& os, seqStack<T>& s);//重载操作符输出栈中的元素
//private:
//	T* elements;
//	int top;
//	int maxsize;
//	void overflowProcess();
//};
//
//template<class T>
//seqStack<T>::seqStack(int sz) :top(-1), maxsize(sz)
//{
//	elements = new T[maxsize];
//	assert(elements != NULL);//利用断言机制若分配内存失败则终止程序
//}
//
//template<class T>
//void seqStack<T>::overflowProcess()
//{
//	T* newArray = new T[maxsize + stackIncreament];
//	if (newArray == NULL)
//	{
//		cout << "failed" << endl; exit(1);
//	}
//	for (int i = 0; i <= top; ++i)
//		newArray[i] = elements[i];
//	maxsize += stackIncreament;
//	delete[]elements;
//	elements = newArray;
//}
//
//template<class T>
//void seqStack<T>::push(T e)
//{
//	if (isFull())
//		overflowProcess();
//	elements[++top] = e;
//}
//
//template<class T>
//bool seqStack<T>::pop(T& e)
//{
//	if (isEmpty())return false;
//	e = elements[top--];
//	return true;
//}
//
//template<class T>
//bool seqStack<T>::getTop (T& x) const
//{
//	if (isEmpty()) return false;
//	x = elements[top];
//	return true;
//}
//
//template<class T>
//ostream& operator <<(ostream& os, seqStack<T>& s)
//{
//	os << "top=" << s.top << endl;
//	for (int i = 0; i <= s.top; ++i)
//		os << s.elements[i];
//	os << endl;
//	return os;
//}
//
//int main()
//{
//	seqStack<int> sq(20);
//	int a = 0;
//	sq.push(2);
//	sq.push(1);
//	sq.push(4);
//	sq.push(7);
//	sq.push(4);
//	sq.push(8);
//	sq.pop(a);
//	cout << "delete value:" << a << endl;
//	cout << sq;
//	return 0;
//}


