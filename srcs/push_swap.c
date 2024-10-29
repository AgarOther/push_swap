/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 13:53:27 by scraeyme          #+#    #+#             */
/*   Updated: 2024/10/29 16:28:18 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != ' '
				&& argv[i][j] != '-')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*stack;

	if (argc < 2)
		return (print_error());
	if (!is_valid(argc, argv))
	{
		ft_putendl_fd("Error!", 1);
		return (print_error());
	}
	stack = get_stack_a(argc - 1, argv);
	if (!stack)
		return (print_error());
	free(stack);
}
