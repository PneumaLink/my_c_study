#include "libtree.h"

tn	*ft_addnode(tn **tree, int n)
{
	tn	*new_node;
	tn	*mom;
	tn	*head;

	new_node = ft_newnode(n);
	if (!new_node)
		return (NULL);
	if (!*tree)
		return (new_node);
	head = *tree;
	while(*tree)
	{
		mom = *tree;
		if ((*tree)->content > new_node->content)
			*tree = (*tree)->bigson;
		else
			*tree = (*tree)->smallson;
	}
	*tree = new_node;
	new_node->mom = mom;
	return (head);
}
