/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharlot <pcharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:55:34 by pcharlot          #+#    #+#             */
/*   Updated: 2020/02/20 11:20:41 by pcharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_list.h"

void swapi(int *a, int *b)
{
	int temp;

	temp = *a;
	*a = *b;
	*b = temp;	
}

t_list	*sort_list(t_list* lst, int (*cmp)(int, int))
{
	t_list	*temp;
	t_list	*begin;
	
	temp = lst;
	begin = lst;

	while(lst)
	{
		temp = lst->next;
		if(temp)
		{
			if(!(*cmp)(lst->data, temp->data))
			{
				swapi(&lst->data, &temp->data);
				lst = begin;
			}
			else
			lst = lst->next;
		}
	}
	return (begin);
}

#include <stdio.h>
int		ascending(int a, int b)
{
		return (a <= b);
}

#include <stdlib.h>

int		main(void)
{
	t_list *l;
	int		i;
	t_list	*t;
	t_list	*b;

	i = 10;
	l = malloc(sizeof(t_list));
	t = l;
	b = l;
	while (i)
	{
		l->data = i % 3;
		l->next = malloc(sizeof(t_list));
		l = l->next;
		--i;
	}
	l->data = (int)"fromage";
	l->next = NULL;
	while (t)
	{
		printf("%d ", t->data);
		t = t->next;
		++i;
	}
	b = sort_list(b, ascending);
	while (b)
	{
		printf("%d ", b->data);
		b = b->next;
		++i;
	}
}