# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmauri <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/05 20:30:36 by mmauri            #+#    #+#              #
#    Updated: 2024/09/20 16:40:26 by mmauri           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I./gnl
SRCS = ft_atoi.c ft_isalpha.c ft_memchr.c ft_memset.c ft_strlcpy.c \
	   ft_strrchr.c ft_bzero.c ft_isascii.c ft_memcmp.c ft_strchr.c \
	   ft_strlen.c ft_tolower.c ft_calloc.c ft_isdigit.c ft_memcpy.c \
	   ft_strdup.c ft_strncmp.c ft_toupper.c ft_isalnum.c ft_isprint.c \
	   ft_memmove.c ft_strlcat.c ft_strnstr.c ft_putendl_fd.c ft_itoa.c \
	   ft_putnbr_fd.c ft_strjoin.c ft_substr.c ft_putchar_fd.c \
	ft_putstr_fd.c ft_strtrim.c ft_split.c ft_strmapi.c ft_striteri.c \
	ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c \
        ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c \
        ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c \
	printf/ft_printf.c printf/ft_printf_utils.c gnl/get_next_line.c \
	gnl/get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJS) 
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
