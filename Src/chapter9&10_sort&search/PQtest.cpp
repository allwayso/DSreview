#include<iostream>
#include<queue>
using namespace std;

const int N = 1e5 + 10;
int a[N];
int n;

bool solve() {
	queue<int>q;
	q.push(a[0]);
	while (q.size()) {
		int t = q.front();
		q.pop();
		
	}
	return false;
}

bool solve2() {
	int idx = 0;
	while (idx < n) {
		int l = idx * 2 + 1;
		int r = idx * 2 + 2;
		if (l < n && a[idx] < a[l]) return false;
		if (r < n && a[idx] < a[r]) return false;
		idx++;
	}
	return true;
}
int main() {
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (solve2()) cout << "YES";
	else cout << "NO";
}