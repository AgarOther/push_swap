/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scraeyme <scraeyme@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:53:33 by scraeyme          #+#    #+#             */
/*   Updated: 2024/12/02 22:11:26 by scraeyme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H
# define SUCCESS "\033[32m>>>>>>>>>> SUCCESS <<<<<<<<<<\033[0m"
# define FAILURE "\033[31m>>>>>>>>>> FAILURE <<<<<<<<<<\033[0m"
# define ERROR_1 "\033[31mERROR: \033[39;9m"
# define ERROR_2 "You must wait at least \033[0;93;9m99h99m99s"
# define ERROR_3 "\033[0m Invalid input."
# include "../libft/libft.h"
# include <limits.h>

typedef struct s_line
{
	char			*line;
	struct s_line	*next;
}				t_line;

// Checker
int		check_moves(char **moves);
char	**get_moves(int i);
int		check_stack(t_list **stack_a, t_list **stack_b);
void	do_move(t_list **stack_a, t_list **stack_b, char *move);

// Lines
void	ft_lineadd_back(t_line **lst, t_line *new);
void	ft_lineclear(t_line **lst);
void	ft_linedelone(t_line *lst);
t_line	*ft_linelast(t_line *lst);
t_line	*ft_linenew(char *content);
int		ft_linesize(t_line *lst);

// Parsing
t_list	*get_stack_a(int argc, char **argv);
int		has_duplicates(int argc, char **argv, int i, int j);
int		has_overflow(char *str);
int		print_error(void);
int		has_space(char *str);
int		has_digit(char *str);
int		is_valid(int argc, char **argv);
int		set_ranks(t_list **stack_a, int size);
int		is_sorted(t_list *stack);

// Operations
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
#endif