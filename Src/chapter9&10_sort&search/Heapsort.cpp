#include<iostream>
#include<queue>
#include<vector>
using namespace std;

priority_queue<int, vector<int>, greater<int>>q;
const int N = 1e4 + 10;
int a[N];
int n;

void heapify(int i,int size) {
	int l = i * 2 + 1;
	int r = i * 2 + 2;
	int big = i;
	if (l<size && a[l]>a[big]) big=l;
	if (r<size && a[r]>a[big]) big = r;
	if (big != i) {
		swap(a[i], a[big]);
		heapify(big,size);
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		q.push(a[i]);
	}
	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(i,n);
	}
	for (int i = n - 1; i > 0; i--) {
		swap(a[i], a[0]);
		heapify(0,i-1);
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	while (q.size()) {
		cout << q.top()<<" ";
		q.pop();
	}
}