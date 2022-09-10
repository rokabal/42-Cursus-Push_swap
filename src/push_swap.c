/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassouf <rkassouf@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 22:20:39 by rkassouf          #+#    #+#             */
/*   Updated: 2022/09/10 16:16:06 by rkassouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	set_stack(argc, argv, &stack_a);
	if (!sorted(&stack_a))
	{
		size = ft_lstsize(stack_a);
		if (size <= 5)
			sort_small(&stack_a, &stack_b, size);
	}
	lst_free(&stack_a);
	lst_free(&stack_b);
}
