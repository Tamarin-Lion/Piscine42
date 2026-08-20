/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhass <nbenhass@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 11:41:43 by nbenhass          #+#    #+#             */
/*   Updated: 2026/08/20 17:56:23 by nbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	ft_strlen(char *l);
int	is_sep(char str, char *charset);
int	word_length(char *str, char *charset, int i);
int	count_words(char *str, char *charset);
char	**ft_split(char *str, char *charset);

int	word_length(char *str, char *charset, int i)
{
	int	l;

	l = 0;
	while (str[i] && !(is_sep(str[i], charset)))
	{
		i++;
		l++;
	}
	return (l);
}

int	count_words(char *str, char *charset)
{
	int	c;
	int	i;
	int	inword;

	inword = 0;
	c = 0;
	i = 0;
	while (str[i])
	{
		if (is_sep(str[i], charset))
		{
			i++;
			inword = 0;
		}
		else if (inword != 1)
		{
			inword = 1;
			c++;
			i++;
		}
		else
			i++;
	}
	return (c);
}

int	is_sep(char str, char *charset)
{
	int	c;

	c = 0;
	while (charset[c])
	{
		if (str == charset[c])
			return (1);
		c++;
	}
	return (0);
}

int	ft_strlen(char *l)
{
	int	i;

	i = 0;
	while (l[i])
		i++;
	return (i);
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int	i;
	int	w;
	int	c;
	int	alloc;

	i = 0;
	w = 0;
	alloc = ft_strlen(str) - count_words(str, charset) + 1;
	if (!str || !charset)
		return (NULL);
	split = malloc(sizeof(**split) * alloc);
//	split = malloc(500); //a supp
	while (str[i])
	{
		if (is_sep(str[i], charset))
		{
			i++;
		}
		else
		{
			c = 0;
			while (!(is_sep(str[i], charset)))
			{
				split[w][c] = str[i];
				i++;
			}
			w++;
		}
	}
	*split[w] = '\0';
	return (split);
}

int	main()
{
	char	str[] = "PuissantgoCommegoEspritgoDegoConquete";
	char	charset[] = "go";
	char	**test;
	int i = 0;
	int w = 0;
	
	test = ft_split(str, charset);
	while (**test)
	{
		i = 0;
		while(test[w][i])
		{
			printf("%c", test[w][i]);
			i++;
		}
		printf("\n");
		w++;
	}
}
