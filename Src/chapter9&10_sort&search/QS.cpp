#include<iostream>
#include<algorithm>
using namespace std;

const int N = 1e4 + 10;
int a[N];
int n;

void quickSort(int l, int r) {
	if (l >= r) return;
	int i = l - 1, j = r + 1, x = a[l +r >> 1];
	while (i < j) {
		do i++; while (a[i] < x);
		do j--; while (a[j] > x);
		if (i < j) swap(a[i], a[j]);
	}
	quickSort(l, j);
	quickSort(j + 1, r);
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	quickSort(0, n - 1);
	for (int i = 0; i < n; i++) {
		cout<< a[i]<<" ";
	}
}