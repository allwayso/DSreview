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

/*
### 测试用例 1：完全配对的复杂情况
输入字符串：[{ (a + b)* c } - d] / (e + f)
预计结果：配对成功(True)
附注：包含了所有三种括号，且层级嵌套关系正确，中间混有字母和算术运算符

### 测试用例 2：括号缺失与错位（不配对）
输入字符串：{ ([]) } )
预计结果：配对失败(False)
附注：虽然前面的嵌套是正确的，但末尾多出了一个无对应左括号的右括号 ')'

### 测试用例 3：混合非法字符与交叉错误
输入字符串：([{ }]) { [(] ) }
预计结果：配对失败(False)
*/


int main_BracketMatching() {
	getline(cin, str);
	if (solve()) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}

