# Compilation

CC			= cc

CFLAGS		= -Wall -Wextra -Werror

LIBFT		= @make -C ./libft

LIB			= libft/libft.a

# Names

NAME		= push_swap

# Sources & Includes

SRCS		= 	srcs/main.c \
				srcs/parsing.c \
				srcs/parsing_utils.c \
				srcs/parsing_rank.c \
				srcs/minimal_sort.c \
				srcs/push.c \
				srcs/swap.c \
				srcs/rotate.c \
				srcs/reverse_rotate.c \
				srcs/sorting.c \
				srcs/elevator_sorting.c

SRCS_BONUS	=	srcs/parsing.c \
				srcs/parsing_utils.c \
				srcs/parsing_rank.c \
				bonus/main.c \
				bonus/instructions.c \
				bonus/ft_parsenew.c

OBJ_FOLDER	= objs

INCLUDES	= includes

# Objects

OBJS		= 	$(patsubst srcs/%.c, $(OBJ_FOLDER)/%.o, $(SRCS))

BONUS_OBJS	=	$(patsubst srcs/%.c, $(OBJ_FOLDER)/%.o, $(SRCS_BONUS))

# Custom Makefile Flags

MAKEFLAGS	+= --no-print-directory --silent

# Custom Colors

PURPLE		= \033[1;35m

LIGHT_GREEN	= \033[1;32m

RESET		= \033[0m

# Custom messages

LIB_DONE	= @echo "🎉$(PURPLE) Libft compiled! 🎉$(RESET)\n"

EXE_DONE	= @echo "🎉$(PURPLE) $(NAME) compiled! 🎉$(RESET)\n"

ALL_CLEAN	= @echo "🧹$(LIGHT_GREEN) Project's objects cleaned! 🧹$(RESET)\n"

ALL_FCLEAN	= @echo "🧹$(LIGHT_GREEN) Project's objects & Executables cleaned! 🧹$(RESET)\n"

# Rules

all : check_relink

check_relink:
	@if [ ! -d $(OBJ_FOLDER) ]; then \
		mkdir $(OBJ_FOLDER); \
	fi
	@if [ -f $(NAME) ]; then \
		echo '✅$(LIGHT_GREEN) Nothing to be done for "all"! ✅$(RESET)\n'; \
	else \
		$(MAKE) $(NAME); \
	fi

$(NAME): libft $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)
	$(EXE_DONE)

$(OBJ_FOLDER)/%.o: srcs/%.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES) -I bonus/push_swap_bonus.c

libft : 
	$(LIBFT)
	$(LIB_DONE)

bonus : libft $(OBJS_BONUS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)

clean :
	@rm -f $(OBJS)
	@cd libft && make clean
	@rm -rf $(OBJ_FOLDER)
	$(ALL_CLEAN)

fclean :
	@rm -f $(NAME) $(OBJS)
	@cd libft && make fclean
	@rm -rf $(OBJ_FOLDER)
	$(ALL_FCLEAN)

re : fclean all

.PHONY: all clean fclean re libft check_relink push_swap
