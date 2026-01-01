#include"linkedlistModel.h"

int n, m;
linkedList l1, l2,merged;

void merge() {
	Node* pt1, * pt2;
	pt1 = l1.head;
	pt2 = l2.head;
	while (pt1 && pt2) {
		int a = pt1->val, b = pt2->val;
		if (a >= b) {
			merged.insert_tail(b);
			pt2 = pt2->next;
		}
		else {
			merged.insert_tail(a);
			pt1 = pt1->next;
		}
	}
	while (pt1) {
		merged.insert_tail(pt1->val);
		pt1 = pt1->next;
	}
	while (pt2) {
		merged.insert_tail(pt2->val);
		pt2 = pt2->next;
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		l1.insert_tail(x);
	}
	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		l2.insert_tail(x);
	}
	merge();
	merged.print();
}