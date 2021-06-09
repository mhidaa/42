/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_heap_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 20:42:22 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 03:19:14 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_set_heap_s_case_e(t_flag *flags, char *heap, \
	long long width)
{
	long long	i;

	i = 0;
	if (flags->acc == 0 && flags->acc_exists)
	{
		if (flags->flag_zero)
			while (i < width)
				heap[i++] = '0';
		else
			while (i < width)
				heap[i++] = ' ';
		heap[i] = '\0';
	}
	else
	{
		if (flags->dot_exists && !(flags->acc_exists))
			while (i < width)
				heap[i++] = ' ';
		else
			while (i < width)
				heap[i++] = '0';
		heap[i] = '\0';
	}
}

void	ft_set_heap_s(t_flag *flags, long long width, char *heap, char *s)
{
	if ((flags->dot_exists && !(flags->acc_exists)) || \
		(flags->acc_exists && flags->acc == 0))
		ft_set_heap_s_case_e(flags, heap, width);
	else if (flags->acc_exists && !(flags->mfw))
		ft_set_heap_s_case_a(heap, s, width);
	else if (!(flags->acc_exists) && flags->mfw)
		ft_set_heap_s_case_b(flags, width, heap, s);
	else if (flags->acc_exists && flags->mfw)
		ft_set_heap_s_case_c(flags, width, heap, s);
	else if (!(flags->acc_exists) && !(flags->mfw))
		ft_set_heap_s_case_d(heap, s, width);
}
