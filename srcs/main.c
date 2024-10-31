/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 13:53:27 by scraeyme          #+#    #+#             */
/*   Updated: 2024/10/31 22:08:42 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	can_parse(int argc, char **argv)
{
	if (argc < 2)
		return (print_error());
	if (!is_valid(argc, argv))
		return (print_error());
	else if (has_duplicates(argc, argv, 1, 0))
		return (print_error());
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (!can_parse(argc, argv))
		return (0);
	stack_a = get_stack_a(argc - 1, argv);
	if (!stack_a)
		return (print_error());
	if (is_sorted(stack_a))
	{
		ft_printf("\nStack is sorted!\n");
		return (0);
	}
	stack_b = NULL;
	pa(&stack_a, &stack_b, 0);
	ft_printstacks(stack_a, stack_b);
	pa(&stack_a, &stack_b, 0);
	ft_printstacks(stack_a, stack_b);
	sb(&stack_b, 0);
	ft_printstacks(stack_a, stack_b);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
}
