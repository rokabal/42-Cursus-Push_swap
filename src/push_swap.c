/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassouf <rkassouf@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 22:20:39 by rkassouf          #+#    #+#             */
/*   Updated: 2022/09/14 14:56:36 by rkassouf         ###   ########.fr       */
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
	int		size;
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*indexed;

	stack_a = NULL;
	stack_b = NULL;
	indexed = NULL;
	if (argc < 2)
		return (0);
	set_stack(argc, argv, &stack_a);
	if (!sorted(&stack_a))
	{
		size = ft_lstsize(stack_a);
		if (size <= 5)
			sort_small(&stack_a, &stack_b, size);
		else
		{
			lst_to_index(&stack_a, &indexed);
			radix_sort(&indexed, &stack_b);
		}
	}
	lst_free(&stack_a);
	if (indexed != NULL)
		lst_free(&indexed);
}
