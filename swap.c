/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoraka <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 11:13:07 by ssoraka           #+#    #+#             */
/*   Updated: 2019/05/27 11:13:07 by ssoraka          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"


#define SUCCESS 0
#define FAIL 1
#define ERROR -1

#define RB 1
#define RRB -1
#define RRR -2
#define RA
#define RRA
#define RR 2





typedef struct		s_elem
{
	int				value;
	int				medium_value;
	int				min_value;
	int				max_value;
	struct s_elem	*next;
	struct s_elem	*prev;
}					t_elem;


void *ft_error(int errnum);
void ft_list_del(t_elem *begin);

t_elem	*ft_create_elem(int value, int min_value, int medium_value, int max_value)
{
	t_elem *tmp;

	tmp = (t_elem *)ft_memalloc(sizeof(t_elem));
	if (!tmp)
		return (NULL);
	tmp->value = value;
	tmp->min_value = min_value;
	tmp->medium_value = medium_value;
	tmp->max_value = max_value;
	return (tmp);
}


int		ft_find_min_value(int *arr, int argc)
{
	int min_value;
	int i;

	i = 1;
	min_value = arr[0];
	while (i < argc)
	{
		if (arr[i] < min_value)
			min_value = arr[i];
		i++;
	}
	return(min_value);
}


int		ft_find_max_value(int *arr, int argc)
{
	int max_value;
	int i;

	i = 1;
	max_value = arr[0];
	while (i < argc)
	{
		if (arr[i] > max_value)
			max_value = arr[i];
		i++;
	}
	return(max_value);
}


int		ft_pubble_int_sort(int *argv, int argc)
{
	int		i;
	int		j;
	int		temp;

	j = 0;
	while (j < argc)
	{
		i = 0;
		while (i < argc - 1)
		{
			if (argv[i] > argv[i + 1])
			{
				temp = argv[i + 1];
				argv[i + 1] = argv[i];
				argv[i] = temp;
			}
			i++;
		}
		j++;
	}
	return (0);
}



int		ft_find_medium_value(int *arr, int argc)
{
	int *sorted;
	int medium;

	sorted = (int *)malloc(sizeof(int) * argc);
	ft_memcpy((void *)sorted, (void *)arr, sizeof(int) * argc);
	ft_pubble_int_sort(sorted, argc);
	if (argc > 10)
		medium = sorted[argc / 2 + 3];
	else
		medium = sorted[argc / 2];
	free(sorted);
	return (medium);
}

t_elem	*ft_create_lists(int *arr, int argc)
{
	int i;
	int value[3];
	t_elem *begin;
	t_elem *tmp;

	value[0] = ft_find_min_value(arr, argc);
	value[1] = ft_find_medium_value(arr, argc);
	value[2] = ft_find_max_value(arr, argc);
	begin = ft_create_elem(arr[0], value[0], value[1], value[2]);
	tmp = begin;
	i = 1;
	while (i < argc)
	{
		if (!tmp || !(tmp->next = ft_create_elem(arr[i], value[0], value[1], value[2])))
		{
			ft_list_del(begin);
			return (NULL);
		}
		tmp->next->prev = tmp;
		tmp = tmp->next;
		i++;
	}
	(tmp != begin) ? tmp->next = begin : 0;
	(tmp != begin) ? begin->prev = tmp : 0;
	return (begin);
}


void	ft_print_list(t_elem *begin, char stack)
{
	int first_value;
	int i;

	i = 0;
	ft_putstr("_");
	ft_putchar(stack);
	ft_putstr("_\n");
	if (begin == NULL)
	{
		ft_putendl("NULL");
		return ;
	}
	first_value = begin->value;
	while (i == 0 || (begin && first_value != begin->value))
	{
		ft_putnbr(begin->value);
		ft_putchar('\n');
		begin = begin->next;
		i++;
	}
}

int		ft_is_sorted(t_elem *begin)
{
	int first_value;
	int i;

	i = 0;
	if (!begin)
		return (0);
	if (!(begin->next))
		return (1);
	first_value = begin->value;
	while (i == 0 || (begin && first_value != begin->value))
	{
		if (first_value == begin->next->value)
			break ;
		if (begin->value > begin->next->value)
			return (0);
		begin = begin->next;
		i++;
	}
	return (1);
}

int		ft_need_only_rotate_for_sort(t_elem *begin)
{
	int first_value;
	int round_count;
	int i;

	i = 0;
	first_value = begin->value;
	round_count = -1;
	while (i == 0 || (begin && first_value != begin->value))
	{
		if (ft_is_sorted(begin))
			round_count = i;
		begin = begin->next;
		i++;
	}
	if (round_count < 0)
		return (0);
	if (round_count == 0)
		return (1);
	if (round_count > i / 2)
		round_count = round_count - i;
	if (round_count < 0)
		return (-1);
	return (2);
}



void	ft_swap_list(t_elem *begin, char stack)
{
	int temp;

	if (!begin)
		return ;
	if (!(begin->next))
		return ;
	temp = begin->value;
	begin->value = begin->next->value;
	begin->next->value = temp;
	if (stack == 'a' || stack == 'b' || stack == 's')
	{
		ft_putchar('s');
		ft_putchar(stack);
		ft_putchar('\n');
	}
}


void	ft_rotate_list(t_elem **begin, char stack)
{
	if (*begin && (*begin)->next)
		*begin = (*begin)->next;
	if (stack == 'a' || stack == 'b' || stack == 'r')
	{
		ft_putchar('r');
		ft_putchar(stack);
		ft_putchar('\n');
	}
}

void	ft_revers_rotate_list(t_elem **begin, char stack)
{
	if (*begin && (*begin)->prev)
		*begin = (*begin)->prev;
	if (stack == 'a' || stack == 'b' || stack == 'r')
	{
		ft_putstr("rr");
		ft_putchar(stack);
		ft_putchar('\n');
	}
}



t_elem	*ft_cut_elem(t_elem **begin)
{
	t_elem *cut_elem;

	cut_elem = *begin;
	if (*begin == NULL)
		return (NULL);
	if ((*begin)->next == NULL)
	{
		*begin = NULL;
		return (cut_elem);
	}
	if ((*begin)->next->next == *begin)
	{
		*begin = (*begin)->next;
		(*begin)->prev = NULL;
		(*begin)->next = NULL;
	}
	else
	{
		(*begin)->prev->next = (*begin)->next;
		*begin = (*begin)->next;
		(*begin)->prev = cut_elem->prev;
	}
	cut_elem->prev = NULL;
	cut_elem->next = NULL;
	return (cut_elem);
}


void	ft_paste_elem(t_elem **begin, t_elem **new)
{
	if (*new == NULL)
		return ;
	if (*begin == NULL)
		*begin = *new;
	else if ((*begin)->next == NULL)
	{
		(*new)->next = *begin;
		(*new)->prev = *begin;
		(*begin)->next = *new;
		(*begin)->prev = *new;
		*begin = (*begin)->prev;
	}
	else
	{
		(*new)->next = *begin;
		(*new)->prev = (*begin)->prev;
		(*begin)->prev = *new;
		(*new)->prev->next = *new;
		*begin = (*begin)->prev;
	}
	*new = NULL;
}


void	ft_push_list(t_elem **stack_a, t_elem **stack_b, char stack)
{
	t_elem *cut_list;

	if (*stack_a == NULL)
		return ;
	cut_list = ft_cut_elem(stack_a);
	ft_paste_elem(stack_b, &cut_list);
	if (stack == 'a' || stack == 'b')
	{
		ft_putchar('p');
		ft_putchar(stack);
		ft_putchar('\n');
	}
}



int		ft_count_of_element_in_stack(t_elem *begin)
{
	int count;
	int first_value;

	count = 0;
	if (begin == NULL)
		return (0);
	first_value = begin->value;
	while (count == 0 || (begin && first_value != begin->value))
	{
		begin = begin->next;
		count++;
	}
	return (count);
}


int		ft_min_count_of_rotation(t_elem *begin, int value)
{
	int round_count;
	int list_count;

	round_count = 0;
	if (begin == NULL)
		return (0);
	if (begin->next == NULL)
		return (0);
	list_count = ft_count_of_element_in_stack(begin);
	while (round_count < list_count)
	{
		if (value == begin->value)
			break ;
		begin = begin->next;
		round_count++;
	}
	if (round_count > list_count / 2)
		round_count = round_count - list_count;
	return (round_count);
}


int		ft_min_count_of_rotat_for_insert(t_elem *begin, int value)
{
	int round_count;
	int list_count;

	round_count = 0;
	list_count = ft_count_of_element_in_stack(begin);
	while (round_count < list_count)
	{
		if (begin->next == NULL)
			break ;
		if (value < begin->value && value > begin->prev->value)
			break ;
		if (value > begin->prev->value && begin->value == begin->min_value)
			break ;
		begin = begin->next;
		round_count++;
	}
	if (round_count > list_count / 2)
		round_count = round_count - list_count;
	return (round_count);
}



int		ft_min_count_of_rotation_stacks(t_elem *stack_a, t_elem *stack_b)
{
	int list_countb;
	int rotate[3];
	int min_values[3];
	t_elem *begin_of_b;

	begin_of_b = stack_b;
	list_countb = ft_count_of_element_in_stack(stack_b);
	min_values[2] = 2147483646;
	while (stack_b && list_countb > 0)
	{
		rotate[0] = ft_min_count_of_rotation(begin_of_b, stack_b->value);
		rotate[1] = ft_min_count_of_rotat_for_insert(stack_a, stack_b->value);
		if (ft_znak(rotate[0]) == ft_znak(rotate[1]))
			rotate[2] = ft_max(ft_abs(rotate[0]), ft_abs(rotate[1]));
		else
			rotate[2] = ft_abs(rotate[0]) + ft_abs(rotate[1]);
		if (rotate[2] < min_values[2])
			ft_memcpy((void *)min_values, (void *)rotate, 12);
		stack_b = stack_b->next;
		list_countb--;
	}
	if (ft_znak(min_values[0]) == ft_znak(min_values[0]))
		return (ft_znak(min_values[0]) + ft_znak(min_values[0]));
	return (ft_znak(min_values[0]));
}


int		ft_is_num_are_sorted(t_elem *begin)
{
	int value;
	int sorted;
	int delta;

	value = begin->value;
	sorted = begin->min_value;
	delta = ((begin->max_value - begin->min_value) / 100) * 6;
	if (delta < 10)
		delta = 10;
	while (begin->value != sorted)
		begin = begin->next;
	while (begin->value != value)
	{
		if (sorted < begin->value && sorted > (begin->value - delta))
			sorted = begin->value;
		begin = begin->next;
	}
	if (sorted <= begin->value && sorted > (begin->value - delta))
		return(1);
	return(0);
}



void	ft_return_from_b_to_a(t_elem **stack_a, t_elem **stack_b)
{
	int rotations_ab;
	int rotations_a;

	rotations_ab = ft_min_count_of_rotation_stacks(*stack_a, *stack_b);
	rotations_a = ft_min_count_of_rotat_for_insert(*stack_a, (*stack_b)->value);
	if (rotations_ab == RR)
	{
		ft_rotate_list(stack_b, 'r');
		ft_rotate_list(stack_a, 0);
	}
	else if (rotations_ab == RRR)
	{
		ft_revers_rotate_list(stack_b, 'r');
		ft_revers_rotate_list(stack_a, 0);
	}
	else if (rotations_ab == RB)
		ft_rotate_list(stack_b, 'b');
	else if (rotations_ab == RRB)
		ft_revers_rotate_list(stack_b, 'b');
	else if (rotations_a > 0)
		ft_rotate_list(stack_a, 'a');
	else if (rotations_a < 0)
		ft_revers_rotate_list(stack_a, 'a');
	else if (rotations_a == 0)
		ft_push_list(stack_b, stack_a, 'a');
}


void	ft_push_notsorted_element_to_b(t_elem **stack_a, t_elem **stack_b, int count_a)
{
	if ((*stack_a)->value == (*stack_a)->min_value ||
	ft_is_num_are_sorted(*stack_a))
	{
		if (count_a <= 5 && (*stack_a)->next->value != (*stack_a)->min_value &&
		(*stack_a)->next->value < (*stack_a)->value &&
		(*stack_a)->next->value > (*stack_a)->prev->value)
			ft_swap_list(*stack_a, 'a');
		else
			ft_rotate_list(stack_a, 'a');
	}
	else
	{
		ft_push_list(stack_a, stack_b, 'b');
		if (count_a > 5 && (*stack_b)->value < (*stack_a)->medium_value &&
		ft_count_of_element_in_stack(*stack_b) > 1)
			ft_rotate_list(stack_b, 'b');
	}
}



t_elem	*ft_vstavka_sort(t_elem *stack_a, t_elem *stack_b)
{
	int count_a;

	count_a = ft_count_of_element_in_stack(stack_a);
	while (stack_a && ft_need_only_rotate_for_sort(stack_a) == 0)
		ft_push_notsorted_element_to_b(&stack_a, &stack_b, count_a);
	while (stack_b)
		ft_return_from_b_to_a(&stack_a, &stack_b);
	while (stack_a->value != stack_a->min_value)
	{
		if (ft_need_only_rotate_for_sort(stack_a) > 0)
			ft_rotate_list(&stack_a, 'a');
		else if (ft_need_only_rotate_for_sort(stack_a) < 0)
			ft_revers_rotate_list(&stack_a, 'a');
	}
	return (stack_a);
}



void	*ft_error(int errnum)
{
	ft_putstr_fd("Error\n", 2);
	exit (0);
	return (NULL);
}


int		ft_is_not_number(char **str)
{
	int i;
	char *tmp;

	i = 0;
	while (**str == '0' && (*str + 1) && ft_isdigit(*(*str + 1)))
		(*str)++;
	tmp = *str;
	if (!ft_isdigit(*tmp))
		return (1);
	while (*tmp && ft_isdigit(*tmp))
		tmp++;
	i = ft_strlen(tmp);
	while (i > 0)
	{
		if (ft_isspace(tmp[i - 1]))
			tmp[i - 1] = '\0';
		else
			break ;
		i--;
	}
	if (*tmp)
		return (1);
	return (0);
}



int		ft_str_not_int_number(char *str)
{
	int i;
	int minus;

	i = 0;
	minus = 0;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		minus = 1;
	if (*str == '-' || *str == '+')
		str++;
	if (ft_is_not_number(&str))
		return (1);
	if (ft_strlen(str) > 10)
		return (1);
	if (ft_strlen(str) == 10)
	{
		if (minus && ft_strcmp("2147483648", str) < 0)
			return (1);
		if (!minus && ft_strcmp("2147483647", str) < 0)
			return (1);
	}
	return (0);
}


int		*ft_arr_int_from_str(char **argv, int argc)
{
	int *arr;
	int i;

	i = 0;
	while (i < argc)
	{
		if (ft_str_not_int_number(argv[i]))
			return (NULL);
		i++;
	}
	if (!(arr = (int *)malloc(4 * (argc))))
		return (NULL);
	i = 0;
	while (i < argc)
	{
		arr[i] = ft_atoi(argv[i]);
		i++;
	}
	return (arr);
}


int		ft_dont_have_repeats_num(int *arr, int argc)
{
	int i;
	int j;

	i = 0;
	while (i < argc)
	{
		j = 0;
		while (j < i)
		{
			if (arr[i] == arr[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}



void	ft_list_del(t_elem *begin)
{
	int list_count;
	int i;
	t_elem *tmp;

	i = 0;
	list_count = ft_count_of_element_in_stack(begin);
	while (i < list_count)
	{
		tmp = begin;
		begin = begin->next;
		tmp->next = NULL;
		free(tmp);
		tmp = NULL;
		i++;
	}
}


int		*ft_valid_arr(int *argc, char **argv)
{
	int *arr;
	int create_argv;

	create_argv = 0;
	argv++;
	if (*argc == 2)
	{
		argv = ft_strsplit(*argv, ' ');
		*argc = 0;
		create_argv = TRUE;
		while (argv[*argc])
			(*argc)++;
	}
	else
		(*argc)--;
	arr = ft_arr_int_from_str(argv, *argc);
	if (create_argv)
		ft_str_arr_free(&argv);
	if (arr && ft_dont_have_repeats_num(arr, *argc))
		return (arr);
	free(arr);
	ft_error(0);
	return (NULL);
}

/*
int		main(int argc, char **argv)
{
	int *arr;
	t_elem *stack_a;
	t_elem *stack_b;

	if (argc == 1)
		return (0);
	if (!(arr = ft_valid_arr(&argc, argv)))
		ft_error(0);
	stack_a = ft_create_lists(arr, argc);
	stack_b = NULL;
	free(arr);
	if (!stack_a)
		ft_error(0);
	stack_a = ft_vstavka_sort(stack_a, stack_b);
	ft_list_del(stack_a);
	ft_list_del(stack_b);
	return (0);
}
*/


//////////




void	ft_use_instruction(char **cmd, t_elem **stack_a, t_elem **stack_b)
{
	int i;

	i = 0;
	while (cmd && cmd[i])
	{
		if (ft_strcmp(cmd[i], "sa") == 0 || ft_strcmp(cmd[i], "ss") == 0)
			ft_swap_list(*stack_a, 0);
		if (ft_strcmp(cmd[i], "sb") == 0 || ft_strcmp(cmd[i], "ss") == 0)
			ft_swap_list(*stack_b, 0);
		if (ft_strcmp(cmd[i], "ra") == 0 || ft_strcmp(cmd[i], "rr") == 0)
			ft_rotate_list(stack_a, 0);
		if (ft_strcmp(cmd[i], "rb") == 0 || ft_strcmp(cmd[i], "rr") == 0)
			ft_rotate_list(stack_b, 0);
		if (ft_strcmp(cmd[i], "rrb") == 0 || ft_strcmp(cmd[i], "rrr") == 0)
			ft_revers_rotate_list(stack_b, 0);
		if (ft_strcmp(cmd[i], "rra") == 0 || ft_strcmp(cmd[i], "rrr") == 0)
			ft_revers_rotate_list(stack_a, 0);
		if (ft_strcmp(cmd[i], "pa") == 0)
			ft_push_list(stack_b, stack_a, 0);
		if (ft_strcmp(cmd[i], "pb") == 0)
			ft_push_list(stack_a, stack_b, 0);
		i++;
	}
}


int		ft_not_valid_command(char **commands)
{
	while (*commands)
	{
		if (ft_strcmp(*commands, "ra") && ft_strcmp(*commands, "rb") &&
				ft_strcmp(*commands, "sa") && ft_strcmp(*commands, "sb") &&
				ft_strcmp(*commands, "ss") && ft_strcmp(*commands, "pa") &&
				ft_strcmp(*commands, "pb") && ft_strcmp(*commands, "rra") &&
				ft_strcmp(*commands, "rrb") && ft_strcmp(*commands, "rrr") &&
				ft_strcmp(*commands, "rr"))
			return (1);
		(commands)++;
	}
	return (0);
}

char	**read_command(void)
{
	char **cmd;
	int red;
	char *str;
	char buf[1001];

	str = NULL;
	while ((red = read(0, buf, 1000)))
	{
		buf[red] = '\0';
		str = ft_strjoin_free(str, buf, 1, 0);
	}
	cmd = ft_strsplit(str, '\n');
	free(str);
	if (cmd && ft_not_valid_command(cmd))
	{
		ft_str_arr_free(&cmd);
		ft_error(0);
	}
	return (cmd);
}

int		main(int argc, char **argv)
{

	int *arr;
	t_elem *stack_a;
	t_elem *stack_b;
	char **cmd;

	if (argc == 1)
		return (0);
	if (!(arr = ft_valid_arr(&argc, argv)))
		ft_error(0);
	cmd = read_command();
	stack_a = ft_create_lists(arr, argc);
	stack_b = NULL;
	free(arr);
	if (!stack_a)
	{
		ft_str_arr_free(&cmd);
		ft_error(0);
	}
	ft_use_instruction(cmd, &stack_a, &stack_b);
	ft_str_arr_free(&cmd);
	(ft_is_sorted(stack_a) && !stack_b) ? ft_putstr("ОК\n") : ft_putstr("KO\n");
	ft_list_del(stack_a);
	ft_list_del(stack_b);
	return (0);
}
