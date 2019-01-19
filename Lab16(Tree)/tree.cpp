#include <iostream>

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
	void add(const T &elem) {
		add(root, elem);
	}
	void print() {
		print(root);
	}
private:
	void add(Node *&node, const T &elem);
	void print(Node *&node);
	void Delete(Node *node);
};
int main() {
	myTree<int> tree;
	int n, a;
	std::cout << "Count" << std::endl;
	std::cin >> n;
	std::cout << std::endl << "Elements" << std::endl;
	for (int i = 0; i < n; i++) {
		std::cin >> a;
		tree.add(a);
	}
	std::cout << std::endl << "Tree" << std::endl;
	tree.print();
	std::cout << '\n';
	system("pause");
	return 0;
}


template<typename T>
void myTree<T>::add(Node *& node, const T & item)
{
	if (node == NULL) { // элемент есть?
		node = new Node(item);
	}
	else if (item < node->item) { //если элемент меньше, то он сын
		add(node->son, item);
	}
	else {// иначе брат
		add(node->bro, item);
	}
}

template<typename T>
void myTree<T>::print(Node *& node)
{
	if (node != NULL) {// если элемент существует печатаем
		std::cout << node->item << '\t';
		if (node->bro != NULL) { // если есть братья, то печатаем братьев
			print(node->bro);
		}
		if (node->son != NULL) { // если есть сыновья, то печатаем сыновей на новой строке
			std::cout << std::endl;
			print(node->son);
		}
	}
}

template<typename T>
void myTree<T>::Delete(Node * node)
{
	if (node) {// если элемент есть удаляем
		Delete(node->son);
		Delete(node->bro);
		delete node;
	}
}
