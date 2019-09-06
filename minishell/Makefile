FILE = src/main.c src/pars.c src/inline_func.c src/ft_cd.c src/ft_cd_too.c src/setenv.c src/unsetenv.c src/launch_shell.c src/exit.c src/echo.c src/matr_print.c

all : 
	@make -C  ft_printf/libft/ all
	gcc -g  $(FILE) -I. ft_printf/lib/libftprintf.a -o minishell  
 
 clean:
	@make -C ft_printf/libft/ clean

 fclean: clean
	@make -C ft_printf/libft/ fclean

 re: fclean all
