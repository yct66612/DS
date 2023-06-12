#include <iostream>
#include <stack>
#include <sstream>

using namespace std;

stack<int> S;

bool isDigit(char c) {
	if (c >= '0' && c <= '9') {
		return true;
	}
	return false;
}

int evaluatePrefixExpression(string ch) {
	int i = ch.length() - 1;
	while (i >= 0) {
		if (isDigit(ch[i])) {
			int num = ch[i] - '0';
			S.push(num);
			cout << "将 " << num << " 入栈" << endl;
		} 
		else if (ch[i] == '+' || ch[i] == '-' || ch[i] == '*' || ch[i] == '/') {
			int oper1 = S.top();
			S.pop();
			cout << "右操作数为 " << oper1 << endl;
			
			int oper2 = S.top();
			S.pop();
			cout << "左操作数为 " << oper2 << endl;
			
			switch (ch[i]) {
			case '+':
				S.push(oper1 + oper2);
				cout << oper1 << " + " << oper2 << " = " << oper1 + oper2 << " 入栈" << endl;
				break;
			case '-':
				S.push(oper1 - oper2);
				cout << oper1 << " - " << oper2 << " = " << oper1 - oper2 << " 入栈" << endl;
				break;
			case '*':
				S.push(oper1 * oper2);
				cout << oper1 << " * " << oper2 << " = " << oper1 * oper2 << " 入栈" << endl;
				break;
			case '/':
				S.push(oper1 / oper2);
				cout << oper1 << " / " << oper2 << " = " << oper1 / oper2 << " 入栈" << endl;
				break;
			}
		}
		i--;
	}
	
	int sum = S.top();
	S.pop();
	cout << "最终结果 " << sum << " 出栈" << endl;
	
	return sum;
}

int main() {
	string prefixExpression = "-/*+56214";
	int result = evaluatePrefixExpression(prefixExpression);
	cout << "最终结果是 " << result << endl;
	
	return 0;
}

