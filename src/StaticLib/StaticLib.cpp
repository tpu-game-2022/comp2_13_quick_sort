#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"
#include <stdlib.h>

// クイックソート(引数が不適切であればfalseを返す)
bool quick_sort(item* begin, const item* end)
{
	// ToDo: クイックソートで並び替えてください

	if (!begin || !end || end - begin < 0)return false;

    int count = end - begin;

	qsort(begin, count, sizeof(item), comparison_base);

    return true;
}

int comparison_base(const void* front, const void* back)
{
	if(((item*)front)->key > ((item*)back)->key) return 1;
	
	if(((item*)front)->key < ((item*)back)->key) return -1;
	
	else return 0;
}

