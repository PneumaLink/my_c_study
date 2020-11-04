#include "libtree.h"

void	ft_addnode(tn **tree, int n)
{
	tn	*new_n;
	tn	*next;

	new_n = malloc(sizeof(tn));
	if (!new_n)
		return ;
	if (!(*tree))
	{
		*tree = new_n;
		return ;
	}
	while (1)
	{
		if (n > (*tree)->content)
			next = (*tree)->bigson;
		else if (n < (*tree)->content)
			next = (*tree)->smallson;
		else
			return ;

		if (!next)
		{
			next = new_n;
			new_n->mom = *tree;
			return ;
		}else
			(*tree) = next;
	}
}
