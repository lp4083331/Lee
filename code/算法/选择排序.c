#include <stdio.h>
#include <stdlib.h>
#include "util_sort.h"

/* 选择排序 */

void select_sort(int *a, int len)
{
    int i = 0, j = 0;
    int index = 0;

    for (i = 0; i < len - 1; i++)
    {
        /* 记录最小值下标 */
        index = i;
        for (j = len - 1; j > i; j--)
        {
            if (a[j] < a[index])
            {
                index = j;
            }
        }

        /* 将最小值放到最前面 */
        swap(a, index, i);
    }
}