### Quick Sort

> 快速排序

```cpp
class QSort {
public:
    void quickSort( vector<int>& nums, int low, int high ) {  // [low, high)
        if ( high - low < 2 )  // 单元素区间自然有序
            return;
        
        int mid = partition( nums, low, high - 1 );  // 在 [low, high] 内构造轴点
        
        quickSort( nums, low, mid );  // 对「前缀」递归排序
        quickSort( nums, mid + 1, high );  // 对「后缀」递归排序
    }

    int partition( vector<int>& nums, int low ,int high ) {  // [low, high]
	swap( nums[low], nums[low + rand() % (high - low + 1)]);  // 任选一个元素与首元素交换
	int pivot = nums[low];  // 以首元素为候选轴点 —— 经以上交换，等效于随机选取

	while ( low < high ) {  // 从向量两端向中间扫描
		while ( ( low < high ) && ( pivot <= nums[high] ) )  // 在不小于 pivot 的前提下
			--high;  // 向左拓展右端子向量
		nums[low] = nums[high];  // 小于 pivot 者归入左端子序列

		while ( ( low < high ) && ( nums[low] <= pivot ) )  // 在不大于 pivot 的前提下
			++low;  // 向右拓展左端子向量
		nums[high] = nums[low];  // 大于 pivot 者归入右侧子序列
	}
	nums[low] = pivot;  // 将备份的轴点记录置于前、后子向量之间
	
	return low;  // 返回轴点的秩
    }
};
```

