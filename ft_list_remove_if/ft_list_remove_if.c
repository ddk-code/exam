/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharlot <pcharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:20:50 by pcharlot          #+#    #+#             */
/*   Updated: 2020/02/19 14:40:37 by pcharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_list.h"

void ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	t_list	*temp;
	t_list	*t;

	temp = *begin_list;
	while(temp && (*cmp)(temp->data, data_ref) == 0)
	{
		*begin_list = (*begin_list)->next;
		free(temp->data);
		free(temp);
		temp = *begin_list;
	}
	while(temp->next)
	{
		if((*cmp)(temp->next->data, data_ref) == 0)
		{
			t = temp->next;
			temp->next = t->next;
			free(t->data);
			free(t);							
		}
		else
			temp = temp->next;	
	}
}

int main()
{
	
}