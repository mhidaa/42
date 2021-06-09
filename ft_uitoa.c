/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 04:01:53 by mhida             #+#    #+#             */
/*   Updated: 2021/06/09 03:08:06 by mhida            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_judge(unsigned long long ullon, int ui_len)
{
	if (ullon == 0)
		ui_len = 1;
	else
	{
		while (ullon)
		{
			ullon /= 10;
			ui_len++;
		}
	}
	return (ui_len);
}

char	*ft_uitoa(unsigned int ui)
{
	char				*heap;
	int					ui_len;
	int					ui_len_origin;
	unsigned long long	ullon;

	ullon = ui;
	ui_len = 0;
	ui_len = ft_judge(ullon, ui_len);
	ui_len_origin = ui_len;
	heap = (char *)malloc(sizeof(char) * (ui_len + 1));
	if (heap == NULL)
		return (NULL);
	while (ui_len)
	{
		heap[ui_len - 1] = ullon % 10 + '0';
		ullon /= 10;
		ui_len--;
	}
	heap[ui_len_origin] = '\0';
	return (heap);
}
