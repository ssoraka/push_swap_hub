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

#define TEST1



void	ft_swap(int *a, int *b)
{
	int temp;

	if (!a || !b)
		return ;
	temp = *a;
	*a = *b;
	*b = temp;
}


typedef struct		s_elem
{
	int				value;
	int				number;
	int				min_value;
	struct s_elem	*next;
	struct s_elem	*prev;
	struct s_arr	*arr;
}					t_elem;


t_elem	*ft_create_elem(int value, int min_value)
{
	t_elem *tmp;

	tmp = (t_elem *)ft_memalloc(sizeof(t_elem));
	tmp->value = value;
	tmp->min_value = min_value;
	return (tmp);
}


int ft_find_min_value(int *arr, int argc)
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
	tmp->next = begin;
	begin->prev = tmp;
	return (begin);
}


void ft_print_list(t_elem *begin, char stek)
{
	int first_value;
	int i;

	i = 0;
	printf("_%c_\n", stek);
	if (begin == NULL)
	{
		printf("NULL\n");
		return ;
	}
	first_value = begin->value;
	while (i == 0 || (begin && first_value != begin->value))
	{
		printf("%d\n", begin->value);
		begin = begin->next;
		i++;
	}
	printf("\n");
}

void ft_print_list2(t_elem *begin, char stek)
{
	int first_value;
	int i;

	i = 0;
	printf(" %c:\t", stek);
	if (begin == NULL)
	{
		printf("NULL\n");
		return ;
	}
	first_value = begin->value;
	while (i == 0 || (begin && first_value != begin->value))
	{
		printf("%d\t", begin->value);
		begin = begin->next;
		i++;
	}
	printf("\n");
}

/*
void ft_print_list3(t_elem *arra, t_elem *arrb, int count)
{
	int first_value_a;
	int first_value_b;
	int i;

	i = 0;
	printf("_%c_\n", stek);
	if (begin == NULL)
	{
		printf("NULL\n");
		return ;
	}
	first_value = begin->value;
	while (i == 0 || (begin && first_value != begin->value))
	{
		printf("%d\n", begin->value);
		begin = begin->next;
		i++;
	}
	printf("\n");
}
*/

int ft_is_sorted(t_elem *begin)
{
	int first_value;
	int i;

	i = 0;
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


int ft_need_round_for_sort(t_elem *begin)
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


void ft_swap_list(t_elem *begin, char stek)
{
	int temp;

	if (!begin)
		return ;
	if (!(begin->next))
		return ;
	temp = begin->value;
	begin->value = begin->next->value;
	begin->next->value = temp;
	if (stek == 'a' || stek == 'b')
		printf("s%c\n", stek);
}


void ft_round_list(t_elem **begin, char stek)
{
	if (*begin && (*begin)->next)
		*begin = (*begin)->next;
	if (stek == 'a' || stek == 'b')
		printf("r%c\n", stek);
}

void ft_revers_round_list(t_elem **begin, char stek)
{
	if (*begin && (*begin)->prev)
		*begin = (*begin)->prev;
	if (stek == 'a' || stek == 'b')
		printf("rr%c\n", stek);
}



t_elem *ft_cut_elem(t_elem **begin)
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


void ft_paste_elem(t_elem **begin, t_elem **new)
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


void ft_push_list(t_elem **arra, t_elem **arrb, char stek)
{
	t_elem *cut_list;

	if (*arra == NULL)
		return ;
	cut_list = ft_cut_elem(arra);
	ft_paste_elem(arrb, &cut_list);
	if (stek == 'a' || stek == 'b')
		printf("p%c\n", stek);
}



char **open_and_read_command(char *name)
{
	int file;
	int red;
	char *str;
	char buf[1001];

	str = NULL;
	file = 0;//open(name, O_RDONLY);
	while ((red = read(file, buf, 1000)))
	{
		buf[red] = '\0';
		str = ft_strjoin_free(str, buf, 1, 0);
	}
	return (ft_strsplit(str, '\n'));
}


int ft_is_not_number(char **str)
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



int ft_str_not_int_number(char *str)
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


void *ft_error(int errnum)
{
	ft_putstr_fd("Error\n", 2);
	exit (0);
	return (NULL);
}


int *ft_arr_int_from_str(char **argv, int argc)
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



int ft_have_repeat_num(int *arr, int argc)
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
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}


int ft_not_valid_command(char **commands)
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


int *ft_valid_arr(int *argc, char **argv)
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
		ft_str_arr_free(argv);
	return (arr);
}



void ft_use_instruction(char **cmd, t_elem **arra, t_elem **arrb)
{
	int i;

	i = 0;
	while (cmd && cmd[i])
	{
		if (ft_strcmp(cmd[i], "sa") == 0 || ft_strcmp(cmd[i], "ss") == 0)
			ft_swap_list(*arra, 0);
		if (ft_strcmp(cmd[i], "sb") == 0 || ft_strcmp(cmd[i], "ss") == 0)
			ft_swap_list(*arrb, 0);
		if (ft_strcmp(cmd[i], "ra") == 0 || ft_strcmp(cmd[i], "rr") == 0)
			ft_round_list(arra, 0);
		if (ft_strcmp(cmd[i], "rb") == 0 || ft_strcmp(cmd[i], "rr") == 0)
			ft_round_list(arrb, 0);
		if (ft_strcmp(cmd[i], "rrb") == 0 || ft_strcmp(cmd[i], "rrr") == 0)
			ft_revers_round_list(arrb, 0);
		if (ft_strcmp(cmd[i], "rra") == 0 || ft_strcmp(cmd[i], "rrr") == 0)
			ft_revers_round_list(arra, 0);
		if (ft_strcmp(cmd[i], "pa") == 0)
			ft_push_list(arrb, arra, 0);
		if (ft_strcmp(cmd[i], "pb") == 0)
			ft_push_list(arra, arrb, 0);
		i++;
	}
}




int		main(int argc, char **argv)
{
	//int arr[] = {10,3,4,5,9,13,0,6,78,8};
	//argc = 10;


	//char **arv;
	//int *arr;

	int *arr;
	t_elem *arra;
	t_elem *arrb;

	if (argc == 1)
		return (0);
	if (!(arr = ft_valid_arr(&argc, argv)))
		ft_error(0);


	//arv = open_and_read_command("arr.txt");
	//arr = ft_arr_int_from_str(arv, &argc);
	//if (ft_have_repeat_num(arr, argc))
	//	ft_error(0);
/*
	int arr[] = {2,1,3,6,5,8};
	argc = 6;
*/

	if (ft_have_repeat_num(arr, argc))
	{
		free(arr);
		ft_error(0);
	}

	arra = ft_create_lists(arr, argc);
	arrb = NULL;

	free(arr);

	if (!arra)
		ft_error(0);




	///checker
	char **cmd;


	cmd = open_and_read_command("command.txt");
	if (ft_not_valid_command(cmd))
		ft_error(0);

	//	printf("%d__%s\n", i, cmd[i]);
	ft_use_instruction(cmd, &arra, &arrb);
	//	ft_print_list2(arra, 'a');
	//	ft_print_list2(arrb, 'b');



	ft_print_list(arra, 'a');
	ft_print_list(arrb, 'b');

	//printf("строк - %d\n", i);
	if (ft_is_sorted(arra) && !arrb)
		printf("ОК\n");
	else
		printf("КО\n");

	return (0);
}
