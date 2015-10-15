# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdieumeg <tdieumeg@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/21 16:00:53 by tdieumeg          #+#    #+#              #
#    Updated: 2015/10/15 17:38:18 by tdieumeg         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# binaries
CXX				= /usr/bin/g++
RM				= /bin/rm
MAKE			= /usr/bin/make
MKDIR			= /bin/mkdir
GIT				= /usr/bin/git
CMAKE			= $(HOME)/.brew/bin/cmake
BREW			= $(HOME)/.brew/bin/brew

# colors
NO_COLOR		= \x1b[0m
OK_COLOR		= \x1b[32;01m
WARN_COLOR		= \x1b[33;01m

# app name
NAME			= nibbler

# dir
ROOT			= $(shell pwd)
OBJDIR			= $(ROOT)/objs
SRCDIR			= $(ROOT)/srcs
INCDIR			= $(ROOT)/includes
SFML_LIB_DIR	= $(ROOT)/SFML
GLFW_LIB_DIR	= $(ROOT)/glfw

# lib
GLFW_LIB		= $(GLFW_LIB_DIR)/src/libglfw3.a

# lib_path
NCURSES_LIB_P	= -lncurses
SFML_LIB_P		= $(SFML_LIB_DIR)/lib -Wl,-rpath,$(SFML_LIB_DIR)/extlibs/libs-osx/lib -lsfml-graphics -lsfml-window -lsfml-system
GLFW_LIB_P		= $(GLFW_LIB_DIR)/src -lglfw3 $(GLFW_FRAMEWORK)
GLFW_FRAMEWORK	= -framework Cocoa -framework OpenGL -framework IOKit -framework CoreVideo -framework GLUT

# compil flags
LDFLAGS			= -L $(GLFW_LIB_P) -L $(SFML_LIB_P) $(NCURSES_LIB_P)
INCFLAGS		= -I $(INCDIR) -I $(SFML_LIB_DIR)/include -I $(GLFW_LIB_DIR)/include -Wno-deprecated
CXXFLAGS		= -Wall -Wextra -Werror

# source files
SRC				= test.cpp

# obj
OBJS			= $(patsubst %.cpp, $(OBJDIR)/%.o, $(SRC))

.PHONY: all clean fclean re

all: $(CMAKE) SFML/CMakeLists.txt glfw/CMakeLists.txt $(SFML_LIB) $(GLFW_LIB) $(OBJDIR) $(NAME)

$(NAME): $(OBJS)
	@echo "$(WARN_COLOR)Care! Shell level: $(SHLVL)"
	@echo "$(OK_COLOR)Compiling executable...$(NO_COLOR)"
	@$(CXX) $^ -o $@ $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@echo "$(OK_COLOR)Compiling objects...$(NO_COLOR)"
	@$(CXX) $< -o $@ -c $(INCFLAGS) $(CXXFLAGS)

$(OBJDIR):
	@$(MKDIR) $@

$(BREW):
	/usr/local/bin/brew update

$(CMAKE):
	$(BREW) update
	$(BREW) install cmake

SFML/CMakeLists.txt:
	@echo "$(OK_COLOR)Submodule initialization...$(NO_COLOR)"
	$(GIT) submodule init
	$(GIT) submodule update

glfw/CMakeLists.txt:
	@echo "$(OK_COLOR)Submodule initialization...$(NO_COLOR)"
	$(GIT) submodule init
	$(GIT) submodule update

$(SFML_LIB):
	cd $(SFML_LIB_DIR) && \
	$(CMAKE) . && \
	$(MAKE) && \
	cd ..

$(GLFW_LIB):
	cd $(GLFW_LIB_DIR) && \
	$(CMAKE) . && \
	$(MAKE) && \
	cd ..

clean:
	@echo "$(WARN_COLOR)"
	$(RM) -rf $(OBJDIR)

fclean: clean
	$(RM) -f $(NAME)
	@echo "$(NO_COLOR)"

re: fclean all
