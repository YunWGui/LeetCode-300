## Disjoint Set - 并查集 模板

```cpp
#include <iostream>
#include <vector>
using namespace std;

/*
	1、用 parent 数组记录每个节点的父节点，相当于指向父节点的指针，所以 parent 数组内
	   实际存储着一个森林（若干棵多叉树）
	2、用 rank 数组记录着每棵树的重量，目的是让 union 后，树依然拥有平衡性，而不会退化
	   成链表，进而影响操作效率
	3、在 find_root 函数中进行「路径压缩」，保证任意树的高度保持在常数，使得 union 和 connected
	   API 时间复杂度为 O(1)
*/

class Union_Find {
private:
	int cnt;  // 连通分量的个数
	vector<int> parent;  // 存储一棵树
	vector<int> rank;  // 记录树的「重量」
public:
	// 构造函数，n 为图的「节点」总数
	Union_Find( int n ) : rank( vector<int>( n, 1 ) ), parent( vector<int>( n ) ) {
		cnt = n;
		for ( int i = 0; i < n; ++i )  // 父节点指针初始指向自身
			parent[i] = i;
	}

	void to_union( int p, int q ) {
		int rootP = find_root( p );
		int rootQ = find_root( q );

		if ( rootP == rootQ )  // 祖先节点相同
			return;

		// 小树接到大树下面，较平衡
		if ( rank[rootP] > rank[rootQ] ) {
			parent[rootQ] = rootP;  // rootQ 的父节点为（指向） rootP
			rank[rootP] += rank[rootQ];
		} else {
			parent[rootP] = rootQ;
			rank[rootQ] += rank[rootP];
		}
		
		--cnt;
	}

	// 两个节点是否连通 / 是否在同一集合
	// bool connected( int p, int q ) {
	bool is_same_set( int p, int q ) {
		int rootP = find_root( p );
		int rootQ = find_root( q );
		// 处于同一棵树上的节点，相互连通
		return rootP == rootQ;
	}

	// 返回节点 x 的根节点
	int find_root( int x ) {
		while ( parent[x] != x ) {
			parent[x] = parent[parent[x]];  // 路径压缩。避免极端情况下，退化为一条长链
			x = parent[x];
		}

		return x;
	}

	int count() {
		return cnt;
	}
};

int main()
{
	vector<vector<int>> edges = {  // 边数
		{ 0, 1 }, { 1, 2 }, { 1, 3 },
		{ 1, 4 }, { 3, 4 }, { 2, 5 }
	};

	int N = 6;  // 节点数

	Union_Find uf( N );

	for ( auto num : edges ) {
		uf.to_union( num[0], num[1] );
	}

	cout << uf.count() << endl;

	return 0;
}
```

## 参考

1. [Union-Find 并查集算法详解 - labuladong](https://mp.weixin.qq.com/s/gUwLfi25TYamq8AJVIopfA)
2. [并查集的C++实现及优化 - 简书](https://www.jianshu.com/p/fc17847b0a31)