# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bizcru <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/28 15:47:58 by bizcru            #+#    #+#              #
#    Updated: 2024/12/11 23:56:10 by bizcru           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror -D BUFFER_SIZE=42 -g
CC = cc

SRCS = ft_islower.c ft_isupper.c ft_isalpha.c ft_isdigit.c ft_isalnum.c \
		ft_isascii.c ft_isprint.c ft_strlen.c ft_toupper.c ft_tolower.c \
		ft_atoi.c ft_atoi_pshswp.c ft_strlcpy.c ft_strlcat.c ft_strncmp.c \
		ft_strcmp.c ft_striteri.c ft_strdup.c ft_substr.c ft_strndup.c \
		ft_strnstr.c ft_strjoin.c ft_strmapi.c ft_strchr.c ft_strrchr.c \
		ft_strtrim.c ft_strdup.c ft_memcpy.c ft_memrcpy.c ft_memrcpy.c \
		ft_memmove.c ft_memcmp.c ft_memset.c ft_memchr.c ft_putnbr_base.c \
		ft_putnbr_base_u.c ft_print_memory.c ft_strchr.c ft_strrchr.c \
		ft_bzero.c ft_calloc.c ft_itoa.c ft_itoa_u.c ft_putchar_fd.c \
		ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_split.c \
		ft_lstnew.c ft_lstadd_front.c ft_lstadd_back.c ft_lstsize.c \
		ft_lstlast.c ft_lstlast_prev.c ft_lstdelone.c ft_lstclear.c \
		ft_lstiter.c ft_lstiter_back.c ft_lstmap.c ft_printf.c \
		ft_printf_utils.c get_next_line.c ft_strstr.c ft_free_array.c \
		ft_strjoinf.c ft_print_lst.c ft_print_array.c ft_strjoins.c

OBJS = $(SRCS:.c=.o)
MAKEFLAGS += --no-print-directory
END = \033[m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
PURPLE = \033[35m
CIAN = \033[36m

all: $(NAME)

$(NAME): $(OBJS) libft.h Makefile
	@echo -n "$(PURPLE) -->building libft library..."
	@ar rc $@ $(OBJS)
	@ranlib $@ 
	@echo "$(GREEN) DONE! $(END)"

%.o: %.c Makefile
	@$(CC) $(CFLAGS) -I. -c $< -o $@

clean: 
	@rm -f $(OBJS)

fclean: clean
	@rm -f libft.a

re: fclean all

.PHONY: all clean fclean re
