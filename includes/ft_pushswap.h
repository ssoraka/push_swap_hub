/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pushswap.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoraka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/05 17:24:30 by ssoraka           #+#    #+#             */
/*   Updated: 2019/05/05 17:24:30 by ssoraka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSHSWAP_H
# define FT_PUSHSWAP_H
# include "libft.h"
# include "ft_pushswap_struct.h"
# define SUCCESS 0
# define FAIL 1
# define ERROR -1
# define RB 1
# define RRB -1
# define RRR -2
# define RA
# define RRA
# define RR 2

/*
**	lists.c
*/

t_elem	*ft_create_elem(int value, int min_value, int medium_value,
			int max_value);
t_elem	*ft_create_lists(int *arr, int argc);
void	ft_list_del(t_elem *begin);

/*
**	print.c
*/

void	ft_print_list(t_elem *begin, char stack);
void	*ft_error(int errnum);

/*
**	is_sorted.c
*/

int		ft_is_sorted(t_elem *begin);
int		ft_need_only_rotate_for_sort(t_elem *begin);

/*
**	min_med_max.c
*/

int		ft_find_min_value(int *arr, int argc);
int		ft_find_max_value(int *arr, int argc);
int		ft_pubble_int_sort(int *argv, int argc);
int		ft_find_medium_value(int *arr, int argc);

/*
**	command.c
*/

void	ft_swap_list(t_elem *begin, char stack);
void	ft_rotate_list(t_elem **begin, char stack);
void	ft_revers_rotate_list(t_elem **begin, char stack);
void	ft_push_list(t_elem **stack_a, t_elem **stack_b, char stack);

/*
**	opt_rotation.c
*/

int		ft_count_of_element_in_stack(t_elem *begin);
int		ft_min_count_of_rotation(t_elem *begin, int value);
int		ft_min_count_of_rotat_for_insert(t_elem *begin, int value);
int		ft_min_count_of_rotation_stacks(t_elem *stack_a, t_elem *stack_b);

/*
**	push_swap.c
*/

int		ft_is_num_are_sorted(t_elem *begin);
void	ft_return_from_b_to_a(t_elem **stack_a, t_elem **stack_b);
void	ft_push_notsorted_element_to_b(t_elem **stack_a, t_elem **stack_b,
			int count_a);
t_elem	*ft_vstavka_sort(t_elem *stack_a, t_elem *stack_b);

/*
**	validation.c
*/

int		ft_is_not_number(char **str);
int		ft_str_not_int_number(char *str);
int		*ft_arr_int_from_str(char **argv, int argc);
int		ft_dont_have_repeats_num(int *arr, int argc);
int		*ft_valid_arr(int *argc, char **argv);

/*
**	checker.c
*/

void	ft_use_instruction(char **cmd, t_elem **stack_a, t_elem **stack_b);
int		ft_not_valid_command(char **commands);
char	**read_command(void);

#endif
