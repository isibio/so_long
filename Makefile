# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: isibio <isibio@student.42nice.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/25 17:29:11 by isibio            #+#    #+#              #
#    Updated: 2023/04/25 17:29:12 by isibio           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors and styles variables
	CLEAN	= \033[0m
	BOLD	= \033[1m
	CLEAR	= \r\033[K
	BLUE	= \033[38;5;27m
	YELLOW	= \033[38;5;226m
	GRAY	= \033[38;5;8m
	GREEN	= \033[38;5;46m
	ORANGE	= \033[38;5;214m
	WHITE	= \033[38;5;231m
	BK_		= \033[48;5;0m

# Colors and styles variables
	CLEAN	= \033[0m
	BOLD	= \033[1m
	CLEAR	= \r\033[K
	BLUE	= \033[38;5;27m
	YELLOW	= \033[38;5;226m
	GRAY	= \033[38;5;8m
	GREEN	= \033[38;5;46m
	ORANGE	= \033[38;5;214m
	WHITE	= \033[38;5;231m
	BK_		= \033[48;5;0m

	TOTAL_NORM_ERR		= $(shell norminette includes srcs | grep -F "Error:" | wc -l)
	TOTAL_NORM_ERR_DOC	= $(shell norminette includes srcs | grep -F Error\! | wc -l)

# Variables fron Shell command
	SRCS_SHELL 				= $(shell ls -d1 srcs/*/** | grep -F .c)
	TOTAL_C_FILES			= $(shell ls -d1 srcs/*/** | grep -F .c | wc -l)
	TOTAL_O_FILES			= $(shell ls -d1 srcs/*/** | grep -F .o | wc -l)
	TOTAL_A_FILES			= $(shell ls bin/ | grep -F .a | wc -l)
	TOTAL_CLEAN_FILES_ECHO	= $(shell echo ${TOTAL_O_FILES})
	TOTAL_FCLEAN_FILES_ECHO	= $(shell echo ${TOTAL_O_FILES} +${TOTAL_A_FILES})
	TOTAL_PERCENT_ECHO		= $(shell echo ${TOTAL_O_FILES} /${TOTAL_C_FILES})
	TOTAL_NORM_ERR			= $(shell norminette | grep -F "Error:" | wc -l)
	TOTAL_NORM_ERR_DOC		= $(shell norminette | grep -F Error\! | wc -l)


	# Project variables
	PROJECT_NAME				=so_long
	PROJECT_NAME_DISPLAY		=${CLEAN}${WHITE}[${ORANGE}${PROJECT_NAME}${WHITE}]${CLEAN}
	PROJECT_NAME_DISPLAY_UNDONE	=${CLEAN}${WHITE}[${BOLD}${GRAY}${TOTAL_PERCENT_ECHO} files${CLEAN}${WHITE}]${CLEAN}
	PROJECT_NAME_DISPLAY_DONE	=${CLEAN}${WHITE}[${ORANGE}${PROJECT_NAME}${WHITE}]${CLEAN}

SRCS = 	$(shell ls -d1 srcs/*/** | grep -F .c) \
		${LIBFT_A}

GCC = gcc

FLAGS = -Wall -Wextra -Werror #-fsanitize=address

HEADER = -I includes/so_long.h

NAME = bin/so_long

OBJS = ${SRCS:.c=.o}

LIBFT_A = lib/libft/bin/libft.a

all : ${LIBFT_A} ${NAME}

.c.o : 
	@printf "$(PROJECT_NAME_DISPLAY_UNDONE) $(CLEAN)${WHITE}Compiling >> %s ${CLEAN}" ${notdir $<}
	@${GCC} ${FLAGS} ${HEADER} -c $< -o ${<:.c=.o}
	@printf "$(CLEAR)$(PROJECT_NAME_DISPLAY_DONE) ${WHITE}Compiling >> ${BOLD}${GREEN}%s  ✓ \n${CLEAN}" ${notdir $<}

${NAME}: ${OBJS}
	@printf "$(PROJECT_NAME_DISPLAY_UNDONE) $(CLEAN)${WHITE}Compiling >> %s ${CLEAN}" ${notdir $<}
	@${GCC} ${FLAGS} ${HEADER} ${OBJS} -o ${NAME}
	@printf "$(CLEAR)$(PROJECT_NAME_DISPLAY_DONE) ${WHITE}Compiling >> ${BOLD}${GREEN}%s  ✓ \n${CLEAN}" ${notdir $<}

${LIBFT_A} :
	@make -C lib/libft

clean :
	@printf "$(PROJECT_NAME_DISPLAY_UNDONE) ${RED}${BOLD}${GRAY}cleaning ${TOTAL_CLEAN_FILES_ECHO} files ${CLEAN}"
	@rm -f ${OBJS}
	@make clean -C lib/libft
	@printf "$(CLEAR)$(PROJECT_NAME_DISPLAY_DONE) ${WHITE}Cleaning : ${BOLD}${GREEN}deleted ${TOTAL_CLEAN_FILES_ECHO} files ✓\n${CLEAN}"

fclean :
	@printf "$(PROJECT_NAME_DISPLAY_UNDONE) ${RED}${BOLD}${GRAY}cleaning ${TOTAL_FCLEAN_FILES_ECHO} files ${CLEAN}"
	@rm -f ${OBJS}
	@rm -f ${NAME}
	@make fclean -C lib/libft
	@printf "$(CLEAR)$(PROJECT_NAME_DISPLAY_DONE) ${WHITE}Cleaning : ${BOLD}${GREEN}deleted ${TOTAL_FCLEAN_FILES_ECHO} files ✓\n${CLEAN}"

re : fclean all

rmds :
	@rm -rf .DS_STORE
	@rm -rf bin/.DS_STORE
	@rm -rf bin/*/.DS_STORE
	@rm -rf lib/.DS_STORE
	@rm -rf lib/*/.DS_STORE
	@rm -rf includes/.DS_STORE
	@rm -rf includes/*/.DS_STORE
	@rm -rf srcs/.DS_STORE
	@rm -rf srcs/*/.DS_STORE

norm :
	@printf "${WHITE}>>> ${ORANGE}${TOTAL_NORM_ERR} ${WHITE}norm error \n>>> ${ORANGE}${TOTAL_NORM_ERR_DOC} ${WHITE}documemts with norm errors\n"

git : fclean norm rmds
	@printf "\n"
	@git status

gitall : fclean norm rmds
	@printf "${WHITE}\n"
	@git status
	@printf "${WHITE}\n"
	@git add .
	@printf "${WHITE}\n"
	@git commit .
	@printf "${WHITE}\n"
	@git push origin master
	@printf "\n"

exec : all
	@clear
	@${NAME}

.PHONY : all clean fclean re 