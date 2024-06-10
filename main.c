/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:51:28 by pmihangy          #+#    #+#             */
/*   Updated: 2024/06/10 15:56:52 by pmihangy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_map	*map;
	t_data	*data;

	handle_args_errors(ac, av);
	map = catch_map(av[1]);
	if (NULL == map)
		return (69);
	handle_map_errors(map);
	data = malloc(sizeof(t_data));
	if (NULL == data)
		return (69);
	init_so_long(data);
	draw_map(data, map);
	mlx_loop(data->con);
	return (0);
}
