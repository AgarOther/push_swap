/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:00:27 by scraeyme          #+#    #+#             */
/*   Updated: 2024/12/03 22:23:43 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_current_pos(t_list *stack_b, int n)
{
	t_list	*tmp;
	int		i;

	tmp = stack_b;
	i = 0;
	while (tmp)
	{
		if (tmp->rank == n)
			return (i);
		i++;
		tmp = tmp->next;
	}
	return (-1);
}

int	is_optimizable(t_list **stack_b, int size)
{
	int		pos1;
	int		pos2;
	int		median;

	pos1 = get_current_pos(*stack_b, size);
	pos2 = get_current_pos(*stack_b, size - 1);
	median = size / 2;
	if (pos2 < pos1 && pos1 <= median && pos2 <= median)
		return (1);
	else if (pos2 > pos1 && pos1 > median && pos2 > median)
		return (1);
	return (0);
}

int	get_highest_pos(t_list *stack_b, int size)
{
	t_list	*tmp;
	int		i;

	tmp = stack_b;
	i = 0;
	while (tmp && tmp->rank != size)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
