/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 10:20:41 by pmihangy          #+#    #+#             */
/*   Updated: 2024/06/11 13:04:02 by pmihangy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	handle_key_press(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_display(data->con);
		mlx_destroy_window(data->con, data->win);
		free(data);
		exit(69);
	}
	if (keysym == XK_Left)
	{
		printf("left\n");
	}
	if (keysym == XK_Right)
	{
		printf("right\n");
	}
	if (keysym == XK_Up)
	{
		printf("up\n");
	}
	if (keysym == XK_Down)
	{
		printf("down\n");
	}
}

void	listen_events(t_data *data)
{
	mlx_hook(data->win, KeyPress, KeyPressMask, handle_key_press, data);	
}
