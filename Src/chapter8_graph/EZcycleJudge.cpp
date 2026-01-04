#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

const int N = 1010;
int e[N], h[N], ne[N], idx;
int in[N];
bool st[N];
int n, m;

void add(int a, int b) {
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
    in[b]++;
}

//非常粗糙的回路判断：只对于root作为根节点的连通有向图成立
bool bfs(int root) {
    memset(st, false, sizeof st);
    queue<int>q;
    q.push(root);
    while (q.size()) {
        int t = q.front();
        q.pop();
        st[t] = true;
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            if (st[j]) return false;
            q.push(j);

        }
    }
    return true;
}

bool topology() {
    queue<int>q;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) {
            q.push(i);
            cnt++;
        }
    }
    while (q.size()) {
        int t = q.front();
        q.pop();
        for (int i = h[t]; i != -1; i = ne[i]) {
            int j = e[i];
            in[j]--;
            if (in[j] == 0) {
                q.push(j);
                cnt++;
            }
        }
    }
    if (cnt != n) return true;
    else return false;
}


int main() {
    memset(h, -1, sizeof h);
    cin >> n >> m;
    while (m--) {
        int x, y;
        cin >> x >> y;
        add(x, y);
    }
    if (topology()) cout << "Yes"<<endl;
    else cout << "No" << endl;
}
