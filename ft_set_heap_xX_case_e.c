/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_heap_xX_case_e.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 22:21:17 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 03:07:13 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_judge_space_len(t_flag *flags, char *heap, \
	long long *i, long long *len)
{
	if (flags->space_perc_to_next)
		heap[*i++] = ' ';
	if (flags->n_zero && flags->acc_is_zero)
		*len = 0;
}

static void	ft_set_heap_xX_case_e2(t_flag *flags, long long width, \
	char *heap, char *n_str)
{
	long long	i;
	long long	j;
	long long	len;

	i = 0;
	j = 0;
	len = ft_strlen(n_str);
	ft_judge_space_len(flags, heap, &i, &len);
	while (i < (width - len))
		heap[i++] = ' ';
	while (i < width)
		heap[i++] = n_str[j++];
	heap[i] = '\0';
}

void	ft_set_heap_xX_case_e(t_flag *flags, long long width, \
	char *heap, char *n_str)
{
	long long	i;
	long long	j;
	long long	len;

	i = 0;
	j = 0;
	len = ft_strlen(n_str);
	if (flags->mfw > len)
		ft_set_heap_xX_case_e2(flags, width, heap, n_str);
	else
	{
		ft_judge_space_len(flags, heap, &i, &len);
		while (i < width)
			heap[i++] = n_str[j++];
		heap[i] = '\0';
	}
}
