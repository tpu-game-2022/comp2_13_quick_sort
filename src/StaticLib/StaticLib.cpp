#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"

void swap (item *x, item *y) {
  item temp;    // 値を一時保存する変数

  temp = *x;
  *x = *y;
  *y = temp;
}

// クイックソート(引数が不適切であればfalseを返す)

bool quick_sort(item* begin, const item* end)
{
	// ToDo: クイックソートで並び替えてください
	if (!begin || !end || end - begin < 0)return false;
	if (end - begin < 2)return true;

	item* pivod = begin + (int)(end - begin) / 2;
	item* left = begin;
	item* right = begin + (end - begin - 1);

	while (left < right) {

		while (pivod->key > left->key)left++;

		swap(left, right);

		left++;
		right--;
	}

	return true;
}
