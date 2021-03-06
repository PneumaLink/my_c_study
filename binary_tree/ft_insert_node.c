#include "libtree.h"

void	ft_insert_node(tn *tree, tn *node)
{
	tn	**next;
	int	n;

	n = node->content;
	if (!node)
		return ;
	while (1)
	{
		if (n < tree->content)
			next = &(tree->smallson);
		else if (n > tree->content)
			next = &(tree->bigson);
		if (!*next)
		{
			*next = node;
			node->mom = tree;
			return ;
		}
		else
			tree = *next;
	}
}
