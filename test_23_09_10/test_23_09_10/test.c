#define _CRT_SECURE_NO_WARNINGS 1

//***************************************//
//*********		 日常练习题		*********//
//*********      Li Huayang		*********//
//*********      2023/09/10		*********//
//***************************************//

#include <stdio.h>
#include <math.h>

//*****  整数逐位变换，奇数变为1，偶数变为0  *****//
//输入	22222
//输出	0	（00000）
//输入	123
//输出	101
void test_1(void)
{
	int input = 0;
	int output = 0;
	int tmp = 0;
	int i = 0;
	scanf("%d", &input);
	while (input)
	{
		tmp = input % 10;
		output += (tmp % 2) * (int)pow(10, i);
		input /= 10;
		i++;
	}
	printf("%d\n", output);
}


//*****  实现两个有序整型数组的合并  *****//
//输入
//5 6				--分别代表两个数组元素个数
//1 3 5 10 22		--第一个数组
//2 5 11 17 33 44	--第二个数组
//输出
//1 2 3 5 5 10 11 17 22 33 44
void test_2(void)
{
	int num_of_line1 = 0;
	int num_of_line2 = 0;
	int arr1[100] = { 0 };
	int arr2[100] = { 0 };
	int arr3[200] = { 0 };	//保存合并后的数组
	int i = 0;
	int j = 0;
	int z = 0;
	//输入行数
	scanf("%d%d", &num_of_line1, &num_of_line2);
	//输入数组
	for (i = 0; i < num_of_line1; i++)
	{
		scanf("%d", arr1 + i);
	}
	for (i = 0; i < num_of_line2; i++)
	{
		scanf("%d", arr2 + i);
	}
	//排序
	i = 0;
	j = 0;
	while ((i < num_of_line1) && (j < num_of_line2))
	{
		arr3[z++] = (arr1[i] < arr2[j] ? arr1[i++] : arr2[j++]);
	}
	if (i == num_of_line1)
	{
		while (j < num_of_line2)
		{
			arr3[z++] = arr2[j++];
		}
	}
	else
	{
		while (i < num_of_line1)
		{
			arr3[z++] = arr1[i++];
		}
	}
	//打印排序后的数组
	for (z = 0; z < (num_of_line1 + num_of_line2); z++)
	{
		printf("%d ", arr3[z]);
	}
}


void test_3(void)
{
	int a=0, b=0, c=0, d=0, e=0;
	for (a = 1; a <= 5; a++)
	{
		for (b = 1; b <= 5; b++)
		{
			if (b != a)
			{
				for (c = 1; c <= 5; c++)
				{
					if ((c != a) && (c != b))
					{
						for (d = 1; d <= 5; d++)
						{
							if ((d != a) && (d != b) && (d != c))
							{
								for (e = 1; e <= 5; e++)
								{
									if ((e != a) && (e != b) && (e != c) && (e != d))
									{
										if (((b == 2) +  (a == 3) == 1)
											&& ((b == 2) + (e == 4) == 1)
											&& ((c == 1) + (d == 2) == 1)
											&& ((c == 5) + (d == 3) == 1)
											&& ((e == 4) + (a == 1) == 1))
										{
											printf("a=%d b=%d c=%d d=%d e=%d\n",a,b,c,d,e);
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


void test_4(void)
{
	int Killer = 0;
	for (Killer = 'a'; Killer <= 'd'; Killer++)
	{
		if ((Killer != 'a') + (Killer == 'c')
			+ (Killer == 'd') + (Killer != 'd') == 3)
		{
			printf("%c\n", Killer);
		}
	}

}

int main()
{
	int i = 4;
	switch (i)
	{
	case 1:
		test_1();
		break;
	case 2:
		test_2();
		break;
	case 3:
		test_3();
		break;
	case 4:
		test_4();
		break;
	case 5:
		break;
	}
	return 0;
}