/*
Title:
    547. Friend Circles
    547. 朋友圈
Address:
    https://leetcode-cn.com/problems/friend-circles/
*/

#include <iostream>
#include <vector>
using namespace std;

// 方法三：DFS



// 方法二：并查集
class Solution_2 {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int N = M.size();
        int count = N;  // 数组圈的总数
        vector<int> rank( N, 1 ), parent( N );
        for ( int i = 0; i < N; ++i )
            parent[i] = i;

        for ( int i = 0; i < N; ++i ) {
            for ( int j = i + 1; j < N; ++j ) {
                if ( M[i][j] == 1 ) {
                    int root_i = find( i, parent );
                    int root_j = find( j, parent );

                    if ( root_i == root_j )
                        continue;

                    if ( rank[root_i] < rank[root_j] ) {
                        parent[root_i] = root_j;
                        rank[root_j] += rank[root_i];
                    } else {
                        parent[root_j] = root_i;
                        rank[root_i] += rank[root_j];
                    }

                    --count;
                }
            }
        }

        return count;
    }

    int find( int x, vector<int>&parent ) {
        while( parent[x] != x ) {
            parent[x] = parent[ parent[x] ];
            x = parent[x];
        }

        return x;
    }
};


// 方法一：并查集
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int N = M.size();
        vector<int> rank ( N, 1 ), parent( N );
        int count = N;  // 朋友圈总数

        for ( int i = 0; i < N; ++i )
            parent[i] = i;

        for ( int i = 0; i < N; ++i ) {
            for ( int j = i + 1; j < N; ++j ) {
                if ( M[i][j] == 1 ) {
                    to_union( i, j, M, rank, parent, count );
                }
            }
        }

        return count;
    }

    void to_union( int i, int j, vector<vector<int>>& M, vector<int>& rank, vector<int>& parent, int& count ) {
        int root_i = find( i, parent );  // 节点 i 的根节点
        int root_j = find( j, parent );  // 节点 j 的根节点

        if ( root_i == root_j )
            return;

        if ( rank[root_i] > rank[root_j] ) {
            parent[root_j] = root_i;
            rank[root_i] += rank[root_j];
        } else { // rank[root_i] <= rank[root_j]
            parent[root_i] = root_j;
            rank[root_j] += rank[root_i];
        }
        --count;
    }

    int find( int x, vector<int>& parent ) {
        while ( parent[x] != x ) {
            parent[x] = parent[ parent[x] ];
            x = parent[x];
        }

        return x;
    }

};

int main()
{


	return 0;
}
