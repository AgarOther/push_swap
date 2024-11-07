/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:23:14 by scraeyme          #+#    #+#             */
/*   Updated: 2024/11/07 17:13:43 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_overflow(char *str)
{
	int		i;
	int		j;
	int		len;
	long	val;

	i = 0;
	while (str[i])
	{
		j = i;
		len = 0;
		while (str[j] && ft_isdigit(str[j]))
		{
			j++;
			len++;
		}
		if (len > 12)
			return (1);
		val = ft_atol(&str[i]);
		if (val > INT_MAX || val < INT_MIN)
			return (1);
		i += ft_intlen(val) + (val < 0);
	}
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

static void	put_element(t_list **stack, char *str, int i, int j)
{
	int		num;
	t_list	*new;
	char	*strnum;

	while (str[i])
	{
		while (str[i] && (str[i] == ' '))
			i++;
		j = i;
		while (str[j] && (ft_isdigit(str[j]) || ft_isoperand(str[j])))
			j++;
		strnum = ft_substr(&str[i], 0, j);
		num = ft_atoi(strnum, 1);
		new = ft_lstnew(num);
		if (!stack)
			stack = &new;
		else
			ft_lstadd_back(stack, new);
		i = j;
	}
}

t_list	*get_stack_a(int argc, char **argv)
{
	char	*input;
	char	**splitted;
	t_list	*stack;
	int		i;

	input = ft_tabjoin(argc, argv, 1, ' ');
	if (!input)
		return (NULL);
	if (has_overflow(input))
	{
		free(input);
		return (NULL);
	}
	stack = NULL;
	i = 0;
	splitted = ft_split(input, ' ');
	while (splitted[i])
	{
		put_element(&stack, splitted[i], 0, 0);
		free(splitted[i]);
		i++;
	}
	free(splitted);
	free(input);
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
			if ((ft_isoperand(argv[i][j]) && !ft_isdigit(argv[i][j + 1])) ||
				(j > 0 && ft_isoperand(argv[i][j])
					&& ft_isdigit(argv[i][j - 1])))
				return (0);
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != ' '
				&& argv[i][j] != '-' && argv[i][j] != '+')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
