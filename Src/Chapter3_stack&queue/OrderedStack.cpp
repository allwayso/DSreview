#include"stackModel.h"
#include<string>
using namespace std;

//递增栈实现
int main_OrderedStack() {
	Stack<int> myS;
	Stack<int>temp;
	int n;
	cin >> n;
	while (n--) {
		int x;
		cin >> x;
		if (myS.empty()) myS.push(x);
		else {
			while (!myS.empty()&&myS.top() < x) {
				temp.push(myS.top());
				myS.pop();
			}
			myS.push(x);
			while (!temp.empty()) {
				myS.push(temp.top());
				temp.pop();
			}
		}
	}
	for (int i = myS.idx-1; i >=0; i--) {
		cout << myS.s[i] << " ";
	}
	return 0;
}