FILE = main.c pars.c inline_func.c ft_cd.c ft_cd_too.c setenv.c unsetenv.c

all : 
	@make -C ../libft/ all
	gcc -g $(FILE) -I. ../libft/lib/libft.a -o minishell
 
 clean:
	rm -rf /a.out
	@make -C ../libft/ clean

 fclean: clean
	@make -C ../libft/ fclean

 re: fclean all