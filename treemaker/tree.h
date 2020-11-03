#include <stdlib.h>

typedef struct	tree_node
{
	struct tree_node	*mom;
	int					contnet;
	struct tree_node	*bigson;
	struct tree_node	*smallson;
}	tn;

tn				*ft_newnode(int content);
