FILE = src/main.c src/pars.c src/inline_func.c src/ft_cd.c src/ft_cd_too.c src/setenv.c src/unsetenv.c src/launch_shell.c src/exit.c src/echo.c src/matr_print.c

OBJ = src/main.o src/pars.o src/inline_func.o src/ft_cd.o src/ft_cd_too.o src/setenv.o src/unsetenv.o src/launch_shell.o src/exit.o src/echo.o src/matr_print.o

NAME = minishell
all : $(NAME)

$(NAME):
	make -C  ft_printf/libft/ all
	gcc -g  $(FILE) -I /includes/  ft_printf/lib/libftprintf.a -o $(NAME)  
 
 clean:
	make -C ft_printf/libft/ clean
	rm -rf $(OBJ)
 fclean: clean
	make -C ft_printf/libft/ fclean
	rm -rf $(NAME)
 re: fclean all
