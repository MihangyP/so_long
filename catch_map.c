/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   catch_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 11:07:47 by pmihangy          #+#    #+#             */
/*   Updated: 2024/06/10 11:09:40 by pmihangy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_map	*catch_map(char *file)
{
	int		fd;
	t_map	*tmp;
	t_map	*map;
	t_map	*head;

	fd = open(file, O_RDONLY);
	if (-1 == fd)
		return (NULL);
	map = malloc(sizeof(t_map));
	if (NULL == map)
		return (NULL);
	head = map;
	map->content = get_next_line(fd);
	map->next = NULL;
	while (map->content)
	{
		tmp = map;
		map->next = malloc(sizeof(t_map));
		map = map->next;
		map->content = get_next_line(fd);
	}
	tmp->next = NULL;
	return (head);
}

