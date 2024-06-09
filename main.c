/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:51:28 by pmihangy          #+#    #+#             */
/*   Updated: 2024/06/09 16:25:19 by pmihangy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx/mlx.h"

int	main(int ac, char **av)
{
	void	*con;
	void	*win;

	con = mlx_init();
	win = mlx_new_window(con, 800, 800, "Donto");
	mlx_loop(con);
	return (0);
}
