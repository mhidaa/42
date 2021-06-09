/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_width.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 07:10:03 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 03:07:41 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_set_width2(t_flag *flags, long long *width)
{
	if (flags->acc_exists && flags->acc < *width)
		*width = flags->acc;
	if (flags->mfw > *width)
		*width = flags->mfw;
	if (flags->dot_exists && !(flags->acc_exists) && !(flags->mfw) \
		&& !(flags->conv_specifier == 8))
		*width = 0;
	else if (flags->dot_exists && !(flags->acc_exists) && !(flags->mfw) \
		&& flags->conv_specifier == 8)
		*width = 1;
	if (flags->dot_exists && !(flags->acc_exists) && flags->mfw)
		*width = flags->mfw;
	else if (flags->dot_exists && flags->acc_is_zero \
		&& flags->conv_specifier == 8 && !(flags->mfw))
		*width = 1;
}

long long	ft_set_width(t_flag *flags, long long width)
{
	if (flags->conv_specifier == 0 || flags->conv_specifier == 1 || \
		flags->conv_specifier == 8)
	{
		if (flags->acc_star_exists && flags->acc_star_minus)
		{
			if (flags->mfw > width)
				width = flags->mfw;
			return (width);
		}
		ft_set_width2(flags, &width);
		return (width);
	}
	if (flags->acc_exists)
		width = flags->acc;
	if (flags->mfw)
		if (flags->mfw > width)
			width = flags->mfw;
	return (width);
}
