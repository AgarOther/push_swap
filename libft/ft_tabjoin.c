/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:32:13 by scraeyme          #+#    #+#             */
/*   Updated: 2024/11/07 17:20:53 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_tab_len(char **tab, int offset, int size)
{
	int	j;
	int	len;

	len = 0;
	while (offset <= size)
	{
		j = 0;
		while (tab[offset][j])
		{
			len++;
			j++;
		}
		offset++;
	}
	return (len + offset);
}

char	*ft_tabjoin(int size, char **tab, int offset, char sep)
{
	int		i;
	int		j;
	char	*new;

	new = malloc(get_tab_len(tab, offset, size) + 1);
	if (!new)
		return (NULL);
	j = 0;
	while (offset <= size)
	{
		i = 0;
		while (tab[offset][i])
		{
			new[j] = tab[offset][i];
			i++;
			j++;
		}
		new[j] = sep;
		j++;
		offset++;
	}
	new[j] = 0;
	return (new);
}
