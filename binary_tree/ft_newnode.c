#include "libtree.h"

tn	*ft_newnode(int content)
{
	tn	*newnode;

	newnode = (tn *)malloc(sizeof(tn));
	if (!newnode)
		return (NULL);
	newnode->content = content;
	newnode->mom = NULL;
	newnode->bigson = NULL;
	newnode->smallson = NULL;
	return (newnode);
}
