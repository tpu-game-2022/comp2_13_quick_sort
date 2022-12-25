#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"

// クイックソート(引数が不適切であればfalseを返す)
bool quick_sort(item* begin, const item* end)
{
	// ToDo: クイックソートで並び替えてください
	if (begin == NULL || end == NULL)return false;
	const int pivot = (begin + (end - begin) / 2)->key;
	item* i = begin;
    item* j = begin + (end - begin);
	while (1) {
		while (i->key < pivot)i++;
		while (j->key > pivot)j--;
		if (i >= j)break;
		i++;
		j--;
	}
	if (i - begin >= 2) {
		quick_sort(begin, i - 1);
	}
	if (end - j >= 2) {
		quick_sort( j+1, end);
	}
	return false;
}
