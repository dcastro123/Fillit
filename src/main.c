/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 16:55:42 by dcastro-          #+#    #+#             */
/*   Updated: 2017/03/16 21:21:53 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../libft/libft.h"

int		main(int argc, char **argv)
{
	char	**tetris_arr;
	int		fd;

	fd = 0;
	if (argc == 2)
	{
		if ((ft_file_read(fd = open(argv[1], O_RDONLY))) &&
			(ft_check_read(fd = open(argv[1], O_RDONLY))))
		{
			tetris_arr = ft_array_from_file(argv[1]);
			if (ft_block_chk(tetris_arr))
				ft_solve(tetris_arr);
			else
				ft_putstr("error\n");
			free(tetris_arr);
		}
		else
			ft_putstr("error\n");
	}
	else
		ft_putstr("usage: ./fillit sourcefile | cat -e\n");
	close(fd);
	return (0);
}
