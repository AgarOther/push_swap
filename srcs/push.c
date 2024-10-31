/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:03:35 by scraeyme          #+#    #+#             */
/*   Updated: 2024/10/31 10:14:45 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **stack_a, t_list **stack_b, int is_pb)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp->next->next)
		tmp = tmp->next;
	ft_lstlast(*stack_b)->next = (*stack_a)->next;
	(*stack_a)->next = NULL;
	if (!is_pb)
		ft_putendl_fd("pa", 1);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	pa(stack_b, stack_a, 1);
	ft_putendl_fd("pb", 1);
}
