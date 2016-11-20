/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpluchar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 16:40:57 by vpluchar          #+#    #+#             */
/*   Updated: 2016/11/10 16:52:44 by vpluchar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_atoi(char *str)
{
	int		v;
	int		nbs;
	int		neg;

	v = 0;
	nbs = 0;
	neg = 0;
	while ((str[v] == ' ') || (str[v] >= 9 && str[v] <= 13))
		v++;
	if (str[v] == 45)
		neg = 1;
	if (str[v] == 45 || str[v] == 43)
		v++;
	while (str[v] >= 48 && str[v] <= 57)
	{
		nbs *= 10;
		nbs += (str[v] - 48);
		v++;
	}
	if (neg == 1)
		return (-nbs);
	else
		return (nbs);
}
