#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "tree.h"

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) > (b)) ? (a) : (b))

int TreeInit(Tree* tree, int v)
{
    return (v >= tree->ln_nodes) ? tree->values[v] : (tree->values[v] = TreeInit(tree, v * 2) + TreeInit(tree, v * 2 + 1), tree->values[v]);
}

Tree* TreeMake(int* data, int size) 
{
    Tree* tree = malloc(sizeof(Tree));
    float lb_ = ceil(log(size) / log(2));
    int lb = (lb_ == (int)lb_) ? (int)lb_ : (int)lb_ + 1;
    *tree = (Tree){calloc(sizeof(int), pow(2, lb) * 2 + 1), pow(2, lb) - 1, size};
    memcpy(tree->values + tree->ln_nodes + 1, data, tree->ln_leaves * sizeof(int));
    TreeInit(tree, 1);
    return tree;
}

void TreePrint(Tree* tree) 
{
    printf("Tree:\n");
    printf("nodes = %d\n", tree->ln_nodes);
    printf("leaves = %d\n", tree->ln_leaves);
    for (int i = 0; i <= tree->ln_nodes + tree->ln_leaves; i++) printf("%.2d ", i);
    printf("\n");
    for (int i = 0; i <= tree->ln_nodes + tree->ln_leaves; i++) printf("%.2d ", tree->values[i]);
    printf("\n");
}

int TreeSum(Tree* tree, int v, int l, int r, int tl, int tr) 
{
    if (l > r)              return 0;
    if (l == tl && r == tr) return tree->values[v];
    int tm = (tr + tl) / 2;
    return TreeSum(tree, v * 2, l, MIN(r, tm), tl, tm) + TreeSum(tree, v * 2 + 1, MAX(l, tm + 1), r, tm + 1, tr);
}

void TreeUpdate(Tree* tree, int v, int tl, int tr, int pos, int x) 
{
    if (tl == tr) tree->values[v] = x;
    else {
        int tm = (tl + tr) / 2;
        if (pos <= tm) TreeUpdate(tree, v * 2, tl, tm, pos, x);
        else TreeUpdate(tree, v * 2 + 1, tm + 1, tr, pos, x);
        tree->values[v] = tree->values[v * 2] + tree->values[v * 2 + 1];
    }
}

void TreeDelete(Tree* tree) 
{
    free(tree->values);
    free(tree);
}