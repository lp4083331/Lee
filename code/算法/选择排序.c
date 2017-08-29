#include <stdio.h>
#include <stdlib.h>
#include "util_sort.h"

/* ѡ������ */

void select_sort(int *a, int len)
{
    int i = 0, j = 0;
    int index = 0;

    for (i = 0; i < len - 1; i++)
    {
        /* ��¼��Сֵ�±� */
        index = i;
        for (j = len - 1; j > i; j--)
        {
            if (a[j] < a[index])
            {
                index = j;
            }
        }

        /* ����Сֵ�ŵ���ǰ�� */
        swap(a, index, i);
    }
}