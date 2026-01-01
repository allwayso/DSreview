#include"stackModel.h"

int main() {
	int n, base;
	cin >> n >> base;
	Stack<int>s;
	if (n == 0) {
		cout << 0 << endl;
		return 0;
	}
	while (n) {
		s.push(n % base);
		n /= base;
	}
	if (base == 16) {
		while (!s.empty()) {
			int t=s.top();
			s.pop();
			if (t <= 9) cout << t ;
			else cout <<(char)('A' + t-10);
		}
	}
	else {
		while (!s.empty()) {
			int t = s.top();
			s.pop();
			cout << t ;
		}
	}
}

