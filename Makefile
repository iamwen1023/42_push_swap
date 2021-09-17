INCS		= includes
LIB			= libft
LIB.A		= libft.a
CH_SRC		= check/check_op1.c check/check_op2.c check/checker_main.c
P_SRC		= src/big_sort.c src/main.c src/small_sort.c
SHARE_SRC 	= share/check_err.c share/creat_listd.c share/operation_1.c share/operation_2.c share/replace_by_ranking.c share/parse_list.c
CH_OBJ_NAME = $(CH_SRC:.c=.o)
P_OBJ_NAME	= $(P_SRC:.c=.o)
SH_OBJ_NAME	= $(SHARE_SRC:.c=.o)
NAME_C		= checker
NAME_P		= push_swap
FLAGS		= -Wall -Wextra -Werror -I${INCS} -I.
ifeq (${DEBUG}, 1)
	FLAGS	+= -g
endif
		
all: $(NAME_P) $(NAME_C)

$(LIB.A):
		make -C $(LIB)
		@mv $(LIB)/$(LIB.A) .

bonus: $(NAME_C)

$(NAME_P): $(LIB.A) $(P_OBJ_NAME) $(SH_OBJ_NAME)
		gcc -o $@ $(P_OBJ_NAME) $(SH_OBJ_NAME) $(LIB.A) $(FLAGS)

$(NAME_C): $(LIB.A) $(CH_OBJ_NAME) $(SH_OBJ_NAME)
		gcc -o $@ $(CH_OBJ_NAME) $(SH_OBJ_NAME) $(LIB.A) $(FLAGS)

%.o: %.c
		cc $(FLAGS) -c $< -o $(<:.c=.o)

clean:
		$(RM) $(CH_OBJ_NAME) $(P_OBJ_NAME) $(SH_OBJ_NAME) $(LIB.A)
		make clean -C $(LIB)

fclean:		clean
		$(RM) $(NAME_C) $(NAME_P) $(LIB.A)
		make fclean -C $(LIB)

re:		fclean all

.PHONY: 	all clean fclean re
