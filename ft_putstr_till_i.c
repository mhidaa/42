/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_till_i.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 12:08:31 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 03:03:11 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_till_i(char *s, size_t i)
{
	if (!s)
		return ;
	while (i > INT_MAX)
	{
		write(1, s, INT_MAX);
		s += INT_MAX;
		i -= INT_MAX;
	}
	write(1, s, i);
}
