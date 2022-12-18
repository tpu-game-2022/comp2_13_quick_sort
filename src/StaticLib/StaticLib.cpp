﻿#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"

static void swap(item* a, item* b)
{
	item t = *a;
	*a = *b;
	*b = t;
}

static item* search_front(int key, item* begin, const item* end)
{
	while (begin->key <= key && begin < end) begin++;
	return begin;
}

static item* search_rear(int key, const item* begin, item* end)
{
	while (key <= end->key && begin < end) end--;
	return end;
}

item* partition(item* begin, const item* end)
{
	int key = begin->key;
	item* head = search_front(key, begin + 1, end);
	item* tail = search_rear(key, begin, begin + (end - begin) - 1);

	while (head < tail) {
		swap(head, tail);
		head = search_front(key, head + 1, end);
		tail = search_rear(key, begin, tail - 1);
	}

	swap(tail, begin);
	return tail;
}

// クイックソート(引数が不適切であればfalseを返す)
bool quick_sort(item* begin, const item* end)
{
	if (begin == NULL || end == NULL || end < begin) return false;
	if (end - begin <= 1) return true;

	item* pivot = partition(begin, end);
	quick_sort(begin, pivot);
	quick_sort(pivot + 1, end);

	return true;
}
