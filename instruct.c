/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruct.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenheni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:12:52 by abenheni          #+#    #+#             */
/*   Updated: 2023/01/20 16:12:54 by abenheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push_to(t_stack **from, t_stack **to)
{
	t_stack	*head_to;
	t_stack	*head_from;
	t_stack	*temp;

	if (!from)
		return (-1);
	head_from = *from;
	temp = head_from;
	head_from = head_from->next;
	*from = head_from;
	head_to = *to;
	if (!to)
	{
		head_to = temp;
		head_to->next = NULL;
		*to = head_to;
	}
	else
	{
		temp->next = head_to;
		*to = temp;
	}
	return (0);
}

int	pb(t_stack **a, t_stack **b)
{
	if (push_to(a, b) == -1)
	{
		return (-1);
	}
	ft_putstr("pb\n");
	return (0);
}

int	pa(t_stack **a, t_stack **b)
{
	if (push_to(b, a) == -1)
	{
		return (-1);
	}
	ft_putstr("pa\n");
	return (0);
}

void	rra(t_stack **head)
{
	t_stack	*current;
	t_stack	*last;

	current = *head;
	if (current == NULL || current->next == NULL)
		return ;
	while (current->next->next != NULL)
	{
		current = current->next;
	}
	last = current->next;
	current->next = NULL;
	last->next = *head;
	*head = last;
	ft_putstr("rra\n");
}

void	ra(t_stack **a)
{
	t_stack	*top;
	t_stack	*c;

	if ((*a) == NULL || (*a)->next == NULL)
		return ;
	top = (*a);
	(*a) = (*a)->next;
	c = top;
	while (c->next != NULL)
		c = c->next;
	top->next = NULL;
	c->next = top;
	ft_putstr("ra\n");
}
