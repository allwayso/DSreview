#include<iostream>
using namespace std;

const int N = 1e5;
int a[N];
int n;

int binarySearch(int x) {
	int l = 0, r = n - 1;
	while (l <= r) {
		int mid = l + r >> 1;
		if (x == a[mid]) return mid;
		else if (x < a[mid])r = mid - 1;
		else l = mid + 1;
	}
	if (a[l] == x) return l;
	else return -1;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int t;
	cin >> t;
	while (t--) {
		int x;
		cin >> x;
		cout << binarySearch(x) << endl;
	}
}