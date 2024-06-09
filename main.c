/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:51:28 by pmihangy          #+#    #+#             */
/*   Updated: 2024/06/09 16:42:42 by pmihangy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx/mlx.h"

int	main(int ac, char **av)
{
	t_map	*map;
	int		fd;
	char	*s;

	fd = open(av[1], O_RDONLY);
	if (-1 == fd)
		return (69);
	s = get_next_line(fd);
	map->content = get_next_line(fd);
	while (s)
	{
		map->content = get_next_line(fd);
		s = get_next_line(fd);
	}
	return (0);
}
