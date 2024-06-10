/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmihangy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 15:51:28 by pmihangy          #+#    #+#             */
/*   Updated: 2024/06/10 13:19:17 by pmihangy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx/mlx.h"

/*
La carte sera construite en utilisant 3 éléments : les murs, les items à collecter,
et l’espace vide.
• Votre carte peut être composée de ces 5 caractères :
0 pour un emplacement vide,
1 pour un mur,
C pour un item à collecter (C pour collectible),
E pour une sortie (E pour exit),
P pour la position de départ du personnage.
Exemple de carte basique :
1111111111111
10010000000C1
1000011111001
1P0011E000001
1111111111111
• La carte doit contenir 1 sortie, au moins 1 item et 1 position de départ.
Si la map contient des doublons, vous devez afficher un message
d’erreur.
• La carte doit être de forme rectangulaire.
• La carte doit être fermée en étant encadrée par des murs. Si ce n’est pas le cas, le
programme retourne une erreur.
• Vous devez vérifier s’il existe un chemin valide (i.e. qu’il est possible d’emprunter)
dans la carte.
• Vous devez pouvoir parser tout type de carte du moment qu’elle respecte les règles
énoncées ci-dessus.
• Un autre exemple de carte .ber basique :
1111111111111111111111111111111111
1E0000000000000C00000C000000000001
1010010100100000101001000000010101
1010010010101010001001000000010101
1P0000000C00C0000000000000000000C1
1111111111111111111111111111111111
• Si une erreur de configuration est détectée, le programme doit quitter proprement
et retourner "Error\n" suivi d’un message d’erreur explicite de votre choix.
*/

size_t	is_close(t_map *map)
{
	int	i;
	int	j;

	j = 0;
	while (map)
	{
		i = 0;
		while (map->content[i] != '\n')
		{
			if ((i == 0 && map->content[i] != '1') 
				|| (map->content[i + 1] == '\n' && map->content[i] != '1'))
				return (0);
			if ((j == 0 && map->content[i] != '1') 
				|| (map->next == NULL && map->content[i] != '1'))
				return (0);
			++i;
		}
		++j;
		map = map->next;
	}
	return (1);
}

size_t	count_head_line_len(t_map *map)
{
	int	len;

	len = 0;
	while (map->content[len] != '\n')
		++len;
	return (len);
}

size_t	is_rect(t_map *map)
{
	int	i;
	int	j;

	i = count_head_line_len(map);
	while (map)
	{
		j = 0;
		while (map->content[j] != '\n')
			++j;
		if (i != j)
			return (0);
		map = map->next;
	}
	return (1);
}

void	handle_map_errors(t_map *map)
{
	if (!is_close(map))
	{
		ft_putstr_fd(
				"Error\n"
				"Your map is not close",
				2);
		exit(69);
	}
	else if (!is_rect(map))
	{
		ft_putstr_fd("Error\n"
				"Your map don't form a rectangle", 2);
		exit(69);
	}
}

int	main(int ac, char **av)
{
	t_map	*map;

	handle_args_errors(ac, av);
	map = catch_map(av[1]);
	if (NULL == map)
		return (69);
	handle_map_errors(map);
	return (0);
}
