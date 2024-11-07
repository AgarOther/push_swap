/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isoperand.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:42:25 by scraeyme          #+#    #+#             */
/*   Updated: 2024/11/07 14:42:44 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isoperand(int c)
{
	return (c == '+' || c == '-');
}