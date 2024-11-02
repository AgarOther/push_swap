/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:03:35 by scraeyme          #+#    #+#             */
/*   Updated: 2024/11/02 20:02:05 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **stack_a, t_list **stack_b, int is_pb)
{
	t_list	*tmp;
	
	tmp = *stack_b;
	if (*stack_b)
		*stack_b = (*stack_b)->next;
	else if (!(*stack_b)->next)
		*stack_b = NULL;
	ft_lstadd_front(stack_a, tmp);
	if (!is_pb)
		ft_putendl_fd("pa", 1);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	pa(stack_b, stack_a, 1);
	ft_putendl_fd("pb", 1);
}
