/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 11:49:55 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 02:59:06 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_free(char *hex_str, t_flag *flags)
{
	free(hex_str);
	flags->error = 1;
}

static int	ft_judge_error_p(char *hex_str, t_flag *flags)
{
	if (hex_str == NULL)
		flags->error = 1;
	if (flags->error)
		return (1);
	else
		return (0);
}

static void	ft_print_p(t_flag *flags, char *heap, \
	char *hex_str, long long width)
{
	if (flags->flag_minus)
		ft_print_p_with_minus(flags, heap, hex_str, width);
	if (flags->flag_zero && !(flags->flag_minus))
		ft_print_p_with_zero(flags, heap, hex_str, width);
	if (!(flags->flag_minus) && !(flags->flag_zero))
		ft_putstr(heap);
}

void	ft_case_p(t_flag *flags, va_list *ap, ssize_t *put_cnt)
{
	unsigned long long	ull;
	char				*heap;
	char				*hex_str;
	long long			width;

	ull = (unsigned long long)va_arg(*ap, unsigned long long);
	if (!ull)
		flags->null = 1;
	if (flags->null)
		ull = 0;
	hex_str = ft_ulltohex_str(ull, flags);
	if ((ft_judge_error_p(hex_str, flags) == 1) || (flags->error))
		return ;
	width = 2;
	width = ft_set_width_for_p(flags, width, (long long)ft_strlen(hex_str));
	heap = (char *)malloc(sizeof(char) * (width + 1));
	if (!heap)
		ft_free(hex_str, flags);
	if (flags->error)
		return ;
	ft_set_heap_p(flags, width, heap, hex_str);
	ft_print_p(flags, heap, hex_str, width);
	*put_cnt += width;
	free(hex_str);
	free(heap);
}
