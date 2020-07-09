/*
Title:
	10. Regular Expression Matching
	10. 正则表达式匹配
Address:
	https://leetcode-cn.com/problems/regular-expression-matching/
Tips:
	同《剑指Offer》- 19
*/

#include <iostream>
#include <vector>
using namespace std;

// 方法一：动态规划
// https://www.acwing.com/solution/acwing/content/736/
class Solution {
public:
    vector<vector<int>> f;
    int n, m;

    bool isMatch( string s, string p ) {
        n = s.size();
        m = p.size();
        f = vector<vector<int>>( n + 1, vector<int>( m + 1, -1 ) );

        return dp( 0, 0, s, p );
    }

    bool dp( int x, int y, string& s, string& p ) {
        if ( f[x][y] != -1 )
            return f[x][y];
        if ( y == m )
            return f[x][y] = x == n;

        bool first_match = x < n && ( s[x] == p[y] || p[y] == '.' );
        bool res;

        if ( y + 1 < m && p[y + 1] == '*' )
            res = dp( x, y + 2, s, p ) || first_match && dp( x + 1, y, s, p );
        else
            res = first_match && dp( x + 1, y + 1, s, p );

        return f[x][y] = res;
    }
};

// 方法二：回溯法
class Solution_2 {
private:
    vector<vector<int> > nums;

    bool backTrack (string& s, int n, string& p, int m) {
        if (m == p.size()) return n == s.size() ? true : false;

        if (nums[n][m]) return false;

        bool flag = n != s.size() && (p[m] == s[n] || p[m] == '.');

        if (m + 1 < p.size() && p[m + 1] == '*')
            flag = backTrack(s, n, p, m + 2) ||            // 0
                   (flag && backTrack(s, n + 1, p, m));    // 1 or more
        else
            flag = flag && backTrack(s, n + 1, p, m + 1);  // next
        nums[n][m] = 1;
        return flag;
    }
public:
    bool isMatch (string s, string p) {
        nums.resize(s.size() + 1, vector<int>(p.size() + 1, 0));

        if (backTrack(s, 0, p, 0))  return true;

        return false;
    }
};

int main()
{


	return 0;
}
