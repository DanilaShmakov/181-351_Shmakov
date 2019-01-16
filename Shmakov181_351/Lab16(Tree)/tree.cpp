#include <iostream>
using namespace std;

template<typename T>
class myTree {
	struct Node {
		T item;
		Node *son;
		Node *bro;

		Node(T i, Node *s = NULL, Node *b = NULL) {
			item = i;
			son = s;
			bro = b;
		}
	};
	Node *root;
public:
	myTree() {
		root = NULL;
	}
	~myTree() {
		Delete(root);
	}
	int GetHeight() {
		return GetHeight(root);
	}
	int GetNodesOnLevel(int level) {
		return GetNodesOnLevel(root, level);
	}
	void add(const T &elem) {
		add(root, elem);
	}
	void print() {
		print(root);
	}
private:
	void add(Node *&node, const T &elem);
	void Delete(Node *node);
	int GetHeight(Node *node);
	int GetNodesOnLevel(Node *node, int level);
	void print(Node *&node);
};
int main() {
	myTree<int> tree;
	int n, a;
	cout << "Count" << std::endl;
	cin >> n;
	int *m = new int[n];
	cout << endl << "Elements" << endl;
	for (int i = 0; i < n; i++) {
		cin >> a;
		tree.add(a);
		m[i] = a;
	}
	cout << endl << "Tree" << endl;
	int t = 0;
	for (int i = 1; i < tree.GetHeight() + 1; i++) {
		for (int j = 0; j < tree.GetNodesOnLevel(i); j++) {
			cout << m[t] << '\t';
			t++;
		}
		std::cout << std::endl;
	}
	system("pause");
	return 0;
}
template<typename R>
R maximum(R *a, int len) {
	R max = a[0];
	for (int i = 1; i < len; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}
	return max;
}

template<typename T>
void myTree<T>::add(Node *& node, const T & item)
{
	if (node == NULL) {
		node = new Node(item);
	}
	else if (item < node->item) {
		add(node->son, item);
	}
	else {
		add(node->bro, item);
	}
}

template<typename T>
void myTree<T>::Delete(Node * node)
{
	if (node) {
		Delete(node->son);
		Delete(node->bro);
		delete node;
	}
}

template<typename T>
int myTree<T>::GetHeight(Node * node)
{
	if (node == NULL)
		return 0;
	int max = 0;
	for (Node *current = node->son; current; current = current->bro) {
		int curHeight = GetHeight(current);
		if (curHeight > max)
			max = curHeight;
	}
	return max + 1;
}

template<typename T>
int myTree<T>::GetNodesOnLevel(Node * node, int level)
{
	if (node == NULL)
		return 0;
	if (level <= 0)
		return 0;

	return GetNodesOnLevel(node->son, level - 1) +
		(level == 1) +
		GetNodesOnLevel(node->bro, level);
}

template<typename T>
void myTree<T>::print(Node *&node)
{
	for (int i = 1; i < GetHeight() + 1; i++) {
		for (int j = 0; j < GetNodesOnLevel(i); j++) {
			cout << node->bro;
		}
		cout << std::endl;
	}
}