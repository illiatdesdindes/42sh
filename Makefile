# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apergens <apergens@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/19 12:04:58 by svachere          #+#    #+#              #
#    Updated: 2014/06/23 14:22:01 by svachere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = patatesh
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
SRCSFILES = main.c \
			env.c \
	 		pathmanip.c \
			free.c \
			builtins.c \
			builtins2.c \
			strvutils.c	\
			bi_cd.c \
			print.c \
			lexer.c \
			token_add_types.c \
			returncmd.c \
			ast.c \
			syntax.c \
			parser.c
SRCSDIR = srcs/
SRCS = $(addprefix $(SRCSDIR), $(SRCSFILES))
OBJSDIR = objs/
OBJSFILES = $(SRCSFILES:.c=.o)
OBJS = $(addprefix $(OBJSDIR), $(OBJSFILES))
HEADERS = srcs/sh42.h libft/libft.h libft/libftprintf.h
HEADERFLAGS = $(addprefix -I, $(dir $(HEADERS)))
LIBS = libft/libft.a
LDFLAGS = -L libft/ -lft

all: $(NAME)

$(NAME): $(OBJSDIR) $(LIBS) $(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

$(OBJSDIR):
	mkdir $(OBJSDIR)

$(LIBS):
	$(MAKE) -C $(dir $@)

$(OBJSDIR)%.o: $(SRCSDIR)%.c $(HEADERS)
	$(CC) $(CFLAGS) $(HEADERFLAGS) -c -o $@ $<

clean:
	$(MAKE) -C libft/ $@
	/bin/rm -f $(OBJS)

fclean: clean
	$(MAKE) -C libft/ $@
	/bin/rm -f $(NAME)

re: fclean all

libftinstall:
	mkdir libft
	$(MAKE) libftupdate

libftupdate:
	cp ../libft/* libft
	$(MAKE) -C libft/ prepare

.PHONY: clean fclean re
