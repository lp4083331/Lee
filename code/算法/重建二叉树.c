/* ����ĳ��������ǰ���������������Ľ�����ؽ����ö�����
   ���������ǰ���������������Ľ���ж������ظ�����
 */
#include "BitTree.h"
#include <stdio.h>
#include <stdlib.h>

BitTree ConstructCore(int *pre_order_begin, int *pre_order_end, int *mid_order_begin, int *mid_order_end)
{
    /* ǰ�������һ���Ǹ��ڵ� */
    int root_value = *pre_order_begin;
    BitTreeNode *root = malloc(sizeof(BitTreeNode));
    root->value = root_value;
    root->left = NULL;
    root->right = NULL;

    if (pre_order_begin == pre_order_end)
    {
        return root;
    }

    /* ������������ҵ����ڵ� */
    int *root_mid_order = NULL;
    root_mid_order = mid_order_begin;
    while (root_mid_order <= mid_order_end && (*root_mid_order) != root_value)
    {
        root_mid_order++;
    }

#if 0
    if (root_mid_order - mid_order_end > 0)
    {
        printf("input error.\n");
        return NULL;
    }
#endif
    int leftlength = root_mid_order - mid_order_begin;
    int *left_pre_end = pre_order_begin + leftlength;
    if (leftlength > 0)
    {
        root->left = ConstructCore(pre_order_begin+1, left_pre_end, mid_order_begin, root_mid_order - 1);
    }
    if (leftlength < pre_order_end - pre_order_begin)
    {
        root->right = ConstructCore(left_pre_end + 1, pre_order_end, root_mid_order + 1, mid_order_end);
    }

    return root;
}

BitTree Construct(int *pre_order, int *mid_order, int length)
{
    if (pre_order == NULL || mid_order == NULL || length <= 0)
    {
        return NULL;
    }

    return ConstructCore(pre_order, pre_order + length - 1, mid_order, mid_order + length - 1);
}


