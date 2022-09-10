# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rkassouf <rkassouf@student.42abudhabi.ae>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/25 17:04:27 by rkassouf          #+#    #+#              #
#    Updated: 2022/09/11 00:08:04 by rkassouf         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

RM = rm -rf

# Executable / Libraries.

FT				= libft.a
NAME			= push_swap

# Libraries.

LFT_DIR			= libft

# I/O Compilation.

SRCS_DIR		= src
OBJS_DIR		= obj

# Location of all header files used in the project.

INCS_DIR		:= inc
INCS_DIR		+= $(LFT_DIR)/includes

# Every libraries needed to compile the project.

LFT				= $(LFT_DIR)/$(FT)

# Used header at each compilation to check file integrity.

INCS			= inc/push_swap.h

# Source files.
SRCS			= ft_px.c				ft_rrx.c \
				  ft_rx.c				ft_sx.c \
				  parse.c				push_swap.c \
				  sort_small.c			index_lst.c

# Some tricks in order to get the makefile doing his job.

D_SRCS			= $(addsuffix /, $(SRCS_DIR))
D_OBJS			= $(addsuffix /, $(OBJS_DIR))
C_OBJS			= $(addprefix $(D_OBJS), $(OBJS))
C_INCS			= $(foreach include, $(INCS_DIR), -I$(include))

# How files should be compiled.

CC				= gcc
OBJS			= $(SRCS:.c=.o)

# Compilation flags.

CFLAGS			= $(C_INCS) -Wall -Wextra -Werror

# Redefinition of the implicit compilation rule to prompt some informations.

$(D_OBJS)%.o: $(D_SRCS)%.c $(INCS)
	@$(CC) $(CFLAGS) -c $< -o $@

# Implicit make rule simply using dependancies to compile our project.

all: $(OBJS_DIR) $(NAME)

$(NAME): $(LFT) $(C_OBJS)
	$(CC) $(C_OBJS) -L$(LFT_DIR) -lft -o $(NAME)

# Libraries installion using their own Makefile.

$(LFT):
	@make -sC $(LFT_DIR)

# Rules used to create folders if they aren't already existing.

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

# Deleting all .o files.

clean :
	@make -sC $(LFT_DIR) clean
	@$(RM) -rf $(OBJS_DIR)

fclean : clean
	@make -sC $(LFT_DIR) fclean
	@$(RM) $(NAME)

re : fclean all

.PHONY : all clean fclean re