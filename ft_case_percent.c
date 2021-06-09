/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 11:52:16 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 02:59:15 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_printf_percent(t_flag *flags, char *heap, long long width)
{
	if (flags->flag_minus)
		ft_print_percent_with_minus(heap);
	if (flags->flag_zero && !(flags->flag_minus))
		ft_print_percent_with_zero(width);
	if (!(flags->flag_minus) && !(flags->flag_zero))
		ft_print_percent_with_no_flag(heap);
}

void	ft_case_percent(t_flag *flags, ssize_t *put_cnt)
{
	char		*heap;
	long long	width;
	long long	i;

	if (flags->error)
		return ;
	width = 1;
	width = ft_set_width(flags, width);
	heap = (char *)malloc(sizeof(char) * (width));
	if (!heap)
	{
		flags->error = 1;
		return ;
	}
	i = 0;
	while (i < width - 1)
		heap[i++] = ' ';
	heap[i] = '\0';
	ft_printf_percent(flags, heap, width);
	*put_cnt += width;
	free(heap);
}
