#include "binarytree.h"

void insert_tree(struct element **root, double val) {
    struct element *ptr, *predecessor;
    struct element *new = malloc(sizeof(struct element));
    new->value = val;
    new->right = NULL;
    new->left = NULL;
    ptr = *root;
    while(ptr) {
        predecessor = ptr;
        if (val > ptr->value) ptr = ptr->right;
        else ptr = ptr->left;
    }
    new->parent = predecessor;
    if (predecessor == NULL) *root = new;
    else if (val > predecessor->value) predecessor->right = new;
    else predecessor->left = new;
}

struct element *max_element_tree(struct element *ptr) {
    while (ptr->right)
        ptr = ptr->right;
    return ptr;
}

struct element *min_element_tree(struct element *ptr) {
    while (ptr->left)
        ptr = ptr->left;
    return ptr;
}

struct element *find_node(struct element *ptr, double val) {
    while(ptr && val != ptr->value) {
        if (val > ptr->value) ptr = ptr->right;
        else ptr = ptr->left;
    }
    return ptr;
}

struct element *successor(struct element *ptr) {
    struct element *predecessor = ptr->parent;
    if(ptr->right) return min_element_tree(ptr->right);
    while(predecessor && predecessor->right == ptr) {
        ptr  = predecessor;
        predecessor = predecessor->parent;
    }
    return predecessor;
}

struct element *predecessor(struct element *ptr) {
    struct element *helper = ptr->parent;
    if(ptr->left) return max_element_tree(ptr->left);
    while(helper && helper->left == ptr) {
        ptr  = helper;
        helper = helper->parent;
    }
    return helper;
}

void dfs_release(struct element *ptr) {
    if(ptr) {
        dfs_release( ptr->left );
        dfs_release( ptr->right );
        free(ptr);
    }
}

