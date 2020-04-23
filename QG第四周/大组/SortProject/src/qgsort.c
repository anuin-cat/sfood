#include<stdio.h>
#include<stdlib.h>
#include <assert.h>
#include"qgsort.h"


/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : 插入排序
 *  @param       : 数组指针 a, 数组长度 n
 */
void insertSort(int* a, int n) {
	for (int i = 0; i < n; i++) {
		int j = i;
		while ((j > 0) && a[j] < a[j - 1]) {
			a[j] = a[j] + a[j - 1];
			a[j - 1] = a[j] - a[j - 1];
			a[j] = a[j] - a[j - 1];
			j--;
		}
	}
};


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点begin，数组终点end，承载数组指针temp
 */
void MergeSort(int* a, int begin, int end, int* temp) {
	if (begin >= end)
		return;
	assert(a);
	//mid将数组二分
	int mid = begin + ((end - begin) >> 1);
	//左边归并排序,使得左子序列有序
	MergeSort(a, begin, mid, temp);
	//右边归并排序,使得右子序列有序
	MergeSort(a, mid + 1, end, temp);
	//将两个有序子数组合并
	_Merge(a, begin, mid, mid + 1, end, temp);
};


/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : 快速排序（递归版）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
void QuickSort_Recursion(int* a, int begin, int end) {
	if (begin < end) {
		int base = Partition1(a, begin, end);
		QuickSort_Recursion(a, begin, base - 1);
		QuickSort_Recursion(a, base + 1, end);
	}
};

int Partition1(int array[], int begin, int end) {
	int base = array[begin];
	while (begin < end) {
		while (begin < end && array[end] >= base) {
			end--;
		}
		Swap(array, begin, end);//array[low] = array[high];
		while (begin < end && array[begin] <= base) {
			begin++;
		}
		Swap(array, begin, end);//array[high] = array[low];
	}
	array[begin] = base;
	return begin;
}

void Swap(int arr[], int low, int high)
{
	if (low == high) {
		return;
	}
	int temp;
	temp = arr[low];
	arr[low] = arr[high];
	arr[high] = temp;
}

/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : 快速排序（非递归版）
 *  @param       : 数组指针a，数组长度size
 */
 //Quick2单独实现
void QuickSort(int* a, int size);


/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : 快速排序（枢轴存放）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */

void swap1(int* x, int* y)

{
	int temp = *x;
	*x = *y;
	*y = temp;
}

int Partition(int* a, int begin, int end) {
	if (begin < end)
	{
		int x = 0;
		int x1 = a[begin], x2 = a[end], x3 = a[(begin + end) >> 1];

		if (x1 <= x2 && x2 <= x3) {
			x = x2;
			swap1(&a[end], &a[begin]);
		}

		else if (x2 <= x1 && x1 <= x3) {
			x = x1;
			swap1(&a[begin], &a[begin]);
		}

		else {
			x = x3;
			swap1(&(a[(begin + end) / 2]), &a[begin]);
		}

		int i = begin, j = end;

		while (i < j)

		{

			while (i < j && a[j] >= x) // 从右向左找第一个小于x的数 
				j--;

			if (i < j)
				a[i++] = a[j];

			while (i < j && a[i] <= x) // 从左向右找第一个大于等于x的数
				i++;

			if (i < j)
				a[j--] = a[i];
		}

		a[i] = x;

		Partition(a, begin, i - 1); // 递归调用  
		Partition(a, i + 1, end);
	}
};


/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size，数组最大值max
 */
void CountSort(int* a, int size, int max) {
	int i;
	int minValue = a[0];
	int maxValue = a[0];
	int range = 0;
	int* tmp = NULL;
	int count = 0;
	for (i = 0; i < size; i++)//计算数据的分散空间
	{
		if (a[i] < minValue) {
			minValue = a[i];
		}
		if (a[i] > maxValue) {
			maxValue = a[i];
		}
	}
	range = maxValue - minValue + 1;
	tmp = (int*)malloc(sizeof(int) * range);//申请辅助空间
	if (tmp == NULL)
		return;
	memset(tmp, 0, sizeof(int) * range);//初始化


	for (i = 0; i < size; i++)//统计每个元素出现的次数
	{
		tmp[a[i] - minValue]++;
	}

	for (i = 0; i < range; i++)//通过统计tmp[];回收元素
	{
		while (tmp[i]--)
		{
			a[count++] = i + minValue;
		}
	}
	if (tmp != NULL)
		free(tmp);
};


/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
 */

 // 找到num的从低到高的第pos位的数据
int GetNumInPos(int num, int pos)
{
	int temp = 1;
	for (int i = 0; i < pos - 1; i++)
		temp *= 10;

	return (num / temp) % 10;
}

void RadixCountSort1(int* a, int size) {
	int k = 999;
	int p = 3;
	int* counts, * temp;
	int index, pval, i, j, n;

	/*为计数器数组分配空间*/
	if ((counts = (int*)malloc(k * sizeof(int))) == NULL)
		return -1;
	/*为已排序元素集分配空间*/
	if ((temp = (int*)malloc(size * sizeof(int))) == NULL)
		return -1;

	/*从元素的最低位到最高位开始排序*/
	for (n = 0; n < p; n++)
	{
		/*初始化计数器*/
		for (i = 0; i < k; i++)
			counts[i] = 0;
		/*计算位置值（幂运算k的n次方）*/
		pval = (int)pow((double)k, (double)n);

		/*统计当前位上每个数值出现的次数*/
		for (j = 0; j < size; j++)
		{
			index = (int)(a[j] / pval) % k;
			counts[index] = counts[index] + 1;
		}
		/*计算偏移量（本身的次数加上前一个元素次数）*/
		for (i = 1; i < k; i++)
			counts[i] = counts[i] + counts[i - 1];

		/*使用计数器放置元素位置*/
		for (j = size - 1; j >= 0; j--)
		{
			index = (int)(a[j] / pval) % k;
			temp[counts[index] - 1] = a[j];
			counts[index] = counts[index] - 1;
		}

		/*将已排序元素拷贝回data*/
		memcpy(a, temp, size * sizeof(int));

	}

	/*释放已排序空间*/
	free(counts);
	free(temp);
};

void RadixCountSort(int* a, int size)
{
	int* radixArrays[10];    //分别为0~9的序列空间
	for (int i = 0; i < 10; i++)
	{
		radixArrays[i] = (int*)malloc(sizeof(int) * (size + 1));
		radixArrays[i][0] = 0;    //index为0处记录这组数据的个数
	}

	for (int pos = 1; pos <= 3; pos++)    //从个位开始到3位
	{
		for (int i = 0; i < size; i++)    //分配过程
		{
			int num = GetNumInPos(a[i], pos);
			int index = ++radixArrays[num][0];
			radixArrays[num][index] = a[i];
		}

		for (int i = 0, j = 0; i < 10; i++)    //收集
		{
			for (int k = 1; k <= radixArrays[i][0]; k++)
				a[j++] = radixArrays[i][k];
			radixArrays[i][0] = 0;    //复位
		}
	}
}


/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
 */
void ColorSort(int* a, int size) {
	//创建三个指针
	int* head = a;
	int* tail = a + size - 1;
	int* mid = a + 1;

	//一层循环交换
	int temp;
	for (int i = 0; i < size; i++) {
		while (*mid != 1) {
			if (*mid == *head && *mid == 0 && mid == head) {
				mid++;
				head++;
			}
			else if (*mid == *tail && *mid == 2 && mid == tail)
			{
				mid++;
				tail--;
			}
			else if (*mid == 0) {
				temp = *head;
				*head = *mid;
				*mid = temp;
				head++;
			}
			else if (*mid == 2)
			{
				temp = *tail;
				*tail = *mid;
				*mid = temp;
				tail--;
			}
		}
		mid++;
		if (*mid == 2 && mid >= tail)
			break;
	}
};


/**
 *  @name        : 自拟
 *  @description : 在一个无序序列中找到第K大/小的数
 *  @param       : 数组指针a，数组长度size
 */
int KMax(int* a, int size, int k) {


	for (int i = 0; i < k; i++) {
		for (int j = i + 1; j < size; j++) {
			if (a[i] < a[j]) {
				swap1(a + i, a + j);
			}
		}
	}

	return a[k - 1];
}


/*
	辅助函数
*/
void _Merge(int* a, int begin1, int end1, int begin2, int end2, int* tmp)
{
	int index = begin1;
	int i = begin1, j = begin2;
	//注意:当划分的区间足够小时,begin1==end1,begin2==end2
	while (i <= end1 && j <= end2) {
		if (a[i] <= a[j])
			tmp[index++] = a[i++];
		else
			tmp[index++] = a[j++];
	}
	//将左边元素填充到tmp中
	while (i <= end1)
		tmp[index++] = a[i++];
	//将右边元素填充的tmp中
	while (j <= end2)
		tmp[index++] = a[j++];
	//将tmp中的数据拷贝到原数组对应的序列区间
	memcpy(a + begin1, tmp + begin1, sizeof(int) * (end2 - begin1 + 1));
}





/*
* 主体函数
*/




