#include "libtree.h"

tn	*ft_create_node(int n)
{
	tn	*newnode;

	newnode = (tn*)malloc(sizeof(tn));
	if (!newnode)
		return (NULL);
	newnode->content = n;
	newnode->mom = NULL;
	newnode->bigson = NULL;
	newnode->smallson = NULL;
	return (newnode);
}
