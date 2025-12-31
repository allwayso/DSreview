/*以洛谷P1886为例

题目描述：
有一个长为 n 的序列 a，以及一个大小为 k 的窗口。现在这个窗口从左边开始向右滑动，
每次滑动一个单位，求出每次滑动后窗口中的最小值和最大值。

输入格式
输入一共有两行，第一行有两个正整数 n,k；
第二行有 n 个整数，表示序列 a。

输出格式
输出共两行，第一行为每次窗口滑动的最小值；
第二行为每次窗口滑动的最大值。*/

#include<deque>//懒得写双端队列了，直接用模板了
#include<vector>//存每个窗口最大最小值
#include<iostream>
using namespace std;
const int N = 1e6 + 10;
int a[N];
deque<int>Max, Min;//由于需要判断是否在窗口外，所以队列存的是索引
vector<int>v_max, v_min;
int n, k;

void slidingWindow() {
	for (int i = 1; i <= n; i++) {
		if (Max.size() && Max.front() < i - k + 1) Max.pop_front();
		while (Max.size() && a[Max.back()] <= a[i]) Max.pop_back();
		Max.push_back(i);
		if (i >= k)v_max.push_back(a[Max.front()]);

		if (Min.size() && Min.front() < i - k + 1) Min.pop_front();
		while (Min.size() && a[Min.back()] >= a[i]) Min.pop_back();
		Min.push_back(i);
		if (i >= k)v_min.push_back(a[Min.front()]);
	}
	for (int i : v_min) cout << i << " ";
	cout << endl;
	for (int i : v_max) cout << i << " ";
}

int main() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	slidingWindow();
}