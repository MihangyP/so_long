/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:23:35 by pmihangy          #+#    #+#             */
/*   Updated: 2024/06/10 14:12:57 by pmihangy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	is_close(t_map *map)
{
	int	i;
	int	j;

	j = 0;
	while (map)
	{
		i = 0;
		while (map->content[i] != '\n')
		{
			if ((i == 0 && map->content[i] != '1') 
				|| (map->content[i + 1] == '\n' && map->content[i] != '1'))
				return (0);
			if ((j == 0 && map->content[i] != '1') 
				|| (map->next == NULL && map->content[i] != '1'))
				return (0);
			++i;
		}
		++j;
		map = map->next;
	}
	return (1);
}

static size_t	count_head_line_len(t_map *map)
{
	int	len;

	len = 0;
	while (map->content[len] != '\n')
		++len;
	return (len);
}

static size_t	is_rect(t_map *map)
{
	int	i;
	int	j;

	i = count_head_line_len(map);
	while (map)
	{
		j = 0;
		while (map->content[j] != '\n')
			++j;
		if (i != j)
			return (0);
		map = map->next;
	}
	return (1);
}

static void	count_each_elements(t_map *map, int *elements)
{
	int	i;

	i = 0;
	while (map)
	{
		i = 0;
		while (map->content[i] != '\n')
		{
			if (map->content[i] == 'P')
				elements[0]++;
			else if (map->content[i] == 'C')
				elements[1]++;
			else if (map->content[i] == 'E')
				elements[2]++;
			++i;
		}
		map = map->next;
	}
}

void	handle_map_errors(t_map *map)
{
	int	elements[3] = {0};
	int	i;

	if (!is_close(map))
	{
		ft_putstr_fd("Error\n"
				"Your map is not close\n", 2);
		exit(69);
	}
	else if (!is_rect(map))
	{
		ft_putstr_fd("Error\n"
				"Your map don't form a rectangle\n", 2);
		exit(69);
	}
	count_each_elements(map, elements);
	i = 0;
	while (i < 3)
	{
		if (elements[i] != 1)
		{
			ft_putstr_fd("Error\n"
					"Should have only 1 Player, 1 Exit and 1 Item\n", 2);
			break ;
		}
		++i;
	}
}
