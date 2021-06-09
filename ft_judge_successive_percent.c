/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_judge_successive_percent.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 11:01:09 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 03:00:28 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

const char	*ft_judge_successive_percent(const char *format, ssize_t *put_cnt)
{
	size_t	i;

	i = 0;
	if (format[i] == '%')
	{
		write(1, format, 1);
		*put_cnt += 1;
	}
	return (&format[i]);
}
