/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 00:06:30 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 03:07:46 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

ssize_t	ft_strchr_i(const char *str, char c)
{
	char	*result;
	ssize_t	i;

	i = 0;
	result = (char *)str;
	while (result[i] != '\0')
	{
		if (result[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
