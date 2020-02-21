/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharlot <pcharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/19 14:58:47 by pcharlot          #+#    #+#             */
/*   Updated: 2020/02/20 11:19:23 by pcharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIST_H
#define FT_LIST_H

typedef	struct		s_list
{
	int				data;
	struct s_list	*next;
}					t_list;

t_list	*sort_list(t_list* lst, int (*cmp)(int, int));

#endif
