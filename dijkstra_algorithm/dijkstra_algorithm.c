#include <stdio.h>
#include <stdlib.h>

typedef struct	_my_node{
	struct _my_node	*next;
	char	name;
	int	weight;	
}my_node;

void	push_back_node(my_node *origin, my_node *new){
	my_node	*cp;

	cp = origin;
	while (1){
		if (cp->next == NULL)
			break;
		cp = cp->next;
	}
	cp->next = new;
	new->next = NULL;
}

void	insert_node(my_node *insert_point, my_node *new_node){
	new_node->next = insert_point->next;
	insert_point->next = new_node;	
}

void	free_all(my_node *head){
	int	idx;
	
	for (idx = 0 ; head != NULL ; head = head->next, idx++){
		printf("%c : %d\n", head->name, head->weight);
		free(head);
	}
}

int 	main(void){
	my_node	*head = malloc(sizeof(my_node));
	head->next = NULL;
	head->name = 'H';
	head->weight = 0;
	my_node	*A = malloc(sizeof(my_node));
	A->name = 'A';
	A->weight = 1;
	my_node	*B = malloc(sizeof(my_node));
	B->name = 'B';
	B->weight = 2;
	my_node	*C = malloc(sizeof(my_node));
	C->name = 'C';
	C->weight = 3;
	my_node	*D = malloc(sizeof(my_node));
	D->name = 'D';
	D->weight = 4;
	my_node	*Z = malloc(sizeof(my_node));
	Z->name = 'Z';
	Z->weight = 999;

	push_back_node(head, A);
	push_back_node(head, B);
	push_back_node(head, C);
	push_back_node(head, D);
	insert_node(B, Z);

	free_all(head);

	return (0);
}
