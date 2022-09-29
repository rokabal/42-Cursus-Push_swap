/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassouf <rkassouf@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 22:20:39 by rkassouf          #+#    #+#             */
/*   Updated: 2022/09/28 20:50:15 by rkassouf         ###   ########.fr       */
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

int	sorted(t_list **stack)
{
	t_list	*tmp;

	if (*stack == NULL)
		return (1);
	tmp = *stack;
	while (tmp->next != NULL)
	{
		if (tmp->content > tmp->next->content)
			break ;
		tmp = tmp->next;
	}
	if (tmp->next == NULL)
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_ps	ps;

	ps = (t_ps){0, NULL, NULL, NULL, NULL};
	if (argc < 2)
		return (0);
	set_stack(argc, argv, &ps.stack_a);
	if (!sorted(&ps.stack_a))
	{
		ps.size = ft_lstsize(ps.stack_a);
		lst_to_index(&ps);
		lst_free(&ps.stack_a);
		if (ps.size <= 5)
			sort_small(&ps);
		else
			radix_sort(&ps);
	}
	print_cmds(&ps.cmds);
	lst_free(&ps.indexed);
}
