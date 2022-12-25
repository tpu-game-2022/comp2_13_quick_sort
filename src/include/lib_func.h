﻿#pragma once // インクルードガード

#include <stdbool.h>

// C++ でCのライブラリを使うときのおまじない
#ifdef __cplusplus
extern "C" {
#endif

	typedef struct item_
	{
		int key;
		char value[256];
	}item;

	// クイックソート(引数が不適切であればfalseを返す)
	bool quick_sort(item *begin, const item* end);

	int comparison_base(const void* front, const void* back);

	// C++ でCのライブラリを使うときのおまじない
#ifdef __cplusplus
} // extern "C"
#endif
