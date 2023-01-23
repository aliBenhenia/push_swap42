/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenheni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 16:28:22 by abenheni          #+#    #+#             */
/*   Updated: 2023/01/21 16:28:27 by abenheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count(char *av[])
{
	int	i;

	i = 0;
	if (!av)
		return (-1);
	while (av[i])
		i++;
	return (i);
}

void	sa(t_stack **s)
{
	int	temp;

	if ((*s) == NULL || (*s)->next == NULL)
		return ;
	temp = (*s)->data;
	(*s)->data = (*s)->next->data;
	(*s)->next->data = temp;
	ft_putstr("sa\n");
}

void	sort_three(t_stack **first)
{
	t_stack	*sc;
	t_stack	*third;

	sc = (*first)->next;
	third = sc->next;
	if ((*first)->data < sc->data
		&& (*first)->data < third-> data && sc->data > third->data)
	{
		sa(first);
		ra(first);
	}
	else if ((*first)->data < sc->data && (*first)-> data > third->data)
		rra(first);
	else if ((*first)->data > sc->data && (*first)-> data < third->data)
		sa(first);
	else if ((*first)->data > sc-> data
		&& sc-> data > third->data && (*first)->data > third->data)
	{
		sa(first);
		rra(first);
	}
	else if ((*first)-> data > sc-> data
		&& (*first)-> data > third-> data && third-> data > sc-> data)
		ra(first);
}
