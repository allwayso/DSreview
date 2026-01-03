#include<queue>
#include<iostream>
#include<vector>
using namespace std;

priority_queue<int, vector<int>, greater<int>>q;
//此为简略版，仅计算最小带权路径，没有得到树的结构
int main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		q.push(x);
	}
	int res = 0;
	while (q.size() > 1) {
		int a = q.top();
		q.pop();
		int b = q.top();
		q.pop();
		res += a + b;
		q.push(a + b);//贪心：总是将最小的两堆合并
	}
	cout << res;
}