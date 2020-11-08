#include "libtree.h"

int	main()
{
	int	arr[] = {10,5,4,3,2,1,6,7,8};
	int	arr2[] = {0,5,1,99,2,88,3,77,4,66,10};
	int	idx;
	tn	*head;
	tn	*pin;
	tn	*cp_head;

	head = ft_createnote(arr[0]);
	if (!head)
	{
		printf("head allocate fall!!\n");
		return (0);
	}
	printf("push node...\n");
	for (idx = 1 ; idx < 9 ; idx++)
	{
		printf("insert %d\n", arr[idx]);
		ft_insertnode(head, arr[idx]);
	}
	printf("push finish!\n");
	for (idx = 0 ; idx < 11 ; idx++)
	{
		pin = ft_findnode(head, arr2[idx]);
		printf("%d is... ", arr2[idx]);
		if (pin)
			printf("found it %d\n", arr2[idx]);
		else
			printf("not found\n");
	}
	return (0);
}
