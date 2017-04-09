/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_read.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 18:09:51 by dcastro-          #+#    #+#             */
/*   Updated: 2017/03/18 21:29:14 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../libft/libft.h"

int			ft_check_read(int fd)
{
	char	buff[21];
	int		curr;
	int		last;

	while ((curr = read(fd, buff, 21)))
	{
		buff[curr] = '\0';
		last = curr;
	}
	return ((last == 20) ? 1 : 0);
}

char		**ft_tetris_create(char **tetris_array, int fd)
{
	char	buff[1];
	int		num_lines;
	int		a;
	int		b;

	a = 0;
	b = 0;
	while (read(fd, buff, 1))
	{
		b = 0;
		num_lines = 0;
		while (num_lines != 4)
		{
			if (*buff == '\n')
				num_lines++;
			tetris_array[a][b] = *buff;
			b++;
			read(fd, buff, 1);
		}
		tetris_array[a][b] = '\0';
		a++;
	}
	tetris_array[a] = 0;
	return (tetris_array);
}

char		**ft_array_from_file(char *file)
{
	int		fd;
	int		i;
	char	**tetris_array;

	tetris_array = (char **)malloc(sizeof(char*) * g_num_tetris + 1);
	i = 0;
	while (i < g_num_tetris)
	{
		tetris_array[i] = (char*)malloc((sizeof(char) * 21));
		i++;
	}
	fd = open(file, O_RDONLY);
	tetris_array = ft_tetris_create(tetris_array, fd);
	close(fd);
	return (tetris_array);
}
