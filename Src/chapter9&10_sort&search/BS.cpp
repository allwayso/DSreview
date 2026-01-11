#include<iostream>
using namespace std;

const int N = 1e4 + 10;
int a[N];

int main() {
	int n, k;
	cin >> n >> k;
	int l = 0, r = n - 1;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int count = 0;
	while (l < r) {
		int mid = l + r >> 1;
		if (a[mid] < k) l = mid + 1;
		else r = mid;
		count++;
	}
	cout << count;
}