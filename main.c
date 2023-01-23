/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenheni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:07:57 by abenheni          #+#    #+#             */
/*   Updated: 2023/01/20 15:08:04 by abenheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_swap(t_stack **a, t_stack **b)
{
	if (get_size(*a) == 2)
		sa(a);
	else if (get_size(*a) == 3)
		sort_three(a);
	else if (get_size(*a) == 4)
		sort4(a, b);
	else if (get_size(*a) == 5)
		sort5(a, b);
	else
	{
		indexing_stack(a);
		radix(a, b);
	}
}

int	main(int ac, char *av[])
{
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	a = NULL;
	if (ac < 2)
	{
		return (0);
	}
	if (check_input(ac, &a, av) == 0)
	{
		free_stack(&a);
		free_stack(&b);
		write(2, "error\n", 7);
		exit(1);
	}
	if (is_sorted(a))
		return (0);
	push_swap(&a, &b);
	free_stack(&a);
	free_stack(&b);
	return (0);
}
