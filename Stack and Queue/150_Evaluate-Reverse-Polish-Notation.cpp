/*
Title:
	150. Evaluate Reverse Polish Notation
	150. 逆波兰表达式求值
Address:
	https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/
*/


#include <iostream>
#include <vector>
#include <stack>
using namespace std;


// 方法一：栈
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if ( tokens.empty() )
            return 0;
            
        stack<int> S;

        for ( int i = 0; i < (int)tokens.size(); ++i ) {
            if ( tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/" ) {
                int val_1 = S.top(); S.pop();
                int val_2 = S.top(); S.pop();
                 
                if ( tokens[i] == "+" )
                    S.push( val_2 + val_1 );
                if ( tokens[i] == "-" )
                    S.push( val_2 - val_1 );
                if ( tokens[i] == "*" )
                    S.push( val_2 * val_1 );
                if ( tokens[i] == "/" )
                    S.push( val_2 / val_1 );
            }            
            else {
                S.push( atoi( tokens[i].c_str() ) );
            }
        }

        return S.top();
    }
};


int main()
{
	

	return 0;
}