/*
    91. Decode Ways
*/

#include <iostream>
#include <vector>
using namespace std;

// 方法二：动态规划
class Solution_2 {
public:
    int numDecodings(string s) {
        int i, j, len = s.size();

        if (s[0] == '0')
            return 0; //首字符为0直接返回0
        
        vector<int> dp(len + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (i = 1; i < len; i++) {
            j = (s[i - 1] - '0') * 10 + s[i] - '0'; //和前一个字符合起来的值
            if (s[i] > '0')
                dp[i + 1] = dp[i]; //此处不为0，继承前一项的方法数
            if (j > 9 && j <= 26)
                dp[i + 1] += dp[i - 1]; //如果和前面一项合起来在10~26之间，则再加上前两项的数
            if (dp[i + 1] == 0)
                return 0; //出现不合法直接返回0
        }
        return dp[len];
    }
};

// 方法一：动态规划
class Solution {
public:
    int numDecodings(string s) {
        if ( s[0] == '0' )  // 首字母为 0 
            return 0;
        
        int len = s.size();
        // vector<int> dp( len+1, 0 );
        int dp[len + 1];
        dp[0] = 1;
        dp[1] = 1;

        // 写法一：
        for ( int i = 2; i <= len; ++i ) {
            if ( s[i-1] == '0' ) 
                if ( s[i-2] == '1' || s[i-2] == '2' )  // 即 s[i-1]s[i] == 10 or 20
                    dp[i] = dp[i-2];  // 退「两格」
                else  // 其他情况，如: s[i-1]s[i] == 00, 30, 40...
                    return 0;
            else 
                if ( s[i-2] == '1' || ( s[i-2] == '2' && s[i-1] <= '6' ) )  // 11 ~ 19 and 21 ~ 26
                    dp[i] = dp[i-1] + dp[i-2];
                else   
                    dp[i] = dp[i-1];
        }

        // 写法二：
        for ( int i = 2; i <= len; ++i ) {
            string temp = s.substr( i-2, 2 );
            if ( temp[1] == '0' )
                if ( temp[0] == '1' || temp[0] == '2' )
                    dp[i] = dp[i-2];  // 退「两格」
                else  
                    return 0;  // 非法字符，如 00, 30, 40....
            else
                if ( "11" <= temp && temp <= "26" )
                    dp[i] = dp[i-1] + dp[i-2];
                else
                    dp[i] = dp[i-1];
        }

        return dp[len];
    }


};

int main()
{

    

    return 0;
}