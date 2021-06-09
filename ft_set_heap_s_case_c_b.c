/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_heap_s_case_c_b.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 20:57:37 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 03:05:16 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_set_heap_s2(t_flag *flags, long long width, \
	char *heap, char *s)
{
	long long	i;
	long long	j;

	i = 0;
	j = 0;
	if (!(flags->flag_zero))
	{
		while (i < (width - flags->acc))
			heap[i++] = ' ';
		while (i < width)
			heap[i++] = s[j++];
		heap[i] = '\0';
	}
	else
	{
		while (i < (width - flags->acc))
			heap[i++] = '0';
		while (i < width)
			heap[i++] = s[j++];
		heap[i] = '\0';
	}
}

void	ft_set_heap_s_case_c_b(t_flag *flags, long long width, \
	char *heap, char *s)
{
	long long	i;
	long long	j;

	i = 0;
	j = 0;
	if (!(flags->acc_star_minus))
		ft_set_heap_s2(flags, width, heap, s);
	else
	{
		while (i < (width - (long long)ft_strlen(s)))
			heap[i++] = ' ';
		while (i < width)
			heap[i++] = s[j++];
		heap[i] = '\0';
	}
}
