#include"BST.h"

int main() {
	int n;
	cin >> n;
	BST tree;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		tree.insert(x);
	}
	cout << "inorder traverse result :" << endl;
	tree.inorderTraverse(tree.root);
	cout << endl;
	int t;
	cin >> t;
	while (t--) {
		int x;
		cin >> x;
		tree.remove(x);
		cout << "inorder traverse result :" << endl;
		tree.inorderTraverse(tree.root);
		cout << endl;
	}
}