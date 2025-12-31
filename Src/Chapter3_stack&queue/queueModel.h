#pragma once
#include<iostream>
const int N = 1e5 + 10;
using namespace std;

template <typename T>
struct Queue {
	int f,b;
	T q[N];
	void pop();
	void push(T t);
	T front();
	T back();
	bool empty();
	Queue() :f(0), b(0) {}
};

template <typename T>
bool Queue<T>::empty() {
	return f == b;
}

template <typename T>
T Queue<T>::back() {
	if (empty()) return T();
	else return q[f - 1];
}

template <typename T>
T Queue<T>::front() {
	if (empty()) return T();
	else return q[b];
}

template <typename T>
void Queue<T>::push(T t) {
	q[f++] = t;
}

template <typename T>
void Queue<T>::pop() {
	if (empty()) cerr<<"no element to be popped"<<endl;
	else b++;
}