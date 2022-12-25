#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"

// クイックソート(引数が不適切であればfalseを返す)
void Swap(item* array, int i, int j)
{
	item cp;

	cp = array[i];
	array[i] = array[j];
	array[j] = cp;
}

void Qsort(item* array,int left,int right)
{
	int i, j;
	int pivot = array[(right + left) / 2].key;
	i = left;
	j = right;

	while (true)
	{
		while (array[i].key < pivot)
			i++;
		while (array[j].key > pivot)
			j--;
		if (i >= j)
			break;

		Swap(array, i, j);
		i++;
		j--;
	}
	if (left < i - 1)
		Qsort(array, left, i - 1);
	if (j + 1 < right)
		Qsort(array, j + 1, right);
}

bool quick_sort(item* begin, const item* end)
{
	// ToDo: クイックソートで並び替えてください
	int array_size = end - begin;
	if (begin == NULL || end == NULL)return false;
	if (array_size < 0)return false;

	Qsort(begin, 0, array_size);

	return true;
}
