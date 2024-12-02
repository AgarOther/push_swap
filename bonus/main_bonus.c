/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 13:53:27 by scraeyme          #+#    #+#             */
/*   Updated: 2024/12/02 14:15:59 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	is_sorted(t_list *stack)
{
	int		tmp;

	while (stack->next)
	{
		tmp = stack->value;
		stack = stack->next;
		if (tmp > stack->value)
			return (0);
	}
	return (1);
}

int	print_error(void)
{
	ft_putendl_fd("Error", 2);
	return (0);
}

int	can_parse(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	else if (argc == 2 && argv[1][0] == 0)
		return (print_error());
	if (!is_valid(argc, argv))
		return (print_error());
	else if (has_duplicates(argc, argv, 0, 0))
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
	stack_b = NULL;
	if (!stack_a)
		return (print_error());
	if (!check_stack(&stack_a, &stack_b))
		print_error();
	else if (is_sorted(stack_a) && !stack_b)
		ft_putendl_fd("OK", 1);
	else
		ft_putendl_fd("KO", 1);
	ft_lstclear(&stack_a);
	if (stack_b)
		ft_lstclear(&stack_b);
}
