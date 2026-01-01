#pragma once
#include <iostream>
using namespace std;
const int N = 1e5 + 10;

template <typename T>
struct Stack {
	T s[N];
	int idx;

	Stack() : idx(0) {}
	int size();
	bool empty();
	void push(T x);
	T top();
	void pop();
};

template <typename T>
bool Stack<T>::empty() {
	return idx <= 0;
}

template <typename T>
void Stack<T>::push(T x) {
	if (idx < N) {
		s[idx++] = x;
	}
}

template <typename T>
T Stack<T>::top() {
	if (!empty()) {
		return s[idx - 1];
	}
	else {
		std::cout << "empty stack" << std::endl;
		return T();
	}
}

template <typename T>
void Stack<T>::pop() {
	if (!empty()) {
		idx--;
	}
	else {
		std::cout << "empty stack" << std::endl;
	}
}

template <typename T>
int Stack<T>::size() {
	return idx;
}