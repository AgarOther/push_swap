/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 17:13:26 by scraeyme          #+#    #+#             */
/*   Updated: 2024/10/31 09:42:35 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **stack_a, int is_rr)
{
	t_list	*head;
	t_list	*last;

	head = *stack_a;
	last = ft_lstlast(*stack_a);
	*stack_a = head->next;
	last->next = head;
	head->next = NULL;
	if (!is_rr)
		ft_putendl_fd("ra", 1);
}

void	rb(t_list **stack_b, int is_rr)
{
	ra(stack_b, 1);
	if (!is_rr)
		ft_putendl_fd("rb", 1);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a, 1);
	rb(stack_b, 1);
	ft_putendl_fd("rr", 1);
}
