#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"

void Swap_Item(item* begin, item* i, item* j)
{
	item Temp_Items;
	Temp_Items = *i;
	*i=*j;
	*j= Temp_Items;
}

// クイックソート(引数が不適切であればfalseを返す)
bool quick_sort(item* begin, const item* end)
{
	const int ElementCount = end - begin;
	if (!begin || !end)return false;
	if (end < begin)return false;
	int i, j;
	int pivot;//中央値
	item* left = begin;//始まり
	item* right = begin+ElementCount-1;//終端
	i = left->key;
	j = right->key;

	pivot = (left->key + right->key) / 2;

	while (1)
	{
		while (left->key < pivot)
			left++;
		while (right->key > pivot)
			right--;
		if (left>=right)break;

		Swap_Item(begin, left, right);
		left++;
		right--;
	}

	if (left->key < i - 1)
	{
		quick_sort(begin ,left);
	}
	if (right->key > j + 1)
	{
		quick_sort(right,end);
	}
	return true;
}

