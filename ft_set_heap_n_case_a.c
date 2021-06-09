/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_heap_n_case_a.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 22:02:35 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 03:03:25 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_judge_space_len(t_flag *flags, char *heap, \
	long long *i, long long *len)
{
	if (flags->space_perc_to_next)
		heap[*i++] = ' ';
	if (flags->n_zero && flags->dot_exists)
		*len = 0;
}

static void	ft_set_heap_n_case_a_a_a(t_flag *flags, long long width, \
	char *heap, char *n_str)
{
	long long	i;
	long long	j;
	long long	len;

	i = 0;
	j = 0;
	len = ft_strlen(n_str);
	ft_judge_space_len(flags, heap, &i, &len);
	if (flags->dot_exists && !(flags->acc_exists))
	{
		while (i < width - len)
			heap[i++] = ' ';
		while (i < width)
			heap[i++] = n_str[j++];
	}
	else
	{
		heap[i++] = '-';
		j++;
		while (i < (width - (len - 1)))
			heap[i++] = '0';
		while (i < width + 1)
			heap[i++] = n_str[j++];
	}
	heap[i] = '\0';
}

static void	ft_set_heap_n_case_a_b(t_flag *flags, long long width, \
	char *heap, char *n_str)
{
	long long	i;
	long long	j;
	long long	len;

	i = 0;
	j = 0;
	len = ft_strlen(n_str);
	ft_judge_space_len(flags, heap, &i, &len);
	if (!(flags->acc_exists) && flags->dot_exists)
	{
		while (i < width - len)
			heap[i++] = ' ';
		while (i < width)
			heap[i++] = n_str[j++];
		heap[i] = '\0';
	}
	else
	{
		while (i < (width - len))
			heap[i++] = '0';
		while (i < width)
			heap[i++] = n_str[j++];
		heap[i] = '\0';
	}
}

static void	ft_set_heap_n_case_a_a(t_flag *flags, long long width, \
	char *heap, char *n_str)
{
	long long	i;
	long long	j;
	long long	len;

	i = 0;
	j = 0;
	len = ft_strlen(n_str);
	ft_judge_space_len(flags, heap, &i, &len);
	if (flags->flag_minus)
	{
		while (i < (width - len))
			heap[i++] = ' ';
		while (i < width)
			heap[i++] = n_str[j++];
		heap[i] = '\0';
	}
	else
		ft_set_heap_n_case_a_a_a(flags, width, heap, n_str);
}

void	ft_set_heap_n_case_a(t_flag *flags, long long width, \
	char *heap, char *n_str)
{
	long long	i;
	long long	j;
	long long	len;

	i = 0;
	j = 0;
	len = ft_strlen(n_str);
	ft_judge_space_len(flags, heap, &i, &len);
	if (flags->flag_zero && flags->n_minus && \
		!(flags->flag_minus && flags->flag_zero))
		ft_set_heap_n_case_a_a(flags, width, heap, n_str);
	else if (flags->flag_zero && !(flags->n_minus) && \
		!(flags->flag_minus && flags->flag_zero))
		ft_set_heap_n_case_a_b(flags, width, heap, n_str);
	else
	{
		while (i < (width - len))
			heap[i++] = ' ';
		while (i < width)
			heap[i++] = n_str[j++];
		heap[i] = '\0';
	}
}
