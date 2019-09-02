FILE = src/main.c src/pars.c src/inline_func.c src/ft_cd.c src/ft_cd_too.c src/setenv.c src/unsetenv.c src/launch_shell.c src/exit.c src/echo.c src/matr_print.c

all : 
	@make -C ../libft/ all
	gcc -g $(FILE) -I. ../libftprintf.a -o minishell
 
 clean:
	rm -rf /a.out
	@make -C ../libft/ clean

 fclean: clean
	@make -C ../libft/ fclean

 re: fclean all