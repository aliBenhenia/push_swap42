/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenheni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:14:26 by abenheni          #+#    #+#             */
/*   Updated: 2023/01/20 16:14:29 by abenheni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>

typedef struct stack
{
	int				data;
	int				index;
	struct stack	*next;
}t_stack;
void	ft_putstr(char *s);
int		ft_isdigit(int c);
int		count(char *av[]);
long	ft_atoi(const char *s);
char	**ft_split(char const *s, char c);
void	free_split_array(char ***arr);
void	free_stack(t_stack **head);
t_stack	*addnew(int n);
void	addfront(t_stack **a, t_stack *new);
void	print(t_stack *head);
int		pb(t_stack **a, t_stack **b);
int		pa(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rra(t_stack **head);
void	sa(t_stack **s);
int		check_input(int ac, t_stack **a, char *av[]);
int		is_sorted(t_stack *a);
void	indexing_stack(t_stack **A);
int		get_smallest_number(t_stack *a);
int		get_size(t_stack *a);
void	sort_three(t_stack **top);
void	sort4(t_stack **a, t_stack **b);
void	sort5(t_stack **a, t_stack **b);
void	radix(t_stack **a, t_stack **b);

#endif 
