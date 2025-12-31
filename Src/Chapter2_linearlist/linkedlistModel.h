#pragma once
#include<iostream>
using namespace std;

struct Node {
	int val;
	Node* next;
	Node(int x) :val(x), next(nullptr) {}
	Node() :val(0), next(nullptr) {}
};

//头插法链表
struct linkedList {
	Node* head,* tail;

	void insert(int val) {
		Node* newnode = new Node(val);
		if (tail == nullptr) tail = newnode;
		newnode->next = head;
		head = newnode;
	}

	void insert_tail(int val) {
		Node* newnode = new Node(val);
		if (head == nullptr) {
			head = newnode;
			tail = newnode;
		}
		else {
			tail->next = newnode;
			tail= newnode;
		}
	}

	void print() {
		Node* cur = head;
		while (cur != nullptr) {
			cout << cur->val << " ";
			cur = cur->next;
		}
	}

	void find_lastK(int k) {
		Node* fast = head;
		Node* slow = head;
		while (k&&fast!=nullptr) {
			fast = fast->next;
			k--;
		}
		if (k) cerr << "no enough nodes" << endl;
		while (fast) {
			fast = fast->next;
			slow = slow->next;
		}
		if (slow) {
			cout << slow->val << endl;
		}
	}
	void Delete(int val) {
		if (head == nullptr) {
			cerr << "empty list" << endl;
			return;
		}
		if (head->val == val) {
			Node* temp = head;
			head = head->next;
			if (head == nullptr) tail = nullptr;
			delete temp;
			return;
		}
		Node* cur = head;
		while (cur != nullptr && cur->next != nullptr) {
			if (cur->next->val == val) {
				Node* temp = cur->next;
				cur->next = cur->next->next;
				if (temp == tail) tail = cur;
				delete temp;
				return;
			}
			else cur = cur->next;
		}
		if (cur == nullptr) cerr << "no such node in the linkedlist" << endl;
	}
	linkedList() :head(nullptr),tail(nullptr) {}
};