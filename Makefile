NAME 	= 			libftprintf.a

HEAD 	=			ft_printf.h

OBJ_DIR		=		obj/

CC 	 	=			cc

CFLAGS	=			-Wall -Werror -Wall -MMD -MP

AR		=			ar -rcs

SRC		=	ft_printf.c \
			utils.c

OBJ		=			$(SRC:%.c=$(OBJ_DIR)%.o)
DEP		=			$(SRC:%.c=$(OBJ_DIR)%.d)

$(OBJ_DIR)%.o: %.c $(HEAD) Makefile | $(OBJ_DIR)
						$(CC) $(CFLAGS) -c $< -o $@

all:				$(NAME)

$(NAME):			$(OBJ)
						$(AR) $@ $?

$(OBJ_DIR):
						@mkdir -p $(OBJ_DIR)

clean:
						@rm -rf $(OBJ) $(OBJ_DIR)
						@echo "Deleting 'obj'"

fclean:				clean
						@rm -rf $(NAME)
						@echo "Deleting 'libft.a'"

re: 					fclean all

.PHONY: 				clean fclean re all

-include $(DEP) $(DEP_BONUS)
