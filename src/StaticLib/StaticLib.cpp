#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義
#include <stdlib.h>
#include "../include/lib_func.h"

// クイックソート(引数が不適切であればfalseを返す)
int Quick__sab(const void* a, const void* b)
{
	if (((item*)a)->key > ((item*)b)->key) {
		return 1;
	}
	if (((item*)a)->key < ((item*)b)->key) {
		return -1;
	}
	else {
		return false;
	}

}
bool quick_sort(item* begin, const item* end)
{
	// ToDo: クイックソートで並び替えてください

	if (begin == NULL || end == NULL || begin > end)return false;
	if (begin + 1 == end)return true;
	qsort(begin, end - begin, sizeof(item), Quick__sab);
	return true;
}