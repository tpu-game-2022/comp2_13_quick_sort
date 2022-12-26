#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"

// クイックソート(引数が不適切であればfalseを返す)
bool quick_sort(item* begin, const item* end)
{
	// ToDo: クイックソートで並び替えてください
	if (begin == NULL || end < begin)
	return false;

	int diff = end - begin;
	if (diff <= 1)
		return true;

	item* left = begin;
	item* right = diff + begin - 1;
	int pivot = end->key;

	while (1) {
		while (left->key < pivot) {
			left++;
		}

		while (right->key > pivot) {
			right--;
		}

		if (left >= right)
			break;

		item temp = *left;
		*left = *right;
		*right = temp;

		left++;
		right--;
	}

	quick_sort(begin, left);

	quick_sort(right, end);

	return true;
}
