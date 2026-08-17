/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhass <nbenhass@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 10:41:47 by nbenhass          #+#    #+#             */
/*   Updated: 2026/08/17 10:45:21 by nbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return ;
}
/*
#include <stdio.h>
int main(int argc, char **argv)
{
        if (argc != 2)
                printf("Error");
        else
        {
                ft_putstr(&argv[1][0]);
        }
	return (0);
}*/
