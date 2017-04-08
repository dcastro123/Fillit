/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/24 17:58:59 by dcastro-          #+#    #+#             */
/*   Updated: 2017/03/18 19:12:39 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../libft/libft.h"

int			map_size(void)
{
	int 	a;
	int		pieces;

	a = 2;
	pieces = (g_num_tetris * 4);
	while ((a * a) - pieces < 0)
		a++;
	return (a);
}

static char **ft_insert_dots(char **new_map)
{
	int i;
	int j;

	i = 0;
	while (i < g_map_size)
	{
		j = 0;
		while (j < g_map_size)
		{
			new_map[i][j] = '.';
			j++;
		}
		new_map[i][j] = '\0';
		i++;
	}
	new_map[i] = 0;
	return (new_map);
}
char		**create_map(void)
{
	char	**new_map;
	int		i;
	int		j;

	i = 0;
	new_map = (char**)malloc(sizeof(char*) * (g_map_size + 1));
	j = 0;
	while (j < g_map_size)
	{
		new_map[j] = (char*)malloc(sizeof(char) * (g_map_size + 1));
		j++;
	}
	new_map = ft_insert_dots(new_map);
	return (new_map);
}

void	print_map(char **new_map)
{
	int	i;
	int	j;

	i = 0;
	while (new_map[i] != '\0')
	{
		j = 0;
		while (new_map[i][j] != '\0')
		{
			// if (j == 4)
			// {
			// 	ft_putchar('\n');
			// 	j = 0;
			// }
			ft_putchar(new_map[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
