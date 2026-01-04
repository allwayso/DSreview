#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N = 110;
int g[N][N],d[N];
int n,m;
bool st[N];

int dijkstra(int s,int e) {
	memset(st, false, sizeof st);
	d[s] = 0;
	for (int i = 0; i < n-1; i++) {
		int t = -1;
		for (int j = 1; j <= n; j++) {
			if (!st[j] &&(t==-1|| d[j] < d[t])) t = j;
		}
		st[t] = true;
		for (int j = 1; j <= n; j++) {
			d[j] = min(d[j], d[t] + g[t][j]);
		}
	}
	if (d[e] == 0x3f3f3f3f) return -1;
	return d[e];
}
int main() {
	cin >> n>>m;
	memset(d, 0x3f, sizeof d);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> g[i][j];
			if (g[i][j]==0) g[i][j] = 0x3f3f3f3f;
		}
	}
	int s, t;
	cin >> s >> t;
	cout << dijkstra(s, t);
}