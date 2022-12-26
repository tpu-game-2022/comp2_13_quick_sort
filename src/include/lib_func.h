#pragma once // インクルードガード

#include <stdbool.h>
#include <stdlib.h>
// C++ でCのライブラリを使うときのおまじない
#ifdef __cplusplus
extern "C" {
#endif

	typedef struct item_
	{
		int key;
		char value[256];
	}item;
	int sortbase(const void* a, const void* b)
	{
		if (((item*)a)->key > ((item*)b)->key)
			return 1;

		if (((item*)a)->key < ((item*)b)->key)
			return -1;

		else
			return false;


	}
	// クイックソート(引数が不適切であればfalseを返す)
	bool quick_sort(item* begin, const item* end)
	{
		if (begin == NULL || end == NULL || begin > end)
		return false;

	    if (begin + 1 == end)
		return true;

	    qsort(begin, end - begin, sizeof(item), sortbase);
	
		return true;
	}
}

	// C++ でCのライブラリを使うときのおまじない
#ifdef __cplusplus
 // extern "C"
#endif
