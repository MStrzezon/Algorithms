#ifndef CLASSES_AVL_TREE_H
#define CLASSES_AVL_TREE_H

#include "binarytree.h"

void left_rotation(struct element **root, struct element *x);
void right_rotation(struct element **root, struct element *x);
int number_of_transformations(unsigned int n);
void DSW(struct element **root, int n);
void insert_avl(struct element **root, double val);

#endif //CLASSES_AVL_TREE_H
