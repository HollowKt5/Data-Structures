//linkedBinaryTree
#include<iostream>
#include<assert.h>
#include<stdlib.h>
#define stackSize 20
using namespace std;
template<class T>
struct BTNode
{
	T data;
	typedef BTNode<T>* pointer;
	pointer left, right;
	BTNode() :left(NULL), right(NULL) {}
	BTNode(T e, pointer l = NULL, pointer r = NULL)
		:data(e), left(l), right(r) {}
};

template<class T>
class BinaryTree
{
public:
	BinaryTree() :root(NULL) {}
	BinaryTree(T value) :RefValue(value), root(NULL) {}
	BinaryTree(BinaryTree<T>& s);//���ƹ��캯��
	~BinaryTree() { destory(root); }
	bool IsEmpty() { return root == NULL; }
	BTNode<T>* Parent(BTNode<T>* current)
	{
		if (root == NULL || root == current) return NULL;
		else return Parent(root, current);//���ظ��ڵ�
	}
	int Height() { return Height(root); }
	int Size() { return Size(root); }
	BTNode<T>* getRoot() { return root; }
	void setRoot(BTNode<T>* p) { root = p; }
	BTNode<T>* Search(T item) { return Search(root, item); }
	int Insert(T item) { return Insert(root, item); }
	void createBinTree(T in[]) { createBinTree(in, root); }
	void printBinTree() { printBinTree(root); }//�ù�������������
	void Traverse() { Traverse(root, 1); }//�ð�������������
	void createBinTree_pre(T pre[])
	{
		int i = 0;
		 creatBinTree_pre(pre, root, i);
	}
	void PreOrder() { PreOrder(root); }
	void InOrder() { InOrder(root); }
	void PostOrder() { PostOrder(root); }
	void LevelOrder();
	//void PreOrder_iter();//�ǵݹ�ǰ�����
	//void InOrder_iter();
	//void PostOrder_iter();
	friend bool operator ==(BTNode<T>& s, BTNode<T>& t);

protected:
	BTNode<T>* root;
	T RefValue;//����ֹͣ�����־
	void destory(BTNode<T>*& subTree);//��������
	void createBinTree(T in[], BTNode<T>*& subTree);//�������������
	void creatBinTree_pre(T pre[], BTNode<T>*& subTree, int& n);
	BTNode<T>* Parent(BTNode<T>* subTree, BTNode<T>* current);
	BTNode<T>* Search(BTNode<T>* p, T item);
	BTNode<T>* Copy(BTNode<T>* orignode);
	int Insert(BTNode<T>*& subTree, T item);
	int Height(BTNode<T>* subTree);
	int Size(BTNode<T>* subTree);
	void Traverse(BTNode<T>* subTree, int k);
	void PreOrder(BTNode<T>* p);
	void InOrder(BTNode<T>* p);
	void PostOrder(BTNode<T>* p);
	bool equal(BTNode<T>* a, BTNode<T>* b);
};

template<class T>
void BinaryTree<T>::destory(BTNode<T>*& subTree)
{
	if (subTree != NULL)
	{
		destory(subTree->left);
		destory(subTree->right);
		delete subTree;//�������,���Ա�֤��ɾ��ڵ���ɾ�ҽڵ���󸸽ڵ�
		subTree = NULL;
	}
}

template<class T>
BTNode<T>* BinaryTree<T>::Parent(BTNode<T>* subTree, BTNode<T>* current)
{//��subTree�����ҵ�current�ĸ��ڵ�
	if (subTree == NULL)
		return NULL;
	if (subTree == current)
		return NULL;
	if (subTree->left == current || subTree->right == current)
		return subTree;
	BTNode<T>* p;
	if ((p = Parent(subTree->left, current)) != NULL)
		return p;
	else return Parent(subTree->right, current);
}

template<class T>
void BinaryTree<T>::Traverse(BTNode<T>* subTree, int k)
//k�ǲ�Σ�����k=1�㣩
{//�����������
	for (int i = 0; i < 5 * (k - 1); i++)
		cout << " ";
	if (subTree != NULL)
	{
		cout << subTree->data << endl;
		Traverse(subTree->left, k + 1);
		Traverse(subTree->right, k + 1);
	}//ǰ�����
	else cout << "#" << endl;
}

template<class T>
void BinaryTree<T>::createBinTree(T in[], BTNode<T>*& subTree)
{//�����ʽΪ:A(B(D,E(G,)),(C,F))#�Ĺ������������ָ��ΪsubTree�Ķ�������ָ��
	BTNode<T>* s[stackSize];//��Ƕջ
	int top = -1;
	BTNode<char>* p, * t;
	int k = 0, flag;
	char ch;
	subTree = NULL;
	ch = in[k++];
	while (ch != '#')
	{
		switch (ch)
		{
		case'(':s[++top] = p;//���ڵ���ջ
			flag = 1; break;
		case')':--top; break;
		case',':flag = 2; break;
		default:p = new BTNode<T>(ch);
			if (subTree == NULL)subTree = p;//Initialize
			else {
				t = s[top];
				if (flag == 1)
					t->left = p;
				else t->right = p;
			}
		}
		ch = in[k++];
	}
}

template<class T>
void BinaryTree<T>::creatBinTree_pre(T pre[], BTNode<T>*& subTree, int& n)
//��ʽ:ÿ���ڵ���������Ҷ�ӽڵ�(leaf)'#'�����ʽΪǰ��
//eg,AB#CD####
{
	T ch = pre[n++];
	if (ch == ';')
		return;
	if (ch != '#')
	{
		subTree = new BTNode<T>(ch);
		creatBinTree_pre(pre, subTree->left, n);
		creatBinTree_pre(pre, subTree->right, n);
	}
	else subTree = NULL;
}

template<class T>
int BinaryTree<T>::Height(BTNode<T>* subTree)
{
	if (subTree == NULL)
		return 0;
	int k = 1, j = 1;
		k = k + Height(subTree->left);
		j = j + Height(subTree->right);
		return(k > j) ?  k : j;
}

template<class T>
int BinaryTree<T>::Size(BTNode<T>* subTree)
{
	int k = 0;
	if (subTree != NULL)
	{
		++k;
		k = k + Size(subTree->left);
		k = k + Size(subTree->right);
	}
	return k;
}

template<class T>
void BinaryTree<T>::PreOrder(BTNode<T>* p)
{
	if (p != NULL)
	{
		cout << p->data << " ";
		PreOrder(p->left);
		PreOrder(p->right);
	}
}

template<class T>
void BinaryTree<T>::InOrder(BTNode<T>* p)
{
	if (p != NULL)
	{
		InOrder(p->left);
		cout << p->data << " ";
		InOrder(p->right);
	}
}

template<class T>
void BinaryTree<T>::PostOrder(BTNode<T>* p)
{
	if (p != NULL)
	{
		PostOrder(p->left);
		PostOrder(p->right);
		cout << p->data << " ";
	}
}

template<class T>
void BinaryTree<T>::LevelOrder()
{
	int s = 8;//Height()*2;
	BTNode<T>** x = new BTNode<T>*[s];
	BTNode<T>* y;
	x[0] = root;
	int p = 1, i = 1, k = 0;
	while (p > 0)
	{
		y = x[k];
		x[k++] = NULL;
		cout << y->data<<" ";
		--p;		
		if (y->left != NULL)
		{
			x[i++] = y->left; ++p;
		}
		if (y->right != NULL)
		{
			x[i++] = y->right; ++p;
		}
	}
	delete[] x;
}
int main()
{
	int n;
	BinaryTree<char> b;
	cin >> n;
	char* a = new char[n];
	for (int i = 0; i < n; ++i)
	{
		cout << "input ["<<i<<"]:";
		cin >> a[i];
	}
	b.createBinTree_pre(a);
	b.InOrder();
	cout << endl;
	b.LevelOrder();
	cout << endl;
	cout<<b.Size()<<endl;
	cout << b.Height() << endl;
	delete[] a;
	return 0;
}