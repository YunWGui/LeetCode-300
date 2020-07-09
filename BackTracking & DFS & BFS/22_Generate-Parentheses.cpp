/*
Title:
    22. Generate Parentheses
    22. 括号生成
Address:
    https://leetcode-cn.com/problems/generate-parentheses/
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 方法一：回溯法
// https://mp.weixin.qq.com/s/XVnoX-lBzColVvVXNkGc5g
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;  // 记录所有合法的括号组合
        string track;  // 回溯过程中的路径

        if ( n == 0 )
            return res;
        
        backTrack( n, n, track, res );

        return res;        
    }

    // 可用的左括号数量为 leftPa 个、左括号数量为 rightPa 个
    void backTrack( int leftPa, int rightPa, string& track, vector<string>& res ) {
        if ( leftPa > rightPa )  // 左括号多于右括号，则不合法
            return;
        if ( leftPa < 0 || rightPa < 0 )  // 数量小于 0，则不合法
            return;
        if ( leftPa == 0 && rightPa == 0 ) {  // 当所有括号都恰好用完时，得到一个合法的括号组合
            res.push_back( track );
            return;
        }

        // 尝试放一个左括号
        track.push_back( '(' );  // 选择
        backTrack( leftPa - 1, rightPa, track, res );
        track.pop_back();  // 撤销

        // 尝试放一个右括号
        track.push_back( ')' );  // 选择
        backTrack( leftPa, rightPa - 1, track, res );
        track.pop_back();  // 撤销
    }
};

// 方法二：动态规划
class Solution_2 {
  public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> v(n + 1);
        v[0].push_back("");
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                for (string &str1 : v[j]) {
                    for (string &str2 : v[i - j - 1])
                        v[i].push_back("(" + str2 + ")" + str1);
                }
            }
        }
        return v[n];
    }
};


int main()
{
    int n { 3 };

    Solution solve;
    vector<string> res = solve.generateParenthesis( n );

    for ( string str : res ) 
        cout << str << " ";
    
    cout << endl;
    
    return 0;
}