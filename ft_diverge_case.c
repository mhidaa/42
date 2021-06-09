/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diverge_case.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 01:42:21 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 02:59:49 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_diverge_case(t_flag *flags, va_list *ap, ssize_t *put_cnt)
{
	if (flags->conv_specifier == 0)
		ft_case_c(flags, ap, put_cnt);
	if (flags->conv_specifier == 1)
		ft_case_s(flags, ap, put_cnt);
	if (flags->conv_specifier == 2)
		ft_case_p(flags, ap, put_cnt);
	if (flags->conv_specifier == 3 || flags->conv_specifier == 4)
		ft_case_di(flags, ap, put_cnt);
	if (flags->conv_specifier == 5)
		ft_case_u(flags, ap, put_cnt);
	if (flags->conv_specifier == 6 || flags->conv_specifier == 7)
		ft_case_xX(flags, ap, put_cnt);
	if (flags->conv_specifier == 8)
		ft_case_percent(flags, put_cnt);
	if (flags->conv_specifier == 9)
		ft_case_o(flags, ap, put_cnt);
}
