#include "libtree.h"

void	ft_delete_cnode(tn *tree, int content)
{
	tn	*node;

	node = ft_find_node(tree, content);
	if (!node)
		printf("can't find it!\n");
	else
	{
		ft_delete_node(tree, node);
		printf("delete!\n");
	}
}
