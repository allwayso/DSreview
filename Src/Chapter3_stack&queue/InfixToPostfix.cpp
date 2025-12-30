#include"stackModel.h"
#include<string>
#include<sstream>
#include<cctype>
using namespace std;

//运算优先级辅助函数
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

int main() {
	string infix;
	getline(cin, infix);
	string postfix = Infix2Postfix(infix);
	cout << postfix;
	return 0;
}