/*Kruskal算法求最小生成树

给定一个 n个点 m条边的无向图，图中可能存在重边和自环，边权可能为负数。
求最小生成树的树边权重之和，如果最小生成树不存在则输出 impossible。
给定一张边带权的无向图 G=(V,E)，其中 V表示图中点的集合，E表示图中边的集合，n=|V|，m=|E|

由 V中的全部 n个顶点和 E中 n−1条边构成的无向连通子图被称为 G的一棵生成树，其中边的权值之和最小的生成树被称为无向图 G的最小生成树。

输入格式
第一行包含两个整数 n 和 m

接下来 m行，每行包含三个整数 u,v,w，表示点 u和点 v之间存在一条权值为 w的边。

输出格式
共一行，若存在最小生成树，则输出一个整数，表示最小生成树的树边权重之和，如果最小生成树不存在则输出 impossible。

数据范围
1≤n≤105
,
1≤m≤2∗105
,
图中涉及边的边权的绝对值均不超过 1000
。

输入样例：
4 5
1 2 1
1 3 2
1 4 3
2 3 2
3 4 4
输出样例：
6
*/

#include<iostream>
#include<algorithm>

using namespace std;

struct edge {
	int x, y, w;
	bool operator<(edge& e) const {
		return w < e.w;
	}
};

const int N = 2e5 + 10;
edge edges[N];
int p[N];
int n, m;

int find(int x) {
	if (x != p[x]) p[x] = find(p[x]);
	return p[x];
}

int Kruskal() {
	sort(edges, edges + m);
	int size = 0, len = 0;
	for (int i = 0; i < m; i++) {
		int x = edges[i].x, y = edges[i].y, w = edges[i].w;
		int px = find(x), py = find(y);
		if (px == py)continue;
		p[px] = py;
		size++;
		len += w;
		if (size == n - 1) break;
	}
	if (size == n - 1) return len;
	else return -1;
}
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) p[i] = i;
	for(int i=0;i<m;i++) {
		int x, y, w;
		cin >> x >> y >> w;
		edges[i] = { x,y,w };
	}
	int res = Kruskal();
	if (res == -1) cout << "impossible" << endl;
	else cout << res << endl;
}