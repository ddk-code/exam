/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcharlot <pcharlot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 10:04:41 by pcharlot          #+#    #+#             */
/*   Updated: 2020/02/15 10:58:23 by pcharlot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int blank(char c)
{
   if (c == ' ' || c == '\t' || c == '\n')
      return (1);
   else
      return (0);
}

int words(char *s)
{
   int i;
   int res;

   i = 0;
   res = 0;
   while(s[i])
   {
      if (!blank(s[i]) && (blank(s[i + 1]) || s[i + 1] == '\0'))
         ++res;
      ++i;
   }
   return(res);
}

int letters(char *s)
{
   int i;

   i = 0;
   while(s[i] && !blank(s[i]))
      ++i;
   return (i);
}

char    **ft_split(char *str)
{
   int i;
   int j;
   int k;
   char **split;

   split = (char **)malloc(sizeof(char *) * (words(str) + 1));
   i = 0;
   k = 0;
   while(str[i])
   {
      j = 0;
      if (!blank(str[i]))
      {
         split[k] = (char *)malloc(letters(str + i) + 1);
         while (!blank(str[i]) && str[i])
         {
            split[k][j] = str[i];
            ++j;
            ++i;
         }
         split[k][j] = '\0';
         ++k;
      }
      else
         ++i;
   }
   split[k] = NULL;
   return (split);
}

#include <stdio.h>

int main(int argc, char **argv)
{
   char **res;
   int i;

// printf("%d", words(argv[1]));
   i = 0;
   res = ft_split(argv[1]);
   while(res[i] != NULL)
   {
      printf("i#%d: %s\n", i, res[i]);
      ++i;
   }
   return(0);
}

//
//#include <stdlib.h>
//
//int        ft_isspace(char c)
//{
// return (c == ' ' || c == '\n' || c == '\t');
//}
//
//int     count_words(char *str)
//{
// int    count;
//
// count = 0;
// while (*str)
// {
//    // move to the beggining of a new word
//    while (*str && ft_isspace(*str))
//       str++;
//    if (*str && !ft_isspace(*str))
//    {
//       count++;
//       // move to the next whitespace
//       while (*str && !ft_isspace(*str))
//          str++;
//    }
// }
// return (count);
//}
//
//char *malloc_word(char *str)
//{
// char *word;
// int    i;
//
// i = 0;
// while (str[i] && !ft_isspace(str[i]))
//    i++;
// word = (char *)malloc(sizeof(char) * (i + 1));
// i = 0;
// while (str[i] && !ft_isspace(str[i]))
// {
//    word[i] = str[i];
//    i++;
// }
// word[i] = '\0';
// return (word);
//}
//
//char **ft_split(char *str)
//{
// char **arr = (char **)malloc(sizeof(char *) * (count_words(str) + 1));
//
// // same as count_words, except we save word to array instead of counting
// int i = 0;
// while (*str)
// {
//    // move to the beggining of a new word
//    while (*str && ft_isspace(*str))
//       str++;
//    if (*str && !ft_isspace(*str))
//    {
//       // save word to array
//       arr[i] = malloc_word(str);
//       i++;
//       // move to the next whitespace
//       while (*str && !ft_isspace(*str))
//          str++;
//    }
// }
// arr[i] = NULL;
// return (arr);
//}
//
// #include <stdio.h>
//
// int    main(int ac, char **av)
// {
//     char **arr;
//
//     char *phrase = "   Hello,   Flavio\t Wuensche!  ";
//     arr = ft_split(phrase);
//     printf("%s\n", arr[0]);
//     printf("%s\n", arr[1]);
//     printf("%s\n", arr[2]);
//     printf("%s\n", arr[3]);
// }