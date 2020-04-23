#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<assert.h>

void Print(int* arr, int size);
void quickSortNor(int* arr, int size);

typedef struct Stack {
	int* data;
	int size;

}stack;


void  InitStack(stack* s)
{
	int* data = (int*)malloc(20 * sizeof(int));
	if (data == NULL)
	{
		assert(0);
		return;
	}
	s->data = data;
	s->size = 0;
}

void PushStack(stack* s, int d)
{
	assert(s);
	if (s->size > 20)
	{
		return;
	}
	else
		s->data[s->size++] = d;
}

void PopStack(stack* s)
{
	assert(s);
	if (s->size == 0)
	{
		return;
	}
	else
		s->size--;
}

int TopStack(stack* s)
{
	assert(s);
	return s->data[s->size - 1];

}

int EmptyStack(stack* s)
{
	assert(s);
	return s->size == 0;
}

//打印函数
void Print(int* arr, int size)
{
	int i = 0;
	for (i = 0; i < size; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void swap(int* x, int* y)

{
	int temp = *x;
	*x = *y;
	*y = temp;
}
int MiddleNumber(int* arr, int begin, int end)
{
	int mid = begin + ((end - begin) >> 1);
	if (arr[begin] > arr[mid])
	{
		if (arr[begin] > arr[end])
		{
			if (arr[mid] > arr[end])
			{
				return mid;
			}
			else
				return end;
		}
		else
			return begin;
	}
	else
	{
		if (arr[mid] > arr[end])
		{
			if (arr[begin] > arr[end])
			{
				return begin;
			}
			else
			{
				return end;
			}
		}
		else
			return mid;
	}

}

int qs2(int* arr, int begin, int end)
{
	int index = MiddleNumber(arr, begin, end);
	if (index != end)
	{
		swap(&arr[index], &arr[end]);
	}

	//第一个坑
	int key = arr[end];
	int k = end;
	while (begin != end)
	{
		while (arr[begin] <= key && begin < end)
		{
			begin++;
		}
		if (begin != end)
		{
			arr[end] = arr[begin];
			end--;
		}
		while (arr[end] >= key && begin < end)
		{
			end--;
		}
		if (begin != end)
		{
			arr[begin] = arr[end];
			begin++;
		}
	}
	if (begin != k)
	{
		arr[begin] = key;
	}
	return begin;
}
//快速排序1
void quickSortNor(int* arr, int size)
{
	stack s;
	int position;
	int left = 0;
	int right = 0;
	InitStack(&s);
	PushStack(&s, 0);
	PushStack(&s, size);
	while (!EmptyStack(&s))
	{
		right = TopStack(&s);
		PopStack(&s);
		left = TopStack(&s);
		PopStack(&s);
		position = qs2(arr, left, right - 1);
		//先快排基准左侧，则先将后侧的下标入栈
		if ((right - left) > position + 1)
		{
			PushStack(&s, position + 1);
			PushStack(&s, right - left);
		}
		if (position > 0)
		{
			PushStack(&s, 0);
			PushStack(&s, position);
		}
	}
}
