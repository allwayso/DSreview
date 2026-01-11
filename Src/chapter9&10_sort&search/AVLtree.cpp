#include<iostream>
#include<algorithm>
using namespace std;

struct Node {
	int val;
	int height;
	Node* l, * r;
	Node(int x) :val(x), height(1), l(nullptr), r(nullptr) {}
	Node() :val(0), height(0), l(nullptr), r(nullptr) {}
};

int get_height(Node* p) {
	return p ? p->height : 0;
}
Node* insert(Node* root, int x) {
	if (!root) return new Node(x);
	if (root->val < x) root->r = insert(root->r, x);
	else if (root->val > x) root->l = insert(root->l, x);
	else return root;
	root->height = max(get_height(root->l), get_height(root->r)) + 1;
	//左旋/右旋逻辑
	return root;
}

Node* find_prev(Node* root, int x) {
	Node* prev = nullptr;
	Node* cur = root;
	while (cur && cur->val != x) {
		prev = cur;
		if (x > cur->val) cur = cur->r;
		else cur = cur->l;
	}
	if (!cur) return nullptr;
	return prev;
}

Node* remove(Node* root, int x) {
	Node* parent = nullptr;
	Node* target = root;
	while (target && target->val != x) {
		parent = target;
		if (target->val < x) target = target->r;
		else target = target->l;
	}
	if (!target) return root;
	if (target->l && target->r) {
		Node* prev = target, * cur = target->l;
		while (cur->r) {
			prev = cur;
			cur = cur->r;
		}
		target->val = cur->val;
		if (prev == target) prev->l = cur->l;
		else prev->r = cur->l;
		delete cur;
	}
	else if (target->l && !target->r) {
		if (target == root) root = root->l;
		else {
			if (parent->l == target) parent->l = target->l;
			else parent->r = target->l;
		}
		delete target;
	}
	else if (target->r && !target->l) {
		if (target == root) root = root->r;
		else {
			if (parent->l == target) parent->l = target->r;
			else parent->r = target->r;
		}
		delete target;
	}
	else {
		if (target == root) root = nullptr;
		else {
			if (parent->l == target) parent->l = nullptr;
			else parent->r = nullptr;
		}
		delete target;
	}
	return root;
}

Node* rr(Node* target) {//左旋
	Node* p = target->r;
	target->r = p->l;
	p->l = target;
	target->height = max(get_height(target->l), get_height(target->r)) + 1;
	p->height = max(get_height(p->l), get_height(p->r)) + 1;
	return p;
}

Node* ll(Node* target) {//右旋
	Node* p = target->l;
	target->l = p->r;
	p->r = target;
	target->height = max(get_height(target->l), get_height(target->r)) + 1;
	p->height = max(get_height(p->l), get_height(p->r)) + 1;
	return p;
}

Node* lr(Node* target) {//左子树右偏，先左旋后右旋
	target->l = rr(target->l);
	return ll(target);
}

Node* rl(Node* target) {//右子树左偏，先右旋后左旋
	target->r = ll(target->r);
	return rr(target);
}