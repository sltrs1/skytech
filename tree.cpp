#include "tree.h"

void insert(node ** tree, int val) {

    node *temp = NULL;
    if(!(*tree)) {
        temp = (node *)malloc(sizeof(node));
        temp->left = temp->right = NULL;
        temp->data = val;
        *tree = temp;
        return;
    }

    if(val < (*tree)->data) {
        insert(&(*tree)->left, val);
    } else if(val > (*tree)->data) {
        insert(&(*tree)->right, val);
    }

}

node *findMinNode(node *tree) {
    if (tree == NULL) {
        return NULL;
    } else if (tree->left == NULL) {
        return tree;
    } else {
        return findMinNode(tree->left);
    }
}

void deleteNode(node **tree, int val) {
    if (*tree == NULL) {
        return;
    }

    if (val < (*tree)->data) {
        deleteNode(&(*tree)->left, val);
    } else if (val > (*tree)->data) {
        deleteNode(&(*tree)->right, val);
    } else {
        // Case 1: Deleting a leaf node
        if ((*tree)->left == NULL && (*tree)->right == NULL) {
            free(*tree);
            *tree = NULL;
        }
        // Case 2: Deleting a node with one child
        else if ((*tree)->left == NULL) {
            node *temp = *tree;
            *tree = (*tree)->right;
            free(temp);
        } else if ((*tree)->right == NULL) {
            node *temp = *tree;
            *tree = (*tree)->left;
            free(temp);
        }
        // Case 3: Deleting a node with two children
        else {
            node *temp = findMinNode((*tree)->right);
            (*tree)->data = temp->data;
            deleteNode(&(*tree)->right, temp->data);
        }
    }
}

void printLevelByLevel(node* head) {
    if (head == NULL) {
        printf("Tree is empty\n");
        return;
    }

    // Create a queue to store the nodes
    struct node* queue[100];
    int front = 0;
    int rear = 0;

    // Enqueue the head node
    queue[rear++] = head;

    while (front < rear) {
        // Dequeue a node and print its data
        struct node* current = queue[front++];
        printf("%d ", current->data);

        // Enqueue the left child if it exists
        if (current->left != NULL) {
            queue[rear++] = current->left;
        }

        // Enqueue the right child if it exists
        if (current->right != NULL) {
            queue[rear++] = current->right;
        }
    }
}


