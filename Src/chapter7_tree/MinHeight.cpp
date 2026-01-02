#include"BinaryLinkedTree.h"

int height = 0x3f3f3f3f;

void solve(Node* cur,int length) {
	if (!cur)return;
	if (!(cur->l) && !(cur->r)) {
		if (length < height)height = length;
	}
	solve(cur->l, length + 1);
	solve(cur->r, length + 1);
}
int main() {
	int n;
	cin >> n;
	BLT tree(n);
	solve(tree.root, 0);
	cout << height;
}