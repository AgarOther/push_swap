/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 16:00:27 by scraeyme          #+#    #+#             */
/*   Updated: 2024/12/02 17:32:43 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_reach(t_list **stack)
{
	t_list	*head;
	int		i;
	int		j;
	int		size;

	head = *stack;
	i = 0;
	j = 0;
	size = ft_lstsize(*stack);
	while (*stack)
	{
		(*stack)->reach = j;
		if (i - 1 < (size - 1) / 2)
		{
			if (size % 2 == 0 || (size % 2 && i < (size - 1) / 2))
				j++;
		}
		else
			j--;
		*stack = (*stack)->next;
		i++;
	}
}
