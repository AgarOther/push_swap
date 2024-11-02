/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:40:28 by scraeyme          #+#    #+#             */
/*   Updated: 2024/11/02 10:55:07 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_printranks(t_list *lst)
{
	while (lst)
	{
		ft_printf("Number: %d | Rank: %d\n", lst->value, lst->rank);
		lst = lst->next;
	}
}

void	ft_printlst(t_list *lst)
{
	char	**str;
	int		size;
	int		i;

	size = ft_lstsize(lst);
	str = malloc((size + 1) * sizeof(char *));
	str[size] = 0;
	size--;
	i = size;
	while (lst)
	{
		str[size] = ft_itoa(lst->value);
		lst = lst->next;
		size--;
	}
	size++;
	while (size <= i)
	{
		ft_putendl_fd(str[size], 1);
		free(str[size]);
		size++;
	}
	free(str);
}

void	ft_printstacks(t_list *stack_a, t_list *stack_b)
{
	ft_putchar('\n');
	ft_putendl_fd("Stack A: ", 1);
	if (!stack_a)
		ft_putendl_fd("(null)", 1);
	else
		ft_printlst(stack_a);
	ft_putendl_fd("<><><><>", 1);
	ft_putendl_fd("Stack B: ", 1);
	if (!stack_b)
		ft_putendl_fd("(null)", 1);
	else
		ft_printlst(stack_b);
	ft_putstr_fd("\n[--------]\n", 1);
}
