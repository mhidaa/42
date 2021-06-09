/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_heap_p_case_d.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 12:08:24 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 03:25:12 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_set_heap_p_case_d2(t_flag *flags, long long width, \
	char *heap)
{
	long long	i;

	i = 0;
	while (i < (width - (flags->acc + 2)))
		heap[i++] = ' ';
	heap[i++] = '0';
	heap[i++] = 'x';
	while (i < (width - flags->acc))
		heap[i++] = '0';
	while (i < width)
		heap[i++] = '0';
	heap[i] = '\0';
}

void	ft_set_heap_p_case_d(t_flag *flags, long long width, \
	char *heap, char *n_str)
{
	long long	i;
	long long	j;
	long long	len;

	i = 0;
	j = 2;
	len = ft_strlen(n_str);
	if (flags->null)
		ft_set_heap_p_case_d2(flags, width, heap);
	else
	{
		while (i < (width - (flags->acc + 2)))
			heap[i++] = ' ';
		heap[i++] = '0';
		heap[i++] = 'x';
		while (i < (width - (len - 2)))
			heap[i++] = '0';
		while (i < width)
			heap[i++] = n_str[j++];
		heap[i] = '\0';
	}
}
