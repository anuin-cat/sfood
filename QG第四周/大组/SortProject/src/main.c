#include<stdio.h>
#include<stdlib.h>
#include <limits.h>
#include<windows.h>
#include<string.h>
#include <math.h>
#include<time.h>
#include"qgsort.h"

void quickSortNor(int* arr, int size);
void print(int* a, int size);

int main() {
	double start = 0;
	double end = 0;

	
	//�������ݴ���
	start = clock();
	CreateTxt1();
	end = clock();
	printf("����100*100k����ʹ��ʱ�䣺%.2lf\n", (double)(end-start)/CLK_TCK);

	start = clock();
	CreateTxt21();
	end = clock();
	printf("����10k����ʹ��ʱ�䣺%.2lf\n", (double)(end - start) / CLK_TCK);


	start = clock();
	CreateTxt22();
	end = clock();
	printf("����50k����ʹ��ʱ�䣺%.2lf\n", (double)(end - start) / CLK_TCK);


	start = clock();
	CreateTxt23();
	end = clock();
	printf("����200k����ʹ��ʱ�䣺%.2lf\n\n", (double)(end - start) / CLK_TCK);
	

	test1();
	test2();
	test3();
	test4();


	system("pause");
	//�����㷨����



}
//10k����
void test1() {
	double start = 0;
	double end = 0;

	int temp[100000] = { 0 };
	int a[10000] = { 0 };
	int b[10000] = { 0 };
	int c[10000] = { 0 };
	int d[10000] = { 0 };
	int e[10000] = { 0 };
	int f[10000] = { 0 };

	FILE* fp1;
	fp1 = fopen("21.txt", "r");
	for (int i = 0; i < 10000; i++) {
		fscanf(fp1, "%d", &a[i]);
		b[i] = a[i];
		c[i] = a[i];
		d[i] = a[i];
		e[i] = a[i];
		f[i] = a[i];
	}

	printf("-----10k���ݲ���-----\n");

	start = clock();
	insertSort(a, 10000);
	end = clock();
	printf("����������ʱ��%.4lf\n", (double)(end - start) / CLK_TCK);


	start = clock();
	MergeSort(b, 0, 9999, temp);
	end = clock();
	printf("�鲢������ʱ��%.4lf\n", (double)(end - start) / CLK_TCK);

	start = clock();
	QuickSort_Recursion(c, 0, 9999);
	end = clock();
	printf("�������򣨵ݹ�棩��ʱ��%.4lf\n", (double)(end - start) / CLK_TCK);

	start = clock();
	quickSortNor(d, 10000);
	end = clock();
	printf("�������򣨷ǵݹ飩��ʱ��%.4lf\n", (double)(end - start) / CLK_TCK);


	start = clock();
	CountSort(e, 10000, 999);
	end = clock();
	printf("����������ʱ��%.4f\n", (double)(end - start) / CLK_TCK);


	start = clock();
	RadixCountSort(f, 10000);
	end = clock();
	printf("����������ʱ��%.4lf\n", (double)(end - start) / CLK_TCK);

	fclose(fp1);
}

//50k����
void test2() {
	printf("\n\n");
	printf("-----50k���ݲ���-----\n");

	double start = 0;
	double end = 0;

	int temp[50000] = { 0 };
	int a[50000] = { 0 };

	FILE* fp2;
	fp2 = fopen("22.txt", "r");


	
	rewind(fp2);
	for (int i = 0; i < 50000; i++) {
		fscanf(fp2, "%d", &a[i]);
	}
	start = clock();
	insertSort(a, 50000);
	end = clock();
	printf("����������ʱ��%.4lf\n", (double)(end - start) / CLK_TCK);


	rewind(fp2);
	for (int i = 0; i < 50000; i++) {
		fscanf(fp2, "%d", &a[i]);
	}
	start = clock();
	MergeSort(a, 0, 49999, temp);
	end = clock();
	printf("�鲢������ʱ��%.4lf\n", (double)(end - start) / CLK_TCK);


	rewind(fp2);
	for (int i = 0; i < 50000; i++) {
		fscanf(fp2, "%d", &a[i]);
	}
	start = clock();
	QuickSort_Recursion(a, 0, 49999);
	end = clock();
	printf("�������򣨵ݹ�棩��ʱ��%.4lf\n", (double)(end - start) / CLK_TCK);
	
	/*
	rewind(fp2);
	for (int i = 0; i < 50000; i++) {
		fscanf(fp2, "%d", &a[i]);
	}
	start = clock();
	quickSortNor(a, 49999);
	end = clock();
	printf("�������򣨷ǵݹ飩��ʱ��%.4lf\n", (double)(end - start) / CLK_TCK);*/

	
	rewind(fp2);
	for (int i = 0; i < 50000; i++) {
		fscanf(fp2, "%d", &a[i]);
	}
	start = clock();
	CountSort(a, 50000, 999);
	end = clock();
	printf("����������ʱ��%.4f\n", (double)(end - start) / CLK_TCK);
	

	rewind(fp2);
	for (int i = 0; i < 50000; i++) {
		fscanf(fp2, "%d", &a[i]);
	}
	start = clock();
	RadixCountSort(a, 50000);
	end = clock();
	printf("����������ʱ��%.4lf\n", (double)(end - start) / CLK_TCK);

	fclose(fp2);
}

//200k����
void test3() {
	printf("\n\n");
	printf("-----200k���ݲ���-----\n");

	double start = 0;
	double end = 0;

	int temp[200000] = { 0 };
	int a[200000] = { 0 };

	FILE* fp3;
	fp3 = fopen("23.txt", "r");



	rewind(fp3);
	for (int i = 0; i < 200000; i++) {
		fscanf(fp3, "%d", &a[i]);
	}
	start = clock();
	insertSort(a, 200000);
	end = clock();
	printf("����������ʱ��%.4lf\n", (double)(end - start) / CLK_TCK);


	rewind(fp3);
	for (int i = 0; i < 200000; i++) {
		fscanf(fp3, "%d", &a[i]);
	}
	start = clock();
	MergeSort(a, 0, 199999, temp);
	end = clock();
	printf("�鲢������ʱ��%.4lf\n", (double)(end - start) / CLK_TCK);


	rewind(fp3);
	for (int i = 0; i < 200000; i++) {
		fscanf(fp3, "%d", &a[i]);
	}
	start = clock();
	QuickSort_Recursion(a, 0, 199999);
	end = clock();
	printf("�������򣨵ݹ�棩��ʱ��%.4lf\n", (double)(end - start) / CLK_TCK);

	/*
	rewind(fp2);
	for (int i = 0; i < 50000; i++) {
		fscanf(fp2, "%d", &a[i]);
	}
	start = clock();
	quickSortNor(a, 49999);
	end = clock();
	printf("�������򣨷ǵݹ飩��ʱ��%.4lf\n", (double)(end - start) / CLK_TCK);*/


	rewind(fp3);
	for (int i = 0; i < 200000; i++) {
		fscanf(fp3, "%d", &a[i]);
	}
	start = clock();
	CountSort(a, 200000, 999);
	end = clock();
	printf("����������ʱ��%.4f\n", (double)(end - start) / CLK_TCK);


	rewind(fp3);
	for (int i = 0; i < 200000; i++) {
		fscanf(fp3, "%d", &a[i]);
	}
	start = clock();
	RadixCountSort(a, 200000);
	end = clock();
	printf("����������ʱ��%.4lf\n", (double)(end - start) / CLK_TCK);

	fclose(fp3);
}

//100*100k���ݲ���
void test4() {
	printf("\n\n");
	printf("-----100*100k���ݲ���-----\n");

	double start = 0;
	double end = 0;

	int temp[100] = { 0 };
	int a[100] = { 0 };

	FILE* fp4;
	fp4 = fopen("1.txt", "r");


	
	rewind(fp4);
	start = clock();
	for (int i = 0; i < 100*100000; i++) {
		fscanf(fp4, "%d", &a[i%100]);
		if (i % 100 == 99) {
			insertSort(a, 100);
		}
	}
	end = clock();
	printf("����������ʱ��%.4lf\n", (double)(end - start) / CLK_TCK);


	rewind(fp4);
	start = clock();
	for (int i = 0; i < 100 * 100000; i++) {
		fscanf(fp4, "%d", &a[i % 100]);
		if (i % 100 == 99) {
			MergeSort(a, 0, 99, temp);
		}
	}
	end = clock();
	printf("�鲢������ʱ��%.4lf\n", (double)(end - start) / CLK_TCK);


	rewind(fp4);
	start = clock();
	for (int i = 0; i < 100 * 100000; i++) {
		fscanf(fp4, "%d", &a[i % 100]);
		if (i % 100 == 99) {
			QuickSort_Recursion(a, 0, 99);
		}
	}
	end = clock();
	printf("�������򣨵ݹ�棩��ʱ��%.4lf\n", (double)(end - start) / CLK_TCK);
	

	/*
	rewind(fp2);
	for (int i = 0; i < 50000; i++) {
		fscanf(fp2, "%d", &a[i]);
	}
	start = clock();
	quickSortNor(a, 49999);
	end = clock();
	printf("�������򣨷ǵݹ飩��ʱ��%.4lf\n", (double)(end - start) / CLK_TCK);*/


	rewind(fp4);
	start = clock();
	for (int i = 0; i < 100 * 100000; i++) {
		fscanf(fp4, "%d", &a[i % 100]);
		if (i % 100 == 99) {
			CountSort(a, 100, 99);
		}
	}
	end = clock();
	printf("����������ʱ��%.4lf\n", (double)(end - start) / CLK_TCK);


	rewind(fp4);
	start = clock();
	for (int i = 0; i < 100 * 100000; i++) {
		fscanf(fp4, "%d", &a[i % 100]);
		if (i % 100 == 99) {
			RadixCountSort(a, 100);
		}
	}
	end = clock();
	printf("����������ʱ��%.4lf\n", (double)(end - start) / CLK_TCK);


	fclose(fp4);
}



//��ɫ����ĵ���
void ColorSortM() {
	int sum = 0;
	char b[50];
	//int a[50];
	printf("����һ�����ݣ���һ�������ݳ��ȣ��ڶ�������������(�ÿո����)\n");
	scanf("%d", &sum);
	int* a = (int*)malloc(sizeof(int) * sum);

	for (int i = 0; i < sum; i++) {
		scanf("%d", a + i);
		if (a[i] < 0 || a[i] > 2) {
			printf("������������\n");
			gets(b);
			break;
		}
	}

	ColorSort(a, sum);

	printf("\n");
	for (int j = 0; j < sum; j++) {
		printf("%d", a[j]);
	}

	free(a);
}

//��������ĵ���
void insertSortM() {
	int sum = 0;
	char b[50];
	//int a[50];
	printf("����һ�����ݣ���һ�������ݳ��ȣ��ڶ�������������(�ÿո����)\n");
	scanf("%d", &sum);
	int* a = (int*)malloc(sizeof(int) * sum);

	for (int i = 0; i < sum; i++) {
		scanf("%d", a + i);
	}

	insertSort(a, sum);

	printf("\n");
	for (int j = 0; j < sum; j++) {
		printf("%d", a[j]);
	}

	free(a);
}

//�鲢����ĵ���
void MergeArrayM() {
	int a[10] = { 0 };
	int b[10] = { 0 };

	for (int i = 0; i < 10; i++) {
		scanf("%d", a + i);
	}

	MergeSort(a, 0, 9, b);

	for (int j = 0; j < 10; j++) {
		printf("%d", a[j]);
	}

}

//��������1�ĵ���
void QuickSortM1() {
	int a[10] = { 0 };
	int b[10] = { 0 };

	for (int i = 0; i < 10; i++) {
		scanf("%d", a + i);
	}

	QuickSort_Recursion(a, 0, 9);

	for (int j = 0; j < 10; j++) {
		printf("%d", a[j]);
	}
}

//��������2�ĵ���
void QuickSortM2() {
	int a[10] = { 0 };

	for (int i = 0; i < 10; i++) {
		scanf("%d", a + i);
	}

	quickSortNor(a, 10);

	for (int j = 0; j < 10; j++) {
		printf("%d", a[j]);
	}
}

//��������3�ĵ���
void QuickSortM3() {
	int a[10] = { 0 };

	for (int i = 0; i < 10; i++) {
		scanf("%d", a + i);
	}

	Partition(a, 0, 9);

	for (int j = 0; j < 10; j++) {
		printf("%d", a[j]);
	}
}


//�����ı�����
void CreateTxt1() {
	FILE* fp;
	fp = fopen("1.txt", "w");

	for (int i = 0; i < 100000; i++) {
		for (int j = 0; j < 100; j++) {
			fprintf(fp, "%d ", rand() % 1000);
		}
		//fprintf(fp, "\n");
	}

	fclose(fp);

}

void CreateTxt21() {
	FILE* fp;
	fp = fopen("21.txt", "w");

	for (int i = 0; i < 10000; i++) {
		fprintf(fp, "%d ", rand() % 1000);
	}
	fprintf(fp, "\n");
}

void CreateTxt22() {
	FILE* fp;
	fp = fopen("22.txt", "w");

	for (int i = 0; i < 50000; i++) {
		fprintf(fp, "%d ", rand() % 1000);
	}
	fprintf(fp, "\n");
}

void CreateTxt23() {
	FILE* fp;
	fp = fopen("23.txt", "w");

	for (int i = 0; i < 200000; i++) {
		fprintf(fp, "%d ", rand() % 1000);
	}
	fprintf(fp, "\n");
}


//��ȡ�ı�����
int* read(int i) {

}

//��ӡ����
void print(int* a, int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", a[i]);
	}
	printf("\n");
}