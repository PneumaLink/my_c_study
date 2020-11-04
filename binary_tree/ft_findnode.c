#include "libtree.h"

tn	*ft_findnode(tn *head, int n)
{
	while (head)
	{
		if (n == head->content)
			break ;
		else if (n > head->content)
			head = head->bigson;
		else
			head = head->smallson;
	}
	return (head);
}
