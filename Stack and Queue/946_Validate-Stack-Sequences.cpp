/*
Title:
	946. Validate Stack Sequences
	946. 验证栈序列
Address:
	https://leetcode-cn.com/problems/validate-stack-sequences/
Tips:
	同 《剑指Offer》31 题
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 方法一：栈
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        if ( pushed.empty() || popped.empty() )
            return pushed.empty() && popped.empty();
        
        if ( pushed.size() != popped.size() )
            return false;
        
        int i = 0;
        stack<int> S;
        for ( int j = 0; j < pushed.size(); ++j ) {
            S.push( pushed[j] );
            while ( !S.empty() && i < popped.size() && S.top() == popped[i] ) {
                S.pop();
                ++i;
            }
        }

        return S.empty();
    }
};

int main()
{
	

	return 0;
}