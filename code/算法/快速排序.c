#include <stdio.h>
#include <stdlib.h>
#include "util_sort.h"


int partiotion(int *a, int left, int right)
{
    int key = 0;
    int m = 0;
    int i = left;
    int j = right;

    /* 选取key值时采用三数取中法 */

    m = left + (right - left) / 2;

    /* 交换左端与右端数据，保证左端较小 */
    if (a[left] > a[right])
    {
        swap(a, left, right);
    }

    /* 交换中间与右端， 保证中间较小 */
    if (a[m] > a[right])
    {
        swap(a, m, right);
    }

    /* 交换中间与左端，保证左端较小 中间最小*/
    if (a[m] > a[left])
    {
        swap(a, left, m);
    }

    key = a[left];

    /* 从两端交替向中间扫描 */
    while (i < j)
    {
        while (i < j && key <= a[j])
        {
            /* 寻找结束的条件就是
            1 找到1个小于或者大于key的数（升序还是降序)
            2 没有符合条件1的，并且i与j的大小没有反转
            */
            j--; /* 向前寻找*/
        }

        /* 找到一个这样的数后就把值赋给前面的被拿走的i的值 第一次循环并且key是a[left] 则就是key*/
        /* 使用替换而不是交换 */
        a[i] = a[j];

        while (i < j && key >= a[i])
        {
            i++;
        }

        a[j] = a[i];

    }

    /* 当在组内找完一编后把中间数key回归 */
    a[i] = key;

    /* 返回枢纽所在位置 */
    return i; 
}

int quick_sort(int *a, int left, int right)
{
    int *s = malloc(sizeof(int)* (right + 1));
    int p = 0;
    int q = 0;
    int low = 0;
    int high = 0;

    s[p++] = left;
    s[p++] = right;

    while (p > 0)
    {
        high = s[--p];
        low = s[--p];

        if (low < high)
        {
            q = partiotion(a, low, high);

            if (q > low)
            {
                s[p++] = low;
                s[p++] = q - 1;
            }

            if (high > q)
            {
                s[p++] = q + 1;
                s[p++] = high;
            }

#if 0
            if (q - low > high - q)
            {
                s[p++] = low;
                s[p++] = q - 1;

                if (high > q)
                {
                    s[p++] = q + 1;
                    s[p++] = high;
                }
            }
            else
            {
                s[p++] = q + 1;
                s[p++] = high;

                if (q > low)
                {
                    s[p++] = low;
                    s[p++] = q - 1;
                }
            }
#endif
        }
    }

    free(s);
    s = NULL;

    return 0;
}

int quick_sort_dg(int *a, int left, int right)
{
    /* 如果左边索引大于右边的索引就代表已经整理完成一组了 */
    if (left >= right)
    {
        return 0;
    }

    int i = partiotion(a, left, right);

    quick_sort_dg(a, left, i - 1); 
    quick_sort_dg(a, i + 1, right);

    return 0;
}

