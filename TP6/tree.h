#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int val;
    struct node *left, *right;
} Node;


/* typedef struct noeud {
    char lettre;
    char *def
    struct noeud *fils[26];
} */


void initTree(Node **);          // initialize the tree's root node
bool insertTree(Node **, int);    // add the node to tree
void inorderTree(Node *, int);   // inorder traversal of tree
void preorderTree(Node *, int);  // preorder traversal of tree
void postorderTree(Node *, int); // postorder traversal of tree
void breadthTree(Node *);        // breadth first traversal of tree
int maxTree(Node *);             // find max value in tree
int minTree(Node *);             // find min value in tree
Node *searchTree(Node *, int);   // search for val in tree and return node
Node *removeTree(Node *, int);   // remove val from tree and return node
void printTree(Node *);			 // print tree
void freeTree(Node *); 			 // free the tree