/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassouf <rkassouf@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 13:46:55 by rkassouf          #+#    #+#             */
/*   Updated: 2022/09/28 17:06:17 by rkassouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	is_int(char *str)
{
	ssize_t	nbr;
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

static int	is_dup(t_list **stack, int value)
{
	t_list	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->content == value)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

static char	*join_args(int argc, char **argv)
{
	int		i;
	char	*tmp;
	char	*joined;

	joined = ft_strdup(argv[1]);
	if (joined == NULL)
		return (NULL);
	i = 1;
	while (++i < argc)
	{
		tmp = joined;
		joined = ft_strjoin(tmp, " ");
		free(tmp);
		if (joined == NULL)
			return (NULL);
		tmp = joined;
		joined = ft_strjoin(tmp, argv[i]);
		free(tmp);
		if (joined == NULL)
			return (NULL);
	}
	return (joined);
}

static void	fill_stack(t_list **stack, char ***splitted, int value)
{
	if (is_dup(stack, value))
	{
		free_split(*splitted);
		lst_free(stack);
		exit_on_err(STDERR_FILENO, ERR);
	}
	if (*stack == NULL)
		ft_lstadd_front(stack, ft_lstnew(value));
	else
		ft_lstadd_back(stack, ft_lstnew(value));
}

void	set_stack(int argc, char **argv, t_list **stack)
{
	int		i;
	char	*args;
	char	**splitted;

	args = join_args(argc, argv);
	if (args == NULL)
		exit_on_err(STDERR_FILENO, ERR);
	splitted = ft_split(args, ' ');
	free(args);
	if (splitted == NULL)
		exit_on_err(STDERR_FILENO, ERR);
	i = -1;
	while (splitted[++i])
	{
		if (!is_int(splitted[i]))
		{
			free_split(splitted);
			lst_free(stack);
			exit_on_err(STDERR_FILENO, ERR);
		}
		fill_stack(stack, &splitted, ft_atoi(splitted[i]));
	}
	free_split(splitted);
}
