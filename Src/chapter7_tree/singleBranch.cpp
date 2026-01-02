#include"BinaryLinkedTree.h"

int res;

void solve1(Node* p){//使用全局变量的递归做法
	if (!p) return;
	if ((p->l==nullptr) ^ (p->r==nullptr)) res++;
	solve1(p->l);
	solve1(p->r);
}

int solve2(Node* p) {//不使用全局变量的递归做法
	if (!p) return 0;
	int cur = ((p->l == nullptr) ^ (p->r == nullptr)) ? 1 : 0;
	return cur + solve2(p->l) + solve2(p->r);
}

int main() {
	string s;
	getline(cin, s);
	BLT tree(s, INDEX_BASED);
	cout<<solve2(tree.root);
}