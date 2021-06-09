/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p_with_minus_case_c.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 13:39:51 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 03:25:59 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_p_with_minus_case_c(t_flag *flags, char *heap, \
	char *n_str, long long width)
{
	long long	len;

	len = ft_strlen(n_str);
	if (len <= flags->acc && flags->acc <= flags->mfw)
	{
		ft_putstr(n_str);
		ft_putstr_till_i(heap, width - len);
	}
	else if (flags->acc == len && len == flags->mfw)
		ft_putstr(n_str);
	else if (flags->acc <= len && len <= flags->mfw)
	{
		ft_putstr(n_str);
		ft_putstr_till_i(heap, width - len);
	}
	else if (flags->acc <= flags->mfw && flags->mfw <= len)
		ft_putstr(n_str);
	else
		ft_putstr(heap);
}
