#pragma once
#include<iostream>
#include<string>
#include<queue>
#include<algorithm>
#include<sstream>
using namespace std;

enum BuildMethod { INDEX_BASED, QUEUE_BASED };
enum TraverseMethod{Preorder,Inorder,Postorder};

void removeSpace(string& s) {
	s.erase(remove(s.begin(), s.end(), ' '), s.end());
}

struct Node {
	char name;
	Node* l,* r;
	Node(char x) :name(x), l(nullptr), r(nullptr) {}
};

//超全二叉链，包含四种建树，三种遍历
struct BLT {
	Node* root;
	BLT(const string& s,BuildMethod method) {//情形1：给定有#表示空结点的完全二叉树的层序遍历字符串
		if (method == INDEX_BASED) buildByIndex(s);
		else if (method == QUEUE_BASED) buildByQueue(s);
	}
	BLT(const string& level,const string& in) {//情形2：给定层序和中序遍历字符串
		root = buildByLevel_in(level, in);
	}
	BLT(int n) {
		string line;
		Node* nodes[300]={nullptr};
		bool first = true;
		char Root=0;
		while (n--) {
			getline(cin>>ws, line);
			istringstream ss(line);
			char x, left, right;
			ss >> x >> left >> right;
			if (first) {//默认以第一行为根节点信息
				Root = x;
				first = false;
			}
			if (nodes[x] == nullptr) nodes[x] = new Node(x);
			Node* p = nodes[x];
			if (left != '#'&&left!='0') {
				if (nodes[left] == nullptr) nodes[left] = new Node(left);
				p->l = nodes[left];
			}
			if (right != '#'&&right!='0') {
				if (nodes[right] == nullptr) nodes[right] = new Node(right);
				p->r = nodes[right];
			}
		}
		root = nodes[Root];
	}
	Node* buildByLevel_in(const string& Level, const string& In) {
		if (In.empty()) return nullptr;
		Node* p =new Node(Level[0]);
		int pos = In.find(p->name);
		string leftIn = In.substr(0, pos);
		string rightIn = In.substr(pos+1);
		string leftLevel = "", rightLevel = "";
		for (char c : Level) {
			if (leftIn.find(c) != string::npos) leftLevel += c;
			else if (rightIn.find(c) != string::npos) rightLevel += c;
		}
		p->l=buildByLevel_in(leftLevel, leftIn);
		p->r=buildByLevel_in(rightLevel, rightIn);
		return p;
	}
	void buildByIndex(const string& s) {
		int i = 0;
		int n = s.length();
		Node** temp = new Node * [n];//指针数组
		for (int i = 0; i < n; i++) {
			if (s[i] != '#') temp[i] = new Node(s[i]);
			else temp[i] = nullptr;
		}
		root = temp[0];
		for (int i = 0; i < n; i++) {
			if (i * 2 + 2 < n && temp[i] != nullptr) {
				temp[i]->l = temp[i * 2 + 1];
				temp[i]->r = temp[i * 2 + 2];
			}
		}
		delete[] temp;
	}
	void buildByQueue(const string& s){//方法二：基于队列遍历
		int i = 0;
		int n = s.length();
		queue<Node*>q;
		root = new Node(s[i++]);
		q.push(root);
		while (q.size() && i < n) {
			Node* cur = q.front();
			q.pop();
			if (i<n&&s[i] != '#') {
				Node* left = new Node(s[i]);
				cur->l = left;
				q.push(left);
			}
			i++;
			if (i<n&&s[i] != '#') {
				Node* right = new Node(s[i]);
				cur->r = right;
				q.push(right);
			}
			i++;
		}
	}
	void swap(Node* cur) {
		if (!cur) return;
		swap(cur->l);
		swap(cur->r);
		Node* temp = cur->l;
		cur->l = cur->r;
		cur->r = temp;
	}
	void print(TraverseMethod method) {
		if (method == Preorder) preorder(root);
		else if (method == Inorder) inorder(root);
		else if (method == Postorder) postorder(root);
	}
	void preorder(Node* cur) {
		if (cur == nullptr) return;
		cout << cur->name << " ";
		preorder(cur->l);
		preorder(cur->r);
	}
	void inorder(Node* cur) {
		if (cur == nullptr) return;
		inorder(cur->l);
		cout << cur->name << " ";
		inorder(cur->r);
	}
	void postorder(Node* cur) {
		if (cur == nullptr) return;
		postorder(cur->l);
		postorder(cur->r);
		cout << cur->name << " ";
	}
};

