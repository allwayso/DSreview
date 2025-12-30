//问题描述：检查一个字符串表达式中的左括号与右括号是否正确配对

#include"stackModel.h"
#include<string>
using namespace std;

Stack<char> myS;
string str;

bool solve() {
	for (char c : str) {
		if (c == '(' || c == '[' || c == '{') {
			myS.push(c);
		}
		else if (c == ')' || c == ']' || c == '}') {
			if (myS.empty()) return false; // 多出右括号，必不配对
			char t = myS.top(); 
			if ((c == ')' && t == '(') ||
				(c == ']' && t == '[') ||
				(c == '}' && t == '{')) {
				myS.pop();
			}
			else {
				return false;
			}
		}
		else continue;
	}
	if (myS.empty()) {
		return true;
	}
	else return false;
}

int main() {
	getline(cin, str);
	if (solve()) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}

