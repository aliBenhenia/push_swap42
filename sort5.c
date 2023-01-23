/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenheni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:42:09 by abenheni          #+#    #+#             */
/*   Updated: 2023/01/21 16:42:11 by abenheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	norm_help(t_stack **a, t_stack **b)
{
	rra(a);
	rra(a);
	rra(a);
	pb(a, b);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	return (0);
}

static void	push_sm_to_b(t_stack **a, t_stack **b)
{
	int	pos;

	pos = get_smallest_number(*a);
	if (pos == 5)
	{
		rra(a);
		pb(a, b);
	}
	if (pos == 4)
	{
		rra(a);
		rra(a);
		pb(a, b);
	}
	if (pos == 3)
		norm_help(a, b);
	if (pos == 2)
	{
		sa(a);
		pb(a, b);
	}
	if (pos == 1)
		pb(a, b);
}

void	sort5(t_stack **a, t_stack **b)
{
	push_sm_to_b(a, b);
	sort4(a, b);
	pa(a, b);
}
