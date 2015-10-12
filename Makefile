# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdieumeg <tdieumeg@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/21 16:00:53 by tdieumeg          #+#    #+#              #
#    Updated: 2015/10/12 12:34:42 by tdieumeg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# binaries
CXX		= /usr/bin/g++
RM		= /bin/rm
MAKE	= /usr/bin/make
MKDIR	= /bin/mkdir

# colors
NO_COLOR=\x1b[0m
OK_COLOR=\x1b[32;01m
WARN_COLOR=\x1b[33;01m

# app name
NAME	= nibbler

# dir
ROOT	= $(shell pwd)
OBJDIR	= $(ROOT)/objs
SRCDIR	= $(ROOT)/srcs
INCDIR	= $(ROOT)/includes

# compil flags
CXXFLAGS = -I $(INCDIR) -Wall -Wextra -Werror

# source files
SRC		=

# obj
OBJS	= $(patsubst %.cpp, $(OBJDIR)/%.o, $(SRC))

.PHONY: all clean fclean re

all: $(OBJDIR) $(NAME)

$(NAME): $(OBJS)
	@echo "$(OK_COLOR)Compiling executable...$(NO_COLOR)"
	@$(CXX) $(OBJS) -o $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@echo "$(OK_COLOR)Compiling objects...$(NO_COLOR)"
	@$(CXX) $< -o $@ -c $(CXXFLAGS)

$(OBJDIR):
	@$(MKDIR) $@

clean:
	@echo "$(WARN_COLOR)"
	$(RM) -rf $(OBJDIR)

fclean: clean
	$(RM) -f $(NAME)
	@echo "$(NO_COLOR)"

re: fclean all
