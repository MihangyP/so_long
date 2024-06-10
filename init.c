/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:32:21 by pmihangy          #+#    #+#             */
/*   Updated: 2024/06/10 15:54:41 by pmihangy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_so_long(t_data *data)
{
	data->con = mlx_init();
	if (NULL == data->con)
		exit(69);
	data->win = mlx_new_window(data->con, WIDTH, HEIGHT, "So Long");
	if (NULL == data->win)
	{
		mlx_destroy_display(data->con);
		free(data->con);
		exit(69);
	}
	data->img.img_ptr = mlx_new_image(data->con, WIDTH, HEIGHT);
	data->img.addr = mlx_get_data_addr(data->img.img_ptr, 
										&(data->img.bpp),
										&(data->img.size_len), 
										&(data->img.endian));
}
