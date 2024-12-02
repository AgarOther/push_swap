/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_moves_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:23:54 by scraeyme          #+#    #+#             */
/*   Updated: 2024/12/02 14:13:04 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	check_stack(t_list **stack_a, t_list **stack_b)
{
	char	**moves;
	int		i;

	moves = get_moves(0);
	i = 0;
	if (!check_moves(moves))
	{
		ft_tabfree(moves, ft_tablen((const char **)moves));
		return (0);
	}
	if (!moves || !*moves)
		return (1);
	while (moves[i])
	{
		do_move(stack_a, stack_b, moves[i]);
		i++;
	}
	ft_tabfree(moves, ft_tablen((const char **)moves));
	return (1);
}
