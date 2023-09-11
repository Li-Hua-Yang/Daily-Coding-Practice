#define _CRT_SECURE_NO_WARNINGS 1

//***************************************//
//*********		 日常练习题		*********//
//*********      Li Huayang		*********//
//*********      2023/09/11		*********//
//***************************************//

#include <stdio.h>
#include <assert.h>

//*****		转置二维数组		*****//
//输入
//3 5		--二维数组行列
//1 2 3 4 5 --第一行元素
//2 3 4 5 6 --第二行元素
//3 4 5 6 7 --第三行元素
//输出
//1 2 3
//2 3 4
//3 4 5
//4 5 6
//5 6 7
void Transpose_Array(int* dest, const int* sour, int row, int col)
{
	assert(dest && sour);
	int i = 0;
	int j = 0;
	int z = 0;
	for (i = 0; i < col; i++)
	{
		const int* ret = sour + i;
		for (j = 0; j < row; j++)
		{
			dest[z++] = ret[col * j];
		}
	}
}

void test1(void)
{
	int arr1[10][10] = { 0 };
	int arr2[10][10] = { 0 };
	int row = 0;
	int col = 0;
	scanf("%d%d", &row, &col);
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{s
		for (j = 0; j < col; j++)
		{
			scanf("%d", &arr1[i][j]);
		}
	}
	Transpose_Array(&arr2[0][0], &arr1[0][0], 10, 10);
	for (i = 0; i < col; i++)
	{
		for (j = 0; j < row; j++)
		{
			printf("%d ", arr2[i][j]);
		}
		printf("\n");
	}
}



//*****		上三角矩阵判定		*****//
//输入
//3			--方阵阶数
//1 2 3 --第一行元素
//0 4 5 --第二行元素
//0 0 6 --第三行元素
//输出
//YES

//输入
//3			--方阵阶数
//1 2 3 --第一行元素
//0 4 5 --第二行元素
//0 6 7 --第三行元素
//输出
//NO
void test2(void)
{
	int arr[10][10] = { 0 };
	int i = 0;
	int j = 0;
	int n = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			scanf("%d", &arr[i][j]);
		}
	}
	int flag = 1;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < i; j++)
		{
			if (arr[i][j] != 0)
				flag = 0;
		}
		if (flag == 0)
			break;
	}
	if (flag == 0)
		printf("NO\n");
	else
		printf("YES\n");
}



//*****		判断数列是否有序		*****//
//输入
//5				--元素个数
//1 2 2 4 5		--数列
//输出
//sorted

//输入
//5				--元素个数
//1 2 1 4 5		--数列
//输出
//unsorted
void test3(void)
{
	int arr[50] = { 0 };
	int n = 0;
	scanf("%d", &n);
	int i = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	int flag1 = 0;//1--有升序，0--无序
	int flag2 = 0;//1--有降序，0--无序
	for (i = 0; i < n - 1; i++)
	{
		if (arr[i] < arr[i + 1])
			flag1 = 1;
		else if (arr[i] > arr[i + 1])
			flag2 = 1;
		i++;
	}
	if ((flag1 + flag2) <= 1)
		printf("sorted\n");
	else
		printf("unsorted\n");
}


int main()
{

	return 0;
}