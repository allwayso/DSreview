#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 1010;
bool g[N][N];
bool st[N];
int d[N],n;

void dijkstra(int u) {
	memset(d, 0x3f, sizeof d);
	memset(st,false,sizeof st);
	d[u] = 0;
	for (int i = 0; i < n - 1; i++) {
		int t = -1;
		for (int j = 0; j < n; j++) {
			if (!st[j] && (t == -1 || d[j] < d[t])) t = j;
		}
		if (t == -1) break;
		st[t] = true;
		for (int j = 0; j < n; j++) {
			if (g[t][j]) {
				d[j] = min(d[j], d[t] + 1);
			}
		}
	}
	int t = u;
	for (int i = 0; i < n; i++) {
		if (d[i]>d[t]&&d[i]!=0x3f3f3f3f) t = i;
	}
	if (d[t]==0) cout << -1 << endl;
	else {
		for (int i = 0; i < n; i++) {
			if (d[t] == d[i]) cout << i << " ";
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
	dijkstra(x);
}