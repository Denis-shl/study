# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oargrave <oargrave@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/23 14:13:04 by yquaro            #+#    #+#              #
#    Updated: 2019/09/02 16:12:35 by oargrave         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

all:
	@echo \*\*\* Reassembly libft.a and printf.a to $(NAME)
	ar -x libft.a
	ar -x printf.a
	@ar rc $(NAME) *.o
	@ranlib $(NAME)
	@rm -f __.SYMDEF*
	# @mv $(NAME) ../$(NAME)
	@mv $(NAME) ../lib$(NAME)
	@echo \*\*\* LIBFTPRINTF COMPILED!

clean:
	@rm -f *.o

fclean: clean