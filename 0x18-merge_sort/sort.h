#ifndef _SORT_H_
#define _SORT_H_
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
void print_array(const int *array, size_t size);
void merge_sort(int *array, size_t size);
void merge(int *arr, int *copy, int s, int e, int m);
void split(int *arr, int *copy, int start, int end);

#endif
