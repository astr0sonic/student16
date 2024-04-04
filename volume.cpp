#include "bracket.h"

int getMaxVolume(int lenght, int width, int height, int n, int* collumns) {
	int maxHeight, maxLen, h_X_len = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int j = i + 1; j < n; j++) {
			if ((j - i) * min(collumns[i], collumns[j]) > h_X_len && min(collumns[i], collumns[j]) <= height && j - i <= lenght) {
				h_X_len = (j - i) * min(collumns[i], collumns[j]);
			}
		}
	}
	return h_X_len * width;
}
