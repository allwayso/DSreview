#include<iostream>
#include<queue>
#include<string>
#include<vector>
using namespace std;

struct Node {
	char name;
	int val;
	Node* l;
	Node* r;
	Node(char c, int i) :name(c), val(i), l(nullptr), r(nullptr) {}
};

struct cmp {
	bool operator()(Node* a, Node* b) {
		return a->val > b->val;
	}
};

vector<char> chars;//按顺序输出编码
vector<string> code;
priority_queue<Node*, vector<Node*>, cmp>q;
Node* root;
int n;

int Huffman() {//建树+求最小合并成本/最小带权路径
	int res = 0;
	while (q.size() > 1) {
		Node* a = q.top();
		q.pop();
		Node* b = q.top();
		q.pop();
		Node* parent=new Node('\0', a->val + b->val);
		res += a->val + b->val;
		parent->l = a;
		parent->r = b;
		q.push(parent);
	}
	root = q.top();
	return res;
}

void huffmanCode(Node* cur,string curcode) {//遍历Huffman树求编码
	if (!cur) return;
	if (!cur->l && !cur->r) {
		for (int i=0;i<n;i++) {
			if (chars[i] == cur->name) {
				code[i] = curcode;
				break;
			}
		}
		return;
	}
	huffmanCode(cur->l, curcode + "0");
	huffmanCode(cur->r, curcode + "1");
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		char c;
		int x;
		cin >> c >> x;
		chars.push_back(c);
		code.push_back("");
		Node* leaf = new Node(c, x);
		q.push(leaf);
	}
	Huffman();
	huffmanCode(root, "");
	for (string s : code) cout << s << " ";
}