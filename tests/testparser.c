#include "../fillit.h"

t_tet	**parse_input(int fd);
void	create_node_to_end(t_tet **head, char **piece);

int			main(int ac, char **av)
{
	t_tet			**head_lst;
	int 			fd;
	if (ac == 2)
	{
	if ((fd = open(av[1], O_RDONLY)) == -1)
		{
            write(2, "error\n", 6);
            exit(1);
        }
		head_lst = parse_input(fd);
	}
	else
		ft_putstr("usage: ./fillit source_file\n");
	return (0);
}
