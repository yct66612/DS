#include<iostream>
#include <stack>
#include <unordered_map>
using namespace std;

stack<char> S;  //运算符栈
unordered_map<char, int> precedence = {
	{'+', 1}, {'-', 1},
	{'*', 2}, {'/', 2},
	{'^', 3}
};
bool isDigit(char c)
{
	return (c >= '0' && c <= '9');
}
string infixToPostfix(string infix)   // 将中缀表达式转化为后缀表达式
{
	int i = 0 ;
	int length = infix.length();
	string postfix;                  //定义一个字符串来存储后缀表达式
	while(i <= length-1)
	{
		cout << "当前字符：" << infix[i] << endl;
		if(isDigit(infix[i])) {    //如果是数字那么写后面
				postfix += infix[i];
			postfix += ' '; // 添加空格分隔符以区分多位数字
			cout << "数字：" << postfix << endl;
		}
		else if(infix[i] == '(') {
			S.push(infix[i]);
			cout << "左括号入栈" << endl;
		}
		else if(infix[i] == ')' && !S.empty()) {
			while(!S.empty()&& S.top() != '('){    //一直出栈一直到下一个‘(’
				postfix += S.top();    // 加入到后缀表达式当中
				S.pop();              //出栈
			}
			S.pop();         // 将这个括号也弹出栈了
			cout << "右括号处理完毕" << endl;
		}
		else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/') {
			while (!S.empty() && S.top() != '(' && precedence[S.top()] >= precedence[infix[i]]) {
				postfix += S.top();
				S.pop();
			}
			S.push(infix[i]);
			cout << "运算符：" << infix[i] << " 入栈" << endl;
		}

		i++;
	}
	while (!S.empty()) {
		postfix += S.top();
		S.pop();
	}
	return postfix;
}

int main()
{
	string infixExpression = "(5+6)2-4";
	string postfixExpression = infixToPostfix(infixExpression);
	
	cout << "转化后的后缀表达式为：" << postfixExpression << endl;
	return 0;
}

