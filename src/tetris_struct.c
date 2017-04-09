/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetri_distance.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 19:25:23 by rramirez          #+#    #+#             */
/*   Updated: 2017/03/20 19:30:31 by dcastro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../includes/fillit.h"

void			ft_ydist(char **map, t_tetris *tstruct, int col)
{
	int	i;
	int	j;
	int	k;
	int	fp;

	i = - 1;
	k = 0;
	while (map[++i] != '\0')
	{
		j = - 1;
		while (map[i][++j] != '\0')
			if (map[i][j] != '.' && k == 0)
			{
				fp = j;
				tstruct->y_value[col][k] = 0;
				k++;
			}
			else if (k != 0 && map[i][j] != '.')
			{
				tstruct->y_value[col][k] = j - fp;
				k++;
			}
	}
	tstruct->y_value[col][4] = '\0';
}

void			ft_xdist(char **map, t_tetris *tstruct, int col)
{
	int	i;
	int	j;
	int	k;
	int	fp;

	i = 0;
	k = 0;
	fp = 0;
	while (map[i] != '\0')
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (map[i][j] != '.' && k == 0)
			{
				fp = i;
				tstruct->x_value[col][k] = 0;
				k++;
			}
			else if (k != 0 && map[i][j] != '.')
			{
				tstruct->x_value[col][k] = i - fp;
				k++;
			}
			j++;
		}
		i++;
	}
	tstruct->x_value[col][4] = '\0';
}

t_tetris		*ft_tet_distance(char **tetris_array, t_tetris *tstruct)
{
	int			col;
	char		**map;

	col = 0;
	while (col < g_num_tetris)
	{
		map = ft_strsplit(tetris_array[col], '\n');
		ft_ydist(map, tstruct, col);
		ft_xdist(map, tstruct, col);
		tstruct->letter[col] = 'A' + col;
		free(map);
		col++;
	}
	return (tstruct);
}

t_tetris		*ft_create_struct(void)
{
	t_tetris	*new_struct;
	int			k;

	k = 0;
	if (!(new_struct = malloc(sizeof(t_tetris))))
		return (0);
	if (!(new_struct->x_value = (int**)malloc(sizeof(int*) * g_num_tetris + 1)))
		return (0);
	if (!(new_struct->y_value = (int**)malloc(sizeof(int*) * g_num_tetris + 1)))
		return (0);
	while (k < g_num_tetris)
	{
		new_struct->x_value[k] = (int*)malloc(sizeof(int) * 5);
		new_struct->y_value[k] = (int*)malloc(sizeof(int) * 5);
		k++;
	}
	new_struct->letter = (char*)malloc(sizeof(char) * g_num_tetris + 1);
	return (new_struct);
}
