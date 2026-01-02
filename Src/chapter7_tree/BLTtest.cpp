#include"BinaryLinkedTree.h"

/*int main() {
	string level, in;
	getline(cin >> ws, level);//去除两行输入中的空行
	getline(cin >> ws, in);
	removeSpace(level);
	removeSpace(in);
	BLT tree(level, in);
	cout << "Ineorder: ";
	tree.print(Inorder);
	cout << endl;
	cout << "Prerder: ";
	tree.print(Preorder);
	cout << endl;
	cout << "Postorder: ";
	tree.print(Postorder);
}
*/

int main() {
	int n;
	cin >> n;
	BLT tree(n);
	tree.print(Preorder);

}