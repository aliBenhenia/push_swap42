/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenheni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:14:17 by abenheni          #+#    #+#             */
/*   Updated: 2023/01/20 15:14:19 by abenheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_stack	*get_next_min(t_stack *A)
{
	int		num;
	t_stack	*m;
	t_stack	*head;

	head = A;
	num = 0;
	m = NULL;
	if (head)
	{
		while (head)
		{
			if ((head->index == -1) && (!num || head->data < m->data))
			{
				m = head;
				num = 1;
			}
			head = head-> next;
		}
	}
	return (m);
}

void	indexing_stack(t_stack **A)
{
	int		index;
	t_stack	*head;

	head = get_next_min(*A);
	index = 0;
	while (head)
	{
		head->index = index++;
		head = get_next_min(*A);
	}
}
