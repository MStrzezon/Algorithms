#ifndef CLASSES_BINARYTREE_H
#define CLASSES_BINARYTREE_H

#include <stdlib.h>

struct element {
    double value;
    struct element *left, *right, *parent;
    int bf;
};

void insert_tree(struct element **root, double val);
struct element *max_element_tree(struct element *ptr);
struct element *min_element_tree(struct element *ptr);
struct element *find_node(struct element *ptr, double val);
struct element *successor(struct element *ptr);
struct element *predecessor(struct element *ptr);
void dfs_release(struct element *ptr);

#endif //CLASSES_BINARYTREE_H
