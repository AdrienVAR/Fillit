#include "fillit.h"
#include <stdio.h>

int			main(void)
{
	char		**sqr;
	char		**sqr2;
	char		**empty_sqr;

	// create a tetriminos and move it rightwards
	sqr = create_empty_sqr(4);
	sqr[0][1] = '#';
	sqr[0][2] = '#';
	sqr[1][1] = '#';
	sqr[1][2] = '#';
	printsqr(sqr);
	printf("\n");
	printf("tetriminos_can_move(sqr): %d\n", tetriminos_can_move(sqr));
	move_tet_right(sqr);
	printsqr(sqr);

	// duplicate the tetriminos with a larger dimension
	// and try moving it backwards/leftwards
	sqr2 = copy_tet_with_dim(sqr, 5);
	printf("sqr2, the copy of sqr\n");
	printsqr(sqr2);
	printf("tetriminos_can_move(sqr2): %d\n", tetriminos_can_move(sqr2));
	move_tet_down_left(sqr2);
	printsqr(sqr2);

	// empty square of dimension 5, a dummy resulting square
	// try placing sqr2 (of same dim) in it, then remove sqr2 from it
	empty_sqr = create_empty_sqr(5);
	printf("dummy resulting square\n");
	printsqr(empty_sqr);
	printf("sqr2 can fit in res: %d\n", tet_can_fit_on_res(empty_sqr, sqr2));
	printf("placing sqr2 in res\n");
	place_tet_on_res(empty_sqr, sqr2);
	printsqr(empty_sqr);
	// printf("removing srq2 chars from res\n");
	// delete_tet_on_res(empty_sqr, '#');
	// printsqr(empty_sqr);
	printf("\n");

	// free the tetriminos, to avoid leaks
	free_sqr(sqr);
	free_sqr(sqr2);

	return (0);
}
