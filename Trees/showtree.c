#include "showtree.h"

void inorder(struct element *root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%lf ", root->value);
    inorder(root->right);
}

void preorder(struct element *root) {
    if (root == NULL) return;
    printf("%lf ", root->value);
    preorder(root->left);
    preorder(root->right);
}

void postorder(struct element *root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%lf ", root->value);
}

void print_tree(struct element *ptr, int val) {
    static char arr[64][32];
    static int pos_x, pos_y, y;
    if (val == 1) {
        for (int i = 0; i < 64; i++)
            for (int j = 0; j < 32; j++)
                arr[i][j] = ' ';
        pos_x = 0;
        pos_y = 32;
        y = 0;
    }
    if (!ptr) return;
    y++;
    pos_y/=2;
    pos_x-=pos_y;
    print_tree(ptr->left, 0);
    pos_x+=pos_y;
    arr[pos_x+32][y] = '0'+(char)(ptr->value);
    pos_x+=pos_y;
    print_tree(ptr->right, 0);
    pos_x-=pos_y;
    pos_y*=2;
    y--;
    if(val == 1){
        for(int j=0;j<32;j++){
            for(int i=0;i<64;i++){
                printf("%c", arr[i][j]);
            }
            printf("\n");
        }
    }
}