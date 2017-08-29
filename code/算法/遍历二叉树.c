#include "BitTree.h"
#include <stdio.h>
#include <stdlib.h>

#define SIZE 1024

typedef struct BitNodeStack
{
    BitTreeNode* data[SIZE];
    int top;
    int tag[SIZE]; //后序遍历需要
}BitNodeStack;

typedef struct BitNodeSeq{
    BitTreeNode* data[SIZE];
    int front;
    int rear;
}BitNodeSeq;

void push(BitNodeStack *stack, BitTreeNode *node)
{
    if (stack->top == SIZE)
    {
        printf("the stack is full.\n");
    }
    else
    {
        stack->top++;
        stack->data[stack->top] = node;
    }
}

BitTreeNode* pop(BitNodeStack *stack)
{
    if (!stack || stack->top == -1)
    {
        return NULL;
    }
    stack->top--;
    return stack->data[stack->top + 1];
}

void enter(BitNodeSeq *seq, BitTreeNode* node)
{
    if (seq->rear == SIZE)
    {
        printf("the queue is full.");
        return;
    }

    seq->data[seq->rear] = node;
    seq->rear++;
}

BitTreeNode* del(BitNodeSeq *seq)
{
    if (seq->front == seq->rear)
    {
        return NULL;
    }
    else
    {
        seq->front++;
        return seq->data[seq->front - 1];
    }
}

void preorder_dg(BitTree tree)
{
    printf("%d\n", tree->value);
    if (tree->left)
    {
        preorder_dg(tree->left);
    }
    
    if (tree->right)
    {
        preorder_dg(tree->right);
    }

    return;
}



void preorder(BitTree tree)
{
    if (tree == NULL)
    {
        printf("The tree is empty.\n");
        return;
    }
    BitTree t = tree;

    BitNodeStack stack;

    stack.top = -1;

    /* 树和栈都空了则推出循环 */
    while (t || stack.top != -1)
    {
        while (t)
        {
            printf("%d\n", t->value);

            push(&stack, t);
            t = t->left;
        }
        t = pop(&stack);
        t = t->right;
    }
}

void midorder_dg(BitTree tree)
{
    if (tree->left)
    {
        midorder_dg(tree->left);
    }

    printf("%d\n", tree->value);

    if (tree->right)
    {
        midorder_dg(tree->right);
    }
}

void midorder(BitTree tree)
{
    if (tree == NULL)
    {
        printf("The tree is empty.\n");
        return;
    }
    BitTree t = tree;

    BitNodeStack stack;

    stack.top = -1;

    /* 树和栈都空了则推出循环 */
    while (t || stack.top != -1)
    {
        while (t)
        {
            push(&stack, t);
            t = t->left;
        }
        t = pop(&stack);
        printf("%d\n", t->value);
        t = t->right;
    }
}

void postorder_dg(BitTree tree)
{
    if (tree->left)
    {
        postorder_dg(tree->left);
    }

    if (tree->right)
    {
        postorder_dg(tree->right);
    }

    printf("%d\n", tree->value);
}

void postorder(BitTree tree)
{
    BitNodeStack stack;
    stack.top = -1;

    if (tree == NULL)
    {
        printf("The tree is empty.\n");
        return;
    }

    BitTree t = tree;

    while (t || stack.top != -1)
    {
        while (t)
        {
            push(&stack, t);
            stack.tag[stack.top] = 0;//设置访问标识，0为第一次访问，1为第二次访问
            t = t->left;
        }

        if (stack.tag[stack.top] == 0)
        {
            t = stack.data[stack.top];
            stack.tag[stack.top] = 1;
            t = t->right;
        }
        else
        {
            while (stack.tag[stack.top] == 1)
            {
                t = pop(&stack);
                printf("%d\n", t->value);
            }
            t = NULL; //必须将t置空，跳过向左走，直接向右走
        }
    }
}

int Depth(BitTree tree)
{
    if (tree == NULL)
    {
        return 0;
    }

    int leftDepth = Depth(tree->left);
    int rightDepth = Depth(tree->right);

    return 1 + max(leftDepth, rightDepth);
}

void print_node_at_level(BitTree tree, int level)
{
    if (tree == NULL || level < 1)
    {
        printf("the tree is NULL.\n");
        return;
    }

    if (level == 1)
    {
        printf("%d\n", tree->value);
        return;
    }
    print_node_at_level(tree->left, level - 1);
    print_node_at_level(tree->right, level - 1);
}

void level_dg(BitTree tree)
{
    if (tree == NULL)
    {
        printf("the tree is NULL.\n");
        return;
    }

    int depth = Depth(tree);

    int i = 0;

    for (i = 1; i <= depth; i++)
    {
        print_node_at_level(tree, i);
    }
}

void level(BitTree tree)
{
    BitNodeSeq seq;

    BitTree t = tree;;

    seq.front = seq.rear = 0;
    if (tree == NULL)
    {
        printf("The tree is empty.");
        return;
    }

    enter(&seq, t);
    while (seq.front != seq.rear)
    {
        t = del(&seq);
        printf("%d\n", t->value);

        if (t->left)
        {
            enter(&seq, t->left);
        }

        if (t->right)
        {
            enter(&seq, t->right);
        }
    }
}