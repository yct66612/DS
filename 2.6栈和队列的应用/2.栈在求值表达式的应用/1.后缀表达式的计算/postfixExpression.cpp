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


int evaluatePostfixExpression(string ch) {
	istringstream iss(ch);
	string token;
	while (iss >> token) {
		if (isDigit(token[0])) {
			int num = stoi(token);
			S.push(num);
			cout << "将 " << num << " 入栈" << endl;
		} else if (token == "+" || token == "-" || token == "*" || token == "/") {
			int operand2 = S.top();
			S.pop();
			cout << "右操作数为 " << operand2 << endl;
			
			int operand1 = S.top();
			S.pop();
			cout << "左操作数为 " << operand1 << endl;
			
			switch (token[0]) {
			case '+':
				S.push(operand1 + operand2);
				cout << operand1 << " + " << operand2 << " = " << operand1 + operand2 << " 入栈" << endl;
				break;
			case '-':
				S.push(operand1 - operand2);
				cout << operand1 << " - " << operand2 << " = " << operand1 - operand2 << " 入栈" << endl;
				break;
			case '*':
				S.push(operand1 * operand2);
				cout << operand1 << " * " << operand2 << " = " << operand1 * operand2 << " 入栈" << endl;
				break;
			case '/':
				S.push(operand1 / operand2);
				cout << operand1 << " / " << operand2 << " = " << operand1 / operand2 << " 入栈" << endl;
				break;
			}
		}
	}
	
	int sum = S.top();
	S.pop();
	cout << "最终结果 " << sum << " 出栈" << endl;
	
	return sum;
}

int main() {
	string postfixExpression = "5 6 2 + * 12 4 / -";
	int result = evaluatePostfixExpression(postfixExpression);
	cout << "最终结果是 " << result << endl;
	return 0;
}

