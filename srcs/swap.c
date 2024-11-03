/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 09:31:32 by scraeyme          #+#    #+#             */
/*   Updated: 2024/10/31 22:21:56 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **stack_a, int is_ss)
{
	t_list	*first;
	t_list	*second;

	if (!*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack_a = second;
	if (!is_ss)
		ft_putendl_fd("sa", 1);
}

void	sb(t_list **stack_b, int is_ss)
{
	sa(stack_b, 1);
	if (!is_ss)
		ft_putendl_fd("sb", 1);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	sa(stack_a, 1);
	sb(stack_b, 1);
	ft_putendl_fd("ss", 1);
}
