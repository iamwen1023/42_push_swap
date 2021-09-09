INCS		= push_swap.h
LIB			= libft
LIB.A		= libft.a
CH_SRC_NAME = checker/check_op1.c checker/check_op2.c checker/checker.c
P_SRC_NAME	= src/big_sort.c src/check_err.c src/creat_listd.c src/main.c \
			src/operation_1.c src/operation_2.c replace_by_ranking.c small_sort.c 
CH_OBJ_NAME = $(CH_SRC_NAME:.c=.o)
P_OBJ_NAME	= $(P_SRC_NAME:.c=.o)
SRC_PATH 	= src
OBJ_PATH	= obj
CH_SRC		= $(addprefix $(SRC_PATH)/, $(CH_SRC_NAME))
P_SRC		= $(addprefix $(SRC_PATH)/, $(P_SRC_NAME))
CH_OBJ 		= $(addprefix $(OBJ_PATH)/, $(CH_OBJ_NAME))
P_OBJ 		= $(addprefix $(OBJ_PATH)/, $(P_OBJ_NAME))
FLAGS		= -Wall -Wextra -Werror
NAME_C		= checker
NAME_P		= push_swap
		
all:	library $(NAME_C) $(NAME_P)

library:
		make -C $(LIB)
$(NAME_C): $(CH_OBJ)
		gcc -o $(NAME_C) $(CH_OBJ) $(INCS) $(LIB)/$(LIB.A) -g
$(NAME_P): $(P_OBJ)
		gcc -o $(NAME_P) $(P_OBJ) $(INCS) $(LIB)/$(LIB.A) -g

$(OBJ_PATH)/%.o: $(SRC_PATH%)%.c
		@mkdir -p $(OBJ_PATH)
		@mkdir -p $(dir $(P_OBJ))
		@mkdir -p $(dir $(CH_OBJ))
		gcc -o $@ -c $< $(INCS) $(FLAGS) -g

clean:
		$(RM) $(CH_OBJ_NAME) $(P_OBJ_NAME) 

fclean:		clean
		$(RM) $(NAME_C) $(NAME_P)

re:		fclean all


.PHONY: 	all clean fclean re .c.o 