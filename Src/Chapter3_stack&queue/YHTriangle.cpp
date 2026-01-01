#include<iostream>
#include<queue>
using namespace std;

int main() {
	int n;
	cin >> n;
	int prev = 0;//prev指当前结点的左上方结点的值
	queue<int>q;
	q.push(1);
	for (int i = 1; i <= n; i++) {
		prev = 0;//每层首结点左上方结点为0
		for (int j = 1; j <= i; j++) {
			int t = q.front();
			q.pop();
			cout << t << " ";
			q.push(t + prev);
			prev = t;
		}
		q.push(1);//下一行行尾为1
		cout << endl;
	}
}