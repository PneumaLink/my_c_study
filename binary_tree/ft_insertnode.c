#include "libtree.h"
#include <stdio.h>

void	ft_insertnode(tn *tree, int n)
{
	tn	*new_n;
	tn	**next;

	new_n = ft_createnote(n);
	if (!new_n)
		return ;
	while (1)
	{
		printf("%d",tree->content);
		if (n < tree->content)
			next = &(tree->smallson);
		else if (n > tree->content)
			next = &(tree->bigson);
		if (!*next)
		{
			*next = new_n;
			new_n->mom = tree;
			printf("->%d\n", (*next)->content);
			return ;
		}
		else
		{
			tree = *next;
			printf("->");
		}
	}
}
