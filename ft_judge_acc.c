/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_judge_acc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 23:35:38 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 03:00:09 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_set_fmt(size_t *fmt_i)
{
	*fmt_i += 1;
	return (1);
}

static void	ft_case_acc_star(t_flag *flags, va_list *ap, size_t *fmt_i)
{
	flags->acc_exists = 1;
	flags->acc_star_exists = 1;
	flags->acc = (int)va_arg(*ap, int);
	if (flags->acc == 0)
		flags->acc_is_zero = 1;
	if (flags->acc < 0)
		flags->acc_star_minus = 1;
	*fmt_i += 1;
}

size_t	ft_judge_acc(t_flag *flags, const char *format, \
	size_t fmt_i, va_list *ap)
{
	while (*format == ' ')
		format += ft_set_fmt(&fmt_i);
	if (*format == '.')
	{
		flags->dot_exists = 1;
		format += ft_set_fmt(&fmt_i);
		while (*format == ' ')
			format += ft_set_fmt(&fmt_i);
		if (ft_isdigit(*format))
		{
			flags->acc_exists = 1;
			while (ft_isdigit(*format))
			{
				flags->acc = (10 * flags->acc) + (*format++ - '0');
				fmt_i++;
			}
			if (flags->acc == 0)
				flags->acc_is_zero = 1;
		}
		else if (*format == '*')
			ft_case_acc_star(flags, ap, &fmt_i);
	}
	return (fmt_i);
}
