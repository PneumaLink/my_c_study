#include "libtree.h"

tn	*ft_findnode(tn *head, int n)
{
	while (head)
	{
		if (head->content == n)
		{
			printf("find it !! break\n");
			break ;
		}
		if (head->content < n)
		{
			printf("move big...\n");
			head = head->bigson;
		}
		else
		{
			printf("move small...\n");
			head = head->smallson;
		}
	}
	return (head);
}
