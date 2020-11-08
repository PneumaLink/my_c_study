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

tn	*ft_createnote(int content);
void	ft_insertnode(tn *tree, int n);
tn	*ft_findnode(tn *head, int n);

#endif
