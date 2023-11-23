#ifndef TREE_H
#define TREE_H

#include <cstdlib>
#include <cstdio>

struct node {
    node * left;
    node * right;
    int data;
};

void insert(node ** tree, int val);
node *findMinNode(node *tree);
void deleteNode(node **tree, int val);
void printLevelByLevel(node* head);

#endif // TREE_H
