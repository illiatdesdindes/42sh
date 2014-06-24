# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svachere <svachere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 12:04:58 by svachere          #+#    #+#              #
#    Updated: 2014/03/19 19:03:40 by svachere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
SRCSFILES = pf_putstr.c pf_putnbr.c pf_print_num.c pf_print_chars.c \
		pf_print_pointer.c pf_format.c ft_printf.c \
		ft_strlen.c ft_strdup.c ft_strcpy.c ft_strcat.c ft_strncat.c \
		ft_strlcat.c ft_strncpy.c ft_strchr.c ft_strrchr.c ft_strstr.c \
		ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_isalpha.c ft_isdigit.c \
		ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c \
		ft_atoi.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
		ft_memchr.c ft_memcmp.c ft_memdup.c \
		ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c ft_strclr.c \
		ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c ft_strequ.c \
		ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c ft_strsplit.c \
		ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c ft_putnbr.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
		ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
		get_next_line.c ft_fact.c ft_pow.c ft_sin.c ft_cos.c ft_tan.c \
		error_if.c ft_strvdel.c ft_strvlen.c ft_strvadd.c error_exit.c \
		ft_putstrv.c
SRCSDIR = ./
SRCS = $(addprefix $(SRCSDIR), $(SRCSFILES))
OBJS = $(SRCS:.c=.o)
HEADERS = libft.h libftprintf.h
HEADERFLAGS = $(addprefix -I, $(dir $(HEADERS)))

SRCTEST = main_.c 
OBJTEST = $(SRCTEST:.c=.o)


all: $(NAME)
	
$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) $(HEADERFLAGS) -c -o $@ $<

clean:
	/bin/rm -f $(OBJS)
	/bin/rm -rf a.out.dSYM

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

prepare: fclean
	rm main_.c main_test_.c svtest_.c svtest_.h test_.c

.PHONY: re fclean clean

check: all
	#$(CC) $(CFLAGS) -$(CFLAGS) c -Wall -Wextra -Werror $(SRCTEST) -I $(HEADER)
	#$(CC) $(OBJTEST) -L. -lft
	$(CC) $(CFLAGS) -Wall -Wextra -Werror $(SRCTEST) -L. -lft -I $(HEADER)

checkfclean: fclean
	/bin/rm -f $(OBJTEST)
	/bin/rm -f a.out

recheck: checkfclean check

rm: checkfclean

retest: recheck
	./a.out

maintest: all
	$(CC) -c -Wall -Wextra -Werror main_test_.c -I $(HEADER)
	$(CC) main_test_.o -L. -lft

