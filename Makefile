# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bizcru <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/18 17:30:42 by bizcru            #+#    #+#              #
#    Updated: 2025/05/20 00:15:08 by bizcru           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC_NAMES = main.c colors.c events.c 2d_utils.c draw_utils.c map.c
SRC_DIR = src
SRC = $(addprefix $(SRC_DIR)/, $(SRC_NAMES))
OBJ = $(SRC:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

BUILD_DIR = build

LIBS_DIR = libs
LIBFT_DIR = $(LIBS_DIR)/libft
LIBFT = $(LIBFT_DIR)/libft.a
LIBMLX = $(LIBS_DIR)/MLX42/build/libmlx42.a
LIB_FLAGS = -L$(LIBFT_DIR) -lft $(LIBMLX) -Iinclude -ldl -lglfw -pthread -lm 

HDER = $(SRC_DIR)/fdf.h
CFLAGS = -Wall -Wextra -Werror -g -fsanitize=address
CC = cc

END = \033[m
RED = \033[31m
GREEN = \033[32m
YELLOW = \033[33m
BLUE = \033[34m
PURPLE = \033[35m
CIAN = \033[36m
MAKEFLAGS += --no-print-directory

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@echo -n "\n$(YELLOW)--->BUILDING $(NAME)...$(END)\n"
	@$(CC) $(CFLAGS) $(OBJ) $(LIB_FLAGS) -o $(NAME)
	@echo "$(GREEN)   === BUILDING COMPLETE : ) ===$(END)\n"

$(LIBFT): 
	@echo "\n $(YELLOW) ---> Compiling libft... === $(END)"
	@make -C $(LIBFT_DIR)
	@echo "$(GREEN)   === libft.a is compiled :) ===$(END)"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c $(HDER) Makefile | $(BUILD_DIR)
	@$(CC) $(CFLAGS) -I. -Imlx_linux -O3 -c $< -o $@
	@echo -n "\n $(BLUE) ---> Building $<... --- $(END)"
	@echo " $(CIAN) DONE! :) $(END)"

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

clean:
	@echo -n "$(RED) --> Deleting object files... $(END)"
	@make -C $(LIBFT_DIR) clean
	@rm -rf $(BUILD_DIR)
	@echo "$(GREEN) DONE! $(END)"

fclean: clean
	@echo -n "$(RED) --> Deleting executables... $(END)"
	@make -C $(LIBFT_DIR) fclean
	@rm -rf $(NAME) 
	@echo "$(GREEN) DONE! $(END)"

re: fclean all

.PHONY: all clean fclean bonus re $(LIBFT)
