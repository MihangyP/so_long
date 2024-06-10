/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_errors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:24:08 by pmihangy          #+#    #+#             */
/*   Updated: 2024/06/10 10:47:34 by pmihangy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static size_t	is_exist(const char *str)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (-1 == fd)
		return (0);
	return (1);
}

static size_t	is_ber_file(char *str)
{
	size_t	len;

	len = ft_strlen(str);
	is_exist(str);
	str += len - 4;
	if (!ft_strncmp(str, ".ber", len))
		return (1);
	return (0);
}

static void	show_args_error_message(void)
{
	ft_putstr_fd(
			"Error\n"
			"Usage: ./so_long *.ber\n",
			2);
}

void	handle_args_errors(int ac, char **av)
{
	if (ac != 2 || !is_ber_file(av[1]))
	{
		show_args_error_message();
		exit(69);
	}
	else if (!is_exist(av[1]))
	{
		show_args_error_message();
		ft_printf("File %s doesn't exist\n", av[1]);
		exit(69);
	}
}
