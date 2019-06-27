#include "fillit.h"
#include <stdio.h>

int			main(int argc, char **argv)
{
	t_tet		*head;
	t_tet		*node;
	char		**piece;

	head = NULL;
	
	// create tetriminos

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

	piece = create_empty_sqr(4);
	piece[1][2] = '#';
	piece[1][3] = '#';
	piece[2][3] = '#';
	piece[3][3] = '#';
	create_node_to_end(&head, piece);

	piece = create_empty_sqr(4);
	piece[0][0] = '#';
	piece[0][1] = '#';
	piece[1][0] = '#';
	piece[1][1] = '#';
	create_node_to_end(&head, piece);

	piece = create_empty_sqr(4);
	piece[1][2] = '#';
	piece[1][3] = '#';
	piece[2][1] = '#';
	piece[2][2] = '#';
	create_node_to_end(&head, piece);

	// normalize, then run the algo

	normalize_lst(&head);
	node = head;
	while (node)
	{
		printsqr(node->piece);
		printf("\n");
		node = node->next;
	}

	resolve(&head);

	return (0);
}
