#ifndef LIBTREE_H
#define LIBTREE_H

#include <stdlib.h>
#include <stdio.h>

typedef struct	tree_node
{
	struct tree_node	*mom;
	int					content;
	struct tree_node	*bigson;
	struct tree_node	*smallson;
}	tn;

tn	*ft_newnode(int content);
tn	*ft_addnode(tn **tree, int n);
tn	*ft_findnode(tn *head, int n);

#endif
