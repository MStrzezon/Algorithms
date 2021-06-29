#include "avl_tree.h"

void left_rotation(struct element **root, struct element *x) {
    struct element *y = x->right;
    if (y == NULL) return;
    x->right = y->left;
    if (y->left) x->right->parent = x;
    y->parent = x->parent;
    if (x->parent == NULL) *root = y;
    else if (x == x->parent->left) x->parent->left = y;
    else x->parent->right = y;
    y->left = x;
    x->parent = y;
}

void right_rotation(struct element **root, struct element *x) {
    struct element *y = x->left;
    if (y == NULL) return;
    x->left = y->right;
    if (y->right) x->left->parent = x;
    y->parent = x->parent;
    if (x->parent == NULL) *root = y;
    else if (x == x->parent->left) x->parent->left = y;
    else x->parent->right = y;
    y->right = x;
    x->parent = y;
}

int number_of_transformations(unsigned int n){
    unsigned int b=1;
    while(n=n>>1){
        b=b<<1;
    }
    return b;
}

void DSW(struct element **root, int n) {
    struct element *w = *root;
    while (w) {
        while (w->left) {
            right_rotation(root, w);
            w = w->parent;
        }
        w = w->right;
    }
    int m = number_of_transformations(n+1) - 1;
    w = *root;
    for (int i = 0; i < n - m; i++) {
        left_rotation(root, w);
        w = w->parent->right;
    }
    while (m > 1) {
        w = *root;
        m /= 2;
        for (int i = 0; i < m; i++) {
            left_rotation(root, w);
            w = w->parent->right;
        }
    }
}

void insert_avl(struct element **root, double val) {
    struct element *ptr, *predecessor = NULL;
    struct element *new = malloc(sizeof(struct element));
    new->value = val;
    new->right = NULL;
    new->left = NULL;
    new->bf = 0;
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
    //AVL
    if (predecessor == NULL) return;
    if (predecessor->bf) {
        predecessor->bf = 0;
        return;
    }
    if (predecessor->left == new) predecessor->bf = 1;
    else predecessor->bf = -1;
    ptr = predecessor->parent;
    while (ptr && ptr->bf==0)
    {
        if(ptr->left == predecessor) ptr->bf=1;
        else ptr->bf=-1;
        predecessor = ptr;
        ptr = ptr->parent;
    }
    if (ptr) {
        if (ptr->left == predecessor && ptr->bf == -1) ptr->bf = 0;
        if (ptr->right == predecessor && ptr->bf == 1) ptr->bf = 0;
        if (ptr->bf == 1 && ptr->left == predecessor && predecessor->bf == -1) { //LR
            if(ptr->left->right->bf == 1) ptr->bf = -1;
            else ptr->bf = 0;
            if(ptr->left->right->bf == -1) ptr->left->bf = 1;
            else ptr->left->bf = 0;
            ptr->left->right->bf = 0;
            left_rotation(root, ptr->left);
            right_rotation(root, ptr);
        }
        if (ptr->left == predecessor && ptr->bf == 1 && predecessor->bf == 1) { //LL
            ptr->bf = 0;
            ptr->left->bf = 0;
            right_rotation(root, ptr);
        }
        if (ptr->bf == -1 && ptr->right == predecessor && predecessor->bf == 1) { //RL
            if (ptr->right->left->bf == -1) ptr->bf = 1;
            else ptr->bf = 0;
            if (ptr->right->left->bf == 1) ptr->right->bf = -1;
            else ptr->right->bf = 0;
            ptr->right->left->bf = 0;
            right_rotation(root, ptr->right);
            left_rotation(root, ptr);
        }
        if (ptr->right == predecessor && ptr->bf == -1 && predecessor->bf == -1) { //RR
            ptr->bf = 0;
            ptr->right->bf = 0;
            left_rotation(root, ptr);
        }
    }
}