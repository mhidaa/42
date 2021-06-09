/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 16:01:24 by mhida             #+#    #+#             */
/*   Updated: 2021/06/06 13:50:01 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_judge_percent(const char *format, size_t *fmt_i)
{
	if (*format == '%')
	{
		*fmt_i += 1;
		return (*fmt_i);
	}
	else
		return (0);
}

static size_t	ft_from_percent(t_flag *flags, const char *format, \
	va_list *ap, ssize_t *put_cnt)
{
	size_t	fmt_i;
	size_t	fmt_i_tmp;

	fmt_i = 0;
	format = ft_judge_successive_percent(format, put_cnt);
	if (ft_judge_percent(format, &fmt_i))
		return (fmt_i);
	ft_init_flags(flags);
	fmt_i = ft_judge_flag(flags, format, fmt_i);
	format += fmt_i;
	fmt_i_tmp = fmt_i;
	fmt_i = ft_judge_mfw(flags, format, fmt_i, ap);
	format += (fmt_i - fmt_i_tmp);
	fmt_i_tmp = fmt_i;
	fmt_i = ft_judge_acc(flags, format, fmt_i, ap);
	format += (fmt_i - fmt_i_tmp);
	fmt_i_tmp = fmt_i;
	fmt_i = ft_judge_conv_specifier(flags, format, fmt_i);
	if (flags->conv_specifier == -1)
		return (fmt_i);
	format += (fmt_i - fmt_i_tmp);
	ft_diverge_case(flags, ap, put_cnt);
	return (fmt_i);
}

static ssize_t	ft_not_percent(const char *format, ssize_t put_cnt)
{
	write(1, format, 1);
	put_cnt++;
	return (put_cnt);
}

static void	ft_init(size_t *i, ssize_t *put_cnt, t_flag *flags)
{
	*i = 0;
	*put_cnt = 0;
	ft_init_flags(flags);
}

int	ft_printf(const char *format, ...)
{
	t_flag		flags;
	va_list		ap;
	ssize_t		put_cnt;
	size_t		i;

	if (!format)
		return (-1);
	va_start(ap, format);
	ft_init(&i, &put_cnt, &flags);
	while (format[i] && flags.error == 0)
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i])
				i += ft_from_percent(&flags, &format[i], &ap, &put_cnt);
		}
		else
			put_cnt = ft_not_percent(&format[i++], put_cnt);
	}
	va_end(ap);
	if (flags.error)
		return (-1);
	else
		return (put_cnt);
}
