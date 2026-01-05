#pragma once
#include<queue>
#include<iostream>
using namespace std;

struct Node {
	int val;
	Node* l,* r;
	Node(int x) :val(x), l(nullptr), r(nullptr) {}
};

struct BST {
	Node* root;

	void insert(int x) {
		if (!root) root = new Node(x);
		else {
			Node* newnode = new Node(x);
			Node* cur = root;
			Node* prev = nullptr;
			while (cur) {
				prev = cur;
				if (cur->val == x) return;
				else if (x > cur->val) cur = cur->r;
				else cur = cur->l;
			}
			if (x > prev->val) prev->r = newnode;
			else if (x < prev->val) prev->l = newnode;
		}
	}
	void find(int x) {
		if (!root) return;
		queue<int>path;
		Node* cur = root;
		while (cur) {
			path.push(cur->val);
			if (cur->val == x) break;
			else if (x > cur->val) cur = cur->r;
			else cur = cur->l;
		}
		if (!cur) cout << "fail to find :" <<x<< endl;
		else cout << "successfully find : "<<x<< endl;
		while (path.size()) {
			int t = path.front();
			cout << t<<" ";
			path.pop();
		}
		cout << endl;
	}
	void inorderTraverse(Node* root) {
		if (!root) return;
		inorderTraverse(root->l);
		cout << root->val << " ";
		inorderTraverse(root->r);
	}
	void findTargetAndParent(int x, Node*& target, Node*& parent) {
		target = nullptr;
		parent = nullptr;
		Node* cur = root;
		while (cur) {
			if (cur->val == x) {
				target = cur;
				break;
			}
			parent = cur; // 先记录父节点，再移动cur
			if (x > cur->val) cur = cur->r;
			else cur = cur->l;
		}
	}
	void remove(int x) {
		Node* parent = nullptr;
		Node* target = nullptr;
		findTargetAndParent(x, target, parent);
		if (!target) return; 
		if (target->l && target->r) {
			Node* p = target;
			Node* cur = target->l;
			while (cur->r) {
				p = cur;
				cur = cur->r;
			}
			target->val = cur->val;
			if (p->l == cur) p->l = cur->l;
			else p->r = cur->l;
			delete cur; 
			return; 
		}
		else if (target->l && !target->r) {
			if (target == root) {
				root = target->l;
			}
			else { 
				if (parent->l == target) parent->l = target->l;
				else parent->r = target->l;
			}
			delete target; 
		}
		else if (target->r && !target->l) {
			if (target == root) {
				root = target->r;
			}
			else { 
				if (parent->l == target) parent->l = target->r;
				else parent->r = target->r;
			}
			delete target; 
		}
		else {
			if (target == root) {
				root = nullptr;
			}
			else {
				if (parent->r == target) parent->r = nullptr;
				else parent->l = nullptr;
			}
			delete target; 
		}
	}
	BST() :root(nullptr) {}
};
