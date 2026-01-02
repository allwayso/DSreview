#include"BinaryLinkedTree.h"

int Width = 0;
int w[100];

void solve1(Node* cur,int level) {//方案1:先序遍历
	if (!cur) return ;
	w[level]++;
	if (w[level] > Width)Width = w[level];
	solve1(cur->l, level + 1);
	solve1(cur->r, level + 1);
}

int solve2(Node* Root) {//方案二：层序遍历
	queue<Node*>q;
	q.push(Root);
	int Max = 0;
	while (q.size()) {
		int n = q.size();
		if (n > Max) Max = n;
		for (int i = 0; i < n; i++) {
			Node* cur = q.front();
			q.pop();
			if (cur->l) q.push(cur->l);
			if (cur->r) q.push(cur->r);
		}
	}
	return Max;
}

int main() {
	string s;
	getline(cin, s);
	BLT tree(s,INDEX_BASED);
	cout<<solve2(tree.root);
	
}