#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

unordered_map<char, int> precedence = {
	{'+', 1}, {'-', 1},
	{'*', 2}, {'/', 2},
	{'^', 3}
};
stack<int> S1;    // 操作数栈
stack<char> S2;    // 运算符栈

bool isDigit(char c) {    // 判断是不是字符数字
	return (c >= '0' && c <= '9');
}

int performOperation(char op, int operand1, int operand2) {
	switch (op) {
	case '+':
		return operand1 + operand2;
	case '-':
		return operand1 - operand2;
	case '*':
		return operand1 * operand2;
	case '/':
		return operand1 / operand2;
		// 添加其他运算符的处理
	}
	return 0;  // 运算符无效
}

int evaluateInfix(const string& infix) {
	int i = 0;
	int length = infix.length();
	while (i < length) {
		if (isDigit(infix[i])) {    // 如果是数字，将整个数字解析并入数字栈
			int number = 0;
			while (i < length && isDigit(infix[i])) {
				number = number * 10 + (infix[i] - '0');
				i++;
			}
			S1.push(number);
		} else if (infix[i] == '(') {    // 左括号直接入符号栈
			S2.push(infix[i]);
			i++;
		} else if (infix[i] == ')') {    // 右括号，进行运算直到遇到左括号
			while (!S2.empty() && S2.top() != '(') {
				char op = S2.top();
				S2.pop();
				
				int operand2 = S1.top();
				S1.pop();
				int operand1 = S1.top();
				S1.pop();
				
				int result = performOperation(op, operand1, operand2);
				S1.push(result);
			}
			
			if (!S2.empty() && S2.top() == '(') {
				S2.pop();    // 弹出左括号
			}
			i++;
		} else if (precedence.find(infix[i]) != precedence.end()) {    // 运算符
			while (!S2.empty() && precedence[S2.top()] >= precedence[infix[i]]) {
				char op = S2.top();
				S2.pop();
				
				int operand2 = S1.top();
				S1.pop();
				int operand1 = S1.top();
				S1.pop();
				
				int result = performOperation(op, operand1, operand2);
				S1.push(result);
			}
			
			S2.push(infix[i]);
			i++;
		} else {
			i++;
		}
	}
	
	while (!S2.empty()) {    // 处理剩余的运算符
		char op = S2.top();
		S2.pop();
		
		int operand2 = S1.top();
		S1.pop();
		int operand1 = S1.top();
		S1.pop();
		
		int result = performOperation(op, operand1, operand2);
		S1.push(result);
	}
	
	return S1.top();    // 返回最终结果
}

int main() {
	string infixExpression = "(5+6)*2-4";
	int result = evaluateInfix(infixExpression);
	
	cout << "中缀表达式的计算结果为：" << result << endl;
	return 0;
}

