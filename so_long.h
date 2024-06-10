/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:52:31 by pmihangy          #+#    #+#             */
/*   Updated: 2024/06/10 13:28:40 by pmihangy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "libft/libft.h"

typedef struct	s_map
{
	char			*content;
	struct s_map	*next;
}	t_map;

/* Errors handlers functions prototypes */
void	handle_args_errors(int ac, char **av);

/* map manip */
t_map	*catch_map(char *file);
/* map errors */
void	handle_map_errors(t_map *map);

#endif
