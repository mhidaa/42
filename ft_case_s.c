/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 11:48:20 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 02:59:22 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_print_s(t_flag *flags, char *heap, \
	char *s, long long width)
{
	if (flags->flag_minus)
		ft_print_s_with_minus(flags, heap, s, width);
	if (flags->flag_zero && !(flags->flag_minus))
		ft_print_s_with_zero(flags, heap, s, width);
	if (!(flags->flag_minus) && !(flags->flag_zero))
		ft_putstr(heap);
}

void	ft_case_s(t_flag *flags, va_list *ap, ssize_t *put_cnt)
{
	char		*s;
	char		*heap;
	long long	width;

	if (flags->error)
		return ;
	s = (char *)va_arg(*ap, char *);
	if (s == NULL)
		flags->null = 1;
	if (flags->null)
		s = "(null)";
	width = ft_strlen(s);
	width = ft_set_width(flags, width);
	heap = (char *)malloc(sizeof(char) * (width + 1));
	if (!heap)
		flags->error = 1;
	if (flags->error)
		return ;
	ft_set_heap_s(flags, width, heap, s);
	ft_print_s(flags, heap, s, width);
	*put_cnt += width;
	free(heap);
}
