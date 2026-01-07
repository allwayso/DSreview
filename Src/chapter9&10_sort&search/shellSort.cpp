#include<iostream>
using namespace std;

const int N = 1e4 + 10;
int a[N];
int n;

void shellSort() {
	for (int gap = n / 2; gap > 0; gap /= 2) {
		for (int i = gap; i < n; i++) {
			int temp = a[i];
			int j;
			for (j = i; j >= gap&&a[j-gap]>temp; j -= gap) {
				a[j] = a[j - gap];
			}
			a[j] = temp;
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	shellSort();
	for (int i = 0; i < n; i++) {
		cout << a[i]<<" ";
	}
}