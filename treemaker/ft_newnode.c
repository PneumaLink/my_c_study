#include "tree.h"

tn	*ft_newnode(void *content)
{
	tn	*newnode;

	newnode = malloc(sizeof(tn));
	if (!newnode)
		return (NULL);
	newnode->contnet = content;
	newnode->next = NULL;
	return (newnode);
}
