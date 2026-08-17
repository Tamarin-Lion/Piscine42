/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhass <nbenhass@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 10:03:06 by nbenhass          #+#    #+#             */
/*   Updated: 2026/08/17 10:38:08 by nbenhass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 32;
		}
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	ft_strlowcase(str);
	while (str[i])
	{
		if (i == 0 && str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		if ((str[i] >= 'a' && str[i] <= 'z')
			&& !((str[i - 1] >= 'A' && str[i - 1] <= 'Z')
				|| (str[i - 1] >= '0' && str[i - 1] <= '9')
				|| (str[i - 1] >= 'a' && str[i - 1] <= 'z')))
			str[i] -= 32;
		i++;
	}
	return (str);
}
/*
#include <stdio.h>
int main(int argc, char **argv)
{
        if (argc != 2)
                printf("Error");
        else
        {
                printf("%s\n", ft_strcapitalize(&argv[1][0]));
        }
}*/
