/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhass <nbenhass@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 11:05:42 by nbenhass          #+#    #+#             */
/*   Updated: 2026/08/17 12:33:13 by nbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr_non_printable(char *str)
{
	char	*hex;
	int		i;

	i = 0;
	hex = "0123456789abcdef";
	while (str[i] != 0)
	{
		if (str[i] >= 32 && str[i] <= 126)
		{
			write(1, &(str[i]), 1);
			i++;
		}
		else
		{
			write(1, "\\", 1);
			write(1, &(hex[str[i] / 16]), 1);
			write(1, &(hex[str[i] % 16]), 1);
			i++;
		}
	}
	return ;
}
/*
int	main()
{
	char tab[] = "Bon\njour\t, Test";
	ft_putstr_non_printable(tab);
}*/
