/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_judge_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 21:13:18 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 03:00:18 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_judge_flag(t_flag *flags, const char *format, size_t fmt_i)
{
	while (*format == ' ')
	{
		flags->space_perc_to_next++;
		fmt_i++;
		format += 1;
	}
	while (*format == '0' || *format == '-')
	{
		if (*format == '0')
			flags->flag_zero = 1;
		if (*format++ == '-')
			flags->flag_minus = 1;
		fmt_i++;
	}
	return (fmt_i);
}
