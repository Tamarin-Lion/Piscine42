/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhass <nbenhass@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/20 11:41:43 by nbenhass          #+#    #+#             */
/*   Updated: 2026/08/20 19:57:21 by nbenhass         ###   ########.fr       */
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

int	is_sep(char s, char *charset)
{
	int	c;

	c = 0;
	while (charset[c])
	{
		if (s == charset[c])
			return (1);
		c++;
	}
	return (0);
}

char	*putstr(char *str, char *charset, int i)
{
	char	*cpy;
	int	s;

	s = 0;
	cpy = malloc(sizeof(char) * word_length(str, charset, i) + 1);
	while (str[i] && !(is_sep(str[i], charset)))
	{
		cpy[s] = str[i];
		s++;
		i++;
	}
	cpy[s] = '\0';
	printf("copy is : %s\n", cpy);
	return (cpy);
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int	i;
	int	w;

	i = 0;
	w = 0;
	if (!str || !charset)
		return (NULL);
	split = malloc(sizeof(char *) * count_words(str, charset) + 1);
	while (is_sep(str[i], charset))
		i++;
	while (str[i])
	{
		split[w] = putstr(str, charset, i);
		i += word_length(str, charset, i);
		while (is_sep(str[i], charset))
			i++;
		w++;
	}
	split[w] = 0;
	return (split);
}

int	main()
{
	char	str[] = "PuissantgdCommegdEspritgdDegdConquete";
	char	charset[] = "gd";
	char	**test;
	int w = 0;
	
	test = ft_split(str, charset);
	while (test[w])
	{
		printf("%s ", test[w]);
		w++;
	}
}
