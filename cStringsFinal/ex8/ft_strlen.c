/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhass <nbenhass@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 10:38:40 by nbenhass          #+#    #+#             */
/*   Updated: 2026/08/17 10:41:18 by nbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
/*
#include <stdio.h>
int main(int argc, char **argv)
{
        if (argc != 2)
                printf("Error");
        else
        {
                printf("%d\n", ft_strlen(&argv[1][0]));
        }
}*/
