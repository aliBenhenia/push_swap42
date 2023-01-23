/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenheni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 17:14:39 by abenheni          #+#    #+#             */
/*   Updated: 2023/01/21 17:14:43 by abenheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr(char *s)
{
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
}

void	free_split_array(char ***arr)
{
	char	**array;
	int		i;

	i = 0;
	array = *arr;
	while (array[i])
		free(array[i++]);
	free(array);
}

void	free_stack(t_stack **head)
{
	t_stack	*current;

	current = *head;
	while (current != NULL)
	{
		free(current);
		current = current->next;
	}
	free(current);
}

void	addfront(t_stack **a, t_stack *new)
{
	new->next = *a;
	*a = new;
}

t_stack	*addnew(int n)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->data = n;
	new->index = -1;
	new->next = NULL;
	return (new);
}
