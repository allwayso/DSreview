#include"BinaryLinkedTree.h"
#include<stack>

stack<Node*>s;
void solve(BLT& tree) {
	Node* cur = tree.root;
	while (cur || s.size()) {
		while (cur) {
			s.push(cur);
			cur = cur->l;
		}
		Node* mid = s.top();
		cout << mid->name << " ";
		s.pop();
		cur = mid->r;
	}
}
int main() {
	string s;
	getline(cin, s);
	BLT tree(s, INDEX_BASED);
	solve(tree);
}