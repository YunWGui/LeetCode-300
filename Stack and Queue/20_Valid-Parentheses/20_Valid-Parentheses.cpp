/*
Title:
    20. Valid Parentheses
    20. 有效括号
Address:
    https://leetcode-cn.com/problems/valid-parentheses/
*/


#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s){
        stack<char> stk;

        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
                if (stk.empty() || !isLegal(stk.top(), s[i]))
                    return false;
                stk.pop();
            }
            else
                stk.push(s[i]);
        }
        if (!stk.empty())
            return false;
        return true;
    }

    bool isLegal(const char& a, const char& b){
        if (a == '(' && b == ')')
            return true;
        if (a == '[' && b == ']')
            return true;
        if (a == '{' && b == '}')
            return true;
		return false;
    }
};



int main()
{
	// string str {"([}{])"};
	string str {"()"};
	Solution solve;

	cout << solve.isValid(str) << endl;

    return 0;
}
