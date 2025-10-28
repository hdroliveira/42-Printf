# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: huda-roc <huda-roc@42student.com>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/27 15:09:15 by huda-roc          #+#    #+#              #
#    Updated: 2025/10/27 15:11:02 by huda-roc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

# Diretórios
LIBFT_DIR	= ./libft
LIBFT		= $(LIBFT_DIR)/libft.a

# Arquivos fonte
SRC		= ft_printf.c ft_print_char.c ft_print_str.c ft_print_int.c \
		  ft_print_unsigned.c ft_print_hex.c ft_print_ptr.c ft_print_percent.c

OBJ		= $(SRC:.c=.o)

# Compilação
CC		= cc
CFLAGS	= -Wall -Wextra -Werror
AR		= ar rcs
RM		= rm -f

# Regras obrigatórias
all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_DIR)
	@cp $(LIBFT) $(NAME)
	@$(AR) $(NAME) $(OBJ)

%.o: %.c ft_printf.h
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C $(LIBFT_DIR)
	@$(RM) $(OBJ)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
