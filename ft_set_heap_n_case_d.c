/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_heap_n_case_d.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 22:18:06 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 03:03:39 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_set_heap_n_case_d_b_a2(t_flag *flags, long long width, \
	char *heap, char *n_str)
{
	long long	i;
	long long	j;
	long long	len;

	i = 0;
	j = 0;
	len = ft_strlen(n_str);
	while (i < width - flags->acc)
		heap[i++] = ' ';
	while (flags->acc - len)
	{
		heap[i++] = '0';
		len++;
	}
	while (i < width)
		heap[i++] = n_str[j++];
	heap[i] = '\0';
}

static void	ft_set_heap_n_case_d_b_a(t_flag *flags, long long width, \
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
	if (len >= flags->acc)
	{
		while (i < (width - len))
			heap[i++] = ' ';
		while (i < width)
			heap[i++] = n_str[j++];
		heap[i] = '\0';
	}
	else
		ft_set_heap_n_case_d_b_a2(flags, width, heap, n_str);
}

static void	ft_set_heap_n_case_d_b(t_flag *flags, long long width, \
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
		while (i < (flags->acc - len + 1))
			heap[i++] = '0';
		while (n_str[j])
			heap[i++] = n_str[j++];
		while (i < width)
			heap[i++] = ' ';
		heap[i] = '\0';
	}
	else
		ft_set_heap_n_case_d_b_a(flags, width, heap, n_str);
}

static void	ft_set_heap_n_case_d_a(t_flag *flags, long long width, \
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
		while (i < (width - flags->acc - 1))
			heap[i++] = ' ';
		heap[i++] = '-';
		j++;
		len--;
	}
	else
		while (i < (width - flags->acc))
			heap[i++] = ' ';
	while (i < (width - len))
		heap[i++] = '0';
	while (i < width)
		heap[i++] = n_str[j++];
	heap[i] = '\0';
}

void	ft_set_heap_n_case_d(t_flag *flags, long long width, \
	char *heap, char *n_str)
{
	if (!(flags->flag_minus))
		ft_set_heap_n_case_d_a(flags, width, heap, n_str);
	else
		ft_set_heap_n_case_d_b(flags, width, heap, n_str);
}
