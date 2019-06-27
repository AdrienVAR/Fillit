#include "fillit.h"
#include <stdio.h>

int			main(int argc, char **argv)
{
	t_tet		*head;
	t_tet		*node;
	char		**piece;

	head = NULL;
	
	// create a list with 3 tetriminos
	piece = create_empty_sqr(4);
	piece[0][1] = '#';
	piece[0][2] = '#';
	piece[1][1] = '#';
	piece[1][2] = '#';
	create_node_to_end(&head, piece);

	piece = create_empty_sqr(4);
	piece[0][2] = '#';
	piece[1][2] = '#';
	piece[2][2] = '#';
	piece[3][2] = '#';
	create_node_to_end(&head, piece);

	piece = create_empty_sqr(4);
	piece[3][0] = '#';
	piece[3][1] = '#';
	piece[3][2] = '#';
	piece[3][3] = '#';
	create_node_to_end(&head, piece);

	// show list before normalization
	node = head;
	while (node)
	{
		printsqr(node->piece);
		printf("\n");
		node = node->next;
	}

	// normalize list and show new state of the list
	normalize_lst(&head);
	node = head;
	while (node)
	{
		printsqr(node->piece);
		printf("\n");
		node = node->next;
	}

	return (0);
}
