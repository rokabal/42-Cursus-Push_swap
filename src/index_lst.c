/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkassouf <rkassouf@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 23:17:24 by rkassouf          #+#    #+#             */
/*   Updated: 2022/09/28 17:00:21 by rkassouf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static int	find_smallest(t_list **stack)
{
	int		smallest;
	t_list	*tmp;

	smallest = INT_MAX;
	tmp = *stack;
	while (tmp)
	{
		if (tmp->content < smallest)
			smallest = tmp->content;
		tmp = tmp->next;
	}
	return (smallest);
}

int	find_rot(t_list **stack)
{
	int		smallest;
	int		rot;
	t_list	*tmp;

	smallest = find_smallest(stack);
	rot = 0;
	tmp = *stack;
	while (tmp->content != smallest)
	{
		rot++;
		tmp = tmp->next;
	}
	if (rot <= 2)
		return (rot);
	return (rot - ft_lstsize(*stack));
}

static void	lst_sort(t_list **stack, t_list **lst_sorted)
{
	t_list	*cur;
	t_list	*tmp;
	t_list	*prev;

	*lst_sorted = NULL;
	cur = (*stack);
	while (cur != NULL)
	{
		if ((*lst_sorted) == NULL || ((*lst_sorted)->content > cur->content))
			ft_lstadd_front(lst_sorted, ft_lstnew(cur->content));
		else
		{
			tmp = *lst_sorted;
			while ((tmp != NULL) && (tmp->content < cur->content))
			{
				prev = tmp;
				tmp = tmp->next;
			}
			prev->next = ft_lstnew(cur->content);
			prev->next->next = tmp;
		}
		cur = cur->next;
	}
}

void	lst_to_index(t_ps *ps)
{
	int		i[2];
	t_list	*tmp;
	t_list	*cur;
	t_list	*lst_sorted;

	lst_sort(&ps->stack_a, &lst_sorted);
	cur = ps->stack_a;
	i[1] = 0;
	while (i[1] != ps->size)
	{
		i[0] = 0;
		tmp = lst_sorted;
		while (cur->content != tmp->content)
		{
			tmp = tmp->next;
			++i[0];
		}
		if (ps->indexed == NULL)
			ft_lstadd_front(&ps->indexed, ft_lstnew(i[0]));
		else
			ft_lstadd_back(&ps->indexed, ft_lstnew(i[0]));
		++i[1];
		cur = cur->next;
	}
	lst_free(&lst_sorted);
}
