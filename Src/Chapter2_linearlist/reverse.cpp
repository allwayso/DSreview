#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1e5 + 10;
int a[N];

//双指针法就地逆置
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int i = 0, j = n - 1;
	while (i < j) {
		swap(a[i], a[j]);
		i++, j--;
	}
	for (int i = 0; i < n; i++) {
		cout<< a[i]<<" ";
	}
}