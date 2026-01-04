#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

const int N = 1010;
bool g[N][N];
bool st[N];
int n;

bool bfs(int a, int b) {
	if (a == b) return true;
	memset(st, false, sizeof st);
	queue<int>q;
	q.push(a);
	while (q.size()){
		int u = q.front();
		q.pop();
		st[u] = true;
		for (int j = 0; j < n; j++) {
			if (!st[j] && g[u][j]) {
				if (j == b) return true;
				q.push(j);
			}
		}
	}
	return st[b];
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> g[i][j];
		}
	}
	int a, b;
	cin >> a >> b;
	if (bfs(a,b)) cout << "TRUE" << endl;
	else cout << "FALSE" << endl;
}