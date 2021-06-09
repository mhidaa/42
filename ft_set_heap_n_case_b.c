/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_heap_n_case_b.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 22:08:15 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 03:03:30 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_set_heap_n_case_b_a(t_flag *flags, long long width, \
	char *heap, char *n_str)
{
	long long	i;
	long long	j;
	long long	len;

	i = 0;
	j = 0;
	len = ft_strlen(n_str);
	if (flags->space_perc_to_next)
		heap[i++] = ' ';
	if (flags->n_minus)
	{
		heap[i++] = '-';
		j++;
		len--;
	}
	while (i < (width - len))
		heap[i++] = '0';
	while (i < width)
		heap[i++] = n_str[j++];
	heap[i] = '\0';
}

void	ft_set_heap_n_case_b(t_flag *flags, long long width, \
	char *heap, char *n_str)
{
	long long	i;
	long long	j;
	long long	len;

	i = 0;
	j = 0;
	len = ft_strlen(n_str);
	if (flags->space_perc_to_next)
		heap[i++] = ' ';
	if (flags->acc >= len)
		ft_set_heap_n_case_b_a(flags, width, heap, n_str);
	else
	{
		if (flags->n_minus)
		{
			heap[i++] = '-';
			j++;
		}
		while (i < width)
			heap[i++] = n_str[j++];
		heap[i] = '\0';
	}
}
