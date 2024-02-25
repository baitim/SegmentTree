#include <stdio.h>

#include "tree.h"

int main()
{
    int data[] = {1, 2, 3, 4, 5, 6, 7, 0, 1, 1, 1};
    int size = sizeof(data) / sizeof(int);

    Tree* tree = TreeMake(data, size);
    TreePrint(tree);

    printf("first sum = %d\n", TreeSum(tree, 1, 0, 2, 0, tree->ln_nodes - 1));
    TreeUpdate(tree, 1, 0, tree->ln_nodes - 1, 1, 5);
    TreePrint(tree);
    printf("second sum = %d\n", TreeSum(tree, 1, 0, 2, 0, tree->ln_nodes - 1));
    TreeDelete(tree);

    return 0;
}