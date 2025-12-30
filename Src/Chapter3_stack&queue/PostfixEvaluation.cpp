#include"stackModel.h"
#include<string>
#include<sstream>
#include<cctype>
using namespace std;

string str1;
Stack<int>nums;

//支持多位数和负数
int solve() {
	string c;
	istringstream ss(str1);
	while(ss>>c) {
		if (isdigit(c[0])||(c[0]=='-'&&isdigit(c[1]))) {
			nums.push(stoi(c));
		}
		else if (c == "+" || c == "-" || c == "*" || c == "/") {
			if (nums.size()<2) {
				cout << "wrong expression" << endl;
				return -1;
			}
			int r = nums.top();
			nums.pop();
			int l = nums.top();
			nums.pop();
			int res = 0;
			if (c == "+") res = l + r;
			else if (c == "-") res = l - r;
			else if (c == "*") res = l * r;
			else res = l / r;
			nums.push(res);
		}
		else {
			cout << "unexpected char: " << c << endl;
			return -1;
		}
	}
	if (nums.idx != 1) {
		cout << "wrong expression" << endl;
		return -1;
	}
	return nums.top();
}

int main() {
	getline(cin, str1);
	int res = solve();
	if (res != -1) cout << res << endl;
	return 0;
}