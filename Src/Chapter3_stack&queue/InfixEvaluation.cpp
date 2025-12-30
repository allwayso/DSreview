#include"stackModel.h"
#include<string>
#include<cctype>
#include<sstream>
using namespace std;

//中缀表达式求值=中缀转后缀+后缀求值

int getPrio(char op) {
	if (op == '*' || op == '/') return 2;
	else if (op == '(') return 0;//注意此处'('的优先级应该为最低，否则其他运算符无法入栈
	else return 1;
}

string Infix2Postfix(string& s) {
	Stack<char>ops;
	string Postfix;
	istringstream ss(s);
	string c;
	while (ss >> c) {

		if (isdigit(c[0]) || isdigit(c[1])) Postfix += c + " ";
		else {
			char op = c[0];
			if (op == '(') ops.push(op);
			else if (op == ')') {
				while (ops.size() && ops.top() != '(') {
					Postfix += ops.top();
					Postfix += " ";
					ops.pop();
				}
				if (ops.size() && ops.top() == '(') ops.pop();
				else {
					cerr << "Wrong expression: no '(' match ')'" << endl;
					return "";
				}
			}
			else {
				while (ops.size() && getPrio(ops.top()) >= getPrio(op)) {
					Postfix += ops.top();
					Postfix += " ";
					ops.pop();
				}
				ops.push(op);
			}
		}
	}
	while (ops.size()) {
		Postfix += ops.top();
		Postfix += " ";
		ops.pop();
	}
	return Postfix;
}

int solve(string& str1) {
	Stack<int>nums;
	string c;
	istringstream ss(str1);
	while (ss >> c) {
		if (isdigit(c[0]) || (c[0] == '-' && isdigit(c[1]))) {
			nums.push(stoi(c));
		}
		else if (c == "+" || c == "-" || c == "*" || c == "/") {
			if (nums.size() < 2) {
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
	string infix;
	getline(cin, infix);
	string postfix = Infix2Postfix(infix);
	cout << solve(postfix);
}