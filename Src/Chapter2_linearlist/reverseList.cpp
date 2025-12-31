#include"linkedlistModel.h"

//原地逆置
int main() {
	linkedList l;
	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		l.insert(x);//由于头插法本身就逆置，又逆回去了
	}
	//三指针逆置
	Node* prev = nullptr;
	Node* cur = l.head;
	Node* next = nullptr;
	while (cur != nullptr) {
		next = cur->next;  
		cur->next = prev; 
		prev = cur;        
		cur = next;
	}
	l.head = prev;
	l.print();
}