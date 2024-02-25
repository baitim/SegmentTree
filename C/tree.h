#ifndef C_TREE_H
#define C_TREE_H

typedef struct _Tree {
    int* values;
    int ln_nodes;
    int ln_leaves;
} Tree;

int     TreeInit    (Tree* tree, int v);
Tree*   TreeMake    (int* data, int size);
void    TreePrint   (Tree* tree);
int     TreeSum     (Tree* tree, int v, int l, int r, int tl, int tr);
void    TreeUpdate  (Tree* tree, int v, int tl, int tr, int pos, int x);
void    TreeDelete  (Tree* tree);

#endif // C_TREE_H