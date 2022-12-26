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
	if (begin == NULL || end == NULL) return false;
    if (begin >= end)return false;

    int count= end - begin;
	item* pivot = begin + 1;
    item* left = begin;
    item* right = begin + count - 1;

	while (begin->key < end->key)
    {
        while ((end->key >= pivot->key) && (begin < end)) end--;

        while ((begin->key <= pivot->key) && (begin < end)) end++;

        swap(left, right);
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
