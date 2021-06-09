/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_width_for_di.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 18:55:33 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 03:07:32 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_set_width_for_di_with_n_zero(t_flag *flags, long long *width)
{
	if (flags->acc_is_zero && !(flags->mfw))
		*width = 0;
	if (flags->dot_exists && !(flags->acc_exists) && !(flags->mfw))
		*width = 0;
	if (flags->dot_exists && flags->acc_is_zero && !(flags->mfw))
		*width = 0;
}

long long	ft_set_width_for_di(t_flag *flags, long long width, long long len)
{
	if (!(flags->n_minus))
	{
		if (flags->acc >= len)
			width = flags->acc;
		else
			width = len;
		if (flags->n_zero)
			ft_set_width_for_di_with_n_zero(flags, &width);
		if (flags->mfw)
			if (flags->mfw > width)
				width = flags->mfw;
		return (width);
	}
	else
	{
		if (flags->acc >= len)
			width = flags->acc + 1;
		else
			width = len;
		if (flags->mfw)
			if (flags->mfw > width)
				width = flags->mfw;
		return (width);
	}
}
