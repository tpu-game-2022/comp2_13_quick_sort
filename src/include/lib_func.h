#pragma once // インクルードガード

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
	void Swap(item* array, int i, int j);
	void Qsort(item* array, int left, int right);

	// C++ でCのライブラリを使うときのおまじない
#ifdef __cplusplus
} // extern "C"
#endif
