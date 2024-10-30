/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:23:14 by scraeyme          #+#    #+#             */
/*   Updated: 2024/10/30 16:53:05 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	print_error(void)
{
	ft_putendl_fd("Error!", 1);
	return (0);
}

int	has_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

static void	get_element(t_list **stack, char *str, int i, int j)
{
	int		num;
	t_list	*new;

	while (str[i])
	{
		if (!has_space(&str[i]))
			num = ft_atoi(&str[i]);
		else
		{
			while (str[i] && str[i] == ' ')
				i++;
			j = i;
			while (str[j] && (ft_isdigit(str[j]) || str[j] == '-'))
				j++;
			num = ft_atoi(ft_substr(&str[i], 0, j));
		}
		new = ft_lstnew(num);
		if (!stack)
			stack = &new;
		else
			ft_lstadd_back(stack, new);
		i += ft_intlen(num) + (num < 0);
	}
}

t_list	*get_stack_a(int argc, char **argv)
{
	int		i;
	t_list	*stack;

	i = 1;
	stack = NULL;
	while (i <= argc)
	{
		get_element(&stack, argv[i], 0, 0);
		i++;
	}
	ft_printlst(stack);
	ft_printf("Size %d\n", ft_lstsize(stack));
	return (stack);
}

int	is_valid(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (!has_digit(argv[i]))
			return (0);
		while (argv[i][j])
		{
			if (argv[i][j] == '-' && argv[i][j + 1] == '-')
				return (0);
			else if (argv[i][j] == '-' && argv[i][j + 1] == '0')
				return (0);
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != ' '
				&& argv[i][j] != '-')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
