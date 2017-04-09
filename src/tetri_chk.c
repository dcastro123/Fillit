/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_chk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 15:24:45 by dcastro-          #+#    #+#             */
/*   Updated: 2017/03/15 18:57:34 by rramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../libft/libft.h"

static	int	file_check(int fd, char *buff, int num_columns, int num_lines)
{
	while ((read(fd, buff, 1)))
	{
		if (*buff != '\n' && *buff != '.' && *buff != '#')
			return (0);
		else if (*buff == '\n')
		{
			num_lines++;
			read(fd, buff, 1);
			if (num_columns != 4 || ((*buff == '\n') && (num_lines != 4)))
				return (0);
			num_columns = 0;
			if (*buff == '\n' && num_lines == 4)
			{
				g_num_tetris++;
				num_lines = 0;
			}
			else
				num_columns++;
		}
		else
			num_columns++;
	}
	close(fd);
	return ((*buff == '\n') ? 1 : 0);
}

int			ft_file_read(int fd)
{
	char	buff[1];
	int		num_lines;
	int		num_columns;

	num_lines = 0;
	num_columns = 0;
	if (fd < 1)
		return (0);
	if ((file_check(fd, buff, num_columns, num_lines) == 1))
		return (1);
	else
		return (0);
}

static	int	ft_count_blocks(char *tet_arr)
{
	int	i;
	int	num_chars;

	i = -1;
	num_chars = 0;
	while (++i < 21 && tet_arr[i] != '\0')
	{
		if (tet_arr[i] == '#')
			num_chars++;
	}
	return ((num_chars == 4) ? 1 : 0);
}

static	int	ft_touch_check(char *tet_arr)
{
	int	i;
	int	touches;

	touches = 0;
	i = 0;
	while (tet_arr[i] != '\0')
	{
		if (tet_arr[i] == '#')
		{
			if (tet_arr[i + 1] == '#')
				touches++;
			if (tet_arr[i - 1] == '#')
				touches++;
			if (tet_arr[i + 5] == '#')
				touches++;
			if (tet_arr[i - 5] == '#')
				touches++;
		}
		i++;
	}
	return ((touches == 6 || touches == 8) ? 1 : 0);
}

int			ft_block_chk(char **tet_arr)
{
	int	i;

	i = 0;
	while (i < g_num_tetris)
	{
		if (!(ft_count_blocks(tet_arr[i])) || (!(ft_touch_check(tet_arr[i]))))
			return (0);
		i++;
	}
	return (1);
}
