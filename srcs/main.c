/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 13:53:27 by scraeyme          #+#    #+#             */
/*   Updated: 2024/11/01 19:05:29 by scraeyme         ###   ########.fr       */
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

void	empty_but_3(t_list **stack_a, t_list **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	while (size > 3)
	{
		pb(stack_a, stack_b);
		size--;
	}
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		size;
	int		tmp_size;
	int		sorted;

	if (!can_parse(argc, argv))
		return (0);
	stack_a = get_stack_a(argc - 1, argv);
	stack_b = NULL;
	if (!stack_a)
		return (print_error());
	size = ft_lstsize(stack_a);
	tmp_size = size + 1;
	sorted = is_sorted(stack_a);
	if (size == 2 && !sorted)
		sort_2(&stack_a);
	else if (size == 3 && !sorted)
	{
		sort_3(&stack_a);
		return (0);
	}
	while (--tmp_size > 3)
			pb(&stack_a, &stack_b);
	if (!is_sorted(stack_a))
		sort_3(&stack_a);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
}
