/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rostring.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharlot <pcharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 08:19:26 by pcharlot          #+#    #+#             */
/*   Updated: 2020/02/13 08:36:32 by pcharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdlib.h>
#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    rostring(char *s)
{
    int i;
    int start;
    int end;

    i = 0;
    while(s[i] && (s[i] == ' ' || s[i] == '\t'))
        ++i;
    start = i;
    while(s[i] && s[i] != ' ' && s[i] != '\t')
        ++i;
    end = i;
    while(s[i])
    {
        while (s[i] && (s[i] == ' ' || s[i] == '\t'))
            ++i;
        if(s[i] != ' ' && s[i] != '\t')
        {
            while(s[i] && s[i] != ' ' && s[i] != '\t')
                {
                    ft_putchar(s[i]);
                    ++i;                    
                }
            ft_putchar(' ');
        }
    }
    while(start < end)
        {
            ft_putchar(s[start]);
            ++start;
        }    
}

int main(int argc, char **argv)
{
    if(argc >= 2)
        rostring(argv[1]);
    ft_putchar('\n');
    return (0);
}