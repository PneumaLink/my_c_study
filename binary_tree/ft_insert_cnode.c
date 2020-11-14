#include "libtree.h"

void	ft_insert_cnode(tn *tree, int n)
{
	tn	*new_n;
	tn	**next;

	new_n = ft_create_node(n);
	if (!new_n)
		return ;
	while (1)
	{
		if (n < tree->content)
			next = &(tree->smallson);
		else if (n > tree->content)
			next = &(tree->bigson);
		if (!*next)
		{
			*next = new_n;
			new_n->mom = tree;
			return ;
		}
		else
			tree = *next;
	}
}
