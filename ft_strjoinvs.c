/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhass <nbenhass@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 15:07:23 by nbenhass          #+#    #+#             */
/*   Updated: 2026/08/19 14:43:38 by nbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int	ft_strlen(char *l)
{
	int	i;

	i = 0;
	while (l[i])
		i++;
	return (i);
}

size_t	total_length(int size, char **strs, char *sep)
{
	int	length;
	
	length = 0;
	while (size > -1)
	{
		size--;
		length += ft_strlen(strs[size]);
		if (size != 0)
			length += ft_strlen(sep);	
	}
//	length += ft_strlen(sep) * (size - 1);
	printf("%i\n", length);
	return (length);
}

char	*add_sep(char *join, char *sep/*, int i*/)
{
	int	c;

	c = 0;
	while (sep[c] != '\0')
	{
		*join = sep[c];
		join++;
		c++;
	}
	return (join);
}

char	*fill(int size, char **strs, char *sep, char *join)
{
	int	sz;
	int	c;
	
	sz = 0;
	while((*strs)[sz] != (*strs)[size])
	{
		c = 0;
		while (strs[sz][c])
		{
			*join = strs[sz][c];
			join++;
			c++;
		}
		if ((*strs)[sz] != (*strs)[size - 1])
			add_sep(join, sep);
		join += ft_strlen(sep);
		sz++;
	}
	*join = '\0';
	*join -= total_length(size, strs, sep);
	return (join);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*join;

	if (size <= 0)
	{
		join = malloc(1);
		join[0] = '\0';
		return (join);
	}
	join = malloc((total_length(size, strs, sep) + 1) * sizeof(char));
//	join = malloc(500);
	if (join == NULL)
		return (NULL);
	fill(size, strs, sep, join);
	return (join);
}

#include <stdio.h>

int main()
{
	char *sep = " . ";
	char *tab[5] = {"Puissant", "comme", "esprit", "de", "conquete"};
	int size;
	char	*test;

	size = 5;
	test = ft_strjoin(size, tab, sep);
	printf("%s\n", test);
}
