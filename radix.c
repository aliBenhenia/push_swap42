/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenheni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:40:00 by abenheni          #+#    #+#             */
/*   Updated: 2023/01/20 16:40:04 by abenheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *a)
{
	t_stack	*b;

	b = NULL;
	while (a)
	{
		b = a->next;
		while (b)
		{
			if (a->data > b->data)
				return (0);
			b = b->next;
		}
		a = a->next;
	}
	return (1);
}

int	get_size(t_stack *a)
{
	int			i;
	t_stack		*head;

	i = 0;
	head = a;
	while (head)
	{
		i++;
		head = head-> next;
	}
	return (i);
}

static int	get_max_bits(t_stack *a)
{
	int		m;
	int		mb;
	t_stack	*head;

	head = a;
	m = head-> index;
	mb = 0;
	while (head)
	{
		if (m < head-> index)
			m = head-> index;
		head = head-> next;
	}
	while ((m >> mb) != 0)
		mb++;
	return (mb);
}

void	radix(t_stack **a, t_stack **b)
{
	int		size;
	int		m_b;
	int		i;
	int		j;
	t_stack	*head;

	head = *a;
	size = get_size(*a);
	m_b = get_max_bits(*a);
	i = 0;
	while (i < m_b)
	{
		j = 0;
		while (j++ < size)
		{
			head = *a;
			if (((head->index >> i) & 1) == 1)
				ra(a);
			else
				pb(a, b);
		}
		while (get_size(*b) != 0)
			pa(a, b);
		i++;
	}
}
