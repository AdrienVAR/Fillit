/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-maes <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 14:27:30 by nde-maes          #+#    #+#             */
/*   Updated: 2019/01/07 13:13:43 by nde-maes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

/*
** Check whether or not tetriminos can fit in the resulting square.
*/

int				tet_can_fit_on_res(char **res, char **current_tet)
{
	int				line;
	int				col;

	line = -1;
	while (res[++line])
	{
		col = -1;
		while (res[line][++col])
			if (current_tet[line][col] != '.' && res[line][col] != '.')
				return (0);
	}
	return (1);
}

/*
** Place the non-dot symbols (i.e. the tetriminos letter in our case)
** on the resulting square.
*/

void			place_tet_on_res(char **res, char **current_tet)
{
	int				line;
	int				col;

	line = -1;
	while (res[++line])
	{
		col = -1;
		while (res[line][++col])
			if (current_tet[line][col] != '.')
				res[line][col] = current_tet[line][col];
	}
}

static int		handle_move_tet(char **current_tet)
{
	int				dir;

	dir = tetriminos_can_move(current_tet);
	if (dir == 1)
		move_tet_right(current_tet);
	else if (dir == 2)
		move_tet_down_left(current_tet);
	else
	{
		free_sqr(current_tet);
		return (1);
	}
	return (0);
}

/*
** This function recursively adds tetriminos in the `res` square.
**
** `resolve_rec` copies the tetriminos to avoid spoiling the ones it receives,
** which are well positionned on the top left corner.
** As far as the result square is concerned, we delete the 4 letters of the
** current node, if we need to go to the previous call of the function.
*/

static void		resolve_rec(char **res, int dim, t_tet *tet, t_tet **tet_head)
{
	char			**current_tet;

	current_tet = copy_tet_with_dim(tet->piece, dim);
	while (1)
	{
		if (tet_can_fit_on_res(res, current_tet))
		{
			place_tet_on_res(res, current_tet);
			if (!(tet->next))
			{
				print_sqr(res);
				free_sqr(res);
				free_sqr(current_tet);
				free_lst(tet_head);
				exit(0);
			}
			resolve_rec(res, dim, tet->next, tet_head);
			delete_tet_on_res(res, tet->letter);
		}
		if (handle_move_tet(current_tet))
			return ;
	}
}

/*
** Entry point of the algo.
** A empty resulting square is created here, it is then passed to the recursive
** `resolve_rec` function which will fill it. At first the resulting square has
** a dimension of 4 because that's the smallest size possible it can have. If
** `resolve_rec` exits, a new resulting square with a dimension of 5 is created
** and passed to `resolve_rec`. So on till `resolve_rec` prints the most
** optimized square with all the tetriminos in it.
*/

void			resolve(t_tet **tet_head, int res_starting_dim)
{
	char			**res;
	int				dim;

	dim = res_starting_dim - 1;
	while (++dim)
	{
		if (dim > res_starting_dim)
			free_sqr(res);
		res = create_empty_sqr(dim);
		resolve_rec(res, dim, *tet_head, tet_head);
	}
}
