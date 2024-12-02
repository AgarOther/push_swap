/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 16:23:20 by scraeyme          #+#    #+#             */
/*   Updated: 2024/12/02 11:27:23 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	has_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	count_numbers(char *str)
{
	int	i;
	int	is_spaced;
	int	numbers;

	i = 0;
	is_spaced = 1;
	numbers = 0;
	if (!has_digit(str))
		return (0);
	while (str[i])
	{
		if (is_spaced && str[i] != ' ')
		{
			numbers++;
			is_spaced = 0;
		}
		else if (!is_spaced && str[i] == ' ')
			is_spaced = 1;
		i++;
	}
	return (numbers);
}

static int	get_stack_size(int argc, char **argv)
{
	int	i;
	int	size;

	i = 1;
	size = 0;
	while (i < argc)
	{
		if (has_space(argv[i]))
			size += count_numbers(argv[i]);
		else if (has_digit(argv[i]))
			size++;
		i++;
	}
	return (size);
}

static int	duplicate_check(int n, int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (n == tab[i])
		{
			free(tab);
			return (1);
		}
		i++;
	}
	return (0);
}

int	has_duplicates(int argc, char **argv, int i, int j)
{
	int	k;
	int	*tab;

	k = 0;
	tab = ft_calloc(get_stack_size(argc, argv) + 1, sizeof(int));
	if (!tab)
		return (1);
	while (++i < argc)
	{
		j = 0;
		while (argv[i][j] && has_digit(&argv[i][j]))
		{
			while (argv[i][j] && argv[i][j] == ' ')
				j++;
			tab[k] = ft_atoi(&argv[i][j], 0);
			if (duplicate_check(tab[k], tab, k))
				return (1);
			k++;
			while (argv[i][j] && (ft_isdigit(argv[i][j])
				|| ft_isoperand(argv[i][j])))
				j++;
		}
	}
	free(tab);
	return (0);
}
