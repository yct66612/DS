#include <iostream>
#include <stack>

using namespace std;

stack<string> S; // 声明一个存储string类型的栈

bool bracketCheck(string s[],int length)    //括号匹配算法
{
	//stack<string> s; // 声明一个存储string类型的栈
	
	for(int i=0;i<length ;i++){    
		if(s[i]=="{"|| s[i] == "[" || s[i] == "(" ) {
			S.push(s[i]) ;             //如果是左括号压入栈中
		}else{ 
			if(S.empty())  
			return false ;    //如果是右括号且栈空 //匹配失败
			
			string topelem ;   // 栈顶元素出栈
			topelem = S.top() ; //获取了栈顶元素在出栈（STL的特性）
			S.pop() ;           // 出栈
			if(s[i] == "(" && topelem!= ")" )
				return false ;
			if(s[i] == "[" && topelem!= "]" )
				return false ;
			if(s[i] == "{" && topelem!= "}" )
				return false ;
			
		}    
		
					
	}
	return S.empty() ;          //栈空说明匹配成功
} 
int main()
{
	string s[100] = {"{", "]", "[", ")"} ;
	
	int length = 5;
	
	if(bracketCheck(s,5))
		cout << "匹配成功" << endl;
	else
		cout << "匹配失败" << endl;
	return 0;
}
