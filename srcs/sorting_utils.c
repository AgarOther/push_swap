/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:00:27 by scraeyme          #+#    #+#             */
/*   Updated: 2024/12/03 18:07:52 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_highest_pos(t_list **stack_b, int size)
{
	t_list	*tmp;
	int		i;

	tmp = *stack_b;
	i = 0;
	while (tmp && tmp->rank != size)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
