#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"

void swap_item(item* p, item* q);

// クイックソート(引数が不適切であればfalseを返す)
bool quick_sort(item* begin, const item* end)
{
	const int size = (end - begin);

	if (begin == nullptr || end == nullptr || size < 0) return false;
	if (size == 1) return true;

	const int pivot = (begin + size / 2)->key;
	item* left = begin;
	item* right = begin + size - 1;

	while (1) {
		while (left->key < pivot) left++;
		while (right->key > pivot) right--;

		if (left >= right) break;

		swap_item(left, right);

		left++;
		right--;
	}

	if (left < begin) {
		if (!quick_sort(begin, left)) return false;
	}

	if (right < end) {
		if (!quick_sort(right, end)) return false;
	}

	return true;
}

void swap_item(item* p, item* q)
{
	item tmp = *p;
	*p = *q;
	*q = tmp;
}
