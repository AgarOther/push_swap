# Compilation
CC					=	cc
CFLAGS				=	-Wall -Wextra -Werror -g
LIBFT				=	@make -C ./libft
LIB					=	libft/libft.a

# Names
NAME				=	push_swap
NAME_BONUS			=	checker

# Sources & Includes
SRCS				= 	srcs/main.c \
						srcs/parsing.c \
						srcs/parsing_utils.c \
						srcs/parsing_rank.c \
						srcs/minimal_sort.c \
						srcs/push.c \
						srcs/swap.c \
						srcs/rotate.c \
						srcs/reverse_rotate.c \
						srcs/sorting_utils.c \
						srcs/sorting.c
SRCS_BONUS			=	srcs/main_bonus.c \
						srcs/parsing_bonus.c \
						srcs/parsing_utils_bonus.c \
						srcs/push_bonus.c \
						srcs/reverse_rotate_bonus.c \
						srcs/rotate_bonus.c \
						srcs/swap_bonus.c \
						srcs/get_moves_bonus.c \
						srcs/moves_utils_bonus.c \
						srcs/ft_lineadd_back_bonus.c \
						srcs/ft_lineclear_bonus.c \
						srcs/ft_linedelone_bonus.c \
						srcs/ft_linelast_bonus.c \
						srcs/ft_linesize_bonus.c \
						srcs/ft_linenew_bonus.c
OBJ_FOLDER			=	objs
OBJ_FOLDER_BONUS	=	objs_bonus
INCLUDES			=	includes
INCLUDES_BONUS		=	bonus

# Objects
OBJS				=	$(OBJ_FOLDER)/main.o \
						$(OBJ_FOLDER)/parsing.o \
						$(OBJ_FOLDER)/parsing_utils.o \
						$(OBJ_FOLDER)/parsing_rank.o \
						$(OBJ_FOLDER)/minimal_sort.o \
						$(OBJ_FOLDER)/push.o \
						$(OBJ_FOLDER)/swap.o \
						$(OBJ_FOLDER)/rotate.o \
						$(OBJ_FOLDER)/reverse_rotate.o \
						$(OBJ_FOLDER)/sorting_utils.o \
						$(OBJ_FOLDER)/sorting.o
OBJS_BONUS			=	$(OBJ_FOLDER_BONUS)/main_bonus.o \
						$(OBJ_FOLDER_BONUS)/parsing_bonus.o \
						$(OBJ_FOLDER_BONUS)/parsing_utils_bonus.o \
						$(OBJ_FOLDER_BONUS)/push_bonus.o \
						$(OBJ_FOLDER_BONUS)/reverse_rotate_bonus.o \
						$(OBJ_FOLDER_BONUS)/rotate_bonus.o \
						$(OBJ_FOLDER_BONUS)/swap_bonus.o \
						$(OBJ_FOLDER_BONUS)/get_moves_bonus.o \
						$(OBJ_FOLDER_BONUS)/moves_utils_bonus.o \
						$(OBJ_FOLDER_BONUS)/ft_lineadd_back_bonus.o \
						$(OBJ_FOLDER_BONUS)/ft_lineclear_bonus.o \
						$(OBJ_FOLDER_BONUS)/ft_linedelone_bonus.o \
						$(OBJ_FOLDER_BONUS)/ft_linelast_bonus.o \
						$(OBJ_FOLDER_BONUS)/ft_linesize_bonus.o \
						$(OBJ_FOLDER_BONUS)/ft_linenew_bonus.o

# Custom Makefile Flags
MAKEFLAGS			+=	--no-print-directory --silent

# Custom Colors
PURPLE				=	\033[1;35m
LIGHT_GREEN			=	\033[1;32m
RESET				=	\033[0m

# Custom messages
LIB_DONE			=	@echo "🎉$(PURPLE) Libft compiled! 🎉$(RESET)\n"
EXE_DONE			=	@echo "🎉$(PURPLE) $(NAME) compiled! 🎉$(RESET)\n"
BONUS_DONE			=	@echo "🎉$(PURPLE) $(NAME_BONUS) compiled! 🎉$(RESET)\n"
ALL_CLEAN			=	@echo "🧹$(LIGHT_GREEN) Project's objects cleaned! 🧹$(RESET)\n"
ALL_FCLEAN			=	@echo "🧹$(LIGHT_GREEN) Project's objects & Executables cleaned! 🧹$(RESET)\n"

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

$(NAME_BONUS): libft $(OBJS_BONUS)
	@$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIB) -o $(NAME_BONUS)
	$(BONUS_DONE)

$(OBJ_FOLDER)/%.o: srcs/%.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES)

$(OBJ_FOLDER_BONUS)/%.o: bonus/%.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(INCLUDES_BONUS)

bonus :
	@if [ ! -d $(OBJ_FOLDER_BONUS) ]; then \
		mkdir $(OBJ_FOLDER_BONUS); \
	fi
	@if [ -f $(NAME_BONUS) ]; then \
		echo '✅$(LIGHT_GREEN) Nothing to be done for "all"! ✅$(RESET)\n'; \
	else \
		$(MAKE) $(NAME_BONUS); \
	fi

libft : 
	$(LIBFT)
	$(LIB_DONE)

clean :
	@cd libft && make clean
	@rm -rf $(OBJ_FOLDER)
	@rm -rf $(OBJ_FOLDER_BONUS)
	$(ALL_CLEAN)

fclean :
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@cd libft && make fclean
	@rm -rf $(OBJ_FOLDER)
	@rm -rf $(OBJ_FOLDER_BONUS)
	$(ALL_FCLEAN)

re : fclean all

f : $(NAME)

fb : $(NAME_BONUS)

.PHONY: all clean fclean re libft check_relink push_swap bonus checker f fb
