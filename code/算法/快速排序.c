#include <stdio.h>
#include <stdlib.h>
#include "util_sort.h"


int partiotion(int *a, int left, int right)
{
    int key = 0;
    int m = 0;
    int i = left;
    int j = right;

    /* ѡȡkeyֵʱ��������ȡ�з� */

    m = left + (right - left) / 2;

    /* ����������Ҷ����ݣ���֤��˽�С */
    if (a[left] > a[right])
    {
        swap(a, left, right);
    }

    /* �����м����Ҷˣ� ��֤�м��С */
    if (a[m] > a[right])
    {
        swap(a, m, right);
    }

    /* �����м�����ˣ���֤��˽�С �м���С*/
    if (a[m] > a[left])
    {
        swap(a, left, m);
    }

    key = a[left];

    /* �����˽������м�ɨ�� */
    while (i < j)
    {
        while (i < j && key <= a[j])
        {
            /* Ѱ�ҽ�������������
            1 �ҵ�1��С�ڻ��ߴ���key�����������ǽ���)
            2 û�з�������1�ģ�����i��j�Ĵ�Сû�з�ת
            */
            j--; /* ��ǰѰ��*/
        }

        /* �ҵ�һ������������Ͱ�ֵ����ǰ��ı����ߵ�i��ֵ ��һ��ѭ������key��a[left] �����key*/
        /* ʹ���滻�����ǽ��� */
        a[i] = a[j];

        while (i < j && key >= a[i])
        {
            i++;
        }

        a[j] = a[i];

    }

    /* ������������һ�����м���key�ع� */
    a[i] = key;

    /* ������Ŧ����λ�� */
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
    /* ���������������ұߵ������ʹ����Ѿ��������һ���� */
    if (left >= right)
    {
        return 0;
    }

    int i = partiotion(a, left, right);

    quick_sort_dg(a, left, i - 1); 
    quick_sort_dg(a, i + 1, right);

    return 0;
}

