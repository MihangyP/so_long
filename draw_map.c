/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:55:16 by pmihangy          #+#    #+#             */
/*   Updated: 2024/06/11 12:30:45 by pmihangy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/*
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
*/

size_t	count_map_width(t_map *map)
{
	int	len;

	len = 0;
	while (map->content[len] != '\n')
		++len;
	return (len);
}

size_t	count_map_height(t_map *map)
{
	int len;

	len = 0;
	while (map)
	{
		++len;
		map = map->next;
	}
	return (len);
}

void	draw_map(t_data *data)
{
	int	i;
	int	j;
	int	t;
	size_t	map_width;
	size_t	map_height;
	t_map	*curr;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			draw_pixel(&data->img, i, j, WHITE);
			++j;
		}
		++i;
	}
	i = 0;
	j = 0;
	map_width = count_map_width(data->map);
	map_height = count_map_height(data->map);
	curr = data->map;
	while (curr)
	{
		t = 0;
		while (curr->content[t] != '\n')
		{
			if (curr->content[t] == '1')
				draw_rect(data, i, j, (int)(WIDTH/map_width), (int)(HEIGHT/map_height), BLACK);
			else if (curr->content[t] == 'P')
			{
				draw_rect(data, i, j, (int)(WIDTH/map_width), (int)(HEIGHT/map_height), RED);
			}
			else if (curr->content[t] == 'C')
				draw_rect(data, i, j, (int)(WIDTH/map_width), (int)(HEIGHT/map_height), GREEN);
			else if (curr->content[t] == 'E')
				draw_rect(data, i, j, (int)(WIDTH/map_width), (int)(HEIGHT/map_height), YELLOW);
			i += (int)(WIDTH/map_width) + 1;
			++t;
		}
		j += (int)(HEIGHT/map_height);
		curr = curr->next;
	}
	mlx_put_image_to_window(data->con,
				data->win,
				data->img.img_ptr,
				0,
				0);
}
