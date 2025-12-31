#include<iostream>
#include<cstring>
using namespace std;

const int N = 1e5 + 10;
int a[N],st[N];

//去掉重复元素:计数
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		st[a[i]]++;
		if (st[a[i]] >= 2) continue;
		cout << a[i] << " ";
	}
}
