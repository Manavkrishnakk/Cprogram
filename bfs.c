#include <stdio.h>
#include <stdlib.h>

struct btnode {
    int value;
    struct btnode *left, *right;
};
typedef struct btnode node;

/* function declarations */
void insert(node *, node *);
void bfs_traverse(node *);

/* global declarations */
node *root = NULL;

void main() {
    node *new = NULL;
    int num = 1;

    printf("Enter the elements of the tree (enter 0 to exit)\n");
    while (1) {
        scanf("%d", &num);
        if (num == 0) break;

        new = malloc(sizeof(node));
        new->left = new->right = NULL;
        new->value = num;

        if (root == NULL)
            root = new;
        else
            insert(new, root);
    }

    printf("Elements in the tree in level order (BFS) are:\n");
    bfs_traverse(root);
}

/* inserting nodes of a tree */
void insert(node *new, node *root) {
    if (new->value > root->value) {
        if (root->right == NULL)
            root->right = new;
        else
            insert(new, root->right);
    }
    else if (new->value < root->value) {
        if (root->left == NULL)
            root->left = new;
        else
            insert(new, root->left);
    }
}

/* displaying elements using BFS traversal */
void bfs_traverse(node *root) {
    if (root == NULL) return;

    node *queue[20];
    int front = 0, rear = -1;

    // Start with the root node
    queue[++rear] = root;

    while (front <= rear) {
        node *current = queue[front++];

        // Print the current node's value
        printf("%d ", current->value);

        // Enqueue left child if exists
        if (current->left != NULL)
            queue[++rear] = current->left;

        // Enqueue right child if exists
        if (current->right != NULL)
            queue[++rear] = current->right;
    }
    printf("\n");
}
