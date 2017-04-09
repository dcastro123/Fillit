/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetris_solve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 14:54:45 by rramirez          #+#    #+#             */
/*   Updated: 2017/03/20 23:07:03 by rramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"
#include "../libft/libft.h"

void	ft_remove_tetri(t_tetris *tstruct, char **solution_map, int tet)
{
	int i;
	int j;

	tstruct->tet_value = tet;
	i = 0;
	while (i < g_map_size)
	{
		j = 0;
		while (j < g_map_size)
		{
			if (solution_map[i][j] == tstruct->letter[tstruct->tet_value])
			{
				solution_map[i][j] = '.';
			}
			j++;
		}
		i++;
	}
}

int		ft_check_placement(char **solution_map, t_tetris *tstruct, int y, int k)
{
	int i;
	int j;
	int h;

	i = 0;
	h = 0;
	while (solution_map[i] != '\0')
	{
		j = 0;
		while (solution_map[i][j] != '\0' && h < 4)
		{
			if (solution_map[i][j] == '.')
			{
				if ((i == (tstruct->x_value[tstruct->tet_value][h]) + y) &&
					(j == (tstruct->y_value[tstruct->tet_value][h]) + k))
				{
					h++;
				}
			}
			j++;
		}
		i++;
	}
	return ((h == 4) ? 1 : 0);
}

void	ft_place_piece(char **solution_map, t_tetris *tstruct, int y, int k)
{
	int i;
	int	j;

	i = 0;
	j = tstruct->tet_value;
	while (i < 4)
	{
		solution_map[y + tstruct->x_value[j][i]]
			[k + tstruct->y_value[j][i]] = tstruct->letter[j];
		i++;
	}
}

int		ft_solve_tetris(t_tetris *tstruct, char **solution_map, int tet)
{
	int y;
	int k;

	y = 0;
	tstruct->tet_value = tet;
	if (tstruct->letter[tet] == '\0')
		return (1);
	while (solution_map[y] != '\0')
	{
		k = 0;
		while (solution_map[y][k] != '\0')
		{
		//	print_map(solution_map);
			if (ft_check_placement(solution_map, tstruct, y, k))
			{
				ft_place_piece(solution_map, tstruct, y, k);
				if (ft_solve_tetris(tstruct, solution_map, ++tet))
					return (1);
				ft_remove_tetri(tstruct, solution_map, --tet);
			}
			k++;
		}
		y++;
	}
	return (0);
}

void	ft_solve(char **tetris_array)
{
	char		**solution_map;
	int			i;
	t_tetris	*tstruct;

	i = 0;
	tstruct = ft_create_struct();
	tstruct = ft_tet_distance(tetris_array, tstruct);
	g_map_size = map_size();
	solution_map = create_map();
	while (!ft_solve_tetris(tstruct, solution_map, 0))
	{
		free(solution_map);
		i++;
		g_map_size = map_size() + i;
		solution_map = create_map();
	}
	print_map(solution_map);
}
