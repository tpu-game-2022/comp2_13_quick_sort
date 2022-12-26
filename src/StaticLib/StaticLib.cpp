#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"

// クイックソート(引数が不適切であればfalseを返す)
bool quick_sort(item* begin, const item* end)
{
	// ToDo: クイックソートで並び替えてください
	if(begin == NULL || end == NULL || end < begin)
	return false;

	int i, j, pivot;
	int  element = end - begin; //要素数
	item* left = begin;
	item* right = begin + element + 1;
	i = left->key;
	j = right->key;
	pivot = left->key;

	do {
		do { left++; } while (i < pivot);
		do { right--; } while (pivot < j);
		if (i < j)
		{
			item* i = left;
			item* j = right;
			item tmp = *i;
			*i = *j;
			*j = tmp;
		}
	} while (i < j);

	if (i < j)
	{
		quick_sort(begin, left);
		quick_sort(right, end);
	}
	return true;
}