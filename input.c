/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenheni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 15:23:09 by abenheni          #+#    #+#             */
/*   Updated: 2023/01/20 15:23:11 by abenheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	add_new_and_push(t_stack **a, int value)
{
	t_stack	*new;

	new = addnew(value);
	if (!new)
	{
		free(new);
		return (0);
	}
	addfront(a, new);
	return (1);
}

static int	is_dup(t_stack *a)
{
	t_stack	*head;

	head = NULL;
	while (a)
	{
		head = a->next;
		while (head)
		{
			if (head->data == a->data)
			{
				return (0);
			}
			head = head->next;
		}
		a = a->next;
	}
	return (1);
}

static int	check_number(char *av)
{
	int	i;

	i = 0;
	if ((av[0] == '-' || av[0] == '+') && av[1] != '\0')
		i++;
	while (av[i] && ft_isdigit(av[i]))
		i++;
	if (av[i] != '\0' && ft_isdigit(av[i]) == 0)
		return (0);
	if (ft_atoi(av) > 2147483647 || ft_atoi(av) < -2147483648)
		return (0);
	return (1);
}

int	contain_spaces(char *av)
{
	int	i;

	i = 0;
	while (av[i] && av[i] == 32)
		i++;
	if (av[i] == '\0')
		return (1);
	return (0);
}

int	check_input(int ac, t_stack **a, char *av[])
{
	char	**arg;
	int		len;
	int		args;

	args = ac - 1;
	while (av[args] && args != 0)
	{
		if (av[args][0] == '\0' || contain_spaces(av[args]))
			return (0);
		arg = ft_split(av[args--], 32);
		len = count(arg);
		if (len == -1)
			return (free_split_array(&arg), 0);
		while (--len >= 0)
		{
			if (check_number(arg[len]) == 0)
				return (free_split_array(&arg), 0);
			if (add_new_and_push(a, ft_atoi(arg[len])) == 0)
				return (free_split_array(&arg), 0);
		}
		free_split_array(&arg);
	}
	if (is_dup(*a) == 0)
		return (0);
	return (1);
}
