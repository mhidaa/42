/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_heap_s_case_c.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 20:43:43 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 03:05:52 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_set_heap_s_case_c(t_flag *flags, long long width, \
	char *heap, char *s)
{
	long long	len;

	len = ft_strlen(s);
	if (flags->acc == len && len == flags->mfw)
		ft_set_heap_s_case_c_a(width, heap, s);
	else if (flags->acc <= len && len <= flags->mfw)
		ft_set_heap_s_case_c_b(flags, width, heap, s);
	else if (flags->acc <= flags->mfw && flags->mfw <= len)
		ft_set_heap_s_case_c_c(flags, width, heap, s);
	else if (len <= flags->acc && flags->acc <= flags->mfw)
		ft_set_heap_s_case_c_d(width, heap, s);
	else if (len <= flags->mfw && flags->mfw <= flags->acc)
		ft_set_heap_s_case_c_e(width, heap, s);
	else if (flags->mfw <= len && len <= flags->acc)
		ft_set_heap_s_case_c_f(width, heap, s);
	else if (flags->mfw <= flags->acc && flags->acc <= len)
		ft_set_heap_s_case_c_g(flags, heap, s);
}
