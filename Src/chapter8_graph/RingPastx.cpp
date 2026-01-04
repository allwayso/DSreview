#include<iostream>
#include<algorithm>
#include<queue>
#include<cstring>
using namespace std;

const int N = 550;
bool g[N][N];
bool st[N];
int parent[N];
int n;

bool bfs(int x) {
	memset(st, false, sizeof st);
	queue<int>q;
	q.push(x);
	while (q.size()) {
		int u = q.front();
		st[u] = true;
		q.pop();
		for (int j = 0; j < n; j++) {
			if (g[u][j]) {
				if (j == x&&parent[u]!=x) return true;
				if (!st[j]) {
					q.push(j);
					parent[j] = u;
				}
			}
		}
	}
	return false;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> g[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		parent[i] = i;
	}
	int x;
	cin >> x;
	if (bfs(x)) cout << "TRUE";
	else cout << "FALSE";
}