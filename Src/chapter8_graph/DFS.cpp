#include<iostream>
#include<cstring>
#include<stack>

using namespace std;
const int N = 550;
bool g[N][N], st[N];
int n;


void dfs1(int x) {
	
	cout << x << " ";
	st[x] = true;
	for (int j = 0; j < n; j++) {
		if (g[x][j] && !st[j]) dfs1(j);
	}
	return;
}

void dfs2(int x) {
	memset(st, false, sizeof st);
	stack<int>s;
	s.push(x);
	while (s.size()) {
		int u = s.top();
		s.pop();
		if (!st[u]) {
			st[u] = true;
			cout << u << " ";
			for (int j = n - 1; j >= 0; j--) {
				if (!st[j] && g[u][j]) {
					s.push(j);
				}
			}
		}
		
	}
	
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> g[i][j];
		}
	}
	int x;
	cin >> x;
	memset(st, false, sizeof st);
	dfs1(x);
	cout << endl;
	dfs2(x);
}