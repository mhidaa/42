/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 11:31:22 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 03:17:57 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_c(t_flag *flags, char *heap, \
	char c, long long width)
{
	if (flags->flag_minus)
		ft_print_c_with_minus(heap, c);
	if (flags->flag_zero && !(flags->flag_minus))
		ft_print_c_with_zero(width, c);
	if (!(flags->flag_minus) && !(flags->flag_zero))
		ft_print_c_with_no_flag(heap, c);
}

void	ft_case_c(t_flag *flags, va_list *ap, ssize_t *put_cnt)
{
	char		c;
	char		*heap;
	long long	width;

	if (flags->error)
		return ;
	width = 1;
	width = ft_set_width(flags, width);
	c = (char)va_arg(*ap, int);
	heap = (char *)malloc(sizeof(char) * (width + 1));
	if (!heap)
	{
		flags->error = 1;
		return ;
	}
	ft_set_heap_c(heap, width);
	ft_print_c(flags, heap, c, width);
	*put_cnt += width;
	free(heap);
}
