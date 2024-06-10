/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:52:31 by pmihangy          #+#    #+#             */
/*   Updated: 2024/06/10 15:56:35 by pmihangy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"
# include "minilibx/mlx.h"

#define WIDTH 800
#define HEIGHT 800

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
}	t_data;

/* Errors handlers functions prototypes */
void	handle_args_errors(int ac, char **av);

/* map manip */
t_map	*catch_map(char *file);
/* map errors */
void	handle_map_errors(t_map *map);
/* init */
void	init_so_long(t_data *data);
/* draw map */
void	draw_map(t_data *data, t_map *map);

#endif
