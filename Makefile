# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kammi <kammi@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 15:43:30 by kammi             #+#    #+#              #
#    Updated: 2023/12/13 13:39:59 by kammi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#######################################################
## SOURCES

SRC = ft_printf.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_putptr.c \
			ft_putnbr.c \

SRCS_DIR = ./srcs/
HEADER_DIR	= ./includes/
SRCS =		$(addprefix $(SRCS_DIR), $(SRC))

OBJS		= $(SRCS:.c=.o)

#######################################################
## ARGUMENTS

CC			= cc
RM			= rm -f
AR			= ar rc
RN			= ranlib
CFLAGS 		= -Wall -Wextra -Werror
NAME		= libftprintf.a

########################################################
## RULES

.c.o:
			$(CC) $(CFLAGS) -I $(HEADER_DIR) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			$(AR) $(NAME) $(OBJS)
			$(RN) $(NAME)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
