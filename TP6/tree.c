#include "tree.h"

void initTree(Node **node)
{
	*node = (Node *)calloc(1, sizeof(Node));
	(*node)->val = NULL;
	(*node)->left = NULL;
	(*node)->right = NULL;
}

bool insertTree(Node **node, int val)
{
	if (node == NULL || *node == NULL)
	{
		return false;
	}

	if ((*node)->val == NULL)
	{
		(*node)->val = val;
	}
	else
	{
		Node *next;
		initTree(&next);
		next->val = val;

		if ((*node)->val > val)
		{
			(*node)->left = next;
		}
		else
		{
			(*node)->right = next;
		}
	}

	return true;
}

void inorderTree(Node *node, int val)
{
}

void preorderTree(Node *node, int val)
{
}

void postorderTree(Node *node, int val)
{
}

void breadthTree(Node *node)
{
}

int maxTree(Node *node)
{
}

int minTree(Node *node)
{
}

Node *searchTree(Node *node, int val)
{
}

Node *removeTree(Node *node, int val)
{
}

void printTree(Node *node)
{
	
}

void freeTree(Node *node)
{
}