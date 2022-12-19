#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"

// クイックソート(引数が不適切であればfalseを返す)
bool quick_sort(item* begin, const item* end)
{
	// ToDo: クイックソートで並び替えてください
	int sort_len = end - begin;
	if (!begin || !end || sort_len < 0)return false;
	if (sort_len < 2)return true;

	item* pic = begin + 1;
	item* left = begin;
	item* right = begin + sort_len - 1;
	while (1) {

		while (pic->key > left->key)left++;
		while (pic->key < right->key)right--;

		if (left >= right)break;

		change_item(left, right);
		left++;
		right--;
	}

	if (left > begin) {
		if (!quick_sort(begin, left))return false;
	}
	if (right < end) {
		if (!quick_sort(right, end))return false;
	}

	return true;
}

void change_item(item* a, item* b) {
	item tmp = *a;
	*a = *b;
	*b = tmp;
}