CPP := c++ -Wall -Werror -Wextra -std=c++98

OBJ_PATH := ./
SRC_PATH := ./

EXE := Span

TAR := $(SRC)$(EXE)

SRC := $(wildcard *.cpp)

OBJ := $(SRC:.cpp=.o)

all: $(TAR)

re: fclean all

$(TAR): $(OBJ)
	$(CPP) -o $@ $(OBJ)

$(OBJ_PATH)/%.o: %(SRC_PATH)/%.c*
	$(CPP) -c -o $@ $<

fclean: clean
	rm -f $(TAR)

clean: 
	rm -f $(OBJ)

.PHONY: fclean clean all re