/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_heap_n.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 18:45:58 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 03:04:09 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_set_heap_n_case_h2(char *heap, long long width)
{
	long long	i;

	i = 0;
	while (i < width)
		heap[i++] = ' ';
	heap[i] = '\0';
}

static void	ft_set_heap_n2(t_flag *flags, long long width, \
	char *heap, char *n_str)
{
	if (!(flags->acc_exists) && flags->mfw)
		ft_set_heap_n_case_a(flags, width, heap, n_str);
	else if (flags->acc_exists && !(flags->mfw))
		ft_set_heap_n_case_b(flags, width, heap, n_str);
	else if (flags->acc_exists && flags->mfw)
	{
		if (flags->acc > flags->mfw)
			ft_set_heap_n_case_c(flags, width, heap, n_str);
		else if (flags->acc == flags->mfw)
			ft_set_heap_n_case_g(flags, width, heap, n_str);
		else if (flags->acc < flags->mfw)
		{
			if (flags->acc >= (long long)ft_strlen(n_str))
				ft_set_heap_n_case_d(flags, width, heap, n_str);
			else
				ft_set_heap_n_case_e(flags, width, heap, n_str);
		}
	}
}

void	ft_set_heap_n(t_flag *flags, long long width, char *heap, char *n_str)
{
	if ((flags->dot_exists && flags->n_zero && !flags->acc_exists) || \
		(flags->dot_exists && flags->n_zero && flags->acc_is_zero))
		ft_set_heap_n_case_h2(heap, width);
	else if (flags->acc_exists || flags->mfw)
		ft_set_heap_n2(flags, width, heap, n_str);
	else
		ft_set_heap_n_case_f(flags, width, heap, n_str);
}
