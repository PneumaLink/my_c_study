#include "libtree.h"

int	main()
{
	int	arr[] = {5,1,9,2,8,10,3,7,4,6};
	int	arr2[] = {0,5,1,99,2,88,3,77,4,66,10};
	int	idx;
	tn	*head;
	tn	*pin;
	tn	*cp_head;

	head = NULL;
	for (idx = 0 ; idx < 10 ; idx++)
		ft_addnode(&head, arr[idx]);
	for (idx = 0 ; idx < 11 ; idx++)
	{
		printf("%d... ... ...\n", arr2[idx]);
		pin = ft_findnode(head, arr2[idx]);
		if (pin)
			printf("found it %d\n", arr2[idx]);
	}
	return (0);
}
