/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_width_for_p.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 11:37:35 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 03:07:37 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long	ft_set_width_for_p_with_null(t_flag *flags, \
	long long width, long long len)
{
	if (flags->dot_exists && !(flags->acc_exists))
	{
		if (flags->mfw && flags->mfw > 1)
			width = flags->mfw;
		else
			width = 2;
		return (width);
	}
	if (flags->acc >= len)
		width = flags->acc + 2;
	else
		width = len;
	if (flags->mfw)
		if (flags->mfw > width)
			width = flags->mfw;
	return (width);
}

long long	ft_set_width_for_p(t_flag *flags, long long width, long long len)
{
	if (flags->null)
	{
		width = ft_set_width_for_p_with_null(flags, width, len);
		return (width);
	}
	else
	{
		if (flags->acc + 2 > len)
			width = flags->acc + 2;
		else
			width = len;
		if (flags->mfw > width)
			width = flags->mfw;
		return (width);
	}
}
