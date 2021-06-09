# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhida <mhida@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/26 16:00:30 by mhida             #+#    #+#              #
#    Updated: 2021/06/09 03:10:06 by mhida            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = ft_printf.c ft_init_flags.c ft_judge_flag.c \
	ft_judge_mfw.c ft_judge_acc.c \
	ft_judge_conv_specifier.c ft_diverge_case.c ft_case_c.c \
	ft_case_s.c ft_case_p.c ft_case_di.c ft_case_u.c \
	ft_case_xX.c ft_case_percent.c ft_judge_successive_percent.c \
	ft_set_width.c ft_print_c_with_minus.c \
	ft_print_c_with_zero.c ft_print_c_with_no_flag.c \
	ft_set_heap_s.c ft_set_heap_s_case_a.c \
	ft_set_heap_s_case_b.c ft_set_heap_s_case_c.c \
	ft_set_heap_s_case_d.c ft_set_heap_s_case_c_a.c \
	ft_set_heap_s_case_c_b.c ft_set_heap_s_case_c_c.c \
	ft_set_heap_s_case_c_d.c ft_set_heap_s_case_c_e.c \
	ft_set_heap_s_case_c_f.c ft_set_heap_s_case_c_g.c \
	ft_print_s_with_minus.c ft_print_s_with_zero.c \
	ft_set_width_for_di.c \
	ft_set_heap_n_case_a.c ft_set_heap_n_case_b.c \
	ft_set_heap_n_case_c.c ft_set_heap_n_case_d.c \
	ft_set_heap_n_case_e.c ft_print_di_with_minus.c \
	ft_print_di_with_zero.c ft_print_di_with_minus_case_a.c \
	ft_print_di_with_minus_case_b.c ft_print_di_with_minus_case_c.c \
	ft_print_di_with_zero_case_a.c ft_print_di_with_zero_case_b.c \
	ft_set_heap_n.c ft_set_heap_n_case_f.c ft_uitohex_str.c \
	ft_ulltohex_str.c ft_set_width_for_p.c ft_set_heap_p.c \
	ft_set_heap_p_case_a.c ft_set_heap_p_case_b.c \
	ft_set_heap_p_case_c.c ft_set_heap_p_case_d.c \
	ft_set_heap_p_case_e.c ft_set_heap_p_case_f.c \
	ft_set_heap_c.c ft_set_heap_n_case_g.c \
	ft_print_percent_with_no_flag.c ft_print_percent_with_minus.c \
	ft_print_percent_with_zero.c ft_case_o.c ft_uitooct_str.c \
	ft_print_p_with_minus.c ft_print_p_with_minus_case_a.c \
	ft_print_p_with_minus_case_b.c ft_print_p_with_minus_case_c.c \
	ft_print_p_with_zero.c ft_print_p_with_zero_case_a.c \
	ft_print_p_with_zero_case_b.c ft_set_heap_u.c \
	ft_set_heap_u_case_a.c ft_set_heap_u_case_b.c \
	ft_set_heap_u_case_c.c ft_set_heap_u_case_g.c \
	ft_set_heap_u_case_d.c ft_set_heap_u_case_e.c \
	ft_set_heap_u_case_f.c ft_print_u_with_minus.c \
	ft_print_u_with_minus_case_a.c ft_print_u_with_minus_case_b.c \
	ft_print_u_with_minus_case_c.c ft_print_u_with_zero.c \
	ft_print_u_with_zero_case_a.c ft_print_u_with_zero_case_b.c \
	ft_set_heap_xX.c ft_set_heap_xX_case_a.c \
	ft_set_heap_xX_case_b.c ft_set_heap_xX_case_c.c \
	ft_set_heap_xX_case_d.c ft_set_heap_xX_case_e.c \
	ft_set_heap_xX_case_f.c ft_set_heap_xX_case_g.c \
	ft_set_heap_n_case_h.c ft_bzero_char_till_i.c \
	ft_isdigit.c ft_itoa.c ft_putstr_till_i.c \
	ft_putstr.c ft_strlen.c ft_toupper.c ft_uitoa.c \
	ft_strtoupper.c ft_strchr_i.c

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -r $(OBJS)

fclean:
	rm -f $(OBJS) $(NAME)

re: fclean all

bonus:

.PHONY: all clean fclean re bonus