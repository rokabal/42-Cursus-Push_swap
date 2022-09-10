/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassouf <rkassouf@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:46:55 by rkassouf          #+#    #+#             */
/*   Updated: 2022/09/10 15:47:24 by rkassouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	lst_free(t_list **stack)
{
	t_list	*tmp;

	while (*stack != NULL)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

/**
 * @brief	Check if str consists of only digits with/without a sign
 * 
 * @return	1 if true, 0 if false
 */
static int	is_int(char *str)
{
	long	nbr;
	int		sign;

	sign = 1;
	nbr = 0;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!str || !*str || !(*str >= '0' && *str <= '9'))
		return (0);
	while (*str >= '0' && *str <= '9')
	{
		nbr = 10 * nbr + (*str - '0');
		str++;
	}
	if (*str && !(*str >= '0' && *str <= '9'))
		return (0);
	nbr = sign * nbr;
	if (nbr < INT_MIN || nbr > INT_MAX)
		return (0);
	return (1);
}

static void	check_dup(t_list **stack, int value)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->content == value)
		{
			lst_free(stack);
			exit_on_err(STDERR_FILENO, "Error\n");
		}
		tmp = tmp->next;
	}
}

static void	validate_args(t_list **stack_a, int argc, char **argv)
{
	t_list	*number;

	while (--argc >= 0)
	{
		if (!ft_strncmp(argv[argc], "./push_swap", 11))
			return ;
		if (!is_int(argv[argc]))
		{
			lst_free(stack_a);
			exit_on_err(STDERR_FILENO, "Error\n");
		}
		number = ft_lstnew(ft_atoi(argv[argc]));
		check_dup(stack_a, number->content);
		ft_lstadd_front(stack_a, number);
	}
}

/**
 * @brief If the arguments are valid, set stack a
 */
void	set_stack(int argc, char **argv, t_list **stack_a)
{
	int		size;
	char	**arg;

	size = 0;
	if (argc == 2)
	{
		arg = ft_split(argv[1], ' ');
		while (arg[size])
			size++;
		validate_args(stack_a, size, arg);
		free_split(arg);
	}
	else
		validate_args(stack_a, argc, argv);
}
