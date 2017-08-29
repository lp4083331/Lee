#include "BitTree.h"
#include <stdlib.h>
#include <stdio.h>

void tree_to_link(BitTreeNode **head, BitTreeNode **tail,BitTreeNode *root)
{
    BitTreeNode *lt = NULL;
    BitTreeNode *rh = NULL;;

    if (root == NULL)
    {
        *head = NULL;
        *tail = NULL;
        return;
    }

    tree_to_link(head, &lt, root->left);
    tree_to_link(&rh, tail, root->right);

    if (lt != NULL)
    {
        lt->right = root;
        root->left = lt;
    }
    else
    {
        *head = root;
    }

    if (rh != NULL)
    {
        root->right = rh;
        rh->left = root;
    }
    else
    {
        *tail = root;
    }


}

BitTreeNode* convert(BitTreeNode *root)
{
    BitTreeNode *head = NULL;
    BitTreeNode *tail = NULL;

    tree_to_link(&head, &tail, root);
    return head;
}