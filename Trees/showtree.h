#ifndef CLASSES_SHOWTREE_H
#define CLASSES_SHOWTREE_H

#include "binarytree.h"
#include <stdio.h>

void inorder(struct element *root);
void preorder(struct element *root);
void postorder(struct element *root);
void print_tree(struct element *ptr, int val);

#endif //CLASSES_SHOWTREE_H
