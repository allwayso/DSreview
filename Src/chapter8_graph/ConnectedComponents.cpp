#include<iostream>
#include<queue>
#include<cstring>
#include<string>
using namespace std;

const int N = 1e5 + 10;

struct union_find_set {
	int parent[N];

	int find(int x) {
		if (x != parent[x]) parent[x] = find(parent[x]);
		return parent[x];
	}

	void unit(int x, int y) {
		int px = find(x);
		int py = find(y);
		if (px != py) parent[px] = py;
	}
	int solve() {
		int n, m;
		cin >> n >> m;
		for (int i = 0; i < n; i++) parent[i] = i;
		while (m--) {
			int a, b;
			cin >> a >> b;
			unit(a, b);
		}
		int res = 0;
		for (int i = 0; i < n; i++) {
			if (parent[i] == i) {
				res++;
			}
		}
		return  res;
	}
};

struct DFS {
	int e[N], h[N], ne[N], idx;
	bool st[N];

	void add(int a, int b) {
		e[idx] = b;
		ne[idx] = h[a];
		h[a] = idx++;
	}

	void dfs(int node) {
		st[node] = true;
		for (int i = h[node]; i != -1; i = ne[i]) {
			int j = e[i];
			if (!st[j]) dfs(j);
		}
	}
	int solve() {
		int n, m;
		cin >> n >> m;
		while (m--) {
			int a, b;
			cin >> a >> b;
			add(a, b);
			add(b, a);
		}
		int res = 0;
		for (int i = 0; i < n; i++) {
			if (!st[i]) {
				res++;
				dfs(i);
			}
		}
		return res;
	}
	DFS() {
		idx = 0; 
		memset(h, -1, sizeof h);
		memset(st, false, sizeof st);
		memset(e, 0, sizeof e);
		memset(ne, 0, sizeof ne);
	}
};


