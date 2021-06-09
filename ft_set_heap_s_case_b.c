/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_heap_s_case_b.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 20:28:27 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 03:05:04 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_set_heap_s_case_b_a(long long width, char *heap, char *s)
{
	long long	i;
	long long	j;
	long long	len;

	i = 0;
	j = 0;
	len = ft_strlen(s);
	if (width > len)
	{
		while (i < (width - len))
			heap[i++] = ' ';
		while (i < width)
			heap[i++] = s[j++];
		heap[i] = '\0';
	}
	else
	{
		while (i < width)
		{
			heap[i] = s[j];
			i ++;
			j++;
		}
		heap[i] = '\0';
	}
}

void	ft_set_heap_s_case_b(t_flag *flags, long long width, \
	char *heap, char *s)
{
	long long	i;

	i = 0;
	if (flags->dot_exists)
	{
		while (i < width)
			heap[i++] = ' ';
		heap[i] = '\0';
	}
	else
		ft_set_heap_s_case_b_a(width, heap, s);
}
