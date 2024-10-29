/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:31:47 by scraeyme          #+#    #+#             */
/*   Updated: 2024/10/29 13:19:08 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, int (*f)(int))
{
	t_list	*new_list;
	t_list	*val;

	if (!f || !lst)
		return (NULL);
	new_list = NULL;
	val = NULL;
	while (lst)
	{
		val = ft_lstnew(f(lst->value));
		if (!val)
		{
			ft_lstclear(&new_list);
			return (NULL);
		}
		ft_lstadd_back(&new_list, val);
		lst = lst->next;
	}
	return (new_list);
}
