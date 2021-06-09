/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_judge_mfw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 23:16:00 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 03:00:23 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_judge_mfw2(t_flag *flags)
{
	if (flags->mfw == 0)
		flags->flag_zero = 1;
	if (flags->mfw < 0)
	{
		flags->mfw = (flags->mfw * -1);
		flags->flag_minus = 1;
	}
}

size_t	ft_judge_mfw(t_flag *flags, const char *format, \
	size_t fmt_i, va_list *ap)
{
	while (*format == ' ')
	{
		fmt_i++;
		format += 1;
	}
	if (ft_isdigit(*format))
	{
		while (ft_isdigit(*format))
		{
			flags->mfw = ((10 * flags->mfw) + (*format++ - '0'));
			fmt_i++;
		}
		if (flags->mfw == 0)
			flags->flag_zero = 1;
	}
	else if (*format == '*')
	{
		flags->mfw = (int)va_arg(*ap, int);
		ft_judge_mfw2(flags);
		fmt_i++;
	}
	if (flags->mfw == INT_MAX || flags->mfw == INT_MIN || \
		flags->mfw * -1 == INT_MIN)
		flags->error = 1;
	return (fmt_i);
}
