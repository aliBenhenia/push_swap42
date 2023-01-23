/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort4.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenheni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:33:02 by abenheni          #+#    #+#             */
/*   Updated: 2023/01/21 16:33:04 by abenheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(const char *s)
{
	long	r;
	int		sign;

	r = 0;
	sign = 1;
	while (*s == 32 || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			sign = sign * -1;
		s++;
	}
	while ((*s >= '0' && *s <= '9'))
	{
		r = r * 10 + *s - '0';
		s++;
	}
	return (r * sign);
}

int	get_smallest_number(t_stack *a)
{
	t_stack	*t1;
	int		min;
	int		pos;
	int		n;

	n = 0;
	pos = 1;
	t1 = a;
	while (t1)
	{
		if (!n || (min > t1->data))
		{
			min = t1->data;
			n = 1;
		}
		t1 = t1->next;
	}
	t1 = a;
	while (t1->data != min)
	{
		pos++;
		t1 = t1->next;
	}
	return (pos);
}

static void	push_sm_to_b(t_stack **a, t_stack **b)
{
	int	pos;

	pos = get_smallest_number(*a);
	if (pos == 4)
	{
		rra(a);
		pb(a, b);
	}
	if (pos == 3)
	{
		rra(a);
		rra(a);
		pb(a, b);
	}
	if (pos == 2)
	{
		sa(a);
		pb(a, b);
	}
	if (pos == 1)
		pb(a, b);
}

void	sort4(t_stack **a, t_stack **b)
{
	push_sm_to_b(a, b);
	sort_three(a);
	pa(a, b);
}
