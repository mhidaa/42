/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_case_o.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 19:50:04 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 02:58:59 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_judge_error_o(char *oct_str, t_flag *flags, long long *width)
{
	*width = 0;
	if (oct_str == NULL)
		flags->error = 1;
	if (flags->error)
		return (1);
	else
		return (0);
}

static void	ft_print_o(t_flag *flags, char *heap, \
	char *oct_str, long long width)
{
	if (flags->flag_minus)
		ft_print_di_with_minus(flags, heap, oct_str, width);
	if (flags->flag_zero && !(flags->flag_minus))
		ft_print_di_with_zero(flags, heap, oct_str, width);
	if (!(flags->flag_minus) && !(flags->flag_zero))
		ft_putstr(heap);
}

void	ft_case_o(t_flag *flags, va_list *ap, ssize_t *put_cnt)
{
	unsigned int	ui;
	char			*heap;
	char			*oct_str;
	long long		width;

	if (flags->error)
		return ;
	ui = (unsigned int)va_arg(*ap, unsigned int);
	if (ui == 0)
		flags->n_zero = 1;
	oct_str = ft_uitooct_str(ui, flags);
	if (ft_judge_error_o(oct_str, flags, &width) == 1)
		return ;
	width = ft_set_width_for_di(flags, width, (long long)ft_strlen(oct_str));
	heap = (char *)malloc(sizeof(char) * (width + 1));
	if (!heap)
	{
		free(oct_str);
		return ;
	}
	ft_set_heap_n(flags, width, heap, oct_str);
	ft_print_o(flags, heap, oct_str, width);
	*put_cnt += width;
	free(oct_str);
	free(heap);
}
