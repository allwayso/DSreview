/*Prim算法求最小生成树 题目来源：https://www.acwing.com/problem/content/860/

给定一个 n个点 m条边的无向图，图中可能存在重边和自环，边权可能为负数。
求最小生成树的树边权重之和，如果最小生成树不存在则输出 impossible。
给定一张边带权的无向图 G=(V,E)，其中 V表示图中点的集合，E表示图中边的集合，n=|V|，m=|E|

由 V 中的全部 n个顶点和 E中 n−1条边构成的无向连通子图被称为 G的一棵生成树，其中边的权值之和最小的生成树被称为无向图 G的最小生成树。

输入格式
第一行包含两个整数 n和 m

接下来 m行，每行包含三个整数 u,v,w
，表示点 u和点 v之间存在一条权值为 w的边。

输出格式
共一行，若存在最小生成树，则输出一个整数，表示最小生成树的树边权重之和，如果最小生成树不存在则输出 impossible。

数据范围
1≤n≤500 1≤m≤105
图中涉及边的边权的绝对值均不超过 10000

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
#include<queue>
#include<cstring>

using namespace std;

typedef pair<int, int> PII;
priority_queue<PII, vector<PII>, greater<PII>> q;
const int N = 550;
vector<PII> g[N];
int parent[N];//记录最小生成树的结构,通过父子结点可以在g中查到权值
bool st[N];
int n, m;

int Prim() {
	q.push({ 0,1 });
	memset(st, false, sizeof st);
	int size = 0, len = 0;
	while (q.size()) {
		PII t = q.top();
		q.pop();
		int cur = t.second;
		int width = t.first;
		if (st[cur]) continue;
		st[cur] = true;
		size++;
		len += width;
		if (size == n) break;
		for (PII p : g[cur]) {
			int u = p.first;
			int w = p.second;
			if (!st[u]) {
				q.push({ w,u });
				parent[u] = cur;
		}
	}
	if (size == n) return len;
	else return 0x3f3f3f3f;
}
int main() {
	cin >> n >> m;
	while (m--) {
		int x, y, w;
		cin >> x >> y >> w;
		g[x].push_back({ y,w });
		g[y].push_back({ x,w });
	}
	int res = Prim();
	if (res == 0x3f3f3f3f) cout << "impossible" << endl;
	else cout << res << endl;
}