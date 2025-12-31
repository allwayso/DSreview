#include"linkedlistModel.h"

int main() {
	linkedList list;
	int n,k;
	cin >> n>>k;
	if (k >= n) cerr << "no so much nodes" << endl;
	while (n--) {
		int x;
		cin >> x;
		list.insert_tail(x);
	}
	Node* fast = list.head;
	Node* slow = list.head;
	while (k--) {
		fast = fast->next;
	}
	while (fast) {
		fast = fast->next;
		slow = slow->next;
	}
	cout << slow->val;
}