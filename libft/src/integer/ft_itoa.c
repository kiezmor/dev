/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsimeon <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 18:27:16 by gsimeon           #+#    #+#             */
/*   Updated: 2015/12/07 01:32:23 by gsimeon          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	tmp[12];
	int		i;

	i = 10;
	tmp[11] = '\0';
	ft_memset(tmp, '0', 11);
	while (n)
	{
		if ((tmp[i] = n % 10) < 0)
		{
			tmp[i] = -tmp[i];
			tmp[i - 1] = '-';
		}
		tmp[i] += '0';
		n /= 10;
		i--;
	}
	if (tmp[i] == '-' || i == 10)
		i--;
	return (ft_strdup(&tmp[i + 1]));
}
