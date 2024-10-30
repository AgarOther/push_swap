/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 18:17:25 by scraeyme          #+#    #+#             */
/*   Updated: 2024/10/30 18:21:36 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **stack_a, int is_rr)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp && tmp->next && tmp->next->next)
		tmp = tmp->next;
	tmp->next->next = *stack_a;
	*stack_a = tmp->next;
	tmp->next = NULL;
	if (!is_rr)
		ft_putendl_fd("rra", 1);
}

void	rrb(t_list **stack_b, int is_rr)
{
	rra(stack_b, is_rr);
	if (!is_rr)
		ft_putendl_fd("rrb", 1);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a, 1);
	rrb(stack_b, 1);
	ft_putendl_fd("rrr", 1);
}
