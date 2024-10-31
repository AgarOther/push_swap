/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:53:33 by scraeyme          #+#    #+#             */
/*   Updated: 2024/10/31 09:45:44 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include "../libft/get_next_line/get_next_line.h"
# include "../libft/ft_printf/includes/ft_printf.h"

// Parsing
t_list	*get_stack_a(int argc, char **argv);
int		has_duplicates(int argc, char **argv, int i, int j);
int		print_error(void);
int		has_space(char *str);
int		has_digit(char *str);
int		is_valid(int argc, char **argv);

// Resolution
int		is_sorted(t_list *stack);

// Operations
void	sa(t_list **stack_a, int is_ss);
void	sb(t_list **stack_b, int is_ss);
void	ss(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b, int is_pb);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a, int is_rr);
void	rb(t_list **stack_b, int is_rr);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a, int is_rr);
void	rrb(t_list **stack_b, int is_rr);
void	rrr(t_list **stack_a, t_list **stack_b);

// For testing purposes
void	ft_printlst(t_list *lst);
#endif