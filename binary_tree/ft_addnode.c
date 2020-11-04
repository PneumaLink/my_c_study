#include "libtree.h"

void	ft_addnode(tn **tree, int n)
{
	tn	*new_n;
	tn	*next;

	new_n = ft_newnode(n);
	if (!new_n)
		return ;
	if (!(*tree))
	{
		*tree = new_n;
		return ;
	}
	while (1)
	{
		printf("%d-", (*tree)->content);
		if (n > (*tree)->content)
		{
			next = (*tree)->bigson;
			if (!next)
			{
				(*tree)->bigson = new_n;
				new_n->mom = (*tree);
				printf("\n");
				break ;
			}
		}
		else if (n < (*tree)->content)
		{
			next = (*tree)->smallson;
			if (!next)
			{
				(*tree)->smallson = new_n;
				new_n->mom = (*tree);
				printf("\n");
				break ;
			}
		}
		else
		{
			printf("\n");
			return ;
		}
		(*tree) = next;
	}
}
