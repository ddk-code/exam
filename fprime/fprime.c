/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprime.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharlot <pcharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 08:59:15 by pcharlot          #+#    #+#             */
/*   Updated: 2020/02/13 09:24:00 by pcharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include <stdio.h>

void	fprime(int	n)
{
	int i;

	i = 2;
	if (n == 1)
	{
		printf("%d", 1);
		return ;
	}
	while(n != 1)
	{
		if (n % i == 0)
		{
			printf("%d", i);
			if (n != i)
				printf("*");
			n = n / i;
		}
		else
		{
			++i;
		}		
	}
}
	
int		main(int argc, char **argv)
{
	if (argc == 2)
			fprime(atoi(argv[1]));
	printf("\n");
	return (0);
}