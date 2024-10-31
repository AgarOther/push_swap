/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:40:28 by scraeyme          #+#    #+#             */
/*   Updated: 2024/10/31 22:06:21 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_printlst(t_list *lst)
{
	char	*str;
	int		size;

	size = ft_lstsize(lst);
	str = malloc(size + 1);
	str[size] = 0;
	size--;
	while (lst)
	{
		str[size] = *ft_itoa(lst->value);
		lst = lst->next;
		size--;
	}
	size = 0;
	while (str[size])
	{
		ft_putchar(str[size]);
		ft_putchar('\n');
		size++;
	}
}

void	ft_printstacks(t_list *stack_a, t_list *stack_b)
{
	ft_putendl_fd("Stack A: ", 1);
	ft_printlst(stack_a);
	ft_putendl_fd("-----------", 1);
	ft_putendl_fd("Stack B: ", 1);
	ft_printlst(stack_b);
}
