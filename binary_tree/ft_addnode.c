#include "libtree.h"

tn	*ft_addnode(tn **tree, int n)
{
	tn	*next_node;
	tn	*new_node;
	tn	*cp_tree;

	new_node = ft_newnode(n);
	if (!new_node)
		return (*tree);
	if (!*tree)
		return (new_node);
	cp_tree = *tree;
	while(1)
	{
		if (n < cp_tree->content)
			next_node = cp_tree->smallson;
		else
			next_node = cp_tree->bigson;
		if (next_node)
			cp_tree = next_node;
		else
		{
			next_node = new_node;
			break ;
		}
	}
	return (*tree);
}
