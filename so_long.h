/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:52:31 by pmihangy          #+#    #+#             */
/*   Updated: 2024/06/11 12:29:02 by pmihangy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "libft/libft.h"
# include "minilibx/mlx.h"
# include <X11/keysym.h>
# include <X11/X.h>

#define WIDTH 800
#define HEIGHT 800

#define BLACK 0x000000
#define WHITE 0xFFFFFF
#define RED 0xFF0000
#define GREEN 0x00FF00
#define YELLOW 0xFFFF00

typedef struct	s_map
{
	char			*content;
	struct s_map	*next;
}	t_map;

typedef struct	s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		size_len;
	int		endian;
}	t_img;

typedef struct	s_data
{
	void	*con;
	void	*win;
	t_img	img;
	t_map	*map;
}	t_data;

/* Errors handlers functions prototypes */
void	handle_args_errors(int ac, char **av);

/* map manip */
t_map	*catch_map(char *file);
/* map errors */
void	handle_map_errors(t_map *map);
/* init */
void	init_so_long(t_data *data, t_map *map);
/* draw map */
void	draw_map(t_data *data);
/* shapes */
void	draw_pixel(t_img *img, int x, int y, int color);
void	draw_rect(t_data *data, int pos_x, int pos_y, int width, int height, int color);
void	draw_circle(t_data *data, int center_x, int center_y, float radius, int color);
void	draw_filled_circle(t_data *data, int center_x, int center_y, float radius, int color);
/* events */
void	listen_events(t_data *data);
#endif
