#include "libtree.h"

void	ft_deleting(tn *tree, tn *node)
{
	tn	*cp_node;

	cp_node = node;
	if (tree->content < node->content)
	{
		while(cp_node->smallson)
			cp_node = cp_node->smallson;
		cp_node->mom->smallson = NULL;
		cp_node->mom = node->mom;
	}
	else
	{
		while(cp_node->bigson)
			cp_node = cp_node->bigson;
		cp_node->mom->bigson = NULL;
		cp_node->mom = node->mom;
	}
}

void	ft_delete_node(tn *tree, int content)
{
	tn	*node;

	node = ft_find_node(tree, content);
	if (!node)
		printf("not find!!!!\n");
	else
		ft_deleting(tree, node);
}
