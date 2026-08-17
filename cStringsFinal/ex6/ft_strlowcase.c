/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhass <nbenhass@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 09:40:52 by nbenhass          #+#    #+#             */
/*   Updated: 2026/08/17 10:02:27 by nbenhass         ###   ########.fr       */
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

/*#include <stdio.h>
int main(int argc, char **argv)
{
	if (argc != 2)
		printf("Error");
	else
	{
		printf("%s\n", ft_strlowcase(&argv[1][0]));
	}
}*/
