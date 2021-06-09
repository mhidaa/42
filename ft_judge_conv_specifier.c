/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_judge_conv_specifier.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 23:53:22 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 03:16:39 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_judge_conv_specifier(t_flag *flags, const char *format, \
	size_t fmt_i)
{
	ssize_t		n;

	while (*format == ' ')
	{
		fmt_i += 1;
		format += 1;
	}
	n = ft_strchr_i("cspdiuxX%o", *format++);
	flags->conv_specifier = n;
	if (!(flags->conv_specifier == -1))
		fmt_i++;
	return (fmt_i);
}
