/*以洛谷P1996为例
题目描述：
n 个人围成一圈，从第一个人开始报数,数到 m 的人出列，
再由下一个人重新从 1 开始报数，数到 m 的人再出圈，
依次类推，直到所有的人都出圈，
输出依次出圈人的编号。
*/

#include"queueModel.h"
#include<iostream>

using namespace std;

int main() {
	int n,m;
	cin >> n>>m;
	Queue<int>q;
	for (int i = 1; i <= n; i++) q.push(i);
	int count = 1;
	while (!q.empty()) {
		if (count == m) {
			cout << q.front()<<" ";
			q.pop();
			count = 1;
		}
		else {
			int temp = q.front();
			q.push(temp);
			q.pop();
			count++;
		}
	}
}

