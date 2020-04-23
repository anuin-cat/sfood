
#ifndef SORT_H_INCLUDED
#define SORT_H_INCLUDED

/**
 *  @name        : void insertSort(int *a,int n);
 *  @description : 插入排序
 *  @param       : 数组指针 a, 数组长度 n
 */
void insertSort(int* a, int n);


/**
 *  @name        : void MergeArray(int *a,int begin,int mid,int end,int *temp);
 *  @description : 归并排序
 *  @param       : 数组指针a，数组起点begin，数组中点mid，数组终点end，承载数组指针temp
 */
void MergeSort(int* a, int begin, int end, int* temp);

/**
 *  @name        : void QuickSort(int *a, int begin, int end);
 *  @description : 快速排序（递归版）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
void QuickSort_Recursion(int* a, int begin, int end);
int Partition1(int array[], int begin, int end);
void Swap(int arr[], int low, int high);

/**
 *  @name        : void QuickSort(int *a,int size)
 *  @description : 快速排序（非递归版）
 *  @param       : 数组指针a，数组长度size
 */
void QuickSort(int* a, int size);


/**
 *  @name        : void QuickSort(int *a, int begin, int end)
 *  @description : 快速排序（枢轴存放）
 *  @param       : 数组指针a，数组起点begin，数组终点end
 */
int Partition(int* a, int begin, int end);


/**
 *  @name        : void CountSort(int *a, int size , int max)
 *  @description : 计数排序
 *  @param       : 数组指针a，数组长度size，数组最大值max
 */
void CountSort(int* a, int size, int max);


/**
 *  @name        : void RadixCountSort(int *a,int size)
 *  @description : 基数计数排序
 *  @param       : 数组指针a，数组长度size
 */
void RadixCountSort(int* a, int size);


/**
 *  @name        : void ColorSort(int *a,int size)
 *  @description : 颜色排序
 *  @param       : 数组指针a（只含0，1，2元素），数组长度size
 */
void ColorSort(int* a, int size);


/**
 *  @name        : 自拟
 *  @description : 在一个无序序列中找到第K大/小的数
 *  @param       : 数组指针a，数组长度size
 */





void ColorSortM();
void insertSortM();
void MergeArrayM();
void QuickSortM1();
void QuickSortM2();
void QuickSortM3();



void CreateTxt1();
void CreateTxt21();
void CreateTxt22();
void CreateTxt23();

void test1();
void test2();
void test3();
void test4();

/*
    辅助函数
*/

void _Merge(int* a, int begin1, int end1, int begin2, int end2, int* tmp);


#endif // QUEUE_H_INCLUDED
