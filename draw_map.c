/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:55:16 by pmihangy          #+#    #+#             */
/*   Updated: 2024/06/10 16:40:14 by pmihangy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_pixel(t_img *img, int x, int y, int color)
{
	int	pos;

	pos = (y * img->size_len) + (x * (img->bpp / 8));
	*(unsigned int *)(pos + img->addr) = color;
}

void	draw_rect(t_data *data, int pos_x, int pos_y, int width, int height, int color)
{
	int	i;
	int	j;

	i = pos_y;
	while (i < pos_y + height)
	{
		j = pos_x;
		while (j < pos_x + width)
		{
			draw_pixel(&data->img, i, j, color);
			++j;
		}
		++i;
	}
}

void	draw_map(t_data *data, t_map *map)
{
	int	i;
	int	j;
	int	t;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			draw_pixel(&data->img, i, j, 0xFFFFFF);
			++j;
		}
		++i;
	}
	i = 0;
	j = 0;
	t = 0;
	while (map->content[t] != '\n')
	{
		draw_rect(data, i, j, 50, 150, 0x000000);
		j += 50 + 10;
		++t;
	}
	mlx_put_image_to_window(data->con,
				data->win,
				data->img.img_ptr,
				0,
				0);
}
